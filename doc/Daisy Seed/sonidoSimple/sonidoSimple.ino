#include <DaisyDuino.h>

// Declarar el objeto DaisySeed
DaisySeed seed;

void setup() {
  // Configuración inicial
  seed.Configure();
  seed.Init();
}

void loop() {
  // Reproducir un sonido simple
  seed.led1.Set(1); // Encender el LED para indicar que está reproduciendo sonido
  seed.StartAudio(AudioCallback);
  delay(5000); // Reproducir durante 5 segundos
  seed.StopAudio();
  seed.led1.Set(0); // Apagar el LED
}

// Función de devolución de llamada de audio
static void AudioCallback(float *in, float *out, size_t size) {
  // Generar sonido aquí, por ejemplo, un tono simple
  for (size_t i = 0; i < size; i += 2) {
    out[i] = 0.2f * sinf(2.0f * M_PI * 440.0f * ((float)i / size));
    out[i + 1] = out[i];
  }
}
