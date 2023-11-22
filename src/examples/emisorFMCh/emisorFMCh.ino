#include <Wire.h>
#include <Adafruit_SI5351.h>

#define SDA_PIN 21
#define SCL_PIN 22

Adafruit_SI5351 si5351 = Adafruit_SI5351();

void setup() {
  Serial.begin(115200);
  
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!si5351.begin()) {
    Serial.println("No se pudo encontrar el SI5351, ¡verifica las conexiones!");
    while (1);
  }

  Serial.println("SI5351 encontrado!");

  // Configurar el transmisor FM
  si5351.setupPLL(SI5351_PLL_A, SI5351_PLL_INPUT_CLKIN, 25, 1);
  si5351.setupMultisynth(SI5351_PLL_A, 0, 25, SI5351_MULTISYNTH_DIV_4);
  si5351.setupRdiv(SI5351_PLL_A, SI5351_R_DIV_1);

  // Configurar el divisor de frecuencia y la frecuencia de salida deseada
  uint32_t frequency = 100000000UL;  // Frecuencia de portadora: 100 MHz
  si5351.set_freq(frequency, SI5351_PLL_A);

  // Iniciar la transmisión del tono FM
  transmitFM(100.0);  // Frecuencia de audio: 100 Hz (ajustar según sea necesario)
}

void loop() {
  // Tu código aquí
}

void transmitFM(float audioFrequency) {
  uint32_t carrierFrequency = 100000000UL;  // Frecuencia de portadora: 100 MHz
  float deviation = 75000.0;  // Desviación de frecuencia: 75 kHz (ajustar según sea necesario)

  while (1) {
    for (float t = 0; t < 1.0; t += 1.0 / 1000) {  // Generar 1 segundo de audio
      float audioSample = sin(2 * PI * audioFrequency * t);
      float modulationIndex = deviation / audioFrequency;
      uint32_t fmFrequency = carrierFrequency + modulationIndex * sin(2 * PI * audioFrequency * t);

      // Configurar la frecuencia de salida del SI5351
      si5351.set_freq(fmFrequency, SI5351_PLL_A);

      // Transmitir el audio
      delayMicroseconds(1000);  // Retardo pequeño para controlar la velocidad de modulación
    }
  }
}
