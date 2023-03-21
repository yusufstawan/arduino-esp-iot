int led = 6;
int ldr = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
}

void loop()
{
  int cahaya = analogRead(ldr);

  if (cahaya < 50)
  {
    digitalWrite(led, HIGH);
    Serial.println("Lampu menyala");
    delay(1000);
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println("Lampu mati");
    delay(1000);
  }
}
