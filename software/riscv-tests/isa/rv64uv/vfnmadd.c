// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matteo Perotti <mperotti@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "float_macros.h"
#include "vector_macros.h"

// Simple random test with similar values
void TEST_CASE1(void) {
  VSET(16, e16, m2);
  //              -0.7461,  0.0514, -0.3071, -0.4934, -0.5220, -0.7983,  0.4907,
  //              -0.9028,  0.1752,  0.0676,  0.1040,  0.4526,  0.3525, -0.2686,
  //              0.3540, -0.0847
  VLOAD_16(v4, 0xb9f8, 0x2a94, 0xb4ea, 0xb7e5, 0xb82d, 0xba63, 0x37da, 0xbb39,
           0x319b, 0x2c54, 0x2ea8, 0x373e, 0x35a4, 0xb44c, 0x35aa, 0xad6c);
  //               0.1573, -0.7700,  0.0804, -0.9438,  0.0790,  0.7998, -0.2854,
  //               0.1963, -0.0687, -0.2123,  0.3625, -0.0002,  0.7168, -0.4033,
  //               0.2812, -0.3159
  VLOAD_16(v6, 0x3109, 0xba29, 0x2d25, 0xbb8d, 0x2d0e, 0x3a66, 0xb491, 0x3248,
           0xac65, 0xb2cb, 0x35cd, 0x897c, 0x39bc, 0xb674, 0x3480, 0xb50e);
  //               0.0337,  0.2034, -0.1886,  0.8242,  0.3225,  0.0331,  0.0698,
  //               0.6777, -0.2539, -0.5825, -0.4319, -0.6323,  0.0674, -0.2903,
  //               -0.8145,  0.1893
  VLOAD_16(v2, 0x284f, 0x3282, 0xb209, 0x3a98, 0x3529, 0x283b, 0x2c77, 0x396c,
           0xb410, 0xb8a9, 0xb6e9, 0xb90f, 0x2c50, 0xb4a5, 0xba84, 0x320f);
  asm volatile("vfnmadd.vv v2, v4, v6");
  //              -0.1322,  0.7598, -0.1383,  1.3506,  0.0894, -0.7734,  0.2512,
  //              0.4155,  0.1132,  0.2517, -0.3176,  0.2864, -0.7407,  0.3254,
  //              0.0071,  0.3320
  VCMP_U16(1, v2, 0xb03b, 0x3a14, 0xb06d, 0x3d67, 0x2db8, 0xba30, 0x3405,
           0x36a6, 0x2f3e, 0x3407, 0xb515, 0x3495, 0xb9ed, 0x3535, 0x1f3d,
           0x3550);

  VSET(16, e32, m2);
  //              -0.36820358,  0.10496315, -0.32905263, -0.92334682,
  //              0.43153936,  0.92736709, -0.59600371,  0.75117606, 0.84123290,
  //              0.33028743, -0.43412161,  0.95273590,  0.06816643,
  //              -0.88978988,  0.18573478,  0.61926919
  VLOAD_32(v4, 0xbebc852e, 0x3dd6f6ec, 0xbea87996, 0xbf6c6075, 0x3edcf2ba,
           0x3f6d67ee, 0xbf1893b3, 0x3f404d13, 0x3f575b0a, 0x3ea91b6f,
           0xbede4530, 0x3f73e680, 0x3d8b9ad8, 0xbf63c945, 0x3e3e3142,
           0x3f1e886d);
  //               0.69083834, -0.31329882, -0.54809541,  0.25019145,
  //               -0.67489260,  0.23259214, -0.14038530,  0.09741956,
  //               -0.23567833,  0.75417399, -0.90357685, -0.87489468,
  //               0.54726779, -0.06705534, -0.15476358, -0.96940458
  VLOAD_32(v6, 0x3f30dac8, 0xbea068b4, 0xbf0c4ffb, 0x3e801918, 0xbf2cc5c3,
           0x3e6e2ca2, 0xbe0fc12a, 0x3dc783e8, 0xbe7155a9, 0x3f41118c,
           0xbf6750d0, 0xbf5ff919, 0x3f0c19be, 0xbd895450, 0xbe1e7a58,
           0xbf782ae6);
  //               0.03722767,  0.80796093,  0.53925264, -0.50804031,
  //               0.63562357, -0.45508829, -0.22051410,  0.42499006,
  //               -0.59229839, -0.50074077, -0.80474108, -0.20762257,
  //               0.15367362,  0.98349953, -0.15871963, -0.07445616
  VLOAD_32(v2, 0x3d187c0a, 0x3f4ed687, 0x3f0a0c76, 0xbf020eee, 0x3f22b83a,
           0xbee90155, 0xbe61ce73, 0x3ed9984c, 0xbf17a0de, 0xbf00308c,
           0xbf4e0383, 0xbe549b03, 0x3e1d5c9e, 0x3f7bc6a0, 0xbe228766,
           0xbd987c79);
  asm volatile("vfnmadd.vv v2, v4, v6");
  //              -0.67713100,  0.22849269,  0.72553790, -0.71928883,
  //              0.40059602,  0.18944177,  0.00895807, -0.41666192, 0.73393923,
  //              -0.58878565,  0.55422139,  1.07270420, -0.55774319,
  //              0.94216329,  0.18424334,  1.01551294
  VCMP_U32(2, v2, 0xbf2d5875, 0x3e69f9fd, 0x3f39bcda, 0xbf382350, 0x3ecd1aec,
           0x3e41fd06, 0x3c12c4e5, 0xbed554b6, 0x3f3be371, 0xbf16baa7,
           0x3f0de173, 0x3f894e5f, 0xbf0ec842, 0x3f71319d, 0x3e3caa49,
           0x3f81fc54);

#if ELEN == 64
  VSET(16, e64, m2);
  //              -0.1517393950396491, -0.0976116299317518,  0.4195080955516000,
  //              -0.8346165642452430,  0.0078216057137750, -0.5126918345148062,
  //              -0.9302856586058497, -0.8971839537614414,  0.1317157676127678,
  //              -0.3423297874984121,  0.7678405723111816, -0.6465198020108864,
  //              0.4795090517472360, -0.9006147069685106,  0.9841759200408695,
  //              0.8437352562659637
  VLOAD_64(v4, 0xbfc36c324d9ae520, 0xbfb8fd1366442100, 0x3fdad9387bb34990,
           0xbfeab52dcc044330, 0x3f8004c625f16600, 0xbfe067f8b4c55ad2,
           0xbfedc4e66df4cc5a, 0xbfecb5bb1f7cd800, 0x3fc0dc0ff121d700,
           0xbfd5e8bb327025d8, 0x3fe892266453ca54, 0xbfe4b04a4bbb4d06,
           0x3fdeb046bbd8fb80, 0xbfecd1d5ef173e7a, 0x3fef7e5e7fc2c286,
           0x3feaffe114849fb0);
  //               0.3915682245289982,  0.0468282563045201,  0.4640582663413180,
  //               0.9199907734666593, -0.6702920875531786,  0.6250479001245852,
  //               -0.3716310293668668,  0.2191474803863191,
  //               -0.3398132406457823, -0.1436002174993440,
  //               -0.7049093483038609,  0.0726450331160087, 0.3054536350672581,
  //               -0.9906780567812383,  0.2659677084286980, -0.6111168392293305
  VLOAD_64(v6, 0x3fd90f742ba04f2c, 0x3fa7f9df8ab696e0, 0x3fddb3217157f678,
           0x3fed70907d95274a, 0xbfe573086459defe, 0x3fe40064742efe82,
           0xbfd7c8cd8353cefc, 0x3fcc0d064ea14910, 0xbfd5bf8008d49208,
           0xbfc2617deeedd880, 0xbfe68e9e0cb3831e, 0x3fb298dd69733960,
           0x3fd38c8d6743b96c, 0xbfefb3a277d7b020, 0x3fd1059d6c5f9294,
           0xbfe38e44e6d0cbb0);
  //               0.8932002267748917,  0.5237198185024288, -0.3716642114238491,
  //               0.8806741908360942,  0.4285584084885536, -0.9185899240339090,
  //               -0.3906189235600976, -0.8681987020972610,
  //               -0.8703598457154336, -0.2254866845234647, 0.7002825787534324,
  //               0.0892712008047818,  0.9241326299982451,  0.6615225744181676,
  //               0.7351775340550828, -0.4044996673659886
  VLOAD_64(v2, 0x3fec9518a458e4ea, 0x3fe0c25010978504, 0xbfd7c958b04a2e10,
           0x3fec2e7ba402502e, 0x3fdb6d803f3895dc, 0xbfed6516b24524fa,
           0xbfd8ffe68378eb00, 0xbfebc848a4fdff0a, 0xbfebd9fce4232e3a,
           0xbfccdcbf67db1aa0, 0x3fe668b702b68b90, 0x3fb6da7a37ee6240,
           0x3fed927e97e0492a, 0x3fe52b3163d622de, 0x3fe786930930a7fe,
           0xbfd9e35292a51b70);
  asm volatile("vfnmadd.vv v2, v4, v6");
  //              -0.2560345624688988,  0.0042928888070631, -0.3081421208222118,
  //              -0.1849655060915788,  0.6669400726566582, -1.0960014534443465,
  //              0.0082438467988533, -0.9980814245844917,  0.4544533558235209,
  //              0.0664094087027049,  0.1672039722542752, -0.0149294340464271,
  //              -0.7485835961663959,  1.5864550162939111, -0.9895117344007368,
  //              0.9524074697338700
  VCMP_U64(3, v2, 0xbfd062deca1cc612, 0x3f71956b9081d880, 0xbfd3b899badce50e,
           0xbfc7acf31fc694ed, 0x3fe55792b50e7883, 0xbff18938d1ee9749,
           0x3f80e22663278b8b, 0xbfeff04874aabc45, 0x3fdd15c38734723f,
           0x3fb10034fe865a4b, 0x3fc566f0944bf4a6, 0xbf8e9352b7d14aa9,
           0xbfe7f46595fb6a6d, 0x3ff9621ea7b8eb80, 0xbfefaa1483484d07,
           0x3fee7a1f3adf237b);
#endif
};

// Simple random test with similar values (masked)
// The numbers are the same of TEST_CASE1
void TEST_CASE2(void) {
  VSET(16, e16, m2);
  //              -0.7461,  0.0514, -0.3071, -0.4934, -0.5220, -0.7983,  0.4907,
  //              -0.9028,  0.1752,  0.0676,  0.1040,  0.4526,  0.3525, -0.2686,
  //              0.3540, -0.0847
  VLOAD_16(v4, 0xb9f8, 0x2a94, 0xb4ea, 0xb7e5, 0xb82d, 0xba63, 0x37da, 0xbb39,
           0x319b, 0x2c54, 0x2ea8, 0x373e, 0x35a4, 0xb44c, 0x35aa, 0xad6c);
  //               0.1573, -0.7700,  0.0804, -0.9438,  0.0790,  0.7998, -0.2854,
  //               0.1963, -0.0687, -0.2123,  0.3625, -0.0002,  0.7168, -0.4033,
  //               0.2812, -0.3159
  VLOAD_16(v6, 0x3109, 0xba29, 0x2d25, 0xbb8d, 0x2d0e, 0x3a66, 0xb491, 0x3248,
           0xac65, 0xb2cb, 0x35cd, 0x897c, 0x39bc, 0xb674, 0x3480, 0xb50e);
  VLOAD_8(v0, 0xAA, 0xAA);
  //               0.0337,  0.2034, -0.1886,  0.8242,  0.3225,  0.0331,  0.0698,
  //               0.6777, -0.2539, -0.5825, -0.4319, -0.6323,  0.0674, -0.2903,
  //               -0.8145,  0.1893
  VLOAD_16(v2, 0x284f, 0x3282, 0xb209, 0x3a98, 0x3529, 0x283b, 0x2c77, 0x396c,
           0xb410, 0xb8a9, 0xb6e9, 0xb90f, 0x2c50, 0xb4a5, 0xba84, 0x320f);
  asm volatile("vfnmadd.vv v2, v4, v6, v0.t");
  //               0.0337,  0.7598, -0.1886,  1.3506,  0.3225, -0.7734,  0.0698,
  //               0.4155, -0.2539,  0.2517, -0.4319,  0.2864,  0.0674,  0.3254,
  //               -0.8145,  0.3320
  VCMP_U16(4, v2, 0x284f, 0x3a14, 0xb209, 0x3d67, 0x3529, 0xba30, 0x2c77,
           0x36a6, 0xb410, 0x3407, 0xb6e9, 0x3495, 0x2c50, 0x3535, 0xba84,
           0x3550);

  VSET(16, e32, m2);
  //              -0.36820358,  0.10496315, -0.32905263, -0.92334682,
  //              0.43153936,  0.92736709, -0.59600371,  0.75117606, 0.84123290,
  //              0.33028743, -0.43412161,  0.95273590,  0.06816643,
  //              -0.88978988,  0.18573478,  0.61926919
  VLOAD_32(v4, 0xbebc852e, 0x3dd6f6ec, 0xbea87996, 0xbf6c6075, 0x3edcf2ba,
           0x3f6d67ee, 0xbf1893b3, 0x3f404d13, 0x3f575b0a, 0x3ea91b6f,
           0xbede4530, 0x3f73e680, 0x3d8b9ad8, 0xbf63c945, 0x3e3e3142,
           0x3f1e886d);
  //               0.69083834, -0.31329882, -0.54809541,  0.25019145,
  //               -0.67489260,  0.23259214, -0.14038530,  0.09741956,
  //               -0.23567833,  0.75417399, -0.90357685, -0.87489468,
  //               0.54726779, -0.06705534, -0.15476358, -0.96940458
  VLOAD_32(v6, 0x3f30dac8, 0xbea068b4, 0xbf0c4ffb, 0x3e801918, 0xbf2cc5c3,
           0x3e6e2ca2, 0xbe0fc12a, 0x3dc783e8, 0xbe7155a9, 0x3f41118c,
           0xbf6750d0, 0xbf5ff919, 0x3f0c19be, 0xbd895450, 0xbe1e7a58,
           0xbf782ae6);
  VLOAD_8(v0, 0xAA, 0xAA);
  //               0.03722767,  0.80796093,  0.53925264, -0.50804031,
  //               0.63562357, -0.45508829, -0.22051410,  0.42499006,
  //               -0.59229839, -0.50074077, -0.80474108, -0.20762257,
  //               0.15367362,  0.98349953, -0.15871963, -0.07445616
  VLOAD_32(v2, 0x3d187c0a, 0x3f4ed687, 0x3f0a0c76, 0xbf020eee, 0x3f22b83a,
           0xbee90155, 0xbe61ce73, 0x3ed9984c, 0xbf17a0de, 0xbf00308c,
           0xbf4e0383, 0xbe549b03, 0x3e1d5c9e, 0x3f7bc6a0, 0xbe228766,
           0xbd987c79);
  asm volatile("vfnmadd.vv v2, v4, v6, v0.t");
  //               0.03722767,  0.22849269,  0.53925264, -0.71928883,
  //               0.63562357,  0.18944177, -0.22051410, -0.41666192,
  //               -0.59229839, -0.58878565, -0.80474108,  1.07270420,
  //               0.15367362,  0.94216329, -0.15871963,  1.01551294
  VCMP_U32(5, v2, 0x3d187c0a, 0x3e69f9fd, 0x3f0a0c76, 0xbf382350, 0x3f22b83a,
           0x3e41fd06, 0xbe61ce73, 0xbed554b6, 0xbf17a0de, 0xbf16baa7,
           0xbf4e0383, 0x3f894e5f, 0x3e1d5c9e, 0x3f71319d, 0xbe228766,
           0x3f81fc54);

#if ELEN == 64
  VSET(16, e64, m2);
  //              -0.1517393950396491, -0.0976116299317518,  0.4195080955516000,
  //              -0.8346165642452430,  0.0078216057137750, -0.5126918345148062,
  //              -0.9302856586058497, -0.8971839537614414,  0.1317157676127678,
  //              -0.3423297874984121,  0.7678405723111816, -0.6465198020108864,
  //              0.4795090517472360, -0.9006147069685106,  0.9841759200408695,
  //              0.8437352562659637
  VLOAD_64(v4, 0xbfc36c324d9ae520, 0xbfb8fd1366442100, 0x3fdad9387bb34990,
           0xbfeab52dcc044330, 0x3f8004c625f16600, 0xbfe067f8b4c55ad2,
           0xbfedc4e66df4cc5a, 0xbfecb5bb1f7cd800, 0x3fc0dc0ff121d700,
           0xbfd5e8bb327025d8, 0x3fe892266453ca54, 0xbfe4b04a4bbb4d06,
           0x3fdeb046bbd8fb80, 0xbfecd1d5ef173e7a, 0x3fef7e5e7fc2c286,
           0x3feaffe114849fb0);
  //               0.3915682245289982,  0.0468282563045201,  0.4640582663413180,
  //               0.9199907734666593, -0.6702920875531786,  0.6250479001245852,
  //               -0.3716310293668668,  0.2191474803863191,
  //               -0.3398132406457823, -0.1436002174993440,
  //               -0.7049093483038609,  0.0726450331160087, 0.3054536350672581,
  //               -0.9906780567812383,  0.2659677084286980, -0.6111168392293305
  VLOAD_64(v6, 0x3fd90f742ba04f2c, 0x3fa7f9df8ab696e0, 0x3fddb3217157f678,
           0x3fed70907d95274a, 0xbfe573086459defe, 0x3fe40064742efe82,
           0xbfd7c8cd8353cefc, 0x3fcc0d064ea14910, 0xbfd5bf8008d49208,
           0xbfc2617deeedd880, 0xbfe68e9e0cb3831e, 0x3fb298dd69733960,
           0x3fd38c8d6743b96c, 0xbfefb3a277d7b020, 0x3fd1059d6c5f9294,
           0xbfe38e44e6d0cbb0);
  VLOAD_8(v0, 0xAA, 0xAA);
  //               0.8932002267748917,  0.5237198185024288, -0.3716642114238491,
  //               0.8806741908360942,  0.4285584084885536, -0.9185899240339090,
  //               -0.3906189235600976, -0.8681987020972610,
  //               -0.8703598457154336, -0.2254866845234647, 0.7002825787534324,
  //               0.0892712008047818,  0.9241326299982451,  0.6615225744181676,
  //               0.7351775340550828, -0.4044996673659886
  VLOAD_64(v2, 0x3fec9518a458e4ea, 0x3fe0c25010978504, 0xbfd7c958b04a2e10,
           0x3fec2e7ba402502e, 0x3fdb6d803f3895dc, 0xbfed6516b24524fa,
           0xbfd8ffe68378eb00, 0xbfebc848a4fdff0a, 0xbfebd9fce4232e3a,
           0xbfccdcbf67db1aa0, 0x3fe668b702b68b90, 0x3fb6da7a37ee6240,
           0x3fed927e97e0492a, 0x3fe52b3163d622de, 0x3fe786930930a7fe,
           0xbfd9e35292a51b70);
  asm volatile("vfnmadd.vv v2, v4, v6, v0.t");
  //               0.8932002267748917,  0.0042928888070631, -0.3716642114238491,
  //               -0.1849655060915788,  0.4285584084885536,
  //               -1.0960014534443465, -0.3906189235600976,
  //               -0.9980814245844917, -0.8703598457154336, 0.0664094087027049,
  //               0.7002825787534324, -0.0149294340464271,
  //               0.9241326299982451,  1.5864550162939111,  0.7351775340550828,
  //               0.9524074697338700
  VCMP_U64(6, v2, 0x3fec9518a458e4ea, 0x3f71956b9081d880, 0xbfd7c958b04a2e10,
           0xbfc7acf31fc694ed, 0x3fdb6d803f3895dc, 0xbff18938d1ee9749,
           0xbfd8ffe68378eb00, 0xbfeff04874aabc45, 0xbfebd9fce4232e3a,
           0x3fb10034fe865a4b, 0x3fe668b702b68b90, 0xbf8e9352b7d14aa9,
           0x3fed927e97e0492a, 0x3ff9621ea7b8eb80, 0x3fe786930930a7fe,
           0x3fee7a1f3adf237b);
#endif
};

// Simple random test with similar values (vector-scalar)
void TEST_CASE3(void) {
  VSET(16, e16, m2);
  float fscalar_16;
  //                              0.2646
  BOX_HALF_IN_FLOAT(fscalar_16, 0x343c);
  //               0.4216, -0.2148,  0.0047,  0.6802, -0.8965, -0.2986, -0.1786,
  //               -0.1904,  0.2805,  0.5322, -0.5298,  0.3208,  0.0567,
  //               -0.9897, -0.5400, -0.4187
  VLOAD_16(v4, 0x36bf, 0xb2e0, 0x1cc3, 0x3971, 0xbb2c, 0xb4c7, 0xb1b7, 0xb218,
           0x347d, 0x3842, 0xb83d, 0x3522, 0x2b41, 0xbbeb, 0xb852, 0xb6b3);
  //              -0.7886, -0.5435, -0.8345,  0.7793,  0.5796, -0.8374, -0.8623,
  //              -0.3313, -0.2690, -0.9214,  0.2126, -0.6772, -0.6514, -0.5703,
  //              -0.2585, -0.3320
  VLOAD_16(v2, 0xba4f, 0xb859, 0xbaad, 0x3a3c, 0x38a3, 0xbab3, 0xbae6, 0xb54d,
           0xb44e, 0xbb5f, 0x32ce, 0xb96b, 0xb936, 0xb890, 0xb423, 0xb550);
  asm volatile("vfnmadd.vf v2, %[A], v4" ::[A] "f"(fscalar_16));
  //              -0.2129,  0.3586,  0.2162, -0.8867,  0.7432,  0.5200,  0.4067,
  //              0.2781, -0.2092, -0.2883,  0.4736, -0.1416,  0.1157,  1.1406,
  //              0.6084,  0.5068
  VCMP_U16(7, v2, 0xb2d0, 0x35bd, 0x32eb, 0xbb17, 0x39f2, 0x3829, 0x3682,
           0x3473, 0xb2b3, 0xb49d, 0x3793, 0xb088, 0x2f68, 0x3c90, 0x38de,
           0x380d);

  VSET(16, e32, m2);
  float fscalar_32;
  //                              -0.13809182
  BOX_FLOAT_IN_FLOAT(fscalar_32, 0xbe0d67f1);
  //              -0.16977388, -0.30800357, -0.37010264, -0.92290556,
  //              0.55768263,  0.47349435,  0.77556002,  0.16363664, 0.80314618,
  //              -0.48171839, -0.60694915,  0.16937894,  0.86316317,
  //              0.00897404, -0.96310323, -0.27890080
  VLOAD_32(v4, 0xbe2dd934, 0xbe9db2a5, 0xbebd7e18, 0xbf6c438a, 0x3f0ec44a,
           0x3ef26dda, 0x3f468b1a, 0x3e27905d, 0x3f4d9afd, 0xbef6a3cb,
           0xbf1b6105, 0x3e2d71ac, 0x3f5cf843, 0x3c1307df, 0xbf768def,
           0xbe8ecc16);
  //              -0.33133313, -0.48972869,  0.95656961, -0.89211702,
  //              0.72045243, -0.36672497,  0.69402671,  0.44954479,
  //              -0.77024877, -0.83221292,  0.37576449, -0.77536738,
  //              -0.55040795, -0.71568310, -0.75874990,  0.91956782
  VLOAD_32(v2, 0xbea9a47f, 0xbefabdb8, 0x3f74e1bf, 0xbf6461c8, 0x3f386f92,
           0xbebbc360, 0x3f31abbc, 0x3ee62abc, 0xbf452f06, 0xbf550be8,
           0x3ec06434, 0xbf467e7a, 0xbf0ce789, 0xbf373702, 0xbf423d6f,
           0x3f6b68cc);
  asm volatile("vfnmadd.vf v2, %[A], v4" ::[A] "f"(fscalar_32));
  //               0.12401948,  0.24037606,  0.50219709,  0.79971153,
  //               -0.45819405, -0.52413607, -0.67972064, -0.10155818,
  //               -0.90951121,  0.36679661,  0.65883917, -0.27645081,
  //               -0.93917000, -0.10780402,  0.85832608,  0.40588558
  VCMP_U32(8, v2, 0x3dfdfded, 0x3e762524, 0x3f008ffd, 0x3f4cb9e5, 0xbeea9869,
           0xbf062dc8, 0xbf2e022c, 0xbdcffdbd, 0xbf68d5ba, 0x3ebbccc3,
           0x3f28a9af, 0xbe8d8af6, 0xbf706d72, 0xbddcc85b, 0x3f5bbb42,
           0x3ecfd03d);

#if ELEN == 64
  VSET(16, e64, m2);
  double dscalar_64;
  //                                0.8978909040536565
  BOX_DOUBLE_IN_DOUBLE(dscalar_64, 0x3fecbb85b489299a);
  //                0.4119623576675431, -0.1190899643735133, 0.9903323592718865,
  //                0.5311038519754858,  0.1686986553141236,
  //                -0.8788301781199843,  0.1880579223718752,
  //                0.7610824660598337, -0.0872931389118274,
  //                -0.6855627317033812, -0.0181686933036735,
  //                -0.9796673648941667,  0.2148282430178909,
  //                -0.1529278220414154, -0.7708574130314993,
  //                -0.4104905538508556
  VLOAD_64(v4, 0x3fda5d975d575ea8, 0xbfbe7cae0e441b80, 0x3fefb0cd7ce7c8e8,
           0x3fe0fecd81607572, 0x3fc597eae3ba06f8, 0xbfec1f6077386c08,
           0x3fc81248312ba2f8, 0x3fe85ac99da9270a, 0xbfb658d7d8ca9eb0,
           0xbfe5f0214100b7de, 0xbf929ad05e338a40, 0xbfef596f5fa5b9ea,
           0x3fcb7f7deb026e00, 0xbfc393238d287f60, 0xbfe8aadd2a5b2eba,
           0xbfda457a2c06ce78);
  //                0.5050016609492949,  0.8257750946258060,
  //                -0.2631016891694440,  0.8041841986447893,
  //                -0.0322547653971421, -0.3994438840519345,
  //                -0.6154540433263920, -0.9209485498858390,
  //                0.3334000822950238, -0.6004917796663505, 0.4588428764280068,
  //                0.8937156106780619,  0.8421999503441004, 0.3083609158934253,
  //                -0.2219824502919918,  0.5118870280625194
  VLOAD_64(v2, 0x3fe028f93e467e2c, 0x3fea6cbfe4289cd0, 0xbfd0d6a877a053e0,
           0x3fe9bbe080247574, 0xbfa083b2550ab080, 0xbfd9907d14a5c710,
           0xbfe3b1ccad88e3e8, 0xbfed786917e1dd9e, 0x3fd5566d4c7c36a8,
           0xbfe3373a8965e1cc, 0x3fdd5dae8310b1e8, 0x3fec99517af92ea6,
           0x3feaf34d4f6d76aa, 0x3fd3bc2f6c481e9c, 0xbfcc69ebc2252060,
           0x3fe06160e798ce12);
  asm volatile("vfnmadd.vf v2, %[A], v4" ::[A] "f"(dscalar_64));
  //              -0.8653987555659035, -0.6223659818850454, -0.7540957457254903,
  //              -1.2531735291223209, -0.1397373948516451,  1.2374872082900796,
  //              0.3645526649939371,  0.0658288599840662,
  //              -0.2120637623916150,  1.2247388386247897, -0.3938221518308497,
  //              0.1772082472555760, -0.9710319178262998, -0.1239466395049457,
  //              0.9701734360082217, -0.0491281525495393
  VCMP_U64(9, v2, 0xbfebb158bb24f2ec, 0xbfe3ea6c104adab7, 0xbfe8218d66be32e5,
           0xbff40cffafbcb13e, 0xbfc1e2ea3a754147, 0x3ff3ccbf630d300f,
           0x3fd754d4b3746402, 0x3fb0da2900c3b814, 0xbfcb24e7c611c0f4,
           0x3ff39887c0a08d49, 0xbfd93461d3a37236, 0x3fc6aec28545a7b7,
           0xbfef12b1874df4ac, 0xbfbfbaf78b1f72ad, 0x3fef0ba929634dea,
           0xbfa927534106be44);
#endif
};

// Simple random test with similar values (vector-scalar) (masked)
void TEST_CASE4(void) {
  VSET(16, e16, m2);
  float fscalar_16;
  //                              0.2646
  BOX_HALF_IN_FLOAT(fscalar_16, 0x343c);
  //                0.4216, -0.2148,  0.0047,  0.6802, -0.8965, -0.2986,
  //                -0.1786, -0.1904,  0.2805,  0.5322, -0.5298,  0.3208,
  //                0.0567, -0.9897, -0.5400, -0.4187
  VLOAD_16(v4, 0x36bf, 0xb2e0, 0x1cc3, 0x3971, 0xbb2c, 0xb4c7, 0xb1b7, 0xb218,
           0x347d, 0x3842, 0xb83d, 0x3522, 0x2b41, 0xbbeb, 0xb852, 0xb6b3);
  VLOAD_8(v0, 0xAA, 0xAA);
  //               -0.7886, -0.5435, -0.8345,  0.7793,  0.5796, -0.8374,
  //               -0.8623, -0.3313, -0.2690, -0.9214,  0.2126, -0.6772,
  //               -0.6514, -0.5703, -0.2585, -0.3320
  VLOAD_16(v2, 0xba4f, 0xb859, 0xbaad, 0x3a3c, 0x38a3, 0xbab3, 0xbae6, 0xb54d,
           0xb44e, 0xbb5f, 0x32ce, 0xb96b, 0xb936, 0xb890, 0xb423, 0xb550);
  asm volatile("vfnmadd.vf v2, %[A], v4, v0.t" ::[A] "f"(fscalar_16));
  //               -0.7886,  0.3586, -0.8345, -0.8867,  0.5796,  0.5200,
  //               -0.8623,  0.2781, -0.2690, -0.2883,  0.2126, -0.1416,
  //               -0.6514,  1.1406, -0.2585,  0.5068
  VCMP_U16(10, v2, 0xba4f, 0x35bd, 0xbaad, 0xbb17, 0x38a3, 0x3829, 0xbae6,
           0x3473, 0xb44e, 0xb49d, 0x32ce, 0xb088, 0xb936, 0x3c90, 0xb423,
           0x380d);

  VSET(16, e32, m2);
  float fscalar_32;
  //                              -0.13809182
  BOX_FLOAT_IN_FLOAT(fscalar_32, 0xbe0d67f1);
  //               -0.16977388, -0.30800357, -0.37010264, -0.92290556,
  //               0.55768263,  0.47349435,  0.77556002,  0.16363664,
  //               0.80314618, -0.48171839, -0.60694915,  0.16937894,
  //               0.86316317,  0.00897404, -0.96310323, -0.27890080
  VLOAD_32(v4, 0xbe2dd934, 0xbe9db2a5, 0xbebd7e18, 0xbf6c438a, 0x3f0ec44a,
           0x3ef26dda, 0x3f468b1a, 0x3e27905d, 0x3f4d9afd, 0xbef6a3cb,
           0xbf1b6105, 0x3e2d71ac, 0x3f5cf843, 0x3c1307df, 0xbf768def,
           0xbe8ecc16);
  VLOAD_8(v0, 0xAA, 0xAA);
  //               -0.33133313, -0.48972869,  0.95656961, -0.89211702,
  //               0.72045243, -0.36672497,  0.69402671,  0.44954479,
  //               -0.77024877, -0.83221292,  0.37576449, -0.77536738,
  //               -0.55040795, -0.71568310, -0.75874990,  0.91956782
  VLOAD_32(v2, 0xbea9a47f, 0xbefabdb8, 0x3f74e1bf, 0xbf6461c8, 0x3f386f92,
           0xbebbc360, 0x3f31abbc, 0x3ee62abc, 0xbf452f06, 0xbf550be8,
           0x3ec06434, 0xbf467e7a, 0xbf0ce789, 0xbf373702, 0xbf423d6f,
           0x3f6b68cc);
  asm volatile("vfnmadd.vf v2, %[A], v4, v0.t" ::[A] "f"(fscalar_32));
  //               -0.33133313,  0.24037606,  0.95656961,  0.79971153,
  //               0.72045243, -0.52413607,  0.69402671, -0.10155818,
  //               -0.77024877,  0.36679661,  0.37576449, -0.27645081,
  //               -0.55040795, -0.10780402, -0.75874990,  0.40588558
  VCMP_U32(11, v2, 0xbea9a47f, 0x3e762524, 0x3f74e1bf, 0x3f4cb9e5, 0x3f386f92,
           0xbf062dc8, 0x3f31abbc, 0xbdcffdbd, 0xbf452f06, 0x3ebbccc3,
           0x3ec06434, 0xbe8d8af6, 0xbf0ce789, 0xbddcc85b, 0xbf423d6f,
           0x3ecfd03d);

#if ELEN == 64
  VSET(16, e64, m2);
  double dscalar_64;
  //                                0.8978909040536565
  BOX_DOUBLE_IN_DOUBLE(dscalar_64, 0x3fecbb85b489299a);
  //                 0.4119623576675431, -0.1190899643735133,
  //                 0.9903323592718865,  0.5311038519754858,
  //                 0.1686986553141236, -0.8788301781199843,
  //                 0.1880579223718752,  0.7610824660598337,
  //                 -0.0872931389118274, -0.6855627317033812,
  //                 -0.0181686933036735, -0.9796673648941667,
  //                 0.2148282430178909, -0.1529278220414154,
  //                 -0.7708574130314993, -0.4104905538508556
  VLOAD_64(v4, 0x3fda5d975d575ea8, 0xbfbe7cae0e441b80, 0x3fefb0cd7ce7c8e8,
           0x3fe0fecd81607572, 0x3fc597eae3ba06f8, 0xbfec1f6077386c08,
           0x3fc81248312ba2f8, 0x3fe85ac99da9270a, 0xbfb658d7d8ca9eb0,
           0xbfe5f0214100b7de, 0xbf929ad05e338a40, 0xbfef596f5fa5b9ea,
           0x3fcb7f7deb026e00, 0xbfc393238d287f60, 0xbfe8aadd2a5b2eba,
           0xbfda457a2c06ce78);
  VLOAD_8(v0, 0xAA, 0xAA);
  //                 0.5050016609492949,  0.8257750946258060,
  //                 -0.2631016891694440,  0.8041841986447893,
  //                 -0.0322547653971421, -0.3994438840519345,
  //                 -0.6154540433263920, -0.9209485498858390,
  //                 0.3334000822950238, -0.6004917796663505,
  //                 0.4588428764280068,  0.8937156106780619,
  //                 0.8421999503441004,  0.3083609158934253,
  //                 -0.2219824502919918,  0.5118870280625194
  VLOAD_64(v2, 0x3fe028f93e467e2c, 0x3fea6cbfe4289cd0, 0xbfd0d6a877a053e0,
           0x3fe9bbe080247574, 0xbfa083b2550ab080, 0xbfd9907d14a5c710,
           0xbfe3b1ccad88e3e8, 0xbfed786917e1dd9e, 0x3fd5566d4c7c36a8,
           0xbfe3373a8965e1cc, 0x3fdd5dae8310b1e8, 0x3fec99517af92ea6,
           0x3feaf34d4f6d76aa, 0x3fd3bc2f6c481e9c, 0xbfcc69ebc2252060,
           0x3fe06160e798ce12);
  asm volatile("vfnmadd.vf v2, %[A], v4, v0.t" ::[A] "f"(dscalar_64));
  //                0.5050016609492949, -0.6223659818850454,
  //                -0.2631016891694440, -1.2531735291223209,
  //                -0.0322547653971421,  1.2374872082900796,
  //                -0.6154540433263920,  0.0658288599840662,
  //                0.3334000822950238,  1.2247388386247897, 0.4588428764280068,
  //                0.1772082472555760,  0.8421999503441004,
  //                -0.1239466395049457, -0.2219824502919918,
  //                -0.0491281525495393
  VCMP_U64(12, v2, 0x3fe028f93e467e2c, 0xbfe3ea6c104adab7, 0xbfd0d6a877a053e0,
           0xbff40cffafbcb13e, 0xbfa083b2550ab080, 0x3ff3ccbf630d300f,
           0xbfe3b1ccad88e3e8, 0x3fb0da2900c3b814, 0x3fd5566d4c7c36a8,
           0x3ff39887c0a08d49, 0x3fdd5dae8310b1e8, 0x3fc6aec28545a7b7,
           0x3feaf34d4f6d76aa, 0xbfbfbaf78b1f72ad, 0xbfcc69ebc2252060,
           0xbfa927534106be44);
#endif
};

int main(void) {
  INIT_CHECK();
  enable_vec();
  enable_fp();

  TEST_CASE1();
  //TEST_CASE2();
  TEST_CASE3();
  //TEST_CASE4();

  EXIT_CHECK();
}
