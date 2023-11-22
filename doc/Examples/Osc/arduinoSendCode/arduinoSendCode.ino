
/*referenced from Sebastien Lexler example code*/
/*Simplified and modified for teaching by Jen Sykes*/
//ethernet, wifi libraries
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include <SPI.h>
#include <OSCBundle.h>

//UDP communication
WiFiUDP Udp;

//the Arduino's IP
const IPAddress outIp(10, 1, 210, 50);  // remote IP of your device not your laptop!!! use IPscanner or FIND_IP sketch to find this
const unsigned int localPort = 8888;    // local port to listen/receive OSC packets (not used for sending)


char ssid[] = "yournetworkname";  // your network SSID (name)
char pass[] = "yourpassword";     // your network password

int LEDon = 0;
int pos;
void setup() {
  //setup ethernet part
  Serial.begin(19200);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  //turn on board LED on and off blink if connected
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(10);
    digitalWrite(LED_BUILTIN, HIGH);
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


  //onboard blue LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

//reads and dispatches the incoming message
void loop() {
  OSCMessage message;
  int size;
  //if our OSC data is greater than zero
  if ((size = Udp.parsePacket()) > 0) {
    while (size--)
      message.fill(Udp.read());
    if (!message.hasError()) {
      //debug is it working?
      Serial.println("working");
      //send the message to the 'routeOn' function
      message.dispatch("/on", routeOn);
    }
  }
}

//what we are doing with the OSC message
void routeOn(OSCMessage &msg) {
  if (msg.isInt(0)) {

    LEDon = msg.getInt(0);
    //send ON (1) message out to digitalPIn
    digitalWrite(LED_BUILTIN, !LEDon);
    //debugging print to console
    Serial.print("/on: ");
    Serial.println("ON");

  }

  //otherwise it's a floating point
  else if (msg.isFloat(0)) {
    //if we receive a flot instead of an int
    LEDon = msg.getFloat(0);
    digitalWrite(LED_BUILTIN, !LEDon);
    //debugging print to console
    Serial.print("/on: ");
    Serial.println("ON");
  }
}