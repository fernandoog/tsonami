#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCData.h>

// Define tus credenciales de red
const char *ssid = "HOUSE";
const char *password = "wifiwifiwifi1992";
const char *device = "/esp";

// Define el puerto local para la comunicación UDP
const int localUdpPort = 8000;

// Crea el objeto para la comunicación UDP
WiFiUDP Udp;

void setup() {
  Serial.begin(9600);

  // Inicializa la conexión WiFi
  connectToWiFi();

  // Inicializa la conexión UDP
  Udp.begin(localUdpPort);
  Serial.println("Servidor OSC iniciado");
}

void loop() {
  // Si hay datos disponibles para leer
  int packetSize = Udp.parsePacket();
  if (packetSize > 0) {
    // Lee el paquete en un buffer de tipo uint8_t*
    uint8_t buffer[packetSize];
    Udp.read(buffer, packetSize);

    // Crea un objeto OSCMessage y llena con el buffer
    OSCMessage msg(device);
    msg.fill(buffer, packetSize);

    //msg.send(Serial);
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
  Serial.print(device);
  Serial.print(msg.getAddress());
  Serial.print(", ");
  for (int i = 0; i < msg.size(); i++) {
    if (msg.isInt(i)) {
      Serial.print("i ");
      Serial.print(msg.getInt(i));
    } else if (msg.isFloat(i)) {
      Serial.print("f ");
      Serial.print(msg.getFloat(i), 4);
    } else if (msg.isString(i)) {
      char strBuffer[100];
      msg.getString(i, strBuffer);
      Serial.print("s ");
      Serial.print(strBuffer);
    }
  }
  Serial.println();
}

