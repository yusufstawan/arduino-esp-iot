const int pinLED = 8;

void setup()
{
  pinMode(pinLED, OUTPUT);
}

int timeDelay = 1000;

void loop()
{
  if (timeDelay <= 100)
  {
    delay(3000);
    timeDelay = 1000;
  }
  else
  {
    timeDelay = timeDelay - 100;
  }

  digitalWrite(pinLED, HIGH);
  delay(timeDelay);
  digitalWrite(pinLED, LOW);
  delay(timeDelay);
}
