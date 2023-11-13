#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <AppleMIDI_Debug.h>
#include <AppleMIDI.h>

#define LEDS_COUNT 1
#define LEDS_PIN 2
#define CHANNEL 0


// Wifi
char ssid[] = "HOUSE";             //  your network SSID (name)
char pass[] = "wifiwifiwifi1992";  // your network password (use for WPA, or use as key for WEP)

// Midi
unsigned long t0 = millis();
int8_t isConnected = 0;
byte note = 43;
byte velocity = 55;
byte channel = 1;

WiFiServer server(5004);  // Puerto para la conexión MIDI

// Declarar la instancia de WiFiUDP globalmente
WiFiUDP udp;

APPLEMIDI_CREATE_DEFAULTSESSION_INSTANCE();

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  Serial.println("Booting");

  // WIFI
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Establishing connection to WiFi..");
  }
  Serial.println("Connected to network");
  Serial.println(WiFi.localIP());
  Serial.println(AppleMIDI.getPort());
  Serial.println(AppleMIDI.getName());

  // MIDI
  MIDI.begin();
  AppleMIDI.setHandleConnected([](const APPLEMIDI_NAMESPACE::ssrc_t& ssrc, const char* name) {
    isConnected++;
    Serial.println(ssrc);
    Serial.println(name);
  });
  AppleMIDI.setHandleDisconnected([](const APPLEMIDI_NAMESPACE::ssrc_t& ssrc) {
    isConnected--;
    Serial.println("Disconnected");
  });
  MIDI.setHandleNoteOn([](byte channel, byte note, byte velocity) {
    Serial.println(note);
  });
  MIDI.setHandleNoteOff([](byte channel, byte note, byte velocity) {
    Serial.println(note);
  });
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void loop() {
  // Esperar una conexión MIDI
  MIDI.read();
}
