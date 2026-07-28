#include <SPI.h>
#include <MFRC522.h>
#include <Preferences.h>

#define SS_PIN 5
#define RST_PIN 22
#define LED_PIN 2

MFRC522 rfid(SS_PIN, RST_PIN);

Preferences preferences;


// Admin card
byte adminUID[] = {0x23, 0x82, 0x2B, 0xD8};

bool registrationMode = false;


void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  SPI.begin(18, 19, 23, SS_PIN);
  rfid.PCD_Init();

  preferences.begin("RFID", false);

  Serial.println("RFID System Ready");
  Serial.println("Tap your card...");
}


void loop() {

  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;


  // Admin card
  if (checkUID(adminUID)) {

    Serial.println("Admin Mode Activated");
    Serial.println("Scan card to register");

    registrationMode = true;

  }


  // Register new card
  else if (registrationMode) {

    Serial.println("Saving card...");

    preferences.putBytes(
      "userCard",
      rfid.uid.uidByte,
      4
    );

    Serial.println("Card Saved Successfully!");

    registrationMode = false;

    digitalWrite(LED_PIN, HIGH);
    delay(2000);
    digitalWrite(LED_PIN, LOW);

  }


  // Check saved card
  else {

    byte savedUID[4];

    preferences.getBytes(
      "userCard",
      savedUID,
      4
    );


    if (checkSavedUID(savedUID)) {

      Serial.println("Access Granted");

      digitalWrite(LED_PIN, HIGH);
      delay(1000);
      digitalWrite(LED_PIN, LOW);

    }

    else {

      Serial.println("Access Denied");

    }

  }


  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

}



bool checkUID(byte storedUID[]) {

  for (byte i = 0; i < 4; i++) {

    if (rfid.uid.uidByte[i] != storedUID[i])
      return false;

  }

  return true;

}



bool checkSavedUID(byte savedUID[]) {

  for (byte i = 0; i < 4; i++) {

    if (rfid.uid.uidByte[i] != savedUID[i])
      return false;

  }

  return true;

}