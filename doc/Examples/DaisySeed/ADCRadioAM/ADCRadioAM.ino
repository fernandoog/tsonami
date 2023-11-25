#include "si5351.h"
#include <DaisyDuino.h>

Si5351 si5351;
// GND
// 22 SCL
// 23 SDA

const float frecuenciaPortadora = 1000;  // Frecuencia de la portadora en Hz + un 0
const int muestrasPorCiclo = 200;        // muestreo
const int outputPin = 25;                // Pin de salida del DAC
const int bits = 12;                     // Resolucion DAC 12 bits (0-4096)
const int analogIn = 34;                 // DAC entrada de sonido.
const int muticlicador = 1;              // para adpatar los valores a la portadora

DaisyHardware hw;
size_t num_channels;
float sample_rate;
float output;

void setup() {

  // Start serial
  Serial.begin(57600);

  // Initialize for Daisy pod at 48kHz
  hw = DAISY.init(DAISY_SEED, AUDIO_SR_48K);
  num_channels = hw.num_channels;
  sample_rate = DAISY.get_samplerate();

  bool i2c_found;
  i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
  if (!i2c_found) {
    Serial.println("Device not found on I2C bus!");
  }

  delay(500);
}

void loop() {
  
  DAISY.begin(MyCallback);

}

void MyCallback(float **in, float **out, size_t size) {
  float saw, freq, output;
  for (size_t i = 0; i < size; i++) {
    output = flt.Process(radioSend());

    for (size_t chn = 0; chn < num_channels; chn++) {
      out[chn][i] = output;
    }
  }
}

float analogIn radioSend() {
    // Leer entrada de audio desde el micrófono
  int entradaAudio = analogRead(analogIn);

  // Mapear la entrada de audio al rango de amplitud apropiado (ajustar según sea necesario)
  int amplitud = map(entradaAudio, 0, 1023, 0, 255);

  // Modulación de amplitud (AM)
  int modulacion = 512 + amplitud * sin(2 * PI * millis() / muestrasPorCiclo);

  // Transmitir la señal modulada
  si5351.set_freq_manual(frecuenciaPortadora * 1000 + modulacion, frecuenciaPortadora * 1000 + modulacion, SI5351_CLK0);

  Serial.println(String(frecuenciaPortadora * 1000 + modulacion));

  return entradaAudio;
}
