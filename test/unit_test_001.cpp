//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-11-26
// PURPOSE: unit tests for the float16 data type
//          https://github.com/RobTillaart/float16
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//


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
  assertEqualFloat(1.000, zero.toDouble(), 1e-2);

  float16 e(exp(1));
  assertEqualFloat(2.782, e.toDouble(), 1e-2);
  float16 pie(PI);
  assertEqualFloat(3.142, pie.toDouble(), 1e-2);

  float16 gr(1.61803398875);    // golden ratio
  assertEqualFloat(1.618, gr.toDouble(), 1e-2);
  float16 minusOne(-1);
  assertEqualFloat(-1.00, minusOne.toDouble(), 1e-2);

  // TODO overflow and NAN constructors?
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
    assertEqualFloat(1, (f / f16.toDouble()), 1e-2);
  }
}


unittest_main()


// -- END OF FILE --
