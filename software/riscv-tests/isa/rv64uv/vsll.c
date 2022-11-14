// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1(void) {
  VSET(16, e8, m2);
  VLOAD_8(v4, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
          0x01, 0x01, 0x01, 0x01, 0x01);
  VLOAD_8(v6, 0, 1, 2, 3, 7, 15, 31, 32, 0, 1, 2, 3, 7, 15, 31, 32);
  asm volatile("vsll.vv v8, v4, v6");
  VCMP_U8(1, v8, 0x01, 0x02, 0x04, 0x08, 0x80, 0x80, 0x80, 0x01, 0x01, 0x02,
          0x04, 0x08, 0x80, 0x80, 0x80, 0x01);

  VSET(16, e16, m2);
  VLOAD_16(v4, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
           0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001);
  VLOAD_16(v6, 0, 1, 2, 3, 7, 15, 31, 32, 0, 1, 2, 3, 7, 15, 31, 32);
  asm volatile("vsll.vv v8, v4, v6");
  VCMP_U16(2, v8, 0x0001, 0x0002, 0x0004, 0x0008, 0x0080, 0x8000, 0x8000,
           0x0001, 0x0001, 0x0002, 0x0004, 0x0008, 0x0080, 0x8000, 0x8000,
           0x0001);

  VSET(16, e32, m2);
  VLOAD_32(v4, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
           0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
           0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
           0x00000001);
  VLOAD_32(v6, 0, 1, 2, 3, 7, 15, 31, 32, 0, 1, 2, 3, 7, 15, 31, 32);
  asm volatile("vsll.vv v8, v4, v6");
  VCMP_U32(3, v8, 0x00000001, 0x00000002, 0x00000004, 0x00000008, 0x00000080,
           0x00008000, 0x80000000, 0x00000001, 0x00000001, 0x00000002,
           0x00000004, 0x00000008, 0x00000080, 0x00008000, 0x80000000,
           0x00000001);

#if ELEN == 64
  VSET(16, e64, m2);
  VLOAD_64(v4, 0x0000000000000001, 0x0000000000000001, 0x0000000000000001,
           0x0000000000000001, 0x0000000000000001, 0x0000000000000001,
           0x0000000000000001, 0x0000000000000001, 0x0000000000000001,
           0x0000000000000001, 0x0000000000000001, 0x0000000000000001,
           0x0000000000000001, 0x0000000000000001, 0x0000000000000001,
           0x0000000000000001);
  VLOAD_64(v6, 0, 1, 2, 3, 7, 15, 31, 32, 0, 1, 2, 3, 7, 15, 31, 32);
  asm volatile("vsll.vv v8, v4, v6");
  VCMP_U64(4, v8, 0x000000000000001, 0x0000000000000002, 0x0000000000000004,
           0x0000000000000008, 0x0000000000000080, 0x0000000000008000,
           0x0000000080000000, 0x0000000100000000, 0x0000000000000001,
           0x0000000000000002, 0x0000000000000004, 0x0000000000000008,
           0x0000000000000080, 0x0000000000008000, 0x0000000080000000,
           0x0000000100000000);
#endif
};

void TEST_CASE2(void) {
  VSET(16, e8, m2);
  VLOAD_8(v4, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
          0x01, 0x01, 0x01, 0x01, 0x01);
  VLOAD_8(v6, 0, 1, 2, 3, 7, 15, 31, 32, 0, 1, 2, 3, 7, 15, 31, 32);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vsll.vv v8, v4, v6, v0.t");
  VCMP_U8(5, v8, 0x00, 0x02, 0x00, 0x08, 0x00, 0x80, 0x00, 0x01, 0x00, 0x02,
          0x00, 0x08, 0x00, 0x80, 0x00, 0x01);

  VSET(16, e16, m2);
  VLOAD_16(v4, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
           0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001);
  VLOAD_16(v6, 0, 1, 2, 3, 7, 15, 31, 32, 0, 1, 2, 3, 7, 15, 31, 32);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vsll.vv v8, v4, v6, v0.t");
  VCMP_U16(6, v8, 0x0000, 0x0002, 0x0000, 0x0008, 0x0000, 0x8000, 0x0000,
           0x0001, 0x0000, 0x0002, 0x0000, 0x0008, 0x0000, 0x8000, 0x0000,
           0x0001);

  VSET(16, e32, m2);
  VLOAD_32(v4, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
           0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
           0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001,
           0x00000001);
  VLOAD_32(v6, 0, 1, 2, 3, 7, 15, 31, 32, 0, 1, 2, 3, 7, 15, 31, 32);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vsll.vv v8, v4, v6, v0.t");
  VCMP_U32(7, v8, 0x00000000, 0x00000002, 0x00000000, 0x00000008, 0x00000000,
           0x00008000, 0x00000000, 0x00000001, 0x00000000, 0x00000002,
           0x00000000, 0x00000008, 0x00000000, 0x00008000, 0x00000000,
           0x00000001);

#if ELEN == 64
  VSET(16, e64, m2);
  VLOAD_64(v4, 0x0000000000000001, 0x0000000000000001, 0x0000000000000001,
           0x0000000000000001, 0x0000000000000001, 0x0000000000000001,
           0x0000000000000001, 0x0000000000000001, 0x0000000000000001,
           0x0000000000000001, 0x0000000000000001, 0x0000000000000001,
           0x0000000000000001, 0x0000000000000001, 0x0000000000000001,
           0x0000000000000001);
  VLOAD_64(v6, 0, 1, 2, 3, 7, 15, 31, 32, 0, 1, 2, 3, 7, 15, 31, 32);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vsll.vv v8, v4, v6, v0.t");
  VCMP_U64(8, v8, 0x000000000000000, 0x0000000000000002, 0x0000000000000000,
           0x0000000000000008, 0x0000000000000000, 0x0000000000008000,
           0x0000000000000000, 0x0000000100000000, 0x0000000000000000,
           0x0000000000000002, 0x0000000000000000, 0x0000000000000008,
           0x0000000000000000, 0x0000000000008000, 0x0000000000000000,
           0x0000000100000000);
#endif
};

void TEST_CASE3(void) {
  const uint64_t scalar = 2;

  VSET(16, e8, m2);
  VLOAD_8(v4, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0xF8, 0xF9, 0xFA,
          0xFB, 0xFC, 0xFD, 0xFE, 0xFF);
  asm volatile("vsll.vx v8, v4, %[A]" ::[A] "r"(scalar));
  VCMP_U8(9, v8, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C, 0x20, 0xE0, 0xE4,
          0xE8, 0xEC, 0xF0, 0xF4, 0xF8, 0xFC);

  VSET(16, e16, m2);
  VLOAD_16(v4, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008,
           0xFFF8, 0xFFF9, 0xFFFA, 0xFFFB, 0xFFFC, 0xFFFD, 0xFFFE, 0x00FF);
  asm volatile("vsll.vx v8, v4, %[A]" ::[A] "r"(scalar));
  VCMP_U16(10, v8, 0x0004, 0x0008, 0x000C, 0x0010, 0x0014, 0x0018, 0x001C,
           0x0020, 0xFFE0, 0xFFE4, 0xFFE8, 0xFFEC, 0xFFF0, 0xFFF4, 0xFFF8,
           0x03FC);

  VSET(16, e32, m2);
  VLOAD_32(v4, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005,
           0x00000006, 0x00000007, 0x00000008, 0xFFFFFFF8, 0xFFFFFFF9,
           0xFFFFFFFA, 0xFFFFFFFB, 0xFFFFFFFC, 0xFFFFFFFD, 0xFFFFFFFE,
           0x000000FF);
  asm volatile("vsll.vx v8, v4, %[A]" ::[A] "r"(scalar));
  VCMP_U32(11, v8, 0x00000004, 0x00000008, 0x0000000C, 0x00000010, 0x00000014,
           0x00000018, 0x0000001C, 0x00000020, 0xFFFFFFE0, 0xFFFFFFE4,
           0xFFFFFFE8, 0xFFFFFFEC, 0xFFFFFFF0, 0xFFFFFFF4, 0xFFFFFFF8,
           0x000003FC);

#if ELEN == 64
  VSET(16, e64, m2);
  VLOAD_64(v4, 0x0000000000000001, 0x0000000000000002, 0x0000000000000003,
           0x0000000000000004, 0x0000000000000005, 0x0000000000000006,
           0x0000000000000007, 0x0000000000000008, 0xFFFFFFFFFFFFFFF8,
           0xFFFFFFFFFFFFFFF9, 0xFFFFFFFFFFFFFFFA, 0xFFFFFFFFFFFFFFFB,
           0xFFFFFFFFFFFFFFFC, 0xFFFFFFFFFFFFFFFD, 0xFFFFFFFFFFFFFFFE,
           0x00000000000000FF);
  asm volatile("vsll.vx v8, v4, %[A]" ::[A] "r"(scalar));
  VCMP_U64(12, v8, 0x0000000000000004, 0x0000000000000008, 0x000000000000000C,
           0x0000000000000010, 0x0000000000000014, 0x0000000000000018,
           0x000000000000001C, 0x0000000000000020, 0xFFFFFFFFFFFFFFE0,
           0xFFFFFFFFFFFFFFE4, 0xFFFFFFFFFFFFFFE8, 0xFFFFFFFFFFFFFFEC,
           0xFFFFFFFFFFFFFFF0, 0xFFFFFFFFFFFFFFF4, 0xFFFFFFFFFFFFFFF8,
           0x00000000000003FC);
#endif
};

void TEST_CASE4(void) {
  const uint64_t scalar = 2;

  VSET(16, e8, m2);
  VLOAD_8(v4, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0xF8, 0xF9, 0xFA,
          0xFB, 0xFC, 0xFD, 0xFE, 0xFF);
  VCLEAR(v8);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vsll.vx v8, v4, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_U8(13, v8, 0x00, 0x08, 0x00, 0x10, 0x00, 0x18, 0x00, 0x20, 0x00, 0xE4,
          0x00, 0xEC, 0x00, 0xF4, 0x00, 0xFC);

  VSET(16, e16, m2);
  VLOAD_16(v4, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008,
           0xFFF8, 0xFFF9, 0xFFFA, 0xFFFB, 0xFFFC, 0xFFFD, 0xFFFE, 0x00FF);
  VCLEAR(v8);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vsll.vx v8, v4, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_U16(14, v8, 0x0000, 0x0008, 0x0000, 0x0010, 0x0000, 0x0018, 0x0000,
           0x0020, 0x0000, 0xFFE4, 0x0000, 0xFFEC, 0x0000, 0xFFF4, 0x0000,
           0x03FC);

  VSET(16, e32, m2);
  VLOAD_32(v4, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005,
           0x00000006, 0x00000007, 0x00000008, 0xFFFFFFF8, 0xFFFFFFF9,
           0xFFFFFFFA, 0xFFFFFFFB, 0xFFFFFFFC, 0xFFFFFFFD, 0xFFFFFFFE,
           0x000000FF);
  VCLEAR(v8);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vsll.vx v8, v4, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_U32(15, v8, 0x00000000, 0x00000008, 0x00000000, 0x00000010, 0x00000000,
           0x00000018, 0x00000000, 0x00000020, 0x00000000, 0xFFFFFFE4,
           0x00000000, 0xFFFFFFEC, 0x00000000, 0xFFFFFFF4, 0x00000000,
           0x000003FC);

#if ELEN == 64
  VSET(16, e64, m2);
  VLOAD_64(v4, 0x0000000000000001, 0x0000000000000002, 0x0000000000000003,
           0x0000000000000004, 0x0000000000000005, 0x0000000000000006,
           0x0000000000000007, 0x0000000000000008, 0xFFFFFFFFFFFFFFF8,
           0xFFFFFFFFFFFFFFF9, 0xFFFFFFFFFFFFFFFA, 0xFFFFFFFFFFFFFFFB,
           0xFFFFFFFFFFFFFFFC, 0xFFFFFFFFFFFFFFFD, 0xFFFFFFFFFFFFFFFE,
           0x00000000000000FF);
  VCLEAR(v8);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vsll.vx v8, v4, %[A], v0.t" ::[A] "r"(scalar));
  VCMP_U64(16, v8, 0x0000000000000000, 0x0000000000000008, 0x0000000000000000,
           0x0000000000000010, 0x0000000000000000, 0x0000000000000018,
           0x0000000000000000, 0x0000000000000020, 0x0000000000000000,
           0xFFFFFFFFFFFFFFE4, 0x0000000000000000, 0xFFFFFFFFFFFFFFEC,
           0x0000000000000000, 0xFFFFFFFFFFFFFFF4, 0x0000000000000000,
           0x00000000000003FC);
#endif
};

void TEST_CASE5(void) {
  VSET(16, e8, m2);
  VLOAD_8(v4, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0xF8, 0xF9, 0xFA,
          0xFB, 0xFC, 0xFD, 0xFE, 0xFF);
  asm volatile("vsll.vi v8, v4, 2");
  VCMP_U8(17, v8, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18, 0x1C, 0x20, 0xE0, 0xE4,
          0xE8, 0xEC, 0xF0, 0xF4, 0xF8, 0xFC);

  VSET(16, e16, m2);
  VLOAD_16(v4, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008,
           0xFFF8, 0xFFF9, 0xFFFA, 0xFFFB, 0xFFFC, 0xFFFD, 0xFFFE, 0x00FF);
  asm volatile("vsll.vi v8, v4, 2");
  VCMP_U16(18, v8, 0x0004, 0x0008, 0x000C, 0x0010, 0x0014, 0x0018, 0x001C,
           0x0020, 0xFFE0, 0xFFE4, 0xFFE8, 0xFFEC, 0xFFF0, 0xFFF4, 0xFFF8,
           0x03FC);

  VSET(16, e32, m2);
  VLOAD_32(v4, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005,
           0x00000006, 0x00000007, 0x00000008, 0xFFFFFFF8, 0xFFFFFFF9,
           0xFFFFFFFA, 0xFFFFFFFB, 0xFFFFFFFC, 0xFFFFFFFD, 0xFFFFFFFE,
           0x000000FF);
  asm volatile("vsll.vi v8, v4, 2");
  VCMP_U32(19, v8, 0x00000004, 0x00000008, 0x0000000C, 0x00000010, 0x00000014,
           0x00000018, 0x0000001C, 0x00000020, 0xFFFFFFE0, 0xFFFFFFE4,
           0xFFFFFFE8, 0xFFFFFFEC, 0xFFFFFFF0, 0xFFFFFFF4, 0xFFFFFFF8,
           0x000003FC);

#if ELEN == 64
  VSET(16, e64, m2);
  VLOAD_64(v4, 0x0000000000000001, 0x0000000000000002, 0x0000000000000003,
           0x0000000000000004, 0x0000000000000005, 0x0000000000000006,
           0x0000000000000007, 0x0000000000000008, 0xFFFFFFFFFFFFFFF8,
           0xFFFFFFFFFFFFFFF9, 0xFFFFFFFFFFFFFFFA, 0xFFFFFFFFFFFFFFFB,
           0xFFFFFFFFFFFFFFFC, 0xFFFFFFFFFFFFFFFD, 0xFFFFFFFFFFFFFFFE,
           0x00000000000000FF);
  asm volatile("vsll.vi v8, v4, 2");
  VCMP_U64(20, v8, 0x0000000000000004, 0x0000000000000008, 0x000000000000000C,
           0x0000000000000010, 0x0000000000000014, 0x0000000000000018,
           0x000000000000001C, 0x0000000000000020, 0xFFFFFFFFFFFFFFE0,
           0xFFFFFFFFFFFFFFE4, 0xFFFFFFFFFFFFFFE8, 0xFFFFFFFFFFFFFFEC,
           0xFFFFFFFFFFFFFFF0, 0xFFFFFFFFFFFFFFF4, 0xFFFFFFFFFFFFFFF8,
           0x00000000000003FC);
#endif
};

void TEST_CASE6(void) {
  VSET(16, e8, m2);
  VLOAD_8(v4, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0xF8, 0xF9, 0xFA,
          0xFB, 0xFC, 0xFD, 0xFE, 0xFF);
  VCLEAR(v8);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vsll.vi v8, v4, 2, v0.t");
  VCMP_U8(21, v8, 0x00, 0x08, 0x00, 0x10, 0x00, 0x18, 0x00, 0x20, 0x00, 0xE4,
          0x00, 0xEC, 0x00, 0xF4, 0x00, 0xFC);

  VSET(16, e16, m2);
  VLOAD_16(v4, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008,
           0xFFF8, 0xFFF9, 0xFFFA, 0xFFFB, 0xFFFC, 0xFFFD, 0xFFFE, 0x00FF);
  VCLEAR(v8);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vsll.vi v8, v4, 2, v0.t");
  VCMP_U16(22, v8, 0x0000, 0x0008, 0x0000, 0x0010, 0x0000, 0x0018, 0x0000,
           0x0020, 0x0000, 0xFFE4, 0x0000, 0xFFEC, 0x0000, 0xFFF4, 0x0000,
           0x03FC);

  VSET(16, e32, m2);
  VLOAD_32(v4, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005,
           0x00000006, 0x00000007, 0x00000008, 0xFFFFFFF8, 0xFFFFFFF9,
           0xFFFFFFFA, 0xFFFFFFFB, 0xFFFFFFFC, 0xFFFFFFFD, 0xFFFFFFFE,
           0x000000FF);
  VCLEAR(v8);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vsll.vi v8, v4, 2, v0.t");
  VCMP_U32(23, v8, 0x00000000, 0x00000008, 0x00000000, 0x00000010, 0x00000000,
           0x00000018, 0x00000000, 0x00000020, 0x00000000, 0xFFFFFFE4,
           0x00000000, 0xFFFFFFEC, 0x00000000, 0xFFFFFFF4, 0x00000000,
           0x000003FC);

#if ELEN == 64
  VSET(16, e64, m2);
  VLOAD_64(v4, 0x0000000000000001, 0x0000000000000002, 0x0000000000000003,
           0x0000000000000004, 0x0000000000000005, 0x0000000000000006,
           0x0000000000000007, 0x0000000000000008, 0xFFFFFFFFFFFFFFF8,
           0xFFFFFFFFFFFFFFF9, 0xFFFFFFFFFFFFFFFA, 0xFFFFFFFFFFFFFFFB,
           0xFFFFFFFFFFFFFFFC, 0xFFFFFFFFFFFFFFFD, 0xFFFFFFFFFFFFFFFE,
           0x00000000000000FF);
  VCLEAR(v8);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vsll.vi v8, v4, 2, v0.t");
  VCMP_U64(24, v8, 0x0000000000000000, 0x0000000000000008, 0x0000000000000000,
           0x0000000000000010, 0x0000000000000000, 0x0000000000000018,
           0x0000000000000000, 0x0000000000000020, 0x0000000000000000,
           0xFFFFFFFFFFFFFFE4, 0x0000000000000000, 0xFFFFFFFFFFFFFFEC,
           0x0000000000000000, 0xFFFFFFFFFFFFFFF4, 0x0000000000000000,
           0x00000000000003FC);
#endif
};

int main(void) {
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  //TEST_CASE2();
  TEST_CASE3();
  //TEST_CASE4();
  TEST_CASE5();
  //TEST_CASE6();

  EXIT_CHECK();
}
