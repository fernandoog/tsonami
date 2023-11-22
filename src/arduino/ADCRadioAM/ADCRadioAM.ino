#include "si5351.h"

Si5351 si5351;

float frecuenciaPortadora = 100000;  // Frecuencia de la portadora en Hz
int muestrasPorCiclo = 100;

void setup() {

  // Start serial
  Serial.begin(57600);

  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);

  bool i2c_found;
  i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
  if (!i2c_found) {
    Serial.println("Device not found on I2C bus!");
  }

  si5351.set_freq_manual(frecuenciaPortadora, frecuenciaPortadora, SI5351_CLK0);

  delay(500);
}


void loop() {
  // Obtener la entrada de audio desde el micrófono
  float entradaAudio = analogRead(34);

  float frecuenciaTono = (entradaAudio * 100) + frecuenciaPortadora ;  // Ajustar según sea necesario


  si5351.set_freq_manual(frecuenciaTono, frecuenciaTono, SI5351_CLK0);
 Serial.println(String(frecuenciaTono));
  
}
