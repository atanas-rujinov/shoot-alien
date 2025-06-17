#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6   // Pin connected to DIN

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  32, 8, LED_PIN,  // Width, Height, Pin
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,  
  NEO_GRB + NEO_KHZ800);

const char text[] = "SHOOT alien"; 
int head = 0;
int body = 0;
int arms = 0;
int legs = 0;
int HP = 100;

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(255);  // Adjust brightness (max 255)

  Serial.begin(9600);

  pinMode(A0, INPUT); // head
  pinMode(A5, INPUT); // body
  pinMode(A2, INPUT); // arm
  pinMode(A1, INPUT); // arm
  pinMode(A4, INPUT); // legs 

  displayHP(); // Show initial HP
}

void displayHP() {
  matrix.fillScreen(0); // Clear screen
  matrix.setCursor(0, 0);
  matrix.setTextColor(matrix.Color(0, 255, 0)); // Green text
  
  matrix.print(HP);
  matrix.show();
}

void loop() {
  head = analogRead(A0);
  if (head) {
    Serial.println("head");
    HP -= 100;
    displayHP();
    delay(1000);
    if (HP <= 0) {
    delay(3000);
    HP = 100;
    displayHP();
  }
  }

  body = analogRead(A5);
  if (body) {
    Serial.println("body");
    HP -= 50;
    displayHP();
    delay(1000);
    if (HP <= 0) {
    delay(3000);
    HP = 100;
    displayHP();
  }
  }



  if (HP <= 0) {
    delay(3000);
    HP = 100;
    displayHP();
  }
}
