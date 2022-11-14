// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1() {
  VSET(4, e8, m2);
  VLOAD_U8(v4, 0xff, 0x00, 0xf0, 0x0f);
  VLOAD_U8(v6, 1, 2, 3, 4);
  __asm__ volatile("vssrl.vv v2, v4, v6");
  VEC_CMP_U8(1, v2, 0x80, 0, 0x1e, 0x01);
}

void TEST_CASE2() {
  VSET(4, e8, m2);
  VLOAD_U8(v4, 0xff, 0x00, 0xf0, 0x0f);
  VLOAD_U8(v6, 1, 2, 3, 4);
  VLOAD_U8(v0, 5, 0, 0, 0);
  CLEAR(v2);
  __asm__ volatile("vssrl.vv v2, v4, v6, v0.t");
  VEC_CMP_U8(2, v2, 0x80, 0, 0x1e, 0);
}

void TEST_CASE3() {
  VSET(4, e8, m2);
  VLOAD_U8(v4, 0xff, 0x00, 0xf0, 0x0f);
  __asm__ volatile("vssrl.vi v2, v4, 5");
  VEC_CMP_U8(3, v2, 8, 0, 8, 0);
}

void TEST_CASE4() {
  VSET(4, e8, m2);
  VLOAD_U8(v4, 0xff, 0x00, 0xf0, 0x0f);
  VLOAD_U8(v0, 5, 0, 0, 0);
  CLEAR(v2);
  __asm__ volatile("vssrl.vi v2, v4, 5, v0.t");
  VEC_CMP_U8(4, v2, 8, 0, 8, 0);
}

void TEST_CASE5() {
  VSET(4, e8, m2);
  VLOAD_U8(v4, 0xff, 0x00, 0xf0, 0x0f);
  uint64_t scalar = 5;
  __asm__ volatile("vssrl.vx v2, v4, %[A]" ::[A] "r"(scalar));
  VEC_CMP_U8(5, v2, 8, 0, 8, 0);
}

void TEST_CASE6() {
  VSET(4, e8, m2);
  VLOAD_U8(v4, 0xff, 0x00, 0xf0, 0x0f);
  uint64_t scalar = 5;
  VLOAD_U8(v0, 5, 0, 0, 0);
  CLEAR(v2);
  __asm__ volatile("vssrl.vx v2, v4, %[A], v0.t" ::[A] "r"(scalar));
  VEC_CMP_U8(6, v2, 8, 0, 8, 0);
}

int main(void) {
  INIT_CHECK();
  enable_vec();
  enable_fp();
  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();
  TEST_CASE5();
  TEST_CASE6();
  EXIT_CHECK();
}
