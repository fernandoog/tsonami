#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <AppleMIDI.h>


// Wifi
char ssid[] = "HOUSE";             //  your network SSID (name)
char pass[] = "wifiwifiwifi1992";  // your network password (use for WPA, or use as key for WEP)
WiFiServer server(5004);           // Puerto para la conexión MIDI
// Declarar la instancia de WiFiUDP globalmente
WiFiUDP udp;

APPLEMIDI_CREATE_DEFAULTSESSION_INSTANCE();
void OnAppleMidiStartReceived(const APPLEMIDI_NAMESPACE::ssrc_t&);
void OnAppleMidiReceivedByte(const APPLEMIDI_NAMESPACE::ssrc_t&, byte);
void OnAppleMidiEndReceive(const APPLEMIDI_NAMESPACE::ssrc_t&);

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
    Serial.println("Connected");
    Serial.println(ssrc);
    Serial.println(name);
  });
  AppleMIDI.setHandleDisconnected([](const APPLEMIDI_NAMESPACE::ssrc_t& ssrc) {
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
