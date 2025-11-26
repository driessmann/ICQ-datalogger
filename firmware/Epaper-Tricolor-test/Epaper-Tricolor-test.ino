#include <Adafruit_EPD.h>

// ---------------------- PIN DEFINITIONS ----------------------
#define EPD_DC     10
#define EPD_CS      9
#define EPD_BUSY    7
#define EPD_RESET   8
#define SRAM_CS    -1      // IMPORTANT: Chinese board has NO external SRAM

// ---------------------- DISPLAY OBJECT -----------------------
// This is the correct class for 2.9" TRICOLOR SSD1680
Adafruit_SSD1680 display(296, 128, EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

void setup() {
  Serial.begin(115200);
  delay(200);

  Serial.println("Initializing SSD1680 Tricolor…");
  
  display.begin(EPD_RED);   // <-- IMPORTANT for red/black/white
  display.clearBuffer();
  display.display();             // initial clear
  delay(2000);
}

void loop() {

  // ---------------- Banner demo ----------------
  Serial.println("Banner demo…");
  display.clearBuffer();
  display.setTextSize(3);
  display.setCursor(20, 50);
  display.setTextColor(EPD_BLACK);
  display.print("Tri");
  display.setTextColor(EPD_RED);
  display.print("Color");
  display.display();   // this takes 6–15 seconds on tricolor
  delay(15000);

  // ---------------- Color bars ----------------
  Serial.println("Color bars…");
  display.clearBuffer();
  display.fillRect(0, 0, 98, 128, EPD_BLACK);
  display.fillRect(98, 0, 98, 128, EPD_RED);
  display.display();
  delay(15000);

  // ---------------- Text block ----------------
  Serial.println("Text demo…");
  display.clearBuffer();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.setTextColor(EPD_BLACK);
  display.print(
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
    "Curabitur adipiscing ante sed nibh tincidunt feugiat."
  );
  display.display();
  delay(15000);

  // ---------------- Line patterns ----------------
  Serial.println("Line pattern…");
  display.clearBuffer();

  for (int16_t i = 0; i < display.width(); i += 4) {
    display.drawLine(0, 0, i, display.height() - 1, EPD_BLACK);
    yield(); // prevents watchdog
  }
  for (int16_t i = 0; i < display.height(); i += 4) {
    display.drawLine(display.width() - 1, 0, 0, i, EPD_RED);
    yield(); // prevents watchdog
  }

  display.display();
  delay(15000);
}
