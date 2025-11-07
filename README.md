# Tsonami Festival - Phonopteros WiFi Interface

WiFi interface development for phonopteros project by Miguel Aparicio during the XVII edition of Tsonami Festival.

## Description

This repository contains all the code used for developing and building a WiFi interface for the phonopteros in Miguel Aparicio's project during the Tsonami Festival. The project includes Arduino code, PureData patches, Max/MSP patches, and various examples for audio processing, OSC communication, and sensor integration.

## Festival Context

This project was developed during the XVII edition of Tsonami Festival. Special thanks to all residency colleagues, organizers, and the audience who made this festival a unique life experience.

Thanks also to all developers who contributed with their libraries and devices to this project.

## Features

- WiFi communication for phonopteros
- OSC (Open Sound Control) protocol support
- PureData and Max/MSP integration
- Arduino-based hardware control
- Audio processing examples
- Sensor integration examples

## Hardware Support

- ESP32 (various models)
- ESP8266
- Daisy Seed
- Arduino boards

## Project Structure

```
tsonami/
├── src/
│   ├── arduino/         # Arduino sketches
│   ├── maxsp/           # Max/MSP patches
│   └── puredata/        # PureData patches
├── doc/                 # Documentation and examples
│   ├── Examples/        # Various code examples
│   ├── Daisy Seed/      # Daisy Seed documentation
│   └── Esp32 Dev kit/   # ESP32 documentation
└── lib/                 # External libraries
```

## Examples Included

- **OSC Communication**: Send/receive OSC messages
- **Audio Processing**: PWM, DAC, I2S audio examples
- **Radio**: FM transmission examples
- **Sensors**: ADC, sensor reading examples
- **WebSocket**: Real-time communication
- **MIDI**: MIDI send/receive examples

## Installation

1. Install Arduino IDE
2. Install required libraries (see lib/ directory)
3. Configure WiFi credentials in Arduino sketches
4. Upload to your ESP32/ESP8266 board

## Usage

### PureData

Open PureData patches in `src/puredata/` and connect to your hardware.

### Max/MSP

Open Max patches in `src/maxsp/` for Max/MSP integration.

### Arduino

Upload sketches from `src/arduino/` to your microcontroller.

## Documentation

See the `doc/` directory for:
- Hardware pinouts and schematics
- Example code
- OSC protocol documentation
- Library documentation

## Author

Fernando Ortega Gorrita (@fernandoog)

Developed for Tsonami Festival XVII edition - Phonopteros project by Miguel Aparicio.

## License

See LICENSE file for details.
