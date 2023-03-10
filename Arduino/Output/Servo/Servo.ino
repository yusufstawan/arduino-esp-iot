/*********************************
 * Sensor : Servo
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * Kabel Orange : 3, 5, 6, 9, 10, 11
 *********************************/

// library Servo
#include <Servo.h>

Servo myservo;
void setup()
{
  myservo.attach(9); // servo terhubung pin 9
}

void loop()
{
  // sudut 0
  myservo.write(0);
  delay(2000);
  // sudut 90
  myservo.write(90);
  delay(2000);
  // sudut 180
  myservo.write(180);
  delay(2000);
}
