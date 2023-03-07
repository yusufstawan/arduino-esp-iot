/*********************************
 * Output : RGB Module
 * Board  : Arduino UNO
 * pin can use : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
 *********************************/

int redpin = 9;    // R
int greenpin = 10; // G
int bluepin = 11;  // B
int val;

void setup()
{
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  for (val = 255; val > 0; val--)
  {
    analogWrite(11, val);
    analogWrite(10, 255 - val);
    analogWrite(9, 128 - val);
    Serial.println(val, DEC);
    delay(5);
  }
  for (val = 0; val < 255; val++)
  {
    analogWrite(11, val);
    analogWrite(10, 255 - val);
    analogWrite(9, 128 - val);

    Serial.println(val, DEC);
    delay(5);
  }
}
