# Sysboy2000 - ESP32 Client

This project represents the client part of the **Sysboy2000** system. The ESP32 retrieves data sent by the Python WebSocket server and controls analog components (such as a VU meter) to display it in real time.

## Features

- Connects to the WebSocket server via Wi-Fi to receive data.
- Wi-Fi configuration through a captive portal to enter network credentials.
- Uses the ESP32 DAC to control an analog VU meter.
- Capable of adding other components like LEDs, buttons, or displays.

## Requirements

- **ESP32** with Wi-Fi support.
- **Hardware components**: analog VU meter, op-amp.
- PlatformIO and Arduino libraries for programming the ESP32.

## Installation

1. **Clone the project**:
   git clone https://github.com/username/sysboy2000-client.git

2. Set up PlatformIO:
        Open the project in VSCode with the PlatformIO extension.
        Ensure Wi-Fi configuration is correct or use the integrated captive portal for setup on first run.

3. Upload to ESP32:
        Connect the ESP32 to your computer and upload the firmware via PlatformIO.

Usage

    Once the ESP32 is configured and connected to the Wi-Fi network, it will automatically connect to the WebSocket server and begin displaying data on the VU meter.

Future Extensions

    Adding new sensors or components (buttons, OLED screens).
    Adjustments to handle other data types beyond VRAM.