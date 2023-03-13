int led = 6;  // pin led
int ldr = A0; // pin sensor cahaya

void setup()
{
  Serial.begin(9600);   // inisialisasi serial
  pinMode(led, OUTPUT); // pin led sebagai output
  pinMode(ldr, INPUT);  // pin sensor cahaya sebagai input
}

void loop()
{
  int cahaya = analogRead(ldr); // baca nilai sensor cahaya
  Serial.println(cahaya);       // tampilkan nilai sensor cahaya

  if (cahaya < 50)
  {                          // jika nilai sensor cahaya kurang dari 50
    digitalWrite(led, HIGH); // led menyala
  }
  else
  {                         // jika nilai sensor cahaya lebih dari 50
    digitalWrite(led, LOW); // led mati
  }
}
