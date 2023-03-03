/*********************************
 * Sensor : Servo
 * Board  : ESP32
 * Output : Serial (9600)
 * Kabel Orange : D23, D22, TX0, RX0, D21, D19, D18, D5, TX2, RX2, D4, D2, D15, D13, D12, D14, D27, D26, D25, D33, D32, D35, D34, VN, VP
 *********************************/

#include <ESP32_Servo.h>

#define SERVO_PIN 13 // ESP32 pin D13 connected to servo motor

Servo servoMotor;

void setup()
{
  servoMotor.attach(SERVO_PIN); // attaches the servo on ESP32 pin
}

void loop()
{
  // rotates from 0 degrees to 180 degrees
  for (int pos = 0; pos <= 180; pos += 1)
  {
    // in steps of 1 degree
    servoMotor.write(pos);
    delay(15); // waits 15ms to reach the position
  }

  // rotates from 180 degrees to 0 degrees
  for (int pos = 180; pos >= 0; pos -= 1)
  {
    servoMotor.write(pos);
    delay(15); // waits 15ms to reach the position
  }
}
