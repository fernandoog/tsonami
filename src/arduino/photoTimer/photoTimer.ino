#include "esp_camera.h"
#include "FS.h"
#include "SD_MMC.h"
#include <TimeLib.h>

#define FILE_PHOTO "/photo_"

// Definir el tiempo entre capturas (en segundos)
const int tiempoEntreCapturas = 60;

void setup() {
  Serial.begin(115200);

  // Configuración de la cámara para el modelo AI-Thinker
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = 5;  // D0
  config.pin_d1 = 18; // D1
  config.pin_d2 = 19; // D2
  config.pin_d3 = 21; // D3
  config.pin_d4 = 36; // D4
  config.pin_d5 = 39; // D5
  config.pin_d6 = 34; // D6
  config.pin_d7 = 35; // D7
  config.pin_xclk = 0; // XCLK
  config.pin_pclk = 22; // PCLK
  config.pin_vsync = 25; // VSYNC
  config.pin_href = 23; // HREF
  config.pin_sscb_sda = 26; // SDA
  config.pin_sscb_scl = 27; // SCL
  config.pin_pwdn = 32; // PWDN
  config.pin_reset = -1; // Reset no conectado
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_UXGA;
  config.jpeg_quality = 10;
  config.fb_count = 2;

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Error en la inicialización de la cámara: 0x%x", err);
    return;
  }

  // Inicializar la tarjeta SD
  if (!SD_MMC.begin()) {
    Serial.println("Error al montar la tarjeta SD");
    return;
  }
}

void loop() {
  // Capturar una foto cada minuto
  delay(tiempoEntreCapturas * 1000);
  capturePhoto();
}

void capturePhoto() {
  Serial.println("Capturando foto...");

  // Obtener la marca de tiempo actual
  time_t t = now();
  struct tm *timeInfo = localtime(&t);

  // Crear un nombre de archivo con la marca de tiempo
  char fileName[30];
  sprintf(fileName, "%s%04d%02d%02d_%02d%02d%02d.jpg", FILE_PHOTO, timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);

  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Error al capturar la foto");
    return;
  }

  // Guardar la foto con el nombre de archivo que incluye la marca de tiempo
  File file = SD_MMC.open(fileName, FILE_WRITE);
  if (!file) {
    Serial.println("Error al abrir el archivo de la foto en la tarjeta SD");
    return;
  }

  file.write(fb->buf, fb->len);
  file.close();

  esp_camera_fb_return(fb);
  Serial.print("Foto capturada y guardada en SD: ");
  Serial.println(fileName);
}
