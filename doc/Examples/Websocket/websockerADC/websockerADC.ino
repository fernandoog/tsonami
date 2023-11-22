#include <WiFi.h>
#include <WebSocketsServer.h>

const char *ssid = "HOUSE";
const char *password = "wifiwifiwifi1992";

int pinMic = 34;  // Cambia al pin que estás utilizando para el micrófono (ejemplo para ESP32)

WiFiServer server(81);
WebSocketsServer webSocket = WebSocketsServer(81);

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  // Manejar eventos WebSocket
  switch (type) {
    case WStype_TEXT:
      // No manejamos texto en este ejemplo
      break;
    case WStype_BIN:
      // Enviar datos binarios a todos los clientes conectados
      webSocket.broadcastBIN(payload, length);
      break;
  }
}

void setup() {
  Serial.begin(115200);

  // Inicializa la conexión WiFi
  connectToWiFi();

  // Iniciar servidor WebSocket
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  // Capturar el valor del micrófono
  int valor = analogRead(pinMic);

  // Enviar el valor a través de WebSocket
  webSocket.broadcastBIN(reinterpret_cast<uint8_t *>(&valor), sizeof(valor));
  //Serial.println(valor);
  // Manejar eventos WebSocket
  webSocket.loop();

  // Puedes agregar lógica adicional aquí si es necesario
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
