const int button = 2;
const int led = 3;
int status = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{

  status = digitalRead(button);

  if (status == HIGH)
  {
    digitalWrite(led, HIGH);
    Serial.println(status);
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println(status);
  }
}
