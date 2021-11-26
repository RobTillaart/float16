//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-11-26
// PURPOSE: unit tests for the float16 data type
//          https://github.com/RobTillaart/float16
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)


#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "float16.h"


unittest_setup()
{
}


unittest_teardown()
{
}


unittest(test_constructor)
{
  fprintf(stderr, "FLOAT16_LIB_VERSION: %s\n", (char*) FLOAT16_LIB_VERSION);

  float16 zero;
  assertEqualFloat(0.000, zero.toDouble(), 1e-2);
  float16 one(1);
  assertEqualFloat(1.000, one.toDouble(), 1e-2);

  float16 e(exp(1));
  assertEqualFloat(1.000, ( 2.7183 / e.toDouble()), 1e-2);
  float16 pie(PI);
  assertEqualFloat(1.000, (3.142 / pie.toDouble()), 1e-2);

  float goldenRatio = 1.61803398875;
  float16 gr(goldenRatio);
  assertEqualFloat(1.000, (goldenRatio / gr.toDouble()), 1e-2);
  float16 minusOne(-1);
  assertEqualFloat(1.000, (-1 / minusOne.toDouble()), 1e-2);

  // NAN constructor
  float16 nanny(1.0/0.0);
  assertNAN(nanny.toDouble());

  // Overflow constructor
  float16 big(1e6);
  assertNAN(big.toDouble());

  float16 bag(-1e6);
  assertNAN(bag.toDouble());
  
  float16 small(1e-30);
  assertEqualFloat(0.0, small.toDouble(), 1e-3);
}


unittest(test_comparisons)
{
  fprintf(stderr, "FLOAT16_LIB_VERSION: %s\n", (char*) FLOAT16_LIB_VERSION);

}


unittest(test_conversion)
{
  fprintf(stderr, "FLOAT16_LIB_VERSION: %s\n", (char*) FLOAT16_LIB_VERSION);

  for (int i = 0; i < 20; i++)
  {
    float f = random(60000000) * 0.001;
    float16 f16(f);
    assertEqualFloat(1, (f / f16.toDouble()), 1e-3);
  }
}


unittest_main()


// -- END OF FILE --
