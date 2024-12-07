# Wemos_GC9A01A
Wemos D1 mini kartı ile GC9A01A ekranında logo yazdırma yapılması

Logo Display on TFT LCD with Wemos D1 Mini and GC9A01A
Bu proje, Wemos D1 Mini kartı kullanarak bir GC9A01A 240x240 TFT LCD ekranında logo görüntülemeyi amaçlamaktadır. Proje, Adafruit_GFX ve Adafruit_GC9A01A kütüphanelerini kullanarak RGB565 formatındaki bir görseli TFT ekran üzerinde gösterir. Görsel, Image Converter programı ile dönüştürülüp Arduino kodunda bir dizi olarak tanımlanır.

**Proje Özeti**
Bu projede, Wemos D1 Mini mikrodenetleyicisi ve 240x240 çözünürlükteki GC9A01A TFT LCD ekran kullanılarak, RGB565 formatındaki bir logo görseli ekranda gösterilmektedir. Resim dosyası, LCD Image Converter programı kullanılarak uygun formata dönüştürülmüş ve sonra Arduino kodu içinde dizi olarak tanımlanmıştır. Wemos D1 Mini, ekran ile iletişim kurarak logoyu başarıyla görüntüler.

**Kullanılan Kütüphaneler**
Adafruit_GFX: Grafik işlemleri için kullanılan temel kütüphane.
Adafruit_GC9A01A: GC9A01A ekranını kontrol etmek için kullanılan kütüphane.
Bağlantı Şeması
Wemos D1 Mini ile GC9A01A TFT LCD ekran arasındaki bağlantılar şu şekildedir:

TFT_MOSI (Wemos D1 Mini Pin D7) -> LCD MOSI (Data Pin)

TFT_SCLK (Wemos D1 Mini Pin D5) -> LCD SCLK (Clock Pin)

TFT_CS (Wemos D1 Mini Pin D8) -> LCD Chip Select

TFT_DC (Wemos D1 Mini Pin D4) -> LCD Data/Command Pin

TFT_RST (Wemos D1 Mini Pin D3) -> LCD Reset Pin


**Kod Açıklaması**

**1.** Kütüphaneler
Projede kullanılan temel kütüphaneler Adafruit_GFX ve Adafruit_GC9A01A kütüphaneleridir. Adafruit_GFX kütüphanesi ekran üzerinde grafik işlemleri yapmayı sağlar, Adafruit_GC9A01A kütüphanesi ise GC9A01A ekranını kontrol eder.

```cpp
#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>
```

**2.** Pin Tanımlamaları
Ekran bağlantılarında kullanılan Wemos D1 Mini'nin GPIO pinleri şu şekilde tanımlanır:

```cpp
#define TFT_MOSI 13  // D7
#define TFT_SCLK 14  // D5
#define TFT_CS   15  // D8
#define TFT_DC    2  // D4
#define TFT_RST   0  // D3
```

**3.** Ekran Başlatma
Ekran başlatılmadan önce, Adafruit_GC9A01A sınıfı ile ekran nesnesi oluşturulur ve begin() fonksiyonu ile ekran başlatılır. Bu fonksiyon, ekranın doğru bir şekilde çalışmasını sağlar.
```cpp
Adafruit_GC9A01A tft = Adafruit_GC9A01A(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);  // Seri portu başlat
  Serial.println("Ekran Başlatılıyor...");
  tft.begin();  // Ekranı başlat
  tft.setRotation(2);  // Ekran yönünü ayarla
  tft.fillScreen(GC9A01A_BLACK);  // Ekranı siyah ile doldur
  tft.setTextColor(GC9A01A_WHITE);  // Yazı rengini beyaz yap
  tft.setTextSize(2);  // Yazı boyutunu ayarla
}
```

**4.** Logo Görüntüleme
Kodda, logo verisi bir dizi olarak tanımlandıktan sonra drawRGBBitmap fonksiyonu ile ekran üzerine yazdırılır. Burada, RGB565 formatındaki dönüştürülmüş logo verileri example_image dizisi içinde yer alır.

```cpp
tft.drawRGBBitmap(0, 0, example_image, 240, 240);
```

**5.** Image Converter Kullanımı
Logo resminizi Image Converter programı ile uygun formata dönüştürdünüz. Bu araç, RGB565 formatına dönüştürerek resmin her pikselini bir renk değeriyle ifade eder. Sonrasında dönüştürülmüş resmi Arduino kodunda kullanmak üzere bir dizi olarak ekleriz.

Image Converter kullanarak dönüştürme adımlarını şu şekilde özetleyebilirsiniz:

Resmi Yükleyin: Logonuzun resmini Image Converter'a yükleyin.
Format Seçimi: Çıktı formatı olarak RGB565 veya RGB888 seçin.
Boyutlandırma: Logonuzun ekranınıza uygun boyutlarda olduğundan emin olun (bu projede 240x240).
Dönüştürme: Resmi dönüştürün ve sonucu Arduino'ya uygun formatta bir dizi olarak çıkarın.
Kodu Ekleyin: Dönüştürülmüş veriyi Arduino kodunuza example_image gibi bir dizi olarak ekleyin.
Dönüştürülmüş resmin kodu şu şekilde görünebilir:

```cpp
const uint16_t example_image[57600] = {
  // RGB565 formatındaki pikseller burada yer alacak
};
```

Proje Kurulumu
Bu projeyi çalıştırmak için aşağıdaki adımları takip edebilirsiniz:

**Gerekli Kütüphaneler:**

Adafruit_GFX ve Adafruit_GC9A01A kütüphanelerini Arduino IDE'nin Library Manager üzerinden yükleyin.

![1](https://github.com/user-attachments/assets/7b377d27-1827-4b96-816d-a5f08cc695cb)
![2](https://github.com/user-attachments/assets/29dc5d8c-f97b-4156-9590-a0b4db61a376)

**Donanım Bağlantıları:**

Ekran ile Wemos D1 Mini arasındaki bağlantıları yukarıda belirtilen pinlere göre yapın.
Arduino IDE:

Wemos D1 Mini kart desteğinin kurulu olduğundan emin olun.
Projeyi yükleyin ve Wemos D1 Mini'yi programlayın.

**Sonuç**

Bu proje, Wemos D1 Mini ile bir GC9A01A 240x240 TFT LCD ekranında RGB565 formatındaki bir logoyu başarıyla görüntülemenizi sağlar. Image Converter programı sayesinde resminizi uygun formata dönüştürüp Arduino kodunda kullanabilirsiniz. Bu tür projeler, görsel içerikleri mikrodenetleyici tabanlı sistemlere aktarmak için oldukça kullanışlıdır.
