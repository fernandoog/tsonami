const int dacChannel = 5;  // Canal DAC, ajusta según tu placa ESP32

void setup() {
  pinMode(dacChannel, OUTPUT);
  randomSeed(analogRead(0));  // Inicializa la semilla aleatoria con un valor analógico cambiante
}

void loop() {
  int frequency = random(1000, 5000);  // Frecuencia aleatoria del zumbido del mosquito
  int duration = random(10, 50);       // Duración aleatoria del zumbido
  
  playTone(frequency, duration);
  
  delay(random(500, 2000));  // Pausa entre zumbidos
}

void playTone(int frequency, int duration) {
  int sampleRate = 44100;
  int numSamples = sampleRate * duration / 1000;
  
  for (int i = 0; i < numSamples; ++i) {
    int value = 127 + 127 * sin(2 * PI * frequency * i / sampleRate);
    analogWrite(dacChannel, value);
  }
  
  // Detener el zumbido
  analogWrite(dacChannel, 0);
}
