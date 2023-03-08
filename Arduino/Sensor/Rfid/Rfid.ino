/*********************************
 * Membaca Tag RFID
 * Sensor : RFID-RC522
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * SDA    : 10
 * RST    : 9
 * MOSI   : 11
 * MISO   : 12
 * SCK    : 13
 * GND    : GND
 * 3.3V   : 3.3V
 *********************************/

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
    delay(500);
  }
}
