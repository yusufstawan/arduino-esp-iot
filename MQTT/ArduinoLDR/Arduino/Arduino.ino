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
    Serial.print("Lampu Menyala");
    Serial.write('\0');
    delay(1000);
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.print("Lampu Mati");
    Serial.write('\0');
    delay(1000);
  }
}
