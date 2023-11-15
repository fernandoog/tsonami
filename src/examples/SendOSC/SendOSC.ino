#include <WiFi.h>
#include <OSCMessage.h>
#include <WiFiUdp.h>

// Define tus credenciales de red
const char *ssid = "HOUSE";
const char *password = "wifiwifiwifi1992";

// Define la dirección IP y el puerto del destino OSC
IPAddress remoteIP(192, 168, 43, 207);  // Cambia la dirección IP a la que quieras enviar los mensajes OSC
const int remotePort = 8000;            // Cambia el puerto OSC según tus necesidades

// Crea el objeto para la comunicación UDP
WiFiUDP Udp;

void setup() {
  // Inicializa la conexión WiFi
  Serial.begin(115200);
  connectToWiFi();

  // Inicializa la conexión UDP
  Udp.begin(8888);  // Puerto local para la comunicación UDP
}

void loop() {
  // Crea un mensaje OSC y agrega datos si es necesario
  OSCMessage msg("/msg");
  msg.add("Hola, mundo!");

  // Envía el mensaje OSC
  Udp.beginPacket(remoteIP, remotePort);
  msg.send(Udp);
  Udp.endPacket();

  // Libera los recursos del mensaje OSC
  msg.empty();

  delay(1000);  // Espera 1 segundo antes de enviar el próximo mensaje (ajusta según sea necesario)
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
