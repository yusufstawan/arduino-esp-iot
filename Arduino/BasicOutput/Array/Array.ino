// Free Ebook Arduino
// www.elangsakti.com
// coder elangsakti
// Inisialisasi Jumlah LED
const int numLED = 6;
int totalloop = 0;
// LED 1,2,3,&4 jadi 1 varibel
// dengaan alamat index 0,1,2,3
const int pinLED[numLED] = {8, 9, 10, 11, 12, 13};
void setup()
{
  // Inisialisasi semua pin LED sebagai OUTPUT
  for (int i = 0; i < numLED; i++)
  {
    pinMode(pinLED[i], OUTPUT);
  }
}
void loop()
{
  // Matikan semua LED
  for (int i = 0; i < numLED; i++)
  {
    // digitalWrite(pinLED[i], LOW);
    if (i % 3 == 0) // merah
    {
      if (totalloop % 5 == 0 || totalloop % 5 == 1)
      {
        digitalWrite(pinLED[i], HIGH);
      }
      else
      {
        digitalWrite(pinLED[i], LOW);
      }
    }
    else if (i % 3 == 1) // hijau
    {
      if (totalloop % 5 == 3 || totalloop % 5 == 4)
      {
        digitalWrite(pinLED[i], HIGH);
      }
      else
      {
        digitalWrite(pinLED[i], LOW);
      }
    }
    else // kuning
    {
      if (totalloop % 5 == 2)
      {
        digitalWrite(pinLED[i], HIGH);
      }
      else
      {
        digitalWrite(pinLED[i], LOW);
      }
    }
  }
  totalloop++;
  delay(1000);

  // Hidupkan semua LED bertahap dg jeda 1 detik
  // for (int i = 0; i < 4; i++)
  // {
  //   if (i % 2 == 0)
  //   {
  //     digitalWrite(pinLED[i], HIGH);
  //   }
  //   else
  //   {
  //     digitalWrite(pinLED[i], LOW);
  //   }
  //   delay(1000);
  // }
}
