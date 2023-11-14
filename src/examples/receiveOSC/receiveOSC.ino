#include <WiFi.h>
#include <OSCMessage.h>
#include <OSCData.h>

const char *ssid = "HOUSE";
const char *password = "wifiwifiwifi1992";

const int puertoWiFi = 12345;  // Puerto para la conexión Wi-Fi
const int puertoOSC = 8000;    // Puerto OSC

WiFiServer server(puertoWiFi);

void setup() {
  Serial.begin(115200);

  // Conectar a Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");

  // Inicializar el servidor Wi-Fi
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        // Recibir y procesar el mensaje OSC
        OSCMessage mensaje;
        while (client.available()) {
          mensaje.fill(client.read());
        }

        // Imprimir el contenido del mensaje en la consola
        Serial.print("Mensaje OSC recibido: ");
        for (int i = 0; i < mensaje.size(); ++i) {
          Serial.print(mensaje.getFloat(i));
          Serial.print(" ");
        }
        Serial.println();

        // Puedes agregar lógica para manejar el mensaje según tus necesidades

        mensaje.empty();  // Limpiar el mensaje para la siguiente iteración
      }
    }
    client.stop();
  }
}
