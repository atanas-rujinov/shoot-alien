#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6  // Pin connected to DIN

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  32, 8, LED_PIN,  // Width, Height, Pin
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,  
  NEO_GRB + NEO_KHZ800);

const char text[] = "SHOOT DIDDY"; 

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(10);  // Adjust brightness (max 255)
}

void loop() {
  static int scrollX = matrix.width(); // Start text off-screen
  static int charWidth = 6;  // Approximate width of a character in pixels
  static int textWidth = strlen(text) * charWidth; // Calculate total text width

  // Fill the entire background with white
  for (int x = 0; x < matrix.width(); x++) {
    for (int y = 0; y < matrix.height(); y++) {
      matrix.drawPixel(x, y, matrix.Color(255, 255, 255)); // White background
    }
  }

  // Draw the scrolling text
  matrix.setCursor(scrollX, 1);
  matrix.setTextColor(matrix.Color(255, 20, 147)); // Pink text
  matrix.print(text);
  matrix.show();

  // Move text left
  scrollX--;

  // Reset text position when fully scrolled out
  if (scrollX < -textWidth) {
    scrollX = matrix.width();
  }

  delay(100); // Adjust speed
}
