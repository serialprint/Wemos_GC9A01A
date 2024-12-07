#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>

// Ekran pinlerini tanımla
#define TFT_MOSI 13  // D7 
#define TFT_SCLK 14  // D5
#define TFT_CS   15  // D8
#define TFT_DC    2  // D4
#define TFT_RST   0  // D3

Adafruit_GC9A01A tft = Adafruit_GC9A01A(TFT_CS, TFT_DC, TFT_RST);

// 240x240 boyutlu örnek bir resim (örnek bitmap array)
#include "example_image.h"  // Resim verisini buradan çekiyoruz

void setup() {
  tft.begin();
  tft.setRotation(2);  // Döndürme

  // Ekranda resmi göster
  tft.drawRGBBitmap(0, 0, example_image, 240, 240);
}

void loop() {
  // Boş bırakılabilir
}
