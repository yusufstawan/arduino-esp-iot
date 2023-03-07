/*********************************
 * Output : Led
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * DATA : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
 *********************************/

const int pinLed = 8;

void setup()
{
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  digitalWrite(pinLed, HIGH);
  delay(1000);
  digitalWrite(pinLed, LOW);
  delay(1000);
}
