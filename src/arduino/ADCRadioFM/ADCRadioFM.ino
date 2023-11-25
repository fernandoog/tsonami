#include <Wire.h>
#include <si5351.h>
#include "heltec.h"

Si5351 si5351;

const int modulationPin = 34;  // Pin analógico para la señal de modulación

// We will output 100 kHz on CLK0 and CLK1.
// A PLLA frequency of 98.5 MHz was chosen to give an even
// divisor by 14.1 MHz.
unsigned long long pll_freq = 985000000ULL;
unsigned long long freq = 1000000ULL;


void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);

  // Start serial and initialize the Si5351
  Serial.begin(115200);


  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);

  bool i2c_found;
  i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
  if (!i2c_found) {
    Serial.println("Device not found on I2C bus!");
  }

  // Set CLK0 and CLK1 to output 100 kHz with a fixed PLL frequency
  si5351.set_freq_manual(freq, pll_freq, SI5351_CLK0);

  delay(500);
}

void loop() {

  // Leer el valor de la señal de modulación
  int analogValue = analogRead(modulationPin);

  // Calcular la frecuencia modulada
  float modulationFrequency = map(analogValue, 0, 4096, -50000, 50000);  // Ajusta según sea necesario
                                                                         // Frecuencia de la portadora en Hz
  float frequency = 98500000 + modulationFrequency;

  // Modificar la frecuencia de la portadora
  si5351.set_freq_manual(frequency, pll_freq, SI5351_CLK0);

  // Display
  Heltec.display->drawLine(analogValue, analogValue * -1, analogValue * -1, analogValue);
  Heltec.display->display();
}
