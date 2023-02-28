void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.print("Analog = ");
  Serial.println(sensorValue);
  Serial.print("Voltage = ");
  Serial.print(voltage);
  Serial.println(" Volt");
  delay(1000);
}
