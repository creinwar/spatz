// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1(void) {
  VSET(16, e8, m2);
  VLOAD_8(v4, 0x37, 0x4e, 0x9a, 0x08, 0x12, 0xfd, 0xa4, 0x21, 0x44, 0x58, 0x5a,
          0xa9, 0x1d, 0x5e, 0xd4, 0x8e);
  VLOAD_8(v8, 0x60, 0x5b, 0x0e, 0x78, 0x67, 0xf4, 0xd3, 0x0f, 0x75, 0x34, 0xc3,
          0xb1, 0x62, 0x42, 0xa9, 0x75);
  asm volatile("vwmulsu.vv v6, v4, v8");
  VSET(16, e16, m2);
  VCMP_I16(1, v6, 0x14a0, 0x1bba, 0xfa6c, 0x03c0, 0x073e, 0xfd24, 0xb42c,
           0x01ef, 0x1f14, 0x11e0, 0x448e, 0xc3d9, 0x0b1a, 0x183c, 0xe2f4,
           0xcbe6);

  VSET(16, e16, m2);
  VLOAD_16(v4, 0xba33, 0x3a22, 0x9f52, 0x0c6a, 0xcb67, 0x790c, 0x1a85, 0x958e,
           0xe967, 0x52b6, 0xa453, 0xe306, 0x3c91, 0x0309, 0xcbad, 0x9b78);
  VLOAD_16(v8, 0x84ef, 0xf522, 0x6224, 0x6e02, 0xeedb, 0x5a1f, 0x98d7, 0xa498,
           0x7a66, 0xdc69, 0xd88b, 0xa611, 0x5a08, 0x6836, 0x9130, 0x85be);
  asm volatile("vwmulsu.vv v6, v4, v8");
  VSET(16, e32, m2);
  VCMP_I32(2, v6, 0xdbc1219d, 0x37aa4284, 0xdaefcb88, 0x0555a4d4, 0xceecc31d,
           0x2a9ce074, 0x0fd53db3, 0xbb8fc450, 0xf532150a, 0x473654a6,
           0xb2744111, 0xed33f766, 0x154cde88, 0x013c4be6, 0xe2532d70,
           0xcb7abb10);

  VSET(16, e32, m2);
  VLOAD_32(v4, 0x8bc45f0a, 0x8a60bc63, 0xf3fcddb9, 0xa810b1c8, 0x8cb59934,
           0x8d3334b0, 0x4387cb58, 0xc59d7a46, 0x939dd006, 0xfbd1dfc1,
           0x75307321, 0xb46b5a27, 0xfd2fbdda, 0xec141137, 0x3a1bc8a7,
           0xf0b1eb21);
  VLOAD_32(v8, 0xe193ae9a, 0x57eccb97, 0x41d9eeff, 0xe8d58ddd, 0x2057ccc2,
           0x3122b84c, 0x003bb317, 0xcdfc6918, 0xb5883636, 0x52788c1f,
           0xab90d0a1, 0x6d890387, 0xf9bf35e7, 0xf88259a4, 0x79d9e6f0,
           0x8203a804);
  asm volatile("vwmulsu.vv v6, v4, v8");
  VSET(16, e64, m2);
  VCMP_I64(3, v6, 0x99948a03e977f804, 0xd79a13a8a4b59f65, 0xfce8fa6d09d3d947,
           0xb005c64673bca1a8, 0xf16f28a6e85f8968, 0xe9f73b3d68722440,
           0x000fbf89e1a9cce8, 0xd10589f688d22c90, 0xb324e8f72e5b2544,
           0xfea741c2f93fa45f, 0x4e89a7a8de9337c1, 0xdfa941cb4089ff91,
           0xfd4155b0080871b6, 0xeca94be43cc5263c, 0x1ba897cf74e12690,
           0xf83a217108785484);
};

void TEST_CASE2(void) {
  VSET(16, e8, m2);
  VLOAD_8(v4, 0x37, 0x4e, 0x9a, 0x08, 0x12, 0xfd, 0xa4, 0x21, 0x44, 0x58, 0x5a,
          0xa9, 0x1d, 0x5e, 0xd4, 0x8e);
  VLOAD_8(v8, 0x60, 0x5b, 0x0e, 0x78, 0x67, 0xf4, 0xd3, 0x0f, 0x75, 0x34, 0xc3,
          0xb1, 0x62, 0x42, 0xa9, 0x75);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmulsu.vv v6, v4, v8, v0.t");
  VSET(16, e16, m2);
  VCMP_I16(4, v6, 0, 0x1bba, 0, 0x03c0, 0, 0xfd24, 0, 0x01ef, 0, 0x11e0, 0,
           0xc3d9, 0, 0x183c, 0, 0xcbe6);

  VSET(16, e16, m2);
  VLOAD_16(v4, 0xba33, 0x3a22, 0x9f52, 0x0c6a, 0xcb67, 0x790c, 0x1a85, 0x958e,
           0xe967, 0x52b6, 0xa453, 0xe306, 0x3c91, 0x0309, 0xcbad, 0x9b78);
  VLOAD_16(v8, 0x84ef, 0xf522, 0x6224, 0x6e02, 0xeedb, 0x5a1f, 0x98d7, 0xa498,
           0x7a66, 0xdc69, 0xd88b, 0xa611, 0x5a08, 0x6836, 0x9130, 0x85be);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmulsu.vv v6, v4, v8, v0.t");
  VSET(16, e32, m2);
  VCMP_I32(5, v6, 0, 0x37aa4284, 0, 0x0555a4d4, 0, 0x2a9ce074, 0, 0xbb8fc450, 0,
           0x473654a6, 0, 0xed33f766, 0, 0x013c4be6, 0, 0xcb7abb10);

  VSET(16, e32, m2);
  VLOAD_32(v4, 0x8bc45f0a, 0x8a60bc63, 0xf3fcddb9, 0xa810b1c8, 0x8cb59934,
           0x8d3334b0, 0x4387cb58, 0xc59d7a46, 0x939dd006, 0xfbd1dfc1,
           0x75307321, 0xb46b5a27, 0xfd2fbdda, 0xec141137, 0x3a1bc8a7,
           0xf0b1eb21);
  VLOAD_32(v8, 0xe193ae9a, 0x57eccb97, 0x41d9eeff, 0xe8d58ddd, 0x2057ccc2,
           0x3122b84c, 0x003bb317, 0xcdfc6918, 0xb5883636, 0x52788c1f,
           0xab90d0a1, 0x6d890387, 0xf9bf35e7, 0xf88259a4, 0x79d9e6f0,
           0x8203a804);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmulsu.vv v6, v4, v8, v0.t");
  VSET(16, e64, m2);
  VCMP_I64(6, v6, 0, 0xd79a13a8a4b59f65, 0, 0xb005c64673bca1a8, 0,
           0xe9f73b3d68722440, 0, 0xd10589f688d22c90, 0, 0xfea741c2f93fa45f, 0,
           0xdfa941cb4089ff91, 0, 0xeca94be43cc5263c, 0, 0xf83a217108785484);
};

void TEST_CASE3(void) {
  VSET(16, e8, m2);
  VLOAD_8(v4, 0x16, 0x39, 0x0d, 0xcb, 0x02, 0x2b, 0xcd, 0x30, 0xec, 0x03, 0x18,
          0x78, 0xec, 0xba, 0xf8, 0x49);
  uint64_t scalar = 5;
  asm volatile("vwmulsu.vx v6, v4, %[A]" ::[A] "r"(scalar));
  VSET(16, e16, m2);
  VCMP_I16(7, v6, 0x006e, 0x011d, 0x0041, 0xfef7, 0x000a, 0x00d7, 0xff01,
           0x00f0, 0xff9c, 0x000f, 0x0078, 0x0258, 0xff9c, 0xfea2, 0xffd8,
           0x016d);

  VSET(16, e16, m2);
  VLOAD_16(v4, 0x602f, 0x1b08, 0xfdd6, 0x7e53, 0x59f7, 0x70f1, 0x8a33, 0x5d93,
           0x02a3, 0x9f70, 0x3919, 0x8f2b, 0xc9d3, 0x1b65, 0x15bd, 0xf8be);
  scalar = 5383;
  asm volatile("vwmulsu.vx v6, v4, %[A]" ::[A] "r"(scalar));
  VSET(16, e32, m2);
  VCMP_I32(8, v6, 0x07e67c49, 0x02386538, 0xffd27eda, 0x0a604345, 0x0763b8c1,
           0x0946db97, 0xf652f665, 0x07af9e05, 0x00377175, 0xf8118c10,
           0x04b09caf, 0xf6bb712d, 0xfb8cd3c5, 0x024008c3, 0x01c9192b,
           0xff676332);

  VSET(16, e32, m2);
  VLOAD_32(v4, 0x77036e08, 0xeb7bd8dc, 0x9c0d7f6a, 0x19d320f6, 0xb0c0d792,
           0x3f02203c, 0xf72a9ea9, 0x392f2986, 0x85b78fe8, 0xdc6a281b,
           0x146ffa52, 0x61f96c3c, 0x876cda10, 0x24d22032, 0xb6ffba3d,
           0xbbd29543);
  scalar = 6474219;
  asm volatile("vwmulsu.vx v6, v4, %[A]" ::[A] "r"(scalar));
  VSET(16, e64, m2);
  VCMP_I64(9, v6, 0x002ded2f109a4958, 0xfff8153a6c2ccdf4, 0xffd96e55a002304e,
           0x0009f73117dc67d2, 0xffe16b51302b8506, 0x00185082d93ab314,
           0xfffc975917645623, 0x001611286b315402, 0xffd0cfd1f64e41f8,
           0xfff24492094603c9, 0x0007e2fc81b92b46, 0x0025cec234e97714,
           0xffd178914242bcb0, 0x000e357b1b4ecfe6, 0xffe3d4511153daff,
           0xffe5b0d6e5269f81);
};

void TEST_CASE4(void) {
  VSET(16, e8, m2);
  VLOAD_8(v4, 0x16, 0x39, 0x0d, 0xcb, 0x02, 0x2b, 0xcd, 0x30, 0xec, 0x03, 0x18,
          0x78, 0xec, 0xba, 0xf8, 0x49);
  uint64_t scalar = 5;
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmulsu.vx v6, v4, %[A], v0.t" ::[A] "r"(scalar));
  VSET(16, e16, m2);
  VCMP_I16(10, v6, 0, 0x011d, 0, 0xfef7, 0, 0x00d7, 0, 0x00f0, 0, 0x000f, 0,
           0x0258, 0, 0xfea2, 0, 0x016d);

  VSET(16, e16, m2);
  VLOAD_16(v4, 0x602f, 0x1b08, 0xfdd6, 0x7e53, 0x59f7, 0x70f1, 0x8a33, 0x5d93,
           0x02a3, 0x9f70, 0x3919, 0x8f2b, 0xc9d3, 0x1b65, 0x15bd, 0xf8be);
  scalar = 5383;
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmulsu.vx v6, v4, %[A], v0.t" ::[A] "r"(scalar));
  VSET(16, e32, m2);
  VCMP_I32(11, v6, 0, 0x02386538, 0, 0x0a604345, 0, 0x0946db97, 0, 0x07af9e05,
           0, 0xf8118c10, 0, 0xf6bb712d, 0, 0x024008c3, 0, 0xff676332);

  VSET(16, e32, m2);
  VLOAD_32(v4, 0x77036e08, 0xeb7bd8dc, 0x9c0d7f6a, 0x19d320f6, 0xb0c0d792,
           0x3f02203c, 0xf72a9ea9, 0x392f2986, 0x85b78fe8, 0xdc6a281b,
           0x146ffa52, 0x61f96c3c, 0x876cda10, 0x24d22032, 0xb6ffba3d,
           0xbbd29543);
  scalar = 6474219;
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v6);
  asm volatile("vwmulsu.vx v6, v4, %[A], v0.t" ::[A] "r"(scalar));
  VSET(16, e64, m2);
  VCMP_I64(12, v6, 0, 0xfff8153a6c2ccdf4, 0, 0x0009f73117dc67d2, 0,
           0x00185082d93ab314, 0, 0x001611286b315402, 0, 0xfff24492094603c9, 0,
           0x0025cec234e97714, 0, 0x000e357b1b4ecfe6, 0, 0xffe5b0d6e5269f81);
};

int main(void) {
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();

  EXIT_CHECK();
}
