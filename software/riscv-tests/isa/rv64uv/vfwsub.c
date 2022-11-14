// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matheus Cavalcante <matheusd@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>
//         Matteo Perotti <mperotti@iis.ee.ethz.ch>

#include "float_macros.h"
#include "vector_macros.h"

// Simple random test with similar values
void TEST_CASE1(void) {
  VSET(16, e16, m2);
  //              -15.5625,  95.7500, -42.4375,  30.7188, -50.7500, -90.2500,
  //              -95.5000,  29.5938, -41.4062, -94.0000,  34.3438,
  //              -69.5625,  31.5625, -75.0625,  46.2500, -63.6875
  VLOAD_16(v4, 0xcbc8, 0x55fc, 0xd14e, 0x4fae, 0xd258, 0xd5a4, 0xd5f8, 0x4f66,
           0xd12d, 0xd5e0, 0x504b, 0xd459, 0x4fe4, 0xd4b1, 0x51c8, 0xd3f6);
  //               57.2500,  43.2812, -49.4062, -53.5625, -54.7812,
  //               -12.1406,  92.1875,  67.1875, -19.7656, -41.2812,  98.0625,
  //               -41.9062,  10.1719, -84.6250, -7.1016,  62.8750
  VLOAD_16(v6, 0x5328, 0x5169, 0xd22d, 0xd2b2, 0xd2d9, 0xca12, 0x55c3, 0x5433,
           0xccf1, 0xd129, 0x5621, 0xd13d, 0x4916, 0xd54a, 0xc71a, 0x53dc);
  asm volatile("vfwsub.vv v8, v4, v6");
  //              -72.81250000,  52.46875000,  6.96875000,  84.28125000,  4.03125000,
  //              -78.10937500, -187.68750000, -37.59375000, -21.64062500,
  //              -52.71875000, -63.71875000,
  //              -27.65625000,  21.39062500,  9.56250000,  53.35156250,
  //              -126.56250000
  VCMP_U32(1, v8, 0xc291a000, 0x4251e000, 0x40df0000, 0x42a89000, 0x40810000,
           0xc29c3800, 0xc33bb000, 0xc2166000, 0xc1ad2000, 0xc252e000,
           0xc27ee000, 0xc1dd4000, 0x41ab2000, 0x41190000, 0x42556800,
           0xc2fd2000);

  VSET(16, e32, m2);
  //               74632.77343750, -65636.60937500,  16165.84765625,
  //               -17815.85937500, -85604.03125000, -76754.03125000,
  //               21778.01171875, -70512.52343750,  85301.90625000,
  //               -8385.11035156,  98258.05468750, -50421.53125000,
  //               69842.53906250, -65219.96093750, -65266.08984375,
  //               -90740.60156250
  VLOAD_32(v4, 0x4791c463, 0xc780324e, 0x467c9764, 0xc68b2fb8, 0xc7a73204,
           0xc795e904, 0x46aa2406, 0xc789b843, 0x47a69af4, 0xc6030471,
           0x47bfe907, 0xc744f588, 0x47886945, 0xc77ec3f6, 0xc77ef217,
           0xc7b13a4d);
  //               5391.72216797, -90760.36718750, -22961.19531250,
  //               12708.62500000,  87107.59375000,  54867.48437500,
  //               55424.39453125, -71436.00781250, -61505.46484375,
  //               57701.78906250, -81581.38281250,  53319.19531250,
  //               -86229.57031250,  44376.69531250,  46809.38671875,
  //               -92887.27343750
  VLOAD_32(v6, 0x45a87dc7, 0xc7b1442f, 0xc6b36264, 0x46469280, 0x47aa21cc,
           0x4756537c, 0x47588065, 0xc78b8601, 0xc7704177, 0x476165ca,
           0xc79f56b1, 0x47504732, 0xc7a86ac9, 0x472d58b2, 0x4736d963,
           0xc7b56ba3);
  asm volatile("vfwsub.vv v8, v4, v6");
  //               69241.0512695312500000,  25123.7578125000000000,
  //               39127.0429687500000000, -30524.4843750000000000,
  //               -172711.6250000000000000, -131621.5156250000000000,
  //               -33646.3828125000000000,  923.4843750000000000,
  //               146807.3710937500000000, -66086.8994140625000000,
  //               179839.4375000000000000, -103740.7265625000000000,
  //               156072.1093750000000000, -109596.6562500000000000,
  //               -112075.4765625000000000,  2146.6718750000000000
  VCMP_U64(2, v8, 0x40f0e790d2000000, 0x40d888f080000000, 0x40e31ae160000000,
           0xc0ddcf1f00000000, 0xc105153d00000000, 0xc100112c20000000,
           0xc0e06dcc40000000, 0x408cdbe000000000, 0x4101ebbaf8000000,
           0xc0f0226e64000000, 0x4105f3fb80000000, 0xc0f953cba0000000,
           0x41030d40e0000000, 0xc0fac1ca80000000, 0xc0fb5cb7a0000000,
           0x40a0c55800000000);
};

// Simple random test with similar values (masked)
// The numbers are the same of TEST_CASE1
void TEST_CASE2(void) {
  VSET(16, e16, m2);
  //              -15.5625,  95.7500, -42.4375,  30.7188, -50.7500, -90.2500,
  //              -95.5000,  29.5938, -41.4062, -94.0000,  34.3438,
  //              -69.5625,  31.5625, -75.0625,  46.2500, -63.6875
  VLOAD_16(v4, 0xcbc8, 0x55fc, 0xd14e, 0x4fae, 0xd258, 0xd5a4, 0xd5f8, 0x4f66,
           0xd12d, 0xd5e0, 0x504b, 0xd459, 0x4fe4, 0xd4b1, 0x51c8, 0xd3f6);
  //               57.2500,  43.2812, -49.4062, -53.5625, -54.7812,
  //               -12.1406,  92.1875,  67.1875, -19.7656, -41.2812,  98.0625,
  //               -41.9062,  10.1719, -84.6250, -7.1016,  62.8750
  VLOAD_16(v6, 0x5328, 0x5169, 0xd22d, 0xd2b2, 0xd2d9, 0xca12, 0x55c3, 0x5433,
           0xccf1, 0xd129, 0x5621, 0xd13d, 0x4916, 0xd54a, 0xc71a, 0x53dc);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vfwsub.vv v8, v4, v6, v0.t");
  //               0.00000000,  52.46875000,  0.00000000,  84.28125000,
  //               0.00000000, -78.10937500,  0.00000000, -37.59375000,
  //               0.00000000, -52.71875000,  0.00000000, -27.65625000,
  //               0.00000000,  9.56250000,  0.00000000, -126.56250000
  VCMP_U32(3, v8, 0x0, 0x4251e000, 0x0, 0x42a89000, 0x0, 0xc29c3800, 0x0,
           0xc2166000, 0x0, 0xc252e000, 0x0, 0xc1dd4000, 0x0, 0x41190000, 0x0,
           0xc2fd2000);

  VSET(16, e32, m2);
  //               74632.77343750, -65636.60937500,  16165.84765625,
  //               -17815.85937500, -85604.03125000, -76754.03125000,
  //               21778.01171875, -70512.52343750,  85301.90625000,
  //               -8385.11035156,  98258.05468750, -50421.53125000,
  //               69842.53906250, -65219.96093750, -65266.08984375,
  //               -90740.60156250
  VLOAD_32(v4, 0x4791c463, 0xc780324e, 0x467c9764, 0xc68b2fb8, 0xc7a73204,
           0xc795e904, 0x46aa2406, 0xc789b843, 0x47a69af4, 0xc6030471,
           0x47bfe907, 0xc744f588, 0x47886945, 0xc77ec3f6, 0xc77ef217,
           0xc7b13a4d);
  //               5391.72216797, -90760.36718750, -22961.19531250,
  //               12708.62500000,  87107.59375000,  54867.48437500,
  //               55424.39453125, -71436.00781250, -61505.46484375,
  //               57701.78906250, -81581.38281250,  53319.19531250,
  //               -86229.57031250,  44376.69531250,  46809.38671875,
  //               -92887.27343750
  VLOAD_32(v6, 0x45a87dc7, 0xc7b1442f, 0xc6b36264, 0x46469280, 0x47aa21cc,
           0x4756537c, 0x47588065, 0xc78b8601, 0xc7704177, 0x476165ca,
           0xc79f56b1, 0x47504732, 0xc7a86ac9, 0x472d58b2, 0x4736d963,
           0xc7b56ba3);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vfwsub.vv v8, v4, v6, v0.t");
  //               0.0000000000000000,  25123.7578125000000000,
  //               0.0000000000000000, -30524.4843750000000000,
  //               0.0000000000000000, -131621.5156250000000000,
  //               0.0000000000000000,  923.4843750000000000,
  //               0.0000000000000000, -66086.8994140625000000,
  //               0.0000000000000000, -103740.7265625000000000,
  //               0.0000000000000000, -109596.6562500000000000,
  //               0.0000000000000000,  2146.6718750000000000
  VCMP_U64(4, v8, 0x0, 0x40d888f080000000, 0x0, 0xc0ddcf1f00000000, 0x0,
           0xc100112c20000000, 0x0, 0x408cdbe000000000, 0x0, 0xc0f0226e64000000,
           0x0, 0xc0f953cba0000000, 0x0, 0xc0fac1ca80000000, 0x0,
           0x40a0c55800000000);
};

// Simple random test with similar values (vector-scalar)
void TEST_CASE3(void) {
  VSET(16, e16, m2);
  float fscalar_16;
  //                              36.4375
  BOX_HALF_IN_FLOAT(fscalar_16, 0x508e);
  //               69.8125, -37.3125, -77.2500,  32.7188,
  //               -83.0000,  76.3125,  14.9375,  72.5000,  39.6250,
  //               -61.2188,  36.3438,  93.5000, -87.1875, -6.9258,  25.1094,
  //               -96.8750
  VLOAD_16(v4, 0x545d, 0xd0aa, 0xd4d4, 0x5017, 0xd530, 0x54c5, 0x4b78, 0x5488,
           0x50f4, 0xd3a7, 0x508b, 0x55d8, 0xd573, 0xc6ed, 0x4e47, 0xd60e);
  asm volatile("vfwsub.vf v8, v4, %[A]" ::[A] "f"(fscalar_16));
  //               33.37500000, -73.75000000, -113.68750000, -3.71875000,
  //               -119.43750000,  39.87500000,
  //               -21.50000000,  36.06250000,  3.18750000, -97.65625000,
  //               -0.09375000,  57.06250000, -123.62500000, -43.36328125,
  //               -11.32812500, -133.31250000
  VCMP_U32(5, v8, 0x42058000, 0xc2938000, 0xc2e36000, 0xc06e0000, 0xc2eee000,
           0x421f8000, 0xc1ac0000, 0x42104000, 0x404c0000, 0xc2c35000,
           0xbdc00000, 0x42644000, 0xc2f74000, 0xc22d7400, 0xc1354000,
           0xc3055000);

  VSET(16, e32, m2);
  float fscalar_32;
  //                              -138614.20312500
  BOX_FLOAT_IN_FLOAT(fscalar_32, 0xc8075d8d);
  //               473107.93750000,  161975.07812500, -173044.89062500,
  //               -322046.09375000, -485607.56250000, -613808.37500000,
  //               -182790.53125000,  121114.44531250, -958537.81250000,
  //               295217.40625000,  281159.84375000, -735195.87500000,
  //               -783982.56250000,  420983.65625000,  954426.12500000,
  //               -297052.53125000
  VLOAD_32(v4, 0x48e7027e, 0x481e2dc5, 0xc828fd39, 0xc89d3fc3, 0xc8ed1cf2,
           0xc915db06, 0xc83281a2, 0x47ec8d39, 0xc96a049d, 0x4890262d,
           0x488948fb, 0xc9337dbe, 0xc93f66e9, 0x48cd8ef5, 0x496903a2,
           0xc8910b91);
  asm volatile("vfwsub.vf v8, v4, %[A]" ::[A] "f"(fscalar_32));
  //               611722.1406250000000000,  300589.2812500000000000,
  //               -34430.6875000000000000, -183431.8906250000000000,
  //               -346993.3593750000000000, -475194.1718750000000000,
  //               -44176.3281250000000000,  259728.6484375000000000,
  //               -819923.6093750000000000,  433831.6093750000000000,
  //               419774.0468750000000000, -596581.6718750000000000,
  //               -645368.3593750000000000,  559597.8593750000000000,
  //               1093040.3281250000000000, -158438.3281250000000000
  VCMP_U64(6, v8, 0x4122ab1448000000, 0x411258b520000000, 0xc0e0cfd600000000,
           0xc106643f20000000, 0xc1152dc570000000, 0xc11d00e8b0000000,
           0xc0e5920a80000000, 0x410fb48530000000, 0xc12905a738000000,
           0x411a7a9e70000000, 0x41199ef830000000, 0xc12234cb58000000,
           0xc123b1f0b8000000, 0x412113dbb8000000, 0x4130adb054000000,
           0xc1035732a0000000);
};

// Simple random test with similar values (vector-scalar) (masked)
void TEST_CASE4(void) {
  VSET(16, e16, m2);
  float fscalar_16;
  //                              36.4375
  BOX_HALF_IN_FLOAT(fscalar_16, 0x508e);
  //                69.8125, -37.3125, -77.2500,  32.7188,
  //                -83.0000,  76.3125,  14.9375,  72.5000,  39.6250,
  //                -61.2188,  36.3438,  93.5000, -87.1875, -6.9258,  25.1094,
  //                -96.8750
  VLOAD_16(v4, 0x545d, 0xd0aa, 0xd4d4, 0x5017, 0xd530, 0x54c5, 0x4b78, 0x5488,
           0x50f4, 0xd3a7, 0x508b, 0x55d8, 0xd573, 0xc6ed, 0x4e47, 0xd60e);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vfwsub.vf v8, v4, %[A], v0.t" ::[A] "f"(fscalar_16));
  //                0.00000000, -73.75000000,  0.00000000, -3.71875000,
  //                0.00000000,  39.87500000,  0.00000000,  36.06250000,
  //                0.00000000, -97.65625000,  0.00000000,  57.06250000,
  //                0.00000000, -43.36328125,  0.00000000, -133.31250000
  VCMP_U32(7, v8, 0x0, 0xc2938000, 0x0, 0xc06e0000, 0x0, 0x421f8000, 0x0,
           0x42104000, 0x0, 0xc2c35000, 0x0, 0x42644000, 0x0, 0xc22d7400, 0x0,
           0xc3055000);

  VSET(16, e32, m2);
  float fscalar_32;
  //                              -138614.20312500
  BOX_FLOAT_IN_FLOAT(fscalar_32, 0xc8075d8d);
  //                473107.93750000,  161975.07812500, -173044.89062500,
  //                -322046.09375000, -485607.56250000, -613808.37500000,
  //                -182790.53125000,  121114.44531250, -958537.81250000,
  //                295217.40625000,  281159.84375000, -735195.87500000,
  //                -783982.56250000,  420983.65625000,  954426.12500000,
  //                -297052.53125000
  VLOAD_32(v4, 0x48e7027e, 0x481e2dc5, 0xc828fd39, 0xc89d3fc3, 0xc8ed1cf2,
           0xc915db06, 0xc83281a2, 0x47ec8d39, 0xc96a049d, 0x4890262d,
           0x488948fb, 0xc9337dbe, 0xc93f66e9, 0x48cd8ef5, 0x496903a2,
           0xc8910b91);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vfwsub.vf v8, v4, %[A], v0.t" ::[A] "f"(fscalar_32));
  //                0.0000000000000000,  300589.2812500000000000,
  //                0.0000000000000000, -183431.8906250000000000,
  //                0.0000000000000000, -475194.1718750000000000,
  //                0.0000000000000000,  259728.6484375000000000,
  //                0.0000000000000000,  433831.6093750000000000,
  //                0.0000000000000000, -596581.6718750000000000,
  //                0.0000000000000000,  559597.8593750000000000,
  //                0.0000000000000000, -158438.3281250000000000
  VCMP_U64(8, v8, 0x0, 0x411258b520000000, 0x0, 0xc106643f20000000, 0x0,
           0xc11d00e8b0000000, 0x0, 0x410fb48530000000, 0x0, 0x411a7a9e70000000,
           0x0, 0xc12234cb58000000, 0x0, 0x412113dbb8000000, 0x0,
           0xc1035732a0000000);
};
// Simple random test with similar values
void TEST_CASE5(void) {
  VSET(16, e16, m2);
  //              -92.15529633,  27.66998672,
  //              -5.68499708,  78.95133209,  57.52299500,  15.45270920,  50.26883316,
  //              46.63587189,  71.16806793, -80.68485260,
  //              -22.34193420,  40.17027283,  93.54611969,  25.86016083,  41.82838821,
  //              82.50254822
  VLOAD_32(v4, 0xc2b84f83, 0x41dd5c22, 0xc0b5eb7f, 0x429de715, 0x4266178c,
           0x41773e4c, 0x42491349, 0x423a8b22, 0x428e560d, 0xc2a15ea5,
           0xc1b2bc48, 0x4220ae5c, 0x42bb179d, 0x41cee19c, 0x42275045,
           0x42a5014e);
  //              -72.5625, -83.4375,  28.8281,  33.5938,
  //              -85.7500,  67.5000,  91.0625, -91.8750, -9.2578, -64.2500,
  //              -58.6250,  50.3438, -70.5000,  36.6250,  5.7930,  86.6875
  VLOAD_16(v6, 0xd489, 0xd537, 0x4f35, 0x5033, 0xd55c, 0x5438, 0x55b1, 0xd5be,
           0xc8a1, 0xd404, 0xd354, 0x524b, 0xd468, 0x5094, 0x45cb, 0x556b);
  asm volatile("vfwsub.wv v8, v4, v6");
  //              -19.59279633,  111.10748291, -34.51312256,  45.35758209,
  //              143.27299500, -52.04729080, -40.79366684,
  //              138.51086426,  80.42588043, -16.43485260,  36.28306580,
  //              -10.17347717,  164.04611206, -10.76483917,  36.03541946,
  //              -4.18495178
  VCMP_U32(9, v8, 0xc19cbe0c, 0x42de3708, 0xc20a0d70, 0x42356e2a, 0x430f45e3,
           0xc250306d, 0xc2232cb7, 0x430a82c8, 0x42a0da0d, 0xc1837a94,
           0x421121dc, 0xc122c690, 0x43240bce, 0xc12c3cc8, 0x42102445,
           0xc085eb20);

  VSET(16, e32, m2);
  //              -79494.9435096215456724,  81629.4152202270051930,
  //              60506.1876363231276628, -81020.4028176319407066,
  //              -6814.2587861350475578,  11974.4045779409498209,
  //              97975.7066144426062237, -93357.8779376419261098,
  //              95959.4397212496260181, -58528.4286213813902577,
  //              28958.3763895476586185, -36387.3665319164574612,
  //              -90399.7993234442838002, -78772.1006454367889091,
  //              -62854.6154750282003079,  37858.6386504948022775
  VLOAD_64(v4, 0xc0f3686f189d8b80, 0x40f3edd6a4bdf6fa, 0x40ed8b46011de3ec,
           0xc0f3c7c671f0e6b7, 0xc0ba9e423fcee2b0, 0x40c76333c935c088,
           0x40f7eb7b4e4af21e, 0xc0f6cade0c085740, 0x40f76d7709192628,
           0xc0ec940db7442fee, 0x40dc479816c42f70, 0xc0e1c46bbaa12444,
           0xc0f611fcca076142, 0xc0f33b419c3e63b8, 0xc0eeb0d3b1f8afb4,
           0x40e27c546fd32998);
  //               95822.63281250,  21789.49804688, -42409.42968750,
  //               60172.89062500, -46359.57812500, -71236.33593750,
  //               4124.35888672, -80527.00000000,  27430.70507812,
  //               39975.67578125, -71197.53125000, -66640.12500000,
  //               47459.75390625, -34899.84375000, -21371.85937500,
  //               17582.65820312
  VLOAD_32(v6, 0x47bb2751, 0x46aa3aff, 0xc725a96e, 0x476b0ce4, 0xc7351794,
           0xc78b222b, 0x4580e2df, 0xc79d4780, 0x46d64d69, 0x471c27ad,
           0xc78b0ec4, 0xc7822810, 0x473963c1, 0xc70853d8, 0xc6a6f7b8,
           0x46895d51);
  asm volatile("vfwsub.wv v8, v4, v6");
  //              -175317.5763221215456724,  59839.9171733520051930,
  //              102915.6173238231276628, -141193.2934426319552585,
  //              39545.3193388649524422,  83210.7405154409498209,
  //              93851.3477277238562237, -12830.8779376419261098,
  //              68528.7346431246260181, -98504.1044026313902577,
  //              100155.9076395476586185,  30252.7584680835425388,
  //              -137859.5532296942838002, -43872.2568954367889091,
  //              -41482.7561000282003079,  20275.9804473698022775
  VCMP_U64(10, v8, 0xc10566ac9c4ec5c0, 0x40ed37fd597bedf4, 0x40f92039e08ef1f6,
           0xc1013c4a58f8735c, 0x40e34f2a380623aa, 0x40f450abd926b811,
           0x40f6e9b5904af21e, 0xc0c90f706042ba00, 0x40f0bb0bc1192628,
           0xc0f80c81aba217f7, 0x40f873be85b10bdc, 0x40dd8b308abdb778,
           0xc100d41c6d03b0a1, 0xc0e56c08387cc770, 0xc0e4415831f8afb4,
           0x40d3ccfebfa65330);
};

// Simple random test with similar values (masked)
// The numbers are the same of TEST_CASE1
void TEST_CASE6(void) {
  VSET(16, e16, m2);
  //              -92.15529633,  27.66998672,
  //              -5.68499708,  78.95133209,  57.52299500,  15.45270920,  50.26883316,
  //              46.63587189,  71.16806793, -80.68485260,
  //              -22.34193420,  40.17027283,  93.54611969,  25.86016083,  41.82838821,
  //              82.50254822
  VLOAD_32(v4, 0xc2b84f83, 0x41dd5c22, 0xc0b5eb7f, 0x429de715, 0x4266178c,
           0x41773e4c, 0x42491349, 0x423a8b22, 0x428e560d, 0xc2a15ea5,
           0xc1b2bc48, 0x4220ae5c, 0x42bb179d, 0x41cee19c, 0x42275045,
           0x42a5014e);
  //              -72.5625, -83.4375,  28.8281,  33.5938,
  //              -85.7500,  67.5000,  91.0625, -91.8750, -9.2578, -64.2500,
  //              -58.6250,  50.3438, -70.5000,  36.6250,  5.7930,  86.6875
  VLOAD_16(v6, 0xd489, 0xd537, 0x4f35, 0x5033, 0xd55c, 0x5438, 0x55b1, 0xd5be,
           0xc8a1, 0xd404, 0xd354, 0x524b, 0xd468, 0x5094, 0x45cb, 0x556b);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vfwsub.wv v8, v4, v6, v0.t");
  //               0.00000000,  111.10748291,  0.00000000,  45.35758209,
  //               0.00000000, -52.04729080,  0.00000000,  138.51086426,
  //               0.00000000, -16.43485260,  0.00000000, -10.17347717,
  //               0.00000000, -10.76483917,  0.00000000, -4.18495178
  VCMP_U32(11, v8, 0x0, 0x42de3708, 0x0, 0x42356e2a, 0x0, 0xc250306d, 0x0,
           0x430a82c8, 0x0, 0xc1837a94, 0x0, 0xc122c690, 0x0, 0xc12c3cc8, 0x0,
           0xc085eb20);

  VSET(16, e32, m2);
  //              -79494.9435096215456724,  81629.4152202270051930,
  //              60506.1876363231276628, -81020.4028176319407066,
  //              -6814.2587861350475578,  11974.4045779409498209,
  //              97975.7066144426062237, -93357.8779376419261098,
  //              95959.4397212496260181, -58528.4286213813902577,
  //              28958.3763895476586185, -36387.3665319164574612,
  //              -90399.7993234442838002, -78772.1006454367889091,
  //              -62854.6154750282003079,  37858.6386504948022775
  VLOAD_64(v4, 0xc0f3686f189d8b80, 0x40f3edd6a4bdf6fa, 0x40ed8b46011de3ec,
           0xc0f3c7c671f0e6b7, 0xc0ba9e423fcee2b0, 0x40c76333c935c088,
           0x40f7eb7b4e4af21e, 0xc0f6cade0c085740, 0x40f76d7709192628,
           0xc0ec940db7442fee, 0x40dc479816c42f70, 0xc0e1c46bbaa12444,
           0xc0f611fcca076142, 0xc0f33b419c3e63b8, 0xc0eeb0d3b1f8afb4,
           0x40e27c546fd32998);
  //               95822.63281250,  21789.49804688, -42409.42968750,
  //               60172.89062500, -46359.57812500, -71236.33593750,
  //               4124.35888672, -80527.00000000,  27430.70507812,
  //               39975.67578125, -71197.53125000, -66640.12500000,
  //               47459.75390625, -34899.84375000, -21371.85937500,
  //               17582.65820312
  VLOAD_32(v6, 0x47bb2751, 0x46aa3aff, 0xc725a96e, 0x476b0ce4, 0xc7351794,
           0xc78b222b, 0x4580e2df, 0xc79d4780, 0x46d64d69, 0x471c27ad,
           0xc78b0ec4, 0xc7822810, 0x473963c1, 0xc70853d8, 0xc6a6f7b8,
           0x46895d51);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vfwsub.wv v8, v4, v6, v0.t");
  //               0.0000000000000000,  59839.9171733520051930,
  //               0.0000000000000000, -141193.2934426319552585,
  //               0.0000000000000000,  83210.7405154409498209,
  //               0.0000000000000000, -12830.8779376419261098,
  //               0.0000000000000000, -98504.1044026313902577,
  //               0.0000000000000000,  30252.7584680835425388,
  //               0.0000000000000000, -43872.2568954367889091,
  //               0.0000000000000000,  20275.9804473698022775
  VCMP_U64(12, v8, 0x0, 0x40ed37fd597bedf4, 0x0, 0xc1013c4a58f8735c, 0x0,
           0x40f450abd926b811, 0x0, 0xc0c90f706042ba00, 0x0, 0xc0f80c81aba217f7,
           0x0, 0x40dd8b308abdb778, 0x0, 0xc0e56c08387cc770, 0x0,
           0x40d3ccfebfa65330);
};

// Simple random test with similar values (vector-scalar)
void TEST_CASE7(void) {
  VSET(16, e16, m2);
  float fscalar_16;
  //              -8.76965809,  55.45920181,  71.29286957, -84.65414429,
  //              -81.93881226,  75.13192749, -75.44019318, -48.81898499,
  //              0.10306206, -25.18898392,  49.68006516,  72.66278076,
  //              -24.90880966, -32.59431458,  14.58876038, -55.07221603
  VLOAD_32(v4, 0xc10c5085, 0x425dd639, 0x428e95f3, 0xc2a94eec, 0xc2a3e0ac,
           0x4296438c, 0xc296e161, 0xc24346a4, 0x3dd31233, 0xc1c9830a,
           0x4246b863, 0x42915358, 0xc1c7453e, 0xc2026094, 0x41696b90,
           0xc25c49f3);
  //                              34.7812
  BOX_HALF_IN_FLOAT(fscalar_16, 0x5059);
  asm volatile("vfwsub.wf v8, v4, %[A]" ::[A] "f"(fscalar_16));
  //              -43.55090714,  20.67795181,  36.51161957, -119.43539429,
  //              -116.72006226,  40.35067749, -110.22144318, -83.60023499,
  //              -34.67818832, -59.97023392,  14.89881516,  37.88153076,
  //              -59.69005966, -67.37556458, -20.19248962, -89.85346985
  VCMP_U32(13, v8, 0xc22e3421, 0x41a56c72, 0x42120be6, 0xc2eedeec, 0xc2e970ac,
           0x42216718, 0xc2dc7161, 0xc2a73352, 0xc20ab677, 0xc26fe185,
           0x416e618c, 0x421786b0, 0xc26ec29f, 0xc286c04a, 0xc1a18a38,
           0xc2b3b4fa);

  VSET(16, e32, m2);
  float fscalar_32;
  //               322189.5706008458510041,  914899.9451866354793310,
  //               -620811.0881863175891340, -456926.2657179111847654,
  //               -549945.8717311944346875, -386814.9759888321859762,
  //               748677.5319772073999047,  821298.7777016961481422,
  //               968861.0598710167687386, -343694.5546012039994821,
  //               -782815.4022130169905722, -561429.7869165195152164,
  //               755371.9691831718664616, -954868.1761190977413207,
  //               -606267.0986005428712815,  818185.4808380266185850
  VLOAD_64(v4, 0x4113aa36484b9690, 0x412beba7e3ef80b0, 0xc122f2162d26c1cc,
           0xc11be37910185b2a, 0xc120c873be538d16, 0xc1179bfbe7699dce,
           0x4126d90b105f5108, 0x412910658e2eeaae, 0x412d913a1ea769f6,
           0xc114fa3a37e960c6, 0xc127e3becdeedd54, 0xc121222b92e6b8d8,
           0x41270d57f038c6d6, 0xc12d23e85a2c484a, 0xc1228076327bc536,
           0x4128f812f63066de);
  //                              -83388.08593750
  BOX_FLOAT_IN_FLOAT(fscalar_32, 0xc7a2de0b);
  asm volatile("vfwsub.wf v8, v4, %[A]" ::[A] "f"(fscalar_32));
  //               405577.6565383458510041,  998288.0311241354793310,
  //               -537423.0022488175891340, -373538.1797804111847654,
  //               -466557.7857936944346875, -303426.8900513321859762,
  //               832065.6179147073999047,  904686.8636391961481422,
  //               1052249.1458085167687386, -260306.4686637039994821,
  //               -699427.3162755169905722, -478041.7009790195152164,
  //               838760.0551206718664616, -871480.0901815977413207,
  //               -522879.0126630428712815,  901573.5667755266185850
  VCMP_U64(14, v8, 0x4118c126a04b9690, 0x412e77200fef80b0, 0xc120669e0126c1cc,
           0xc116cc88b8185b2a, 0xc11c79f724a71a2c, 0xc112850b8f699dce,
           0x412964833c5f5108, 0x412b9bddba2eeaae, 0x41300e592553b4fb,
           0xc10fc693bfd2c18c, 0xc1255846a1eedd54, 0xc11d2d66cdcd71b0,
           0x412998d01c38c6d6, 0xc12a98702e2c484a, 0xc11fe9fc0cf78a6c,
           0x412b838b223066de);
};

// Simple random test with similar values (vector-scalar) (masked)
void TEST_CASE8(void) {
  VSET(16, e16, m2);
  float fscalar_16;
  //               -8.76965809,  55.45920181,  71.29286957, -84.65414429,
  //               -81.93881226,  75.13192749, -75.44019318, -48.81898499,
  //               0.10306206, -25.18898392,  49.68006516,  72.66278076,
  //               -24.90880966, -32.59431458,  14.58876038, -55.07221603
  VLOAD_32(v4, 0xc10c5085, 0x425dd639, 0x428e95f3, 0xc2a94eec, 0xc2a3e0ac,
           0x4296438c, 0xc296e161, 0xc24346a4, 0x3dd31233, 0xc1c9830a,
           0x4246b863, 0x42915358, 0xc1c7453e, 0xc2026094, 0x41696b90,
           0xc25c49f3);
  //                              34.7812
  BOX_HALF_IN_FLOAT(fscalar_16, 0x5059);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vfwsub.wf v8, v4, %[A], v0.t" ::[A] "f"(fscalar_16));
  //                0.00000000,  20.67795181,  0.00000000, -119.43539429,
  //                0.00000000,  40.35067749,  0.00000000, -83.60023499,
  //                0.00000000, -59.97023392,  0.00000000,  37.88153076,
  //                0.00000000, -67.37556458,  0.00000000, -89.85346985
  VCMP_U32(15, v8, 0x0, 0x41a56c72, 0x0, 0xc2eedeec, 0x0, 0x42216718, 0x0,
           0xc2a73352, 0x0, 0xc26fe185, 0x0, 0x421786b0, 0x0, 0xc286c04a, 0x0,
           0xc2b3b4fa);

  VSET(16, e32, m2);
  float fscalar_32;
  //                322189.5706008458510041,  914899.9451866354793310,
  //                -620811.0881863175891340, -456926.2657179111847654,
  //                -549945.8717311944346875, -386814.9759888321859762,
  //                748677.5319772073999047,  821298.7777016961481422,
  //                968861.0598710167687386, -343694.5546012039994821,
  //                -782815.4022130169905722, -561429.7869165195152164,
  //                755371.9691831718664616, -954868.1761190977413207,
  //                -606267.0986005428712815,  818185.4808380266185850
  VLOAD_64(v4, 0x4113aa36484b9690, 0x412beba7e3ef80b0, 0xc122f2162d26c1cc,
           0xc11be37910185b2a, 0xc120c873be538d16, 0xc1179bfbe7699dce,
           0x4126d90b105f5108, 0x412910658e2eeaae, 0x412d913a1ea769f6,
           0xc114fa3a37e960c6, 0xc127e3becdeedd54, 0xc121222b92e6b8d8,
           0x41270d57f038c6d6, 0xc12d23e85a2c484a, 0xc1228076327bc536,
           0x4128f812f63066de);
  //                              -83388.08593750
  BOX_FLOAT_IN_FLOAT(fscalar_32, 0xc7a2de0b);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v8);
  asm volatile("vfwsub.wf v8, v4, %[A], v0.t" ::[A] "f"(fscalar_32));
  //                0.0000000000000000,  998288.0311241354793310,
  //                0.0000000000000000, -373538.1797804111847654,
  //                0.0000000000000000, -303426.8900513321859762,
  //                0.0000000000000000,  904686.8636391961481422,
  //                0.0000000000000000, -260306.4686637039994821,
  //                0.0000000000000000, -478041.7009790195152164,
  //                0.0000000000000000, -871480.0901815977413207,
  //                0.0000000000000000,  901573.5667755266185850
  VCMP_U64(16, v8, 0x0, 0x412e77200fef80b0, 0x0, 0xc116cc88b8185b2a, 0x0,
           0xc112850b8f699dce, 0x0, 0x412b9bddba2eeaae, 0x0, 0xc10fc693bfd2c18c,
           0x0, 0xc11d2d66cdcd71b0, 0x0, 0xc12a98702e2c484a, 0x0,
           0x412b838b223066de);
};

int main(void) {
  enable_vec();
  enable_fp();

  TEST_CASE1();
  TEST_CASE2();
  TEST_CASE3();
  TEST_CASE4();

  TEST_CASE5();
  TEST_CASE6();
  TEST_CASE7();
  TEST_CASE8();

  EXIT_CHECK();
}
