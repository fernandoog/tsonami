#include "si5351.h"
#include "heltec.h"

Si5351 si5351;
// GND
// 22 SCL
// 23 SDA

const float frecuenciaPortadora = 8000000;  // Frecuencia de la portadora en Hz + un 0
const int muestrasPorCiclo = 4096;          // muestreo
const int outputPin = 46;                   // Pin de salida del DAC
const int bits = 12;                        // Resolucion DAC 12 bits (0-4096)
const int analogIn = 34;                    // DAC entrada de sonido.
const int muticlicador = 10;                // para adpatar los valores a la portadora

void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);

  // Start serial
  Serial.begin(115200);

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

  // Leer entrada de audio desde el micrófono
  int entradaAudio = analogRead(analogIn);

  // Mapear la entrada de audio al rango de amplitud apropiado (ajustar según sea necesario)
  int amplitud = map(entradaAudio, 0, 4096, 0, 255);

  // Modulación de amplitud (AM)
  int modulacion = amplitud * sin(2 * PI * millis() / muestrasPorCiclo);

  // Transmitir la señal modulada
  si5351.set_freq_manual(frecuenciaPortadora * muticlicador + modulacion, frecuenciaPortadora * 1000 + modulacion, SI5351_CLK0);

  Serial.println(String(frecuenciaPortadora * muticlicador + modulacion));

  dacWrite(outputPin, entradaAudio);

  drawCircles();
}

void drawCircles() {
  Heltec.display->clear();

  // Dibujar círculos aleatorios
  for (int i = 0; i < 10; ++i) {
    int x = random(DISPLAY_WIDTH);
    int y = random(DISPLAY_HEIGHT);
    int radio = random(5, 20);  // Radio entre 5 y 20 píxeles

    Heltec.display->drawCircleQuads(x, y, radio, 0b00001111);
  }
  Heltec.display->display();
}
