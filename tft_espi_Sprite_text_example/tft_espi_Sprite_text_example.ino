#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft); // Create sprite object
void setup() 
{
  tft.begin();
  tft.setRotation(2);
  tft.invertDisplay(1); // depending on the variant of LCD being used
  tft.fillScreen(TFT_BLACK);
  tft.startWrite(); 
}

void loop() 
{
  img.createSprite(240, 50); // Create a 100x30 pixel buffer
  img.fillSprite(TFT_BLACK);  // Clear the buffer off-screen
  img.setTextColor(TFT_WHITE);
  img.setFreeFont(&FreeSansBold18pt7b);
  img.drawString("Flick Free", 0, 0); 
  img.pushSprite(0, 80);       // Push the finished image to the screen
  img.deleteSprite();        // Free memory when done
}
