/*********************************
 * Pengukuran jarak dengan sensor ultrasonic
 * Sensor : HC-SR04
 * Board  : ESP32
 * Output : Serial (9600)
 * Trig   : D23, D22, TX0, RX0, D21, D19, D18, D5, TX2, RX2, D4, D2, D15, D13, D12, D14, D27, D26, D25, D33, D32, D35, D34, VN, VP
 * Echo   : D23, D22, TX0, RX0, D21, D19, D18, D5, TX2, RX2, D4, D2, D15, D13, D12, D14, D27, D26, D25, D33, D32, D35, D34, VN, VP
 *********************************/

#define TRIG_PIN 23 // ESP32 pin GIOP23 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 22 // ESP32 pin GIOP22 connected to Ultrasonic Sensor's ECHO pin

float duration_us, distance_cm;

void setup()
{
  // begin serial port
  Serial.begin(9600);

  // configure the trigger pin to output mode
  pinMode(TRIG_PIN, OUTPUT);
  // configure the echo pin to input mode
  pinMode(ECHO_PIN, INPUT);
}

void loop()
{
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
