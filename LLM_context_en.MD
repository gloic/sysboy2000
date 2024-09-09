Project "Sysboy2000" - Detailed Context

The goal of "Sysboy2000" is to build a physical device that can display real-time data from a computer. This device will sit on my desk and be controlled by an ESP32, connected to my PC via Wi-Fi using the WebSocket protocol. The initial use case is to control an analog VU meter (in milliamps) to visualize the VRAM usage of my GPU.
General Structure of the Project
Key Components:

    Server-side (PC):
        The server will be a Python script running on the computer. It will have two main tasks:
            Collect real-time data from the PC (e.g., VRAM usage) at regular intervals.
            Send this data to the ESP32 (the client) over a WebSocket connection.
            The server should also be able to receive commands from the ESP32, allowing for bi-directional communication.

    Client-side (ESP32):
        The client will be an ESP32 connected to various electronic components (buttons, VU meter, LEDs, etc.).
        The ESP32 will connect to the Python server over Wi-Fi using WebSocket to receive the data to be displayed.
        It will control the analog VU meter by adjusting the signal sent through a DAC (Digital-to-Analog Converter), amplified by an op-amp (operational amplifier) to drive the VU meter.

Technical Choices:

    Communication Protocol: WebSocket:
        We have chosen WebSocket instead of REST because WebSocket is better suited for real-time and bi-directional communication. Unlike REST, WebSocket maintains an open connection between the server and the client, allowing continuous data exchange without the need for frequent HTTP requests.
        This will enable the PC to send VRAM usage information in real-time, and the ESP32 will immediately process and display this data on the VU meter.

    Wireless Connectivity: Wi-Fi:
        Wi-Fi provides a more robust and flexible connection compared to Bluetooth, especially in scenarios where data needs to be sent regularly.
        To make it easier for the ESP32 to connect to the local Wi-Fi network, the ESP32 will initially be set up as an Access Point (AP) with a captive portal. This portal will allow the user to input the Wi-Fi credentials via a simple web interface. The ESP32 can then connect to the network and the Python WebSocket server as a Wi-Fi client.

    Power and Communication:
        The ESP32 will be powered via USB from the computer. This simplifies power management as it eliminates the need for an external power source, especially since the device will remain on the desk and doesn’t need to be far from the PC.
        While Wi-Fi will be used for data communication, the USB connection could also be utilized for debugging or firmware updates.

    Update Frequency:
        The communication between the server and the ESP32 does not need to be perfectly real-time. Updating the data every few seconds will be sufficient to display information on the VU meter.
        This update frequency can be adjusted later for performance optimization or for other types of data display.

Electronic Components:

    ESP32:
        The ESP32 microcontroller is ideal due to its built-in Wi-Fi capabilities, analog/digital interfaces, and low power consumption.
        It will communicate via WebSocket to receive data and use its DAC capabilities to control components like the VU meter.
        The ESP32 setup is modular, allowing future additions of other components such as buttons, potentiometers, LEDs, etc.

    VU Meter (in milliamps):
        The analog VU meter will be the first component to be controlled. The ESP32 will use its DAC to generate an analog signal corresponding to the VRAM value received from the PC, amplified through an op-amp to meet the VU meter’s requirements.
        This will provide a physical and visual representation of the VRAM usage in real-time.

Data to Display:

    VRAM Usage:
        The first type of data to display will be the VRAM usage of the PC. A Python script on the server will gather this information using libraries like pyNVML (for Nvidia GPUs) or psutil for other data if needed.
        The data will be sent as JSON over WebSocket. For example:

        json

        {
          "type": "vram",
          "value": 60.5
        }

        The value field represents the percentage of VRAM usage, which will be interpreted by the ESP32 to control the VU meter through the DAC.

Future Extensions:

    Once the base project is functional (displaying VRAM on the VU meter), it will be easy to extend its functionality by adding other types of data (CPU, RAM, network, etc.) or additional components such as LEDs, buttons, or even OLED screens.
    The WebSocket communication structure and JSON format will allow for easy expansion of new information to be displayed without overhauling the project’s architecture.
    The idea is to keep the project modular to avoid distractions but ensure future scalability to add new features later.

Action Plan:

    WebSocket Implementation:
        Set up a WebSocket server in Python to gather and send VRAM data.
        Implement the WebSocket client on the ESP32 to receive and process this data.

    Wi-Fi and Network Setup:
        Configure the ESP32 to start in Access Point mode with a captive portal for entering Wi-Fi credentials, then connect to the local network.

    DAC and VU Meter:
        Drive the VU meter via the ESP32’s DAC and operational amplifier to display the data sent by the WebSocket server.

With this detailed description, you have a complete overview of the direction for the "Sysboy2000" project, along with the technical choices regarding communication, data structure, and hardware components.