/**************************************************************************/
/**************************************************************************/
/*SendCount++ function referenced from Sebastien Lexler example code*/
/*Simplified and modified for teaching by Jen Sykes*/
/* ESP8266 info */
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>  /// https://github.com/CNMAT/OSC
#include <OSCBundle.h>   /// https://github.com/CNMAT/OSC



char ssid[] = "yournetworkname";  // your network SSID (name)
char pass[] = "yourpassword";     // your network password

WiFiUDP Udp;                              // A UDP instance to let us send and receive packets over UDP
const IPAddress outIp(192, 168, 0, 111);  // remote IP of your computer
const unsigned int outPort = 9999;        // remote port to receive OSC
const unsigned int localPort = 8888;      // local port to listen for OSC packets (actually not used for sending)

long sendCount = 0;
long frameCount = 0;
void sendBundleViaOSC();
int data = 0;
/**************************************************************************/


void oscSetup() {
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  Serial.begin(115200);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(0, LOW);
    delay(10);
    digitalWrite(0, HIGH);
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(localPort);
}

void setup(void) {

  Serial.begin(115200);
  oscSetup();
}


/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void) {

  frameCount++;

  //send data every 2nd frame
  if (frameCount < 2) {
    //visual turn light on when sending
    digitalWrite(0, LOW);  //blue LED on
  } else {
    digitalWrite(0, HIGH);
  }


  if (frameCount > 500) {
    frameCount = 0;
  }
  sendCount++;
  //if sendCount is over 1000 (1 second) send OSC info
  if (sendCount > 1000) {

    sendViaOSC();  //send messages

    //sendBundleViaOSC()  //send bundle
    Serial.println("sendingdata");
  }
}


void sendViaOSC() {
  data++;
  OSCMessage msg("/lightsensor");
  msg.add((int32_t)data);
  //  msg.add("/d12");
  //  msg.add((int32_t)digitalRead(12));
  msg.add("/string");
  msg.add("hello, osc.");
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp);
  Udp.endPacket();
  msg.empty();
  sendCount = 0;
}