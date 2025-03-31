#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9  // Reset pin
#define SS_PIN 10  // Slave select pin

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create an MFRC522 instance

void setup() {
    Serial.begin(9600);  // Initialize Serial Monitor
    SPI.begin();  // Start SPI communication
    mfrc522.PCD_Init();  // Initialize the RFID module
    Serial.println("Scan an RFID tag...");
}

void loop() {
    // Check if a new card is present
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

    // Select one of the cards
    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }

    // Read the UID and format it as a string
    String cardUID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        cardUID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");  // Ensure two-digit format
        cardUID += String(mfrc522.uid.uidByte[i], HEX);  // Convert to HEX format
    }

    cardUID.toUpperCase();  // Convert to uppercase for readability

    // Print UID to Serial Monitor
    Serial.println(cardUID);

    delay(2000);  // Delay to prevent multiple reads of the same card
}
