# Robotic Fish with ESP8266 and Blynk

## Overview
This project implements a biomimetic robotic fish that mimics natural fish fin propulsion using servo motors controlled by an ESP8266 microcontroller. The fin movement — including amplitude, frequency, and directional steering — can be adjusted in real-time via smartphone sliders using the Blynk IoT platform over Wi-Fi.

---

## Features
- Realistic fin oscillation mimicking fish locomotion.
- Adjustable fin swing amplitude and frequency for speed control.
- Directional steering via turn offset adjustment.
- Remote control through smartphone app using Blynk sliders.
- Non-blocking servo control using `millis()` for smooth motion.
- Wi-Fi enabled control with ESP8266 for flexible and wireless operation.

---

## Hardware Components
- ESP8266 NodeMCU or similar Wi-Fi microcontroller
- Servo motor (e.g., SG90 or MG90S)
- External 5V power supply for servo (recommended)
- Connecting wires and breadboard

---

## Software Requirements
- Arduino IDE with ESP8266 board support installed
- Blynk library for Arduino
- Servo library (included in Arduino IDE)

---

## Setup Instructions

### 1. Hardware Connections
- Connect servo signal pin to ESP8266 GPIO pin D4 (GPIO2).
- Connect servo power to external 5V supply and ground to common ground with ESP8266.
- Connect ESP8266 to your computer for programming.

### 2. Blynk App Setup
- Download and install the Blynk app on your smartphone.
- Create a new project selecting ESP8266 as the device.
- Add three sliders linked to virtual pins:
  - V0: Amplitude (0 - 90)
  - V1: Frequency (1 - 10)
  - V2: Turn Offset (-30 to 30)
- Copy the generated Auth Token.

### 3. Code Configuration
- Open the Arduino sketch.
- Replace the placeholders with your Wi-Fi SSID, password, and Blynk Auth Token.
- Upload the code to your ESP8266 board.

### 4. Operation
- Power on the ESP8266 and servo.
- Open the Blynk app and connect to your project.
- Adjust sliders to control the fin’s amplitude, frequency, and turning offset in real-time.
- Observe the fin oscillation mimicking fish swimming motion.

---

## Code Structure
- `setup()`: Initializes servo, Wi-Fi, and Blynk connection.
- `loop()`: Runs Blynk handler and updates servo position based on timing.
- `BLYNK_WRITE(Vx)`: Functions handle slider input to update control parameters.
