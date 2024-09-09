# Sysboy2000

**Sysboy2000** is a project aimed at creating a physical device capable of displaying real-time data from a computer. This device, controlled by an ESP32, uses a Wi-Fi connection and communicates with a Python server through the WebSocket protocol. The initial goal is to control an analog VU meter to display the VRAM usage of the graphics card.

## Features

- Real-time display of data from a PC on an analog VU meter.
- Bi-directional communication between a Python server and an ESP32 via WebSocket.
- Simplified Wi-Fi setup via a captive portal on the ESP32.
- Extensible to other types of data and hardware components (LEDs, buttons, displays, etc.).

## Project Architecture

The project is divided into two parts:

1. **Server (PC)**:
   - WebSocket server written in Python.
   - Retrieves system data (like VRAM usage) and sends it to the ESP32.

2. **Client (ESP32)**:
   - WebSocket client on an ESP32 connected via Wi-Fi.
   - Controls an analog VU meter via a DAC to display the received data.

## Requirements

- An ESP32 with Wi-Fi capability.
- A PC with Python 3.x installed.
- Wi-Fi network for communication.
- Hardware components: analog VU meter, op-amp, etc.

## Installation

### Server

See the [Server README](./serveur/README.md).

### Client

See the [Client README](./client/README.md).

## Future Extensions

The project is designed to be easily extendable, allowing the addition of new sensors, new data types to display, or new user interfaces (LEDs, OLED screens, etc.).