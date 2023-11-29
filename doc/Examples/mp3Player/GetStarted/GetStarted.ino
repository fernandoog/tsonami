#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>

#define RX_PIN 20
#define TX_PIN 21

SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX

DFPlayerMini_Fast myMP3;

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600); // Inicia la comunicación serial con el DFPlayer Mini

  if (!myMP3.begin(mySerial)) {
    Serial.println("Error al iniciar el DFPlayer Mini");
    while (true);
  }

  myMP3.setTimeOut(500); // Configura el tiempo de espera (timeout) para la comunicación
  myMP3.volume(15); // Ajusta el volumen (0-30)
}

void loop() {
  if (myMP3.available()) {
    uint8_t type = myMP3.readType();
    if (type == DFPlayerMini_Fast::DFPlayerPlayFinished) {
      // La reproducción ha terminado
    }
  }
}
