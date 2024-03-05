//
//    FILE: float16_issue_10.ino
//  AUTHOR: alecelular, Rob Tillaart
// PURPOSE: test float16
//     URL: https://github.com/RobTillaart/float16/issues/10


#include "float16.h"

// Error -> 32760 / 32767

float16 f16;

void setup()
{
  delay(500);
  Serial.begin(115200);
  while (!Serial) delay(1);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("FLOAT16_LIB_VERSION: ");
  Serial.println(FLOAT16_LIB_VERSION);

  f16.setDecimals(6);

  for (uint32_t x = 32750; x < 32770; x++)
  // for (uint32_t x = 8175; x < 8205; x++)
  {
    f16 = x;
    Serial.print(x);
    Serial.print("\t");
    Serial.print(f16);
    Serial.print("\t");
    Serial.print(f16.toDouble(), 2);
    Serial.print("\t");
    Serial.println();
    yield();
  }

  f16.setBinary(0x7800);
  Serial.print(f16.toDouble(), 2);
  Serial.println("\ndone");
}

void loop()
{
}

//  -- END OF FILE --
