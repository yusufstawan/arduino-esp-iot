/*********************************
 * Output : Buzzer
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * DATA : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
 *********************************/

const int pinBuzzer = 8;

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
