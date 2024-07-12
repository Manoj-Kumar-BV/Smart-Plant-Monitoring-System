---

# 🌱 Smart Plant Monitoring System 🌿

## Overview

The Smart Plant Monitoring System is an IoT-based project designed to help farmers monitor and control various environmental factors in a greenhouse. The system uses sensors to measure soil moisture, temperature, humidity, and motion, and integrates with the Blynk platform to provide real-time data and alerts.

## Features

- **🌿 Soil Moisture Monitoring**: Measures soil moisture levels and sends data to the Blynk app.
- **🌡️ Temperature and Humidity Monitoring**: Uses a DHT11 sensor to monitor and report temperature and humidity levels.
- **🚨 Motion Detection**: Uses a PIR sensor to detect motion and send alerts.
- **💧 Automated Control**: Controls water pump and fan based on sensor data.
- **📲 Blynk Integration**: Provides real-time data visualization and control via the Blynk app.

## Hardware Requirements

- ESP8266 WiFi module
- DHT11 Temperature and Humidity Sensor
- Soil Moisture Sensor
- PIR Motion Sensor
- Relay Modules (2)
- Water Pump
- Fan
- Connecting Wires
- Breadboard or PCB

## Software Requirements

- Arduino IDE
- Blynk Library
- DHT Sensor Library

## Circuit Diagram



## Setup Instructions

1. **🔄 Clone the Repository**:
    ```sh
    git clone https://github.com/Manoj-Kumar-BV/Smart-Plant-Monitoring-System.git
    cd Smart-Plant-Monitoring-System
    ```

2. **⚙️ Install Dependencies**:
    - Open the Arduino IDE.
    - Go to `Sketch` -> `Include Library` -> `Manage Libraries`.
    - Install the `Blynk` and `DHT sensor library`.

3. **🔧 Configure Blynk**:
    - Replace `BLYNK_AUTH_TOKEN` in the code with your Blynk authentication token.
    - Replace `ssid` and `pass` with your WiFi SSID and password.

4. **⬆️ Upload the Code**:
    - Connect the ESP8266 module to your computer.
    - Open the `Smart_Plant_Monitoring_System.ino` file in the Arduino IDE.
    - Select the correct board and port.
    - Click `Upload`.

5. **🔌 Connect the Hardware**:
    - Assemble the circuit as per the circuit diagram.
    - Power up the system.

6. **📱 Monitor and Control**:
    - Open the Blynk app on your mobile device.
    - Monitor sensor readings and control the water pump and fan via the app.

## Code Overview

The code is structured to read data from sensors and send it to the Blynk app, as well as receive commands from the app to control the water pump and fan.

- **🔧 Setup**: Initializes sensors and Blynk connection.
- **🌡️ DHT11 Sensor**: Reads temperature and humidity data and sends it to Blynk.
- **🌿 Soil Moisture Sensor**: Reads soil moisture levels and sends them to Blynk.
- **🚨 PIR Sensor**: Detects motion and sends alerts to Blynk.
- **💧 Control Functions**: Controls the water pump and fan based on Blynk commands.

---
