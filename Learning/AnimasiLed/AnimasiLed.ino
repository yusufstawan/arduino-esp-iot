const int pinLED = 8;

void setup()
{
  pinMode(pinLED, OUTPUT);
}

int timeDelay = 1000;

void loop()
{
  timeDelay = timeDelay - 100;

  if (timeDelay <= 0)
  {
    timeDelay = 1000;
  }

  digitalWrite(pinLED, HIGH);
  delay(timeDelay);
  digitalWrite(pinLED, LOW);
  delay(timeDelay);
}
