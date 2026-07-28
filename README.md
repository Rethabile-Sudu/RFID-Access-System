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

## Development Progress

### Version 2 - Admin and User Authentication

The RFID system was upgraded from a basic UID reader into an access control system with different user roles.

### Admin Card

The Admin card is used to activate registration mode and add new RFID users.

Admin UID: 23 82 2B D8

Admin functions:
- Activates registration mode
- Allows new cards to be registered

---

### User Card Registration

A user registration system was implemented.

Workflow:

1. Admin card is scanned
2. ESP32 enters registration mode
3. New RFID card/tag is scanned
4. UID is stored in ESP32 memory
5. Registered users can access the system

Example registered user: 29 FD 09 07

## Permanent Storage

The ESP32 now uses internal memory storage to save registered RFID cards.

This means:

✅ Registered cards remain saved after restarting the ESP32  
✅ No external database required  
✅ User authentication works after power cycling

---

## Current Features

- ESP32 RFID reader system
- RC522 RFID module integration
- Admin authentication
- User registration
- Permanent UID storage
- Access granted/denied logic
- LED feedback

---

## Future Improvements

- Multiple registered users
- Delete users using Admin card
- OLED display interface
- Buzzer notifications
- Web-based user management dashboard
- NFC tag integration
