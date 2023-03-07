/*********************************
 * Output : Buzzer
 * Board  : ESP32
 * Output : Serial (9600)
 * DATA   :   D15 (GPIO 15), D2 (GPIO 2), D4 (GPIO 4), RX2 (GPIO 16), TX2 (GPIO 17), D5 (GPIO 5), D18 (GPIO 18),
 *            D19 (GPIO 19), D21 (GPIO 21), RX0 (GPIO 3), TX0 (GPIO 1), D22 (GPIO 22), D23 (GPIO 23)
 *            D13 (GPIO 13), D12 (GPIO 12), D14 (GPIO 14), D27 (GPIO 27), D26 (GPIO 26), D25 (GPIO 25),
 *            D33 (GPIO 33), D32 (GPIO 32), D35 (GPIO 35), D34 (GPIO 34), D39 (GPIO 39), VP (GPIO 36),
 *********************************/

const int pinBuzzer = 15;

void setup()
{
  pinMode(pinBuzzer, OUTPUT);
}

void loop()
{
  digitalWrite(pinBuzzer, HIGH);
  delay(1000);
  digitalWrite(pinBuzzer, LOW);
  delay(1000);
}
