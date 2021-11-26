//
//    FILE: float16_test1.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: test float16
//    DATE: 2015-03-11
//     URL: https://github.com/RobTillaart/float16
//

#include "float16.h"

float16 X;

uint32_t start;
uint32_t stop;


void setup()
{
  Serial.begin(115200);
  Serial.println("Start ");

  float f;

  for (uint16_t n = 0; n < 65535; n++)
  {
    f = X.f16tof32(n);
    Serial.print(n);
    Serial.print('\t');
    Serial.println(f, 6);
  }
  Serial.println("done");
}


void loop()
{
}


// -- END OF FILE --


