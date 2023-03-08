/*********************************
 * Sensor : Relay 1 Channel
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * S      : 6
 *********************************/

int RelayPin = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(RelayPin, OUTPUT);
}

void loop()
{
  digitalWrite(RelayPin, LOW);
  Serial.println("Relay ON");
  delay(3000);

  digitalWrite(RelayPin, HIGH);
  Serial.println("Relay OFF");
  delay(3000);
}
