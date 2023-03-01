const int pin_ldr = A0;

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
