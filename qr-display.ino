#include <Arduino.h>
#include <TFT_eSPI.h> // Hardware-specific library for the display
#include <qrcode.h>   // Library to generate the QR code matrix

// Initialize the TFT display object
TFT_eSPI tft = TFT_eSPI(); 

void setup() {
  // Start the serial communication for debugging (optional)
  Serial.begin(115200);
  
  // Initialize the display
  tft.init();
  
  // Set rotation to 0 (Portrait mode). 
  // The T-Display-S3 is 170 pixels wide and 320 pixels tall in this mode.
  tft.setRotation(0); 
  
  // Fill the screen with white. QR codes need a light background and dark foreground.
  tft.fillScreen(TFT_WHITE);

  // --- QR CODE GENERATION SETUP ---
  
  // The text or URL you want the QR code to contain
  const char* qrText = "https://raspberrypi.tailcda191.ts.net/";
  
  // Create the QR code object
  QRCode qrcode;
  
  // Define the QR Code version (Size/Capacity). 
  // Version 3 is 29x29 modules (blocks), which is perfect for most URLs.
  uint8_t qrcodeVersion = 3;
  
  // Allocate memory for the QR code calculation. 
  // qrcode_getBufferSize calculates the exact byte array size needed.
  uint8_t qrcodeData[qrcode_getBufferSize(qrcodeVersion)];
  
  // Initialize the QR code.
  // Parameters: object, buffer, version, error correction level (0=Low), text
  qrcode_initText(&qrcode, qrcodeData, qrcodeVersion, 0, qrText);

  // --- DRAWING THE QR CODE ---
  
  // The screen is 170 pixels wide. A Version 3 QR code is 29x29 "modules" (dots).
  // 170 / 29 = ~5.8. So, a scale of 5 pixels per module fits nicely.
  int scale = 5; 
  
  // Calculate the total size of the drawn QR code in pixels
  int qrRealSize = qrcode.size * scale;
  
  // Calculate offsets to center the QR code on the 170x320 screen
  int offsetX = (170 - qrRealSize) / 2; // Centers horizontally
  int offsetY = (320 - qrRealSize) / 2; // Centers vertically

  // Loop through the QR code matrix (Y axis)
  for (uint8_t y = 0; y < qrcode.size; y++) {
    // Loop through the QR code matrix (X axis)
    for (uint8_t x = 0; x < qrcode.size; x++) {
      
      // Check if the current module should be black
      if (qrcode_getModule(&qrcode, x, y)) {
        // Draw a black rectangle (scaled up pixel) at the correct position
        tft.fillRect(offsetX + (x * scale), offsetY + (y * scale), scale, scale, TFT_BLACK);
      }
      // We don't need an 'else' to draw white because we already filled the screen white!
    }
  }
}

void loop() {
  // Nothing to do here. The QR code is drawn once in setup() and stays on the screen.
}
