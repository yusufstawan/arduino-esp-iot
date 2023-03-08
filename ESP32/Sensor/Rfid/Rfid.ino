/*********************************
 * Membaca Tag RFID
 * Sensor : RFID-RC522
 * Board  : ESP32
 * Output : Serial (9600)
 * SDA    : D21
 * RST    : D27
 * MOSI   : D23
 * MISO   : D19
 * SCK    : D18
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
