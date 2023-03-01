byte sda = 10;
byte rst = 9;
#include <KRrfid.h>

void setup()
{
  Serial.begin(9600);
  rfidBegin();
}

void loop()
{
  getTAG();
  if (TAG != "")
  {
    Serial.print("TAG :");
    Serial.println(TAG);
    TAG = "";
  }
}
