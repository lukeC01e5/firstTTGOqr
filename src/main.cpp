#include <Arduino.h>
#include <TFT_eSPI.h>       // Include the TFT library
#include <SPI.h>            // Include the SPI library
#include <HardwareSerial.h> // Include the HardwareSerial library

TFT_eSPI tft; // Create an instance of the TFT class

HardwareSerial mySerial(1); // Use the second hardware serial port

void setup()
{
    Serial.begin(115200);
    mySerial.begin(9600, SERIAL_8N1, 27, 26); // Initialize serial communication on pins 27 (RX) and 26 (TX)
    tft.init();                               // Initialize the TFT display
    tft.setRotation(1);                       // Set the display rotation (if needed)
    tft.fillScreen(TFT_BLACK);                // Clear the display
}

void loop()
{
    if (mySerial.available())
    {
        String barcode = mySerial.readString();
        if (!barcode.isEmpty())
        {
            tft.setTextSize(2);
            tft.setTextColor(TFT_WHITE);
            tft.setCursor(0, tft.getCursorY() + 20); // Move the cursor down
            tft.println(barcode);
        }
        else
        {
            Serial.println("Empty barcode");
        }
    }
}
