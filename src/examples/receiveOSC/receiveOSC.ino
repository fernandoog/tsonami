#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>

const char* ssid = "HOUSE";                 // Change this to your WiFi SSID
const char* password = "wifiwifiwifi1992";  // Change this to your WiFi password

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;
const IPAddress outIp(192, 168, 43, 207);  // remote IP (not needed for receive)
const unsigned int outPort = 8001;         // remote port (not needed for receive)
const unsigned int localPort = 8000;       // local port to listen for UDP packets (here's where we send the packets)

OSCErrorCode error;

void setup() {

  Serial.begin(115200);
  while (!Serial) { delay(100); }

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println("******************************************************");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  OSCMessage msg;
  int size = Udp.parsePacket();
  if (size > 0) {
    while (size--) {
      msg.fill(Udp.read());
    }
    if (!msg.hasError()) {
      Serial.println(msg.getInt(0));
    } else {
      error = msg.getError();
      Serial.print("error: ");
      Serial.println(error);
    }
  }
}
