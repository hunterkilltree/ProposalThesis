/*
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
*/
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9 // Configurable, see typical pin layout above
#define SS_PIN 10 // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

void setup_sensor_pos()
{
    SPI.begin();        // Init SPI bus
    mfrc522.PCD_Init(); // Init MFRC522 card
}

String read_pos()
{

    // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
    MFRC522::MIFARE_Key key;
    for (byte i = 0; i < 6; i++)
        key.keyByte[i] = 0xFF;

    //some variables we need
    byte block;
    byte len;
    MFRC522::StatusCode status;

    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return "false";
    }
    // Select one of the cards
    if (!mfrc522.PICC_ReadCardSerial())
    {
        return "false";
    }

    String content = "";

    byte buffer1[18];
    block = 4;
    len = 18;

    // Read first value; eo check error
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(mfrc522.uid)); //line 834 of MFRC522.cpp file
    status = mfrc522.MIFARE_Read(block, buffer1, &len);

    // Read second value; eo check error
    byte buffer2[18];
    block = 1;
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid));
    status = mfrc522.MIFARE_Read(block, buffer2, &len);

    for (uint8_t i = 0; i < 16; i++)
    {
        if (buffer1[i] != 32)
        {
            // Serial.write(buffer1[i]);
            content.concat((char)buffer1[i]);
          
        }
    }

    content.concat(" ");
    
    for (uint8_t i = 0; i < 16; i++)
    {
        if (buffer2[i] != 32)
        {
            // Serial.write(buffer2[i]);
            content.concat((char)buffer2[i]);
        }
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    return content; //content.toUpperCase();
}
