
#include <WiFi.h>
//#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCData.h>
#include <driver/ledc.h>

// Define tus credenciales de red
const char *ssid = "HOUSE";
const char *password = "wifiwifiwifi1992";

//PWM
const int canalPWM = 0;                       // Número de canal PWM
const int gpioNum = 5;                        // Número GPIO válido para PWM en ESP32 //ESP8266-01 0 //ESP32C3
const int frecuenciaPWM = 5000;               // Frecuencia en Hz
const int resolucionPWM = LEDC_TIMER_12_BIT;  // Resolución PWM (10 bits)

//GPIO
const int analogInPin = 34;

// Define el puerto local para la comunicación UDP
const int localUdpPort = 8000;

// Crea el objeto para la comunicación UDP
WiFiUDP Udp;

void setup() {
  Serial.begin(115200);

  // Inicializa la conexión WiFi
  connectToWiFi();

  // Inicializa la conexión UDP
  Udp.begin(localUdpPort);
  Serial.println("Servidor OSC iniciado");

  // Configurar el canal PWM
  ledcSetup(canalPWM, frecuenciaPWM, resolucionPWM);
  pinMode(gpioNum, OUTPUT);
  ledcAttachPin(gpioNum, canalPWM);
}

void loop() {
  // Si hay datos disponibles para leer
  int packetSize = Udp.parsePacket();
  if (packetSize > 0) {
    // Lee el paquete en un buffer de tipo uint8_t*
    uint8_t buffer[packetSize];
    Udp.read(buffer, packetSize);
    // Crea un objeto OSCMessage y llena con el buffer
    OSCMessage msg;
    msg.fill(buffer, packetSize);
    // Pasa el mensaje al puerto serie
    toSerial(msg);
    // Libera los recursos del mensaje OSC
    msg.empty();
  }
}

void connectToWiFi() {
  Serial.println("Conectando a WiFi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando...");
  }

  Serial.println("Conectado a la red WiFi");
  Serial.println("Dirección IP: " + WiFi.localIP().toString());
}

void toSerial(OSCMessage &msg) {

  // Imprime la dirección OSC
  Serial.print(msg.getAddress());
  Serial.print(" ");
  for (int i = 0; i < msg.size(); i++) {
    if (msg.isInt(i)) {
      int valorRecibido = constrain(msg.getInt(i), 0, 255);
      ledcWrite(canalPWM, valorRecibido);
      int pwmValue = ledcRead(canalPWM);
      int analogValue = analogRead(analogInPin);
      Serial.println(String(msg.getInt(i)) + " VAL " + String(valorRecibido) + " PWM " + String(pwmValue) + " ANALOG_IN " + String(analogValue));
    } else if (msg.isFloat(i)) {
      Serial.print(msg.getFloat(i), 1);
    } else if (msg.isString(i)) {
      char strBuffer[100];
      msg.getString(i, strBuffer);
      Serial.print(strBuffer);
    }
  }
  Serial.println();
}

void zumbido(){
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