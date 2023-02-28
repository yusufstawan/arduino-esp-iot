const int button = 7;
const int led = 8;
int status = 0;

const int numLED = 6;
int totalloop = 0;
// dengaan alamat index 0,1,2,3
const int pinLED[numLED] = {8, 9, 10, 11, 12, 13};

void setup()
{
  pinMode(pinLED, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{

  status = digitalRead(button);

  if (status == HIGH)
  {
    digitalWrite(pinLED[0], HIGH);
    // digitalWrite(pinLED[3], HIGH);
    Serial.println(status);
  }
  else
  {
    digitalWrite(pinLED[0], LOW);
    // digitalWrite(pinLED[3], LOW);
    Serial.println(status);
  }
}
