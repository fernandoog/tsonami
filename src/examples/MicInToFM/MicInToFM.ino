#include "si5351.h"

Si5351 si5351;

const int adcPin = 32;  // Puerto analógico donde está conectado el micrófono

void setup() {
  // Initialize Si5351
  si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);

  // Additional setup code...
  bool i2c_found;

  // Start serial and initialize the Si5351
  Serial.begin(57600);

  i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
  if (!i2c_found) {
    Serial.println("Device not found on I2C bus!");
  }
}

void loop() {

  // Modulate the Si5351 frequency based on the audio input
  uint32_t carrierFrequency = audioValue * 1000UL;  // Convertir a Hz y ajustar según sea necesario
  uint32_t modulationIndex = 75000UL;               // Desviación de frecuencia: 75 kHz (ajustar según sea necesario)
  uint32_t duration = 1000;
  // Read audio input from the microphone
  uint32_t frequency = analogRead(microphonePin);

  for (unsigned long t = 0; t < duration * 1000UL; t += 1000UL) {  // Generar la onda cuadrada durante la duración especificada
    uint32_t fmFrequency = carrierFrequency + modulationIndex * sin(2 * PI * frequency * t / 1000000UL);
    si5351.set_freq_manual(fmFrequency, fmFrequency, SI5351_CLK0);

    Serial.println("FM " + String(fmFrequency) + " IN " + String(audioValue));
  }
}
