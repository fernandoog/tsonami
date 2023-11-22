#include "si5351.h"

Si5351 si5351;

float frecuenciaPortadora = 98000000; // Frecuencia de la portadora en Hz

void setup() {

  // Start serial
  Serial.begin(57600);

  bool i2c_found;
  i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
  if (!i2c_found) {
    Serial.println("Device not found on I2C bus!");
  }

  si5351.set_freq_manual(frecuenciaPortadora, frecuenciaPortadora, SI5351_CLK0);

  delay(500);
}

 void loop() {
  // Emitir un tono de 1 kHz en FM
  emitirTonoFM(10000, 100);

}

void emitirTonoFM(int frecuenciaTono, int duracion) {
 
  int muestrasPorCiclo = 200;  // Número de muestras por ciclo de onda (ajustar según sea necesario)

  for (int i = 0; i < duracion; i++) {
    // Modificar la frecuencia de la portadora para representar el tono
    si5351.set_freq(frecuenciaPortadora + sin(2 * PI * i / muestrasPorCiclo) * frecuenciaTono, SI5351_CLK0);
  }
}