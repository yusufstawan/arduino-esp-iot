const int pinLED = 8;

void setup()
{
  pinMode(pinLED, OUTPUT);
}

int timeDelay = 1000;

void loop()
{
  while (timeDelay > 0)
  {
    digitalWrite(pinLED, HIGH);
    delay(500);
    digitalWrite(pinLED, LOW);
    delay(500);

    timeDelay = timeDelay - 100;
  }

  while (timeDelay < 1000)
  {
    digitalWrite(pinLED, HIGH);
    delay(100);
    digitalWrite(pinLED, LOW);
    delay(100);

    timeDelay = timeDelay + 100;
  }
}
