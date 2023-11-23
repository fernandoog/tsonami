#include "si5351.h"

Si5351 si5351;
// GND 
// 22 SCL
// 23 SDA

const float frecuenciaPortadora = 2415117;  // Frecuencia de la portadora en Hz + un 0
const int muestrasPorCiclo = 4096;          // muestreo
const int outputPin = 25;                   // Pin de salida del DAC
const int bits = 12;                        // Resolucion DAC 12 bits (0-4096)
const int analogIn = 34;                    // DAC entrada de sonido.
const int muticlicador = 1000;              // para adpatar los valores a la portadora

void setup() {

  // Start serial
  Serial.begin(57600);

  analogReadResolution(bits);
  // Configurar el pin de salida del DAC
  pinMode(outputPin, OUTPUT);

  bool i2c_found;
  i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
  if (!i2c_found) {
    Serial.println("Device not found on I2C bus!");
  }

  delay(500);
}


void loop() {

  // Obtener la entrada de audio desde el micrófono
  float entradaAudio = analogRead(analogIn);

  // Salida Radio
  float frecuenciaTono = (entradaAudio * muticlicador) + frecuenciaPortadora;
  si5351.set_freq_manual(frecuenciaTono, frecuenciaTono, SI5351_CLK0);

  // Salida al DAC
  dacWrite(outputPin, entradaAudio);

  Serial.println(String(frecuenciaTono) + " " + entradaAudio);
  
}
