//
//    FILE: float16_test_performance.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: test float16
//    DATE: 2021-11-26
//     URL: https://github.com/RobTillaart/float16
//

// TO ELABORATE

#include "float16.h"

uint32_t start, stop;
volatile float f;


void setup()
{
  while (!Serial);
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("FLOAT16_LIB_VERSION: ");
  Serial.println(FLOAT16_LIB_VERSION);
  Serial.println("\nStart ");

  f = random(1000000) * 0.001;

  start = micros();
  float16 f16(f);
  stop = micros();
  Serial.print("Constructor: \t");
  Serial.println(stop - start);
  delay(10);

  start = micros();
  f = f16.toDouble();
  stop = micros();
  Serial.print("toDouble(): \t");
  Serial.println(stop - start);
  delay(10);

  Serial.println("\ndone");
}


void loop()
{
}


// -- END OF FILE --
