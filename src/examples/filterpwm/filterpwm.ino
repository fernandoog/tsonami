const int pwmInputPin = 2;      // Pin donde se conecta la señal PWM
const int analogOutPin = 34;    // Pin analógico de salida
const float R = 10.0;           // Valor de resistencia en kiloohmios
const float C = 3.3e-6;         // Valor de capacitancia en microfaradios

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Leer la señal PWM
  int pwmValue = pulseIn(pwmInputPin, HIGH);

  // Filtrar la señal PWM utilizando un filtro RC
  float filteredValue = pwmFilter(pwmValue);

  // Convertir el valor filtrado en un valor analógico y escribirlo en el pin analógico de salida
  analogWrite(analogOutPin, filteredValue);

  // Mostrar los valores en el puerto serie
  Serial.print("Valor PWM: ");
  Serial.print(pwmValue);
  Serial.print(", Valor filtrado: ");
  Serial.println(filteredValue);

  // Esperar un breve período de tiempo antes de volver a leer
  delay(1000);
}

// Función para filtrar la señal PWM utilizando un filtro RC
float pwmFilter(int pwmValue) {
  static float filteredValue = 0;
  const float alpha = 1 / (1 + R * C);
  filteredValue = alpha * pwmValue + (1 - alpha) * filteredValue;
  return filteredValue;
}
