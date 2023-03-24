#define sensorPin A0
#define ledPin 8

int val = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
}

void loop()
{
  int val = analogRead(sensorPin);

  if (val > 300)
  {
    digitalWrite(ledPin, HIGH);
    Serial.print("Terjadi Banjir - Lampu Menyala");
    Serial.write('\0');
    delay(1000);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.print("Aman - Lampu Mati");
    Serial.write('\0');
    delay(1000);
  }
}
