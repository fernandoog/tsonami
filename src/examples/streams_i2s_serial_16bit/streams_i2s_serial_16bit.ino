/**
 * @file streams-i2s-serial_16bit.ino
 * @author Phil Schatzmann
 * @brief see https://github.com/pschatzmann/arduino-audio-tools/blob/main/examples/examples-stream/streams-i2s-serial_16bit/README.md
 * 
 * @author Phil Schatzmann
 * @copyright GPLv3
 */


#include "AudioTools.h"

AudioInfo info(44100, 2, 16);
I2SStream i2sStream; // Access I2S as stream
PWMAudioOutput pwm;    
StreamCopy copier(pwm, i2sStream); // copy i2sStream to csvStream

// Arduino Setup
void setup(void) {
    Serial.begin(115200);
    AudioLogger::instance().begin(Serial, AudioLogger::Info);
    
    auto cfg = i2sStream.defaultConfig(RX_MODE);
    auto config = pwm.defaultConfig();
    config.start_pin = 3;
    cfg.pin_ws = 4;
    cfg.pin_bck = 5;
    cfg.pin_data = 6;
    cfg.copyFrom(info);
    cfg.i2s_format = I2S_STD_FORMAT; // or try with I2S_LSB_FORMAT
    cfg.is_master = true;
     // this module nees a master clock if the ESP32 is master
    cfg.use_apll = false;  // try with yes
    //cfg.pin_mck = 3; 
    i2sStream.begin(cfg);
    pwm.begin(config);
}

// Arduino loop - copy data
void loop() {
    copier.copy();
}
