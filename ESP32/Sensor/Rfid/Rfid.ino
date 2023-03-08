/*********************************
 * Membaca Tag RFID
 * Sensor : RFID-RC522
 * Board  : ESP32
 * Output : Serial (9600)
 * SDA    : 21
 * RST    : 27
 * MOSI   : 23
 * MISO   : 19
 * SCK    : 18
 * GND    : GND
 * 3.3V   : 3.3V
 *********************************/

byte sda = 21;
byte rst = 27;
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
