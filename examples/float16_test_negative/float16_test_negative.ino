//
//    FILE: float16_test_negative.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: test float16
//    DATE: 2021-11-26
//     URL: https://github.com/RobTillaart/float16
//

#include "float16.h"


void setup()
{
  Serial.begin(115200);
  Serial.println("Start ");

  float16 f16(-1);
  Serial.println(f16.toDouble(), 4);

  Serial.println("done");
}


void loop()
{
}


// -- END OF FILE --
