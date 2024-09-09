# Sysboy2000 - Python Server

This project constitutes the server part of **Sysboy2000**. It is a WebSocket server written in Python that retrieves system data such as VRAM usage and sends it to the ESP32 for display.

## Features

- WebSocket server in Python.
- Sends VRAM usage data to the ESP32 at regular intervals.
- Extensible to send other system data (CPU, RAM, network, etc.).

## Requirements

- **Python 3.x** installed on the PC.
- Required Python libraries: `websockets`, `psutil`, `pyNVML` (or others for system resource management).

## Installation

1. **Clone the project**:
   git clone https://github.com/username/sysboy2000-server.git

2. Install dependencies:

    pip install -r requirements.txt

3. Configure the server:
        Ensure that the libraries for retrieving system data are installed (pyNVML for Nvidia cards, for example).
        Adjust WebSocket connection settings if necessary.

Usage

Run the WebSocket server:
python serveur.py

The server will start fetching system data and sending it to the connected ESP32.
Future Extensions

    Adding new system data to monitor (CPU, RAM, network usage).
    Implementing a web interface to configure the server or view data.