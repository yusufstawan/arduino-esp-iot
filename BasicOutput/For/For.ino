const int pinLED = 8;

void setup()
{
  pinMode(pinLED, OUTPUT);
}

int timeDelay = 3000;

void loop()
{
  for (int i = 1; i <= 10; i++)
  {
    digitalWrite(pinLED, HIGH);
    delay(500);
    digitalWrite(pinLED, LOW);
    delay(500);
  }
  delay(timeDelay);
}
