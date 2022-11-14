// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"

void TEST_CASE1() {
  VSET(16, e16, m2);
  VLOAD_16(v6, 0x460f, 0x1c3e, 0xa322, 0xa7de, 0xd343, 0xa068, 0xf7a8, 0x3a62,
           0x3f7f, 0x0ae0, 0x0e38, 0x57fe, 0xdc97, 0x61e5, 0xe3f4, 0xb1bd);
  VSET(16, e8, m2);
  VLOAD_8(v4, 0x19, 0x87, 0x46, 0xf5, 0x3d, 0x66, 0xd7, 0xcf, 0x9f, 0x73, 0x35,
          0x92, 0xb4, 0xc4, 0xdb, 0x1a);
  VLOAD_8(v8, 0xd0, 0x62, 0xb7, 0xd9, 0x39, 0xdf, 0x3e, 0x3d, 0xa2, 0xbb, 0xf1,
          0xba, 0xe2, 0xd7, 0x51, 0x5d);
  asm volatile("vwmacc.vv v6, v4, v8");
  VSET(16, e16, m2);
  VCMP_I16(1, v6, 0x415f, 0xedec, 0x8f2c, 0xa98b, 0xe0d8, 0x9342, 0xedba,
           0x2eb5, 0x631d, 0xebe1, 0x0b1d, 0x7612, 0xe57f, 0x6b81, 0xd83f,
           0xbb2f);

  VSET(16, e32, m2);
  VLOAD_32(v6, 0x1d5e4130, 0x9a736c84, 0xe2c407c1, 0x62baf7c8, 0xc157159f,
           0x6cea275d, 0x0c385a3e, 0xf8f640d1, 0x484e89df, 0xb7720e91,
           0x17a7a4cf, 0x9cba6dac, 0x177e67d2, 0x491950da, 0x5b48691f,
           0x03289e10);
  VSET(16, e16, m2);
  VLOAD_16(v4, 0x6930, 0x239f, 0x2214, 0x555e, 0x9868, 0x02e7, 0x784f, 0x8c32,
           0xe8d1, 0xe941, 0xaaaf, 0x4833, 0xc773, 0x6156, 0xdad9, 0x02a5);
  VLOAD_16(v8, 0xe798, 0x1fe5, 0xca4f, 0xb93c, 0xafe4, 0x5641, 0x4848, 0x82a3,
           0x6065, 0x1385, 0x5a53, 0x3318, 0xd488, 0xb1cf, 0x5142, 0x0277);
  asm volatile("vwmacc.vv v6, v4, v8");
  VSET(16, e32, m2);
  VCMP_I32(2, v6, 0x135705b0, 0x9ee38abf, 0xdb9e53ed, 0x4b21e7d0, 0xe1c1ea3f,
           0x6de47e04, 0x2e306876, 0x31abe8a7, 0x3f93c454, 0xb5b61056,
           0xf98d818c, 0xab235b74, 0x211898ea, 0x2b5e7b64, 0x4f7d7e11,
           0x032f22c3);

  VSET(16, e64, m2);
  VLOAD_64(v6, 0x37abc1433be408eb, 0xb3af312be2d38e09, 0x3a99dc46913b03d2,
           0xb2cca27c11815d4d, 0x456749124aaf479a, 0xc11d5ef0eaa5ee72,
           0x1e6a624541e03978, 0x36ce0e391abb8a91, 0x552a61c1f7116723,
           0x621ae1e17b7074c2, 0x4c3f1888b5df72b9, 0xde3961024df8c2cf,
           0x37cd59f214853904, 0xe76372440eb37d3d, 0x0f0ff8cee2000142,
           0x061e905b827b9818);
  VSET(16, e32, m2);
  VLOAD_32(v4, 0xb5c0475b, 0xda0c4af7, 0xa939123e, 0xb7261aa3, 0x510b75c1,
           0x7d5e66d9, 0x3b263bb7, 0xc35c07a0, 0x03b0bb28, 0xba423d88,
           0xb4ddeabb, 0x97b1e0ce, 0x01d07d01, 0x16174f78, 0x40c6b24f,
           0x7fab39a9);
  VLOAD_32(v8, 0x376ce1ba, 0x9cc53665, 0x9292669b, 0xcaec0663, 0x174f60ba,
           0x5fc79836, 0x6597295d, 0x737b18f1, 0x8cb86656, 0x044f320e,
           0x2a881643, 0x2e1a8f59, 0xfdc331d1, 0xca03d155, 0x0a51ebfe,
           0xcac2c353);
  asm volatile("vwmacc.vv v6, v4, v8");
  VSET(16, e64, m2);
  VCMP_I64(3, v6, 0x27987c3defb2dc09, 0xc2652748b5903b7c, 0x5fb1b6348769c35c,
           0xc1e76e2cf6217c56, 0x4cc871cf26ba35d4, 0xf0052607e34f7838,
           0x35e364f04a4539f3, 0x1b733cf52ef5b831, 0x5380f57403c23693,
           0x60ee57a5b80c6232, 0x3fc390677f77f3aa, 0xcb708510404efc6d,
           0x37c94aa4ac6b77d5, 0xe2badbd70ab9d815, 0x11ac765b0dd270a4,
           0xeb91935c5ffd04e3);
}

void TEST_CASE2() {
  VSET(16, e16, m2);
  VLOAD_16(v6, 0x460f, 0x1c3e, 0xa322, 0xa7de, 0xd343, 0xa068, 0xf7a8, 0x3a62,
           0x3f7f, 0x0ae0, 0x0e38, 0x57fe, 0xdc97, 0x61e5, 0xe3f4, 0xb1bd);
  VSET(16, e8, m2);
  VLOAD_8(v4, 0x19, 0x87, 0x46, 0xf5, 0x3d, 0x66, 0xd7, 0xcf, 0x9f, 0x73, 0x35,
          0x92, 0xb4, 0xc4, 0xdb, 0x1a);
  VLOAD_8(v8, 0xd0, 0x62, 0xb7, 0xd9, 0x39, 0xdf, 0x3e, 0x3d, 0xa2, 0xbb, 0xf1,
          0xba, 0xe2, 0xd7, 0x51, 0x5d);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vwmacc.vv v6, v4, v8, v0.t");
  VSET(16, e16, m2);
  VCMP_I16(4, v6, 0x460f, 0xedec, 0xa322, 0xa98b, 0xd343, 0x9342, 0xf7a8,
           0x2eb5, 0x3f7f, 0xebe1, 0x0e38, 0x7612, 0xdc97, 0x6b81, 0xe3f4,
           0xbb2f);

  VSET(16, e32, m2);
  VLOAD_32(v6, 0x1d5e4130, 0x9a736c84, 0xe2c407c1, 0x62baf7c8, 0xc157159f,
           0x6cea275d, 0x0c385a3e, 0xf8f640d1, 0x484e89df, 0xb7720e91,
           0x17a7a4cf, 0x9cba6dac, 0x177e67d2, 0x491950da, 0x5b48691f,
           0x03289e10);
  VSET(16, e16, m2);
  VLOAD_16(v4, 0x6930, 0x239f, 0x2214, 0x555e, 0x9868, 0x02e7, 0x784f, 0x8c32,
           0xe8d1, 0xe941, 0xaaaf, 0x4833, 0xc773, 0x6156, 0xdad9, 0x02a5);
  VLOAD_16(v8, 0xe798, 0x1fe5, 0xca4f, 0xb93c, 0xafe4, 0x5641, 0x4848, 0x82a3,
           0x6065, 0x1385, 0x5a53, 0x3318, 0xd488, 0xb1cf, 0x5142, 0x0277);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vwmacc.vv v6, v4, v8, v0.t");
  VSET(16, e32, m2);
  VCMP_I32(5, v6, 0x1d5e4130, 0x9ee38abf, 0xe2c407c1, 0x4b21e7d0, 0xc157159f,
           0x6de47e04, 0x0c385a3e, 0x31abe8a7, 0x484e89df, 0xb5b61056,
           0x17a7a4cf, 0xab235b74, 0x177e67d2, 0x2b5e7b64, 0x5b48691f,
           0x032f22c3);

  VSET(16, e64, m2);
  VLOAD_64(v6, 0x37abc1433be408eb, 0xb3af312be2d38e09, 0x3a99dc46913b03d2,
           0xb2cca27c11815d4d, 0x456749124aaf479a, 0xc11d5ef0eaa5ee72,
           0x1e6a624541e03978, 0x36ce0e391abb8a91, 0x552a61c1f7116723,
           0x621ae1e17b7074c2, 0x4c3f1888b5df72b9, 0xde3961024df8c2cf,
           0x37cd59f214853904, 0xe76372440eb37d3d, 0x0f0ff8cee2000142,
           0x061e905b827b9818);
  VSET(16, e32, m2);
  VLOAD_32(v4, 0xb5c0475b, 0xda0c4af7, 0xa939123e, 0xb7261aa3, 0x510b75c1,
           0x7d5e66d9, 0x3b263bb7, 0xc35c07a0, 0x03b0bb28, 0xba423d88,
           0xb4ddeabb, 0x97b1e0ce, 0x01d07d01, 0x16174f78, 0x40c6b24f,
           0x7fab39a9);
  VLOAD_32(v8, 0x376ce1ba, 0x9cc53665, 0x9292669b, 0xcaec0663, 0x174f60ba,
           0x5fc79836, 0x6597295d, 0x737b18f1, 0x8cb86656, 0x044f320e,
           0x2a881643, 0x2e1a8f59, 0xfdc331d1, 0xca03d155, 0x0a51ebfe,
           0xcac2c353);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vwmacc.vv v6, v4, v8, v0.t");
  VSET(16, e64, m2);
  VCMP_I64(6, v6, 0x37abc1433be408eb, 0xc2652748b5903b7c, 0x3a99dc46913b03d2,
           0xc1e76e2cf6217c56, 0x456749124aaf479a, 0xf0052607e34f7838,
           0x1e6a624541e03978, 0x1b733cf52ef5b831, 0x552a61c1f7116723,
           0x60ee57a5b80c6232, 0x4c3f1888b5df72b9, 0xcb708510404efc6d,
           0x37cd59f214853904, 0xe2badbd70ab9d815, 0x0f0ff8cee2000142,
           0xeb91935c5ffd04e3);
}

void TEST_CASE3() {
  VSET(16, e16, m2);
  VLOAD_16(v6, 0x17db, 0x9069, 0x8e1f, 0x3584, 0xbb3d, 0x39b2, 0x82cf, 0x015b,
           0xd556, 0xd603, 0x85d1, 0x66a6, 0x4e3e, 0xb965, 0xaa7b, 0x9d27);
  VSET(16, e8, m2);
  int64_t scalar = 5;
  VLOAD_8(v8, 0x50, 0x56, 0x94, 0x1e, 0x09, 0x8f, 0xe1, 0x9e, 0x86, 0x97, 0x71,
          0x5e, 0x55, 0x09, 0xdd, 0x23);
  asm volatile("vwmacc.vx v6, %[A], v8" ::[A] "r"(scalar));
  VSET(16, e16, m2);
  VCMP_I16(7, v6, 0x196b, 0x9217, 0x8c03, 0x361a, 0xbb6a, 0x377d, 0x8234,
           0xff71, 0xd2f4, 0xd3f6, 0x8806, 0x687c, 0x4fe7, 0xb992, 0xa9cc,
           0x9dd6);

  VSET(16, e32, m2);
  VLOAD_32(v6, 0xc9b9ade8, 0xfc9c14a8, 0xe1ace4f7, 0x43ea8b48, 0x3ab3025c,
           0xe545695b, 0x538304ce, 0xf430c148, 0xd126fac1, 0xbf51d251,
           0x85ebc0a4, 0x2167faaf, 0x0a2e18cc, 0x0ae19395, 0x03cc9899,
           0x05524f83);
  VSET(16, e16, m2);
  scalar = -5383;
  VLOAD_16(v8, 0x4324, 0xd762, 0xc34b, 0x6f67, 0x5134, 0x4d9d, 0xfa05, 0xacb7,
           0xb7d2, 0xb079, 0x5bb2, 0x7949, 0x51df, 0xbadd, 0xee81, 0x3b49);
  asm volatile("vwmacc.vx v6, %[A], v8" ::[A] "r"(scalar));
  VSET(16, e32, m2);
  VCMP_I32(8, v6, 0xc435e3ec, 0xfff226fa, 0xe6a966ea, 0x3ac40c77, 0x340785f0,
           0xdee56910, 0x5400c5ab, 0xfb080547, 0xd714ba03, 0xc5da1202,
           0x7e63a4c6, 0x1771acb0, 0x037490b3, 0x108f568a, 0x053c7e12,
           0x0073b384);

  VSET(16, e64, m2);
  VLOAD_64(v6, 0xc3afd90f697a742a, 0x585e39767c2959ab, 0xfd5f5c31e16d95ba,
           0x2c39235d58ff74a1, 0x4a793d202092aeac, 0x6d31f07b7bdfb6ea,
           0x902b8e28be41b10d, 0x89114b9383c4b511, 0x1f9a7e912f5a51f0,
           0x5494b9380432890c, 0xfd260f5f1fc1eb45, 0x80381e728c1baa95,
           0xa6be6d48744a823b, 0xd37b8ae766a82bf8, 0x7992c128f1c1f6ab,
           0xbeca06f79871e7e8);
  VSET(16, e32, m2);
  scalar = 6474219;
  VLOAD_32(v8, 0x56545434, 0x99cd1438, 0xa1d42f8a, 0x3500b207, 0x642cd563,
           0x7405746d, 0xe92c3246, 0xdab496dc, 0xcbe26107, 0x6bb989c7,
           0xc8542e0c, 0x5849a179, 0x04aac7de, 0x7b5ce579, 0x0ce6e7ea,
           0x77402b10);
  asm volatile("vwmacc.vx v6, %[A], v8" ::[A] "r"(scalar));
  VSET(16, e64, m2);
  VCMP_I64(9, v6, 0xc3d1296f1ae893e6, 0x5836c95c6dbae113, 0xfd3b05253b5c9368,
           0x2c4d976fb318600e, 0x4a9fe54cf92b4b8d, 0x6d5eb614d7052bf9,
           0x9022bf12bc18cd4f, 0x8902e74ad235ed05, 0x1f86621f3b05e25d,
           0x54be4b3652df41b9, 0xfd1093afbdc79c49, 0x805a304537cce5a8,
           0xa6c03a5756f94905, 0xd3ab25c46d6cd30b, 0x7997bbbadd639479,
           0xbef80b96ee48ff98);
}

void TEST_CASE4() {
  VSET(16, e16, m2);
  VLOAD_16(v6, 0x17db, 0x9069, 0x8e1f, 0x3584, 0xbb3d, 0x39b2, 0x82cf, 0x015b,
           0xd556, 0xd603, 0x85d1, 0x66a6, 0x4e3e, 0xb965, 0xaa7b, 0x9d27);
  VSET(16, e8, m2);
  int64_t scalar = 5;
  VLOAD_8(v8, 0x50, 0x56, 0x94, 0x1e, 0x09, 0x8f, 0xe1, 0x9e, 0x86, 0x97, 0x71,
          0x5e, 0x55, 0x09, 0xdd, 0x23);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vwmacc.vx v6, %[A], v8, v0.t" ::[A] "r"(scalar));
  VSET(16, e16, m2);
  VCMP_I16(10, v6, 0x17db, 0x9217, 0x8e1f, 0x361a, 0xbb3d, 0x377d, 0x82cf,
           0xff71, 0xd556, 0xd3f6, 0x85d1, 0x687c, 0x4e3e, 0xb992, 0xaa7b,
           0x9dd6);

  VSET(16, e32, m2);
  VLOAD_32(v6, 0xc9b9ade8, 0xfc9c14a8, 0xe1ace4f7, 0x43ea8b48, 0x3ab3025c,
           0xe545695b, 0x538304ce, 0xf430c148, 0xd126fac1, 0xbf51d251,
           0x85ebc0a4, 0x2167faaf, 0x0a2e18cc, 0x0ae19395, 0x03cc9899,
           0x05524f83);
  VSET(16, e16, m2);
  scalar = -5383;
  VLOAD_16(v8, 0x4324, 0xd762, 0xc34b, 0x6f67, 0x5134, 0x4d9d, 0xfa05, 0xacb7,
           0xb7d2, 0xb079, 0x5bb2, 0x7949, 0x51df, 0xbadd, 0xee81, 0x3b49);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vwmacc.vx v6, %[A], v8, v0.t" ::[A] "r"(scalar));
  VSET(16, e32, m2);
  VCMP_I32(11, v6, 0xc9b9ade8, 0xfff226fa, 0xe1ace4f7, 0x3ac40c77, 0x3ab3025c,
           0xdee56910, 0x538304ce, 0xfb080547, 0xd126fac1, 0xc5da1202,
           0x85ebc0a4, 0x1771acb0, 0x0a2e18cc, 0x108f568a, 0x03cc9899,
           0x0073b384);

  VSET(16, e64, m2);
  VLOAD_64(v6, 0xc3afd90f697a742a, 0x585e39767c2959ab, 0xfd5f5c31e16d95ba,
           0x2c39235d58ff74a1, 0x4a793d202092aeac, 0x6d31f07b7bdfb6ea,
           0x902b8e28be41b10d, 0x89114b9383c4b511, 0x1f9a7e912f5a51f0,
           0x5494b9380432890c, 0xfd260f5f1fc1eb45, 0x80381e728c1baa95,
           0xa6be6d48744a823b, 0xd37b8ae766a82bf8, 0x7992c128f1c1f6ab,
           0xbeca06f79871e7e8);
  VSET(16, e32, m2);
  scalar = 6474219;
  VLOAD_32(v8, 0x56545434, 0x99cd1438, 0xa1d42f8a, 0x3500b207, 0x642cd563,
           0x7405746d, 0xe92c3246, 0xdab496dc, 0xcbe26107, 0x6bb989c7,
           0xc8542e0c, 0x5849a179, 0x04aac7de, 0x7b5ce579, 0x0ce6e7ea,
           0x77402b10);
  VLOAD_8(v0, 0xAA, 0xAA);
  asm volatile("vwmacc.vx v6, %[A], v8, v0.t" ::[A] "r"(scalar));
  VSET(16, e64, m2);
  VCMP_I64(12, v6, 0xc3afd90f697a742a, 0x5836c95c6dbae113, 0xfd5f5c31e16d95ba,
           0x2c4d976fb318600e, 0x4a793d202092aeac, 0x6d5eb614d7052bf9,
           0x902b8e28be41b10d, 0x8902e74ad235ed05, 0x1f9a7e912f5a51f0,
           0x54be4b3652df41b9, 0xfd260f5f1fc1eb45, 0x805a304537cce5a8,
           0xa6be6d48744a823b, 0xd3ab25c46d6cd30b, 0x7992c128f1c1f6ab,
           0xbef80b96ee48ff98);
}

int main(void) {
  INIT_CHECK();
  enable_vec();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();

  EXIT_CHECK();
}
