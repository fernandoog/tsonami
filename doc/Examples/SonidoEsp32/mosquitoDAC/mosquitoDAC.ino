const int buzzerPin = 5; // Cambia el número del pin según tu conexión

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Alejarse (tono descendente)
  for (int dutyCycle = 255; dutyCycle > 0; --dutyCycle) {
    analogWrite(buzzerPin, dutyCycle);
    delay(random(0, 50));  // Ajusta según la velocidad deseada
  }

  delay(random(0, 50)); // Pausa entre cambios de tono

  // Acercarse (tono ascendente)
  for (int dutyCycle = 0; dutyCycle < 255; ++dutyCycle) {
    analogWrite(buzzerPin, dutyCycle);
    delay(random(0, 50));// Ajusta según la velocidad deseada
  }

  delay(random(0, 50));// Pausa entre cambios de tono
}
