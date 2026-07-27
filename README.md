# RFID-Access-System
A simple RFID access control system built using an ESP32 and an MFRC522 RFID reader.

## Features

- Reads RFID cards
- Verifies authorized UID
- Displays "Access Granted" or "Access Denied"
- Uses the ESP32 built-in LED as a status indicator

## Hardware

- ESP32 DevKit V1
- MFRC522 RFID Reader
- RFID Card/Tag
- Breadboard
- Jumper Wires

## Wiring

| RC522 | ESP32 |
|--------|--------|
| SDA | GPIO 5 |
| SCK | GPIO 18 |
| MOSI | GPIO 23 |
| MISO | GPIO 19 |
| RST | GPIO 22 |
| GND | GND |
| 3.3V | 3.3V |

## Software

- Arduino IDE
- MFRC522 Library
- ESP32 Board Package

## Future Improvements

- Servo-controlled door lock
- OLED display
- Buzzer
- Wi-Fi logging
- Web dashboard
