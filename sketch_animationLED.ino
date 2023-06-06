#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int scrollPosition = 0;
const int scrollSpeed = 1;

void setup() {
  Serial.begin(9600);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true)
      ;
  }

  oled.clearDisplay();
  oled.setTextSize(2);
   oled.setTextColor(WHITE);
  // oled.setCursor(0, 0);
  // oled.println("Hello World!");
  // oled.display();
}

void loop() {
  oled.clearDisplay();

  // Update scroll position
  scrollPosition -= scrollSpeed;

  // Reset scroll position if it goes beyond the text length
  if (scrollPosition <= -oled.width()) {
    scrollPosition = SCREEN_WIDTH;
  }

  // // Set the new text position
  oled.setCursor(scrollPosition, 10);

  // Print the text
  oled.print("Hello World!");

  // Display the updated frame
  oled.display();
}
