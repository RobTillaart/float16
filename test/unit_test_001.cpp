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
  fprintf(stderr, "FLOAT16_LIB_VERSION: %s\n", (char*) FLOAT16_LIB_VERSION);
}


unittest_teardown()
{
}


unittest(test_constructor)
{
  float16 zero;
  assertEqualFloat(0.000, zero.toDouble(), 1e-3);
  float16 one(1);
  assertEqualFloat(1.000, one.toDouble(), 1e-3);

  float16 e(exp(1));
  assertEqualFloat(1.000, ( 2.7183 / e.toDouble()), 1e-3);
  float16 pie(PI);
  assertEqualFloat(1.000, (3.142 / pie.toDouble()), 1e-3);

  float goldenRatio = 1.61803398875;
  float16 gr(goldenRatio);
  assertEqualFloat(1.000, (goldenRatio / gr.toDouble()), 1e-3);

  float16 minusOne(-1);
  // fprintf(stderr, "MINUSONE: %f\n", minusOne.toDouble());
  assertEqualFloat(1.000, (-1 / minusOne.toDouble()), 1e-3);

  //  TODO
  //  NAN constructor how to test
  //  float16 nanny(1.0/0.0);
  //  assertNAN(nanny.toDouble());

  // Overflow constructor
  float16 big(1e6);
  assertInfinity(big.toDouble());

  float16 bag(-1e6);
  assertInfinity(bag.toDouble());

  float16 small(1e-30);
  assertEqualFloat(0.0, small.toDouble(), 1e-3);
  float16 smaller(-1e-30);
  assertEqualFloat(0.0, smaller.toDouble(), 1e-3);
}


unittest(test_compare_equal)
{
  float16 a(1);
  float16 b(1);
  float16 c(2);
  float16 d(-1);

  assertTrue(a == a);
  assertTrue(a == b);
  assertFalse(a == c);
  assertFalse(a == d);

  fprintf(stderr, "\n");
  assertFalse(a != a);
  assertFalse(a != b);
  assertTrue(a != c);
  assertTrue(a != d);
}


unittest(test_compare_1nequal)
{
  float16 a(1);
  float16 b(1);
  float16 c(2);
  float16 d(-2);

  assertFalse(a < a);
  assertTrue(a <= b);
  assertFalse(a > b);
  assertTrue(a >= a);

  fprintf(stderr, "\n");
  assertTrue(a < c);
  assertTrue(a <= c);
  assertFalse(a > c);
  assertFalse(a >= c);

  fprintf(stderr, "\n");
  assertFalse(a < d);
  assertFalse(a <= d);
  assertTrue(a > d);
  assertTrue(a >= d);
}


unittest(test_negation)
{
  float16 f16(123.456);
  float16 f17(-f16);
  float16 f18 = -f16;

  assertEqualFloat(-123.456, f17.toDouble(), 1e-1);
  assertEqualFloat(-123.456, f18.toDouble(), 1e-1);
}


unittest(test_conversion)
{
  for (int i = 0; i < 20; i++)
  {
    float f = random(60000000) * 0.001;
    float16 f16(f);
    assertEqualFloat(1, (f / f16.toDouble()), 1e-3);
  }
}


unittest(test_printable)
{
  float16 f16(123.456);
  // test default value.
  assertEqual(4, f16.getDecimals());
  for (int i = 0; i < 6; i++)
  {
    f16.setDecimals(i);
    assertEqual(i, f16.getDecimals());
  }

  //  TODO
  // printable? how to test?
}


unittest_main()


// -- END OF FILE --
