#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


// Function to draw a heart symbol
void drawHeart(int x, int y) {
  display.fillCircle(x, y, 3, WHITE);      // Left half of the heart
  display.fillCircle(x + 6, y, 3, WHITE);  // Right half of the heart
  display.fillTriangle(x - 3, y + 1, x + 9, y + 1, x + 3, y + 10, WHITE);  // Bottom triangle
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize display with I2C address 0x3C
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);


  // Display the text "Norain"
  display.setCursor(0, 0);
  display.print("Norain");

  // Display the heart symbol using the drawHeart function
  drawHeart(5, 20); // Adjust coordinates as needed to position the heart
  
  display.println();
  // Display the text "kamal!" next to the heart
  display.setCursor(0, 40);
  display.println("kamal!");

  // Render the display
  display.display();
}

void loop() {
  // No need to repeat code in loop, as display is static
}
