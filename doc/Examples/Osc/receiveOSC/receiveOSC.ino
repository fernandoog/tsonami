#include <WiFi.h>
//#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCData.h>
#include <driver/ledc.h>

// Define tus credenciales de red
const char *ssid = "HOUSE";
const char *password = "wifiwifiwifi1992";

//GPIO
const int canalPWM = 0;                       // Número de canal PWM 
const int gpioNum = 0;                       // Número GPIO válido para PWM en ESP32 //ESP8266-01 0 //ESP32C3
const int frecuenciaPWM = 1000;               // Frecuencia en Hz
const int resolucionPWM = LEDC_TIMER_10_BIT;  // Resolución PWM (10 bits)

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

  // Asociar el canal PWM con el pin GPIO
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
      Serial.print(msg.getInt(i));
      int valorRecibido = constrain(msg.getInt(i), 0, 255);
      analogWrite(gpioNum, valorRecibido);
      Serial.print(" ");
      Serial.print(valorRecibido);
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