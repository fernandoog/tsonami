#include <Wire.h>
#include <Si5351.h>

Si5351 si5351;

const int modulationPin = A0;  // Pin analógico para la señal de modulación
const int outputPin = 12;     // Pin de salida conectado al transmisor FM

void setup() {
  Serial.begin(115200);

  // Inicializar el Si5351
  si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);

  // Establecer la frecuencia de la portadora (98.5 MHz)
  si5351.set_freq(98500000, SI5351_CLK0);

  // Configurar el pin de salida
  pinMode(outputPin, OUTPUT);
}

void loop() {
  // Leer el valor de la señal de modulación
  int modulationValue = analogRead(modulationPin);

  // Calcular la frecuencia modulada
  float modulationFrequency = map(modulationValue, 0, 4096, -50000, 50000);  // Ajusta según sea necesario
  float carrierFrequency = 98500000;  // Frecuencia de la portadora en Hz
  float frequency = carrierFrequency + modulationFrequency;

  // Modificar la frecuencia de la portadora
  si5351.set_freq(frequency, SI5351_CLK0);

  // Transmitir la señal (en este ejemplo, simplemente encender y apagar el pin de salida)
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(50);  // Puedes ajustar este valor según sea necesario
  digitalWrite(outputPin, LOW);

  // Agregar un pequeño retardo (ajustar según sea necesario)
  delay(10);
}
