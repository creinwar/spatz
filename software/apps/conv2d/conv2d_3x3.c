#include "conv2d.h"
#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void conv2d_3x3(int32_t *o, int32_t *i, int32_t *f, int32_t R, int32_t C,
                int32_t F) {
  // We work on 4 rows of the output matrix at once
  int32_t block_size_o = 4;
  // We work on block_size_o + F - 1 rows of the input matrix at once

  int32_t block_size_c;

  // Set the vector configuration
  asm volatile("vsetvli %0, %1, e32, m2, ta, ma" : "=r"(block_size_c) : "r"(C+F-1));

  block_size_c = block_size_c - F + 1;

  for (int32_t c = 0; c < C; c += block_size_c) {

    int32_t c_ = MIN(C - c, block_size_c);

    // First iteration round, r = 0
    int32_t *i_ = i + c;
    int32_t *o_ = o + c;

    // For simplicity, compute over the padding rows as well
    conv2d_vec_4xC_slice_init_3x3(o_, c_, C);
    // Preload the first two input rows -> This is not needed in the other rounds
    conv2d_vec_4xC_slice_preload_3x3(i_, c_, C, F);
    // The first F-1 rows have already been loaded by
    // conv2d_vec_4xC_slice_preload_3x3()
    int32_t *i__ = i_ + (F - 1) * (C + F - 1);
    conv2d_vec_4xC_3x3(o_, i__, f, c_, C, F);
    // Re-use some of the already-loaded input rows
    conv2d_vec_4xC_slice_move_3x3(c_, C, F);

    // Iterate over the output rows
    for (int32_t r = block_size_o; r < R; r += block_size_o) {
      i_ = i + r * (C + F - 1) + c;
      o_ = o + r * C + c;

      // For simplicity, compute over the padding rows as well
      conv2d_vec_4xC_slice_init_3x3(o_, c_, C);
      // The first F-1 rows have already been loaded by
      // conv2d_vec_4xC_slice_init()
      i__ = i_ + (F - 1) * (C + F - 1);
      conv2d_vec_4xC_3x3(o_, i__, f, c_, C, F);
      // Re-use some of the already-loaded input rows
      conv2d_vec_4xC_slice_move_3x3(c_, C, F);
    }
  }
}

// Load 4 rows of the output matrix
void conv2d_vec_4xC_slice_init_3x3(int32_t *o, int32_t c, int32_t C) {
  // Helper variables
  int32_t lwo = C << 2;

  // Set the vector configuration
  asm volatile("vsetvli zero, %0, e32, m2, ta, ma" ::"r"(c));
  // Fetch 4 output rows
  asm volatile("vmv.v.i v0,  0; add %0, %0, %1" : "+&r"(o) : "r"(lwo));
  asm volatile("vmv.v.i v2,  0; add %0, %0, %1" : "+&r"(o) : "r"(lwo));
  asm volatile("vmv.v.i v4,  0; add %0, %0, %1" : "+&r"(o) : "r"(lwo));
  asm volatile("vmv.v.i v6,  0;" : "+r"(o));
}

// Load 4 rows of the output matrix
void conv2d_vec_4xC_slice_preload_3x3(int32_t *i, int32_t c, int32_t C, int32_t F) {
  // Helper variables
  int32_t lwi = (C + F - 1) << 2;

  // Set the vector configuration
  asm volatile("vsetvli zero, %0, e32, m2, ta, ma" ::"r"(c + F - 1));
  // Fetch the first floor(F/2) + 1 input rows
  asm volatile("vle32.v v8,  (%0); add %0, %0, %1" : "+&r"(i) : "r"(lwi));
  asm volatile("vle32.v v10, (%0); add %0, %0, %1" : "+r"(i));
}

// Calculate 4 output matrix rows
void conv2d_vec_4xC_3x3(int32_t *o, int32_t *i, int32_t *f, int32_t c, int32_t C,
                        int32_t F) {

  // Temporary variables
  int32_t t0, t1, t2;

  // Helper variables
  int32_t lwo = C << 2;
  int32_t lwi = (C + F - 1) << 2;
  int32_t lwf = F << 2;
  int32_t *f_;

  // Compute on C elements
  asm volatile("vsetvli zero, %0, e32, m2, ta, ma" ::"r"(c + F - 1));
  // Fetch 4 + F - 1 - 2 rows of the input matrix
  asm volatile("vle32.v v12, (%0); add %0, %0, %1" : "+&r"(i) : "r"(lwi));
  asm volatile("vle32.v v14, (%0); add %0, %0, %1" : "+&r"(i) : "r"(lwi));
  asm volatile("vle32.v v16, (%0); add %0, %0, %1" : "+&r"(i) : "r"(lwi));
  asm volatile("vle32.v v18, (%0); add %0, %0, %1" : "+&r"(i) : "r"(lwi));

  f_ = f;
  asm volatile("lw %1, (%0); add %0, %0, %2" : "+&r"(f_), "=&r"(t0) : "r"(lwf));
  asm volatile("vsetvli zero, %0, e32, m2, ta, ma" ::"r"(c));
  // Compute on C elements
  // Fetch the first column of the filter, and start calculating its
  // contribution on the four output rows (v0, v2, v4, v6)
  asm volatile("lw %1, (%0); add %0, %0, %2" : "+&r"(f_), "=&r"(t1) : "r"(lwf));
  asm volatile("vmacc.vx v0, %0, v8" ::"r"(t0));
  asm volatile("vmacc.vx v2, %0, v10" ::"r"(t0));
  asm volatile("vmacc.vx v4, %0, v12" ::"r"(t0));
  asm volatile("vmacc.vx v6, %0, v14" ::"r"(t0));

  asm volatile("lw %1, (%0);" : "+&r"(f_), "=&r"(t2));
  asm volatile("vmacc.vx v0, %0, v10" ::"r"(t1));
  asm volatile("vmacc.vx v2, %0, v12" ::"r"(t1));
  asm volatile("vmacc.vx v4, %0, v14" ::"r"(t1));
  asm volatile("vmacc.vx v6, %0, v16" ::"r"(t1));

  f_ = f + 1;
  asm volatile("lw %1, (%0); add %0, %0, %2" : "+&r"(f_), "=&r"(t0) : "r"(lwf));
  asm volatile("vmacc.vx v0, %0, v12" ::"r"(t2));
  asm volatile("vmacc.vx v2, %0, v14" ::"r"(t2));
  asm volatile("vslidedown.vi v20, v8,  1");
  asm volatile("vmacc.vx v4, %0, v16" ::"r"(t2));
  asm volatile("vmacc.vx v6, %0, v18" ::"r"(t2));

  // Fetch the middle column of the filter, and start calculating its
  // contributions on the output rows To do so, slide down the input rows by one
  asm volatile("lw %1, (%0); add %0, %0, %2" : "+&r"(f_), "=&r"(t1) : "r"(lwf));
  asm volatile("vslidedown.vi v22, v10, 1");
  asm volatile("vmacc.vx v0, %0, v20" ::"r"(t0));

  asm volatile("lw %1, (%0);" : "+&r"(f_), "=&r"(t2));
  asm volatile("vslidedown.vi v24, v12, 1");
  asm volatile("vmacc.vx v0, %0, v22" ::"r"(t1));
  asm volatile("vmacc.vx v2, %0, v22" ::"r"(t0));

  asm volatile("vslidedown.vi v26, v14, 1");
  asm volatile("vmacc.vx v0, %0, v24" ::"r"(t2));
  asm volatile("vmacc.vx v2, %0, v24" ::"r"(t1));
  asm volatile("vmacc.vx v4, %0, v24" ::"r"(t0));

  asm volatile("vslidedown.vi v28, v16, 1");
  asm volatile("vmacc.vx v2, %0, v26" ::"r"(t2));
  asm volatile("vmacc.vx v4, %0, v26" ::"r"(t1));
  asm volatile("vmacc.vx v6, %0, v26" ::"r"(t0));

  asm volatile("vslidedown.vi v30, v18, 1");
  asm volatile("vmacc.vx v4, %0, v28" ::"r"(t2));
  asm volatile("vmacc.vx v6, %0, v28" ::"r"(t1));

  f_ = f + 2;
  asm volatile("lw %1, (%0); add %0, %0, %2" : "+&r"(f_), "=&r"(t0) : "r"(lwf));
  asm volatile("vslidedown.vi v20, v8,  2");
  asm volatile("vmacc.vx v6, %0, v30" ::"r"(t2));

  // Repeat for the last filter column, and then store the output rows
  asm volatile("lw %1, (%0); add %0, %0, %2" : "+&r"(f_), "=&r"(t1) : "r"(lwf));
  asm volatile("vslidedown.vi v22, v10, 2");
  asm volatile("vmacc.vx v0, %0, v20" ::"r"(t0));

  asm volatile("lw %1, (%0);" : "+&r"(f_), "=&r"(t2));
  asm volatile("vslidedown.vi v24, v12, 2");
  asm volatile("vmacc.vx v0, %0, v22" ::"r"(t1));
  asm volatile("vmacc.vx v2, %0, v22" ::"r"(t0));

  asm volatile("vslidedown.vi v26, v14, 2");
  asm volatile("vmacc.vx v0, %0, v24" ::"r"(t2));
  asm volatile("vse32.v  v0, (%0); add %0, %0, %1" : "+&r"(o) : "r"(lwo));
  asm volatile("vmacc.vx v2, %0, v24" ::"r"(t1));
  asm volatile("vmacc.vx v4, %0, v24" ::"r"(t0));

  asm volatile("vslidedown.vi v28, v16, 2");
  asm volatile("vmacc.vx v2, %0, v26" ::"r"(t2));
  asm volatile("vse32.v  v2, (%0); add %0, %0, %1" : "+&r"(o) : "r"(lwo));
  asm volatile("vmacc.vx v4, %0, v26" ::"r"(t1));
  asm volatile("vmacc.vx v6, %0, v26" ::"r"(t0));

  asm volatile("vslidedown.vi v30, v18, 2");
  asm volatile("vmacc.vx v4, %0, v28" ::"r"(t2));
  asm volatile("vse32.v  v4, (%0); add %0, %0, %1" : "+&r"(o) : "r"(lwo));
  asm volatile("vmacc.vx v6, %0, v28" ::"r"(t1));

  asm volatile("vmacc.vx v6, %0, v30" ::"r"(t2));
  asm volatile("vse32.v  v6, (%0);" : "+r"(o));
}

void conv2d_vec_4xC_slice_move_3x3(int32_t c, int32_t C, int32_t F) {
  // Move C+F-1 elements
  asm volatile("vsetvli zero, %0, e32, m2, ta, ma" ::"r"(c + F - 1));
  // Move the last floor(F/2) + 1 input rows
  asm volatile("vmv.v.v v8, v16");
  asm volatile("vmv.v.v v10, v18");
}
