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

  if (val < 50)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("Lampu menyala");
    delay(1000);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("Lampu mati");
    delay(1000);
  }
}
