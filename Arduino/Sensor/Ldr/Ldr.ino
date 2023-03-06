/*********************************
 * Sensor : LDR (Light Dependant Resistor)
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * Analog : A0, A1, A2, A3, A4, A5
 * Recommended pin use: A0
 *********************************/

const int pin_ldr = A0;
// const int pin_ldr = A1;
// const int pin_ldr = A2;
// const int pin_ldr = A3;
// const int pin_ldr = A4;
// const int pin_ldr = A5;

void setup()
{
  Serial.begin(9600); // Inisialisasi monitor serial
}

void loop()
{
  int nilai = analogRead(pin_ldr); // Membaca nilai analog dari pin A0
  // Mengkonversi nilai analog tegangan menggunakan ADC
  // ADC memiliki resolusi 10bit, sehingga dapat mewakili 2 ^ 10 = 1024
  float tegangan_hasil = 5.0 * nilai / 1024;
  // Catatan: Ini adalah konversi D-to-A
  // Mencetak hasil pada monitor serial
  Serial.print("Vout =");
  Serial.print(tegangan_hasil);
  Serial.println("V");
  delay(2000); // jeda selama dua detik
}
