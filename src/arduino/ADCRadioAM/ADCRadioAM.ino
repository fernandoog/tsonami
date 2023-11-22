#include "si5351.h"

Si5351 si5351;
// GND 
// 22 SCL
// 23 SDA

const float frecuenciaPortadora = 100000;  // Frecuencia de la portadora en Hz
const int muestrasPorCiclo = 4096;         // muestreo
const int outputPin = 25;                  // Pin de salida del DAC
const int bits = 12;                       //set the resolution to 12 bits (0-4096)
const int analogIn = 34;
const int frecuencia = 1000;  // Hz
const int periodo = 1000000 / frecuencia;
unsigned long tiempoInicio = micros();

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

  si5351.set_freq_manual(frecuenciaPortadora, frecuenciaPortadora, SI5351_CLK0);

  delay(500);
}


void loop() {

  // Obtener la entrada de audio desde el micrófono
  float entradaAudio = analogRead(analogIn);

  // Calcular la amplitud normalizada en el rango de 0 a 255
  int amplitud = map(sin(2 * PI * (micros() - tiempoInicio) / periodo), -1, 1, 0, 255);

  // Salida Radio
  float frecuenciaTono = (entradaAudio * amplitud) + frecuenciaPortadora;
  si5351.set_freq_manual(frecuenciaTono, frecuenciaTono, SI5351_CLK0);

  // Salida al DAC
  dacWrite(outputPin, amplitud);

  Serial.println(String(frecuenciaTono) + " " + amplitud);
}
