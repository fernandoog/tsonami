#include <SPI.h>

const int csPin = 5; // Pin de selección del esclavo (CS) en el ESP32
SPISettings settings(1000000, MSBFIRST, SPI_MODE0); // Configuración SPI

void setup() {
  Serial.begin(115200);
  pinMode(csPin, OUTPUT);
  SPI.begin();
}

void loop() {
  digitalWrite(csPin, LOW); // Habilitar el esclavo
  SPI.beginTransaction(settings);

  // Enviar datos al Daisy Seed
  byte datoEnviado = 0x55;
  byte datoRecibido = SPI.transfer(datoEnviado);

  SPI.endTransaction();
  digitalWrite(csPin, HIGH); // Deshabilitar el esclavo

  // Procesar el dato recibido (puedes imprimirlo, enviarlo a Pd, etc.)
  Serial.println(datoRecibido);

  delay(1000);
}
