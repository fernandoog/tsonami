
#include "si5351.h"
#include "Wire.h"

Si5351 si5351;

void setup()
{
  bool i2c_found;

  // Start serial and initialize the Si5351
  Serial.begin(57600);
  i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
  if(!i2c_found)
  {
    Serial.println("Device not found on I2C bus!");
  }

  // Set CLK0 to output 14 MHz
  si5351.set_freq(1400000000ULL, SI5351_CLK0);

  // Set CLK1 to output 175 MHz
  si5351.set_ms_source(SI5351_CLK1, SI5351_PLLB);
  si5351.set_freq_manual(17500000000ULL, 70000000000ULL, SI5351_CLK1);

  // Query a status update and wait a bit to let the Si5351 populate the
  // status flags correctly.
  si5351.update_status();
  delay(500);
}

void loop()
{
  // Read the Status Register and print it every 10 seconds
  si5351.update_status();
  Serial.print("SYS_INIT: ");
  Serial.print(si5351.dev_status.SYS_INIT);
  Serial.print("  LOL_A: ");
  Serial.print(si5351.dev_status.LOL_A);
  Serial.print("  LOL_B: ");
  Serial.print(si5351.dev_status.LOL_B);
  Serial.print("  LOS: ");
  Serial.print(si5351.dev_status.LOS);
  Serial.print("  REVID: ");
  Serial.println(si5351.dev_status.REVID);

  delay(10000);
  generateTone(1000, 500);
}

void generateTone(uint32_t frequency, uint32_t duration) {
  uint32_t carrierFrequency = frequency * 1000UL;  // Convertir a Hz y ajustar según sea necesario
  uint32_t modulationIndex = 75000UL;  // Desviación de frecuencia: 75 kHz (ajustar según sea necesario)

  for (unsigned long t = 0; t < duration * 1000UL; t += 1000UL) {  // Generar la onda cuadrada durante la duración especificada
    uint32_t fmFrequency = carrierFrequency + modulationIndex * sin(2 * PI * frequency * t / 1000000UL);

    // Configurar la frecuencia de salida del SI5351

      si5351.set_freq_manual(fmFrequency, fmFrequency, SI5351_CLK1);

  }
}
