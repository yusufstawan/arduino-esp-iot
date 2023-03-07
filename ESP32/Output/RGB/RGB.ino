/*********************************
 * Output : RGB Module
 * Board  : Arduino UNO
 * pin can use : D15 (GPIO 15), D2 (GPIO 2), D4 (GPIO 4), RX2 (GPIO 16), TX2 (GPIO 17), D5 (GPIO 5), D18 (GPIO 18),
 *               D19 (GPIO 19), D21 (GPIO 21), RX0 (GPIO 3), TX0 (GPIO 1), D22 (GPIO 22), D23 (GPIO 23)
 *               D13 (GPIO 13), D12 (GPIO 12), D14 (GPIO 14), D27 (GPIO 27), D26 (GPIO 26), D25 (GPIO 25),
 *               D33 (GPIO 33), D32 (GPIO 32), D35 (GPIO 35), D34 (GPIO 34), D39 (GPIO 39), VP (GPIO 36),
 *********************************/

#define PIN_RED 15
#define PIN_GREEN 2
#define PIN_BLUE 4

void setup()
{
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop()
{
  // color code #00C9CC (R = 0,   G = 201, B = 204)
  analogWrite(PIN_RED, 0);
  analogWrite(PIN_GREEN, 201);
  analogWrite(PIN_BLUE, 204);

  delay(1000); // keep the color 1 second

  // color code #F7788A (R = 247, G = 120, B = 138)
  analogWrite(PIN_RED, 247);
  analogWrite(PIN_GREEN, 120);
  analogWrite(PIN_BLUE, 138);

  delay(1000); // keep the color 1 second

  // color code #34A853 (R = 52,  G = 168, B = 83)
  analogWrite(PIN_RED, 52);
  analogWrite(PIN_GREEN, 168);
  analogWrite(PIN_BLUE, 83);

  delay(1000); // keep the color 1 second
}
