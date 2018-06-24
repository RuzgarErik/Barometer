#include <Wire.h> //SPI K�t�phanesi tan�mland�
#include <Adafruit_BMP085.h> //Bmp 180 K�t�phanesi Tan�mland�		
#include <LCD5110_Basic.h> //5510 k�t�phanesi tan�mland�
Adafruit_BMP085 bmp; //bmp 180 k�t�phanesi ba�lat�ld�
LCD5110 myGLCD(8,9,10,11,12);//5110 pinleri tan�mland�     
extern uint8_t BigNumbers[]; //B�y�kfont Tan�nmland�
extern uint8_t SmallFont[];//K���kfont Tan�mland�

// You could use a spare Hardware Serial on boards that have it (like Mega)

void setup() {
  myGLCD.InitLCD(); //5110 Lcd Ba�lat�ld�
  Serial.begin(9600);//Seri Port Ba�lat�ld�
  if (!bmp.begin()) {
  Serial.print("Hata,Kablolamay� Kontrol Edin");
    while (1) {}
  }
  Serial.print(" RUZGAR ICAT SIRKETI");
  delay(3000);
}
   
void loop() {
  myGLCD.setFont(SmallFont); //K���kfont Ayarland�
  myGLCD.print("Basinc(hPa):",LEFT,10);  //Ekrana bas�n� yaz�s� yazd�r�ld�
  myGLCD.setFont(BigNumbers); //B�y�k Numara fontu ayarland�       
  myGLCD.printNumI(bmp.readPressure()/100,20,20); //Ekrana bas�n� yaz�d�r�ld�
  Serial.println(bmp.readPressure()/100); //Seri porta bas�n� yazd�r�ld�
  Serial.print("hPa"); //Seri porta bas�n� birimi yazd�r�ld�.
  delay(3000); //3 sn Bekleme
  myGLCD.clrScr(); //Ekran� temizle
  myGLCD.setFont(SmallFont); //K���kfont ayarla
  myGLCD.print("Yukseklik(m):",LEFT,10); //Ekrana y�kseklik yazd�r�ld�
  myGLCD.setFont(BigNumbers); //B�y�k Numara Fontu Ayarland�
  myGLCD.printNumI(bmp.readAltitude(),20,20); //Y�kseklik Ekrana yazd�r�ld�
  Serial.println(bmp.readAltitude()); //Seri porta y�kseklik yazd�r�ld�
  Serial.print("m"); //Seri porta birim yazd�r�ld�
  delay(3000); //3 sn Bekleme
  myGLCD.clrScr(); // Ekran temizlendi
  myGLCD.setFont(SmallFont); //K���k font ayarland�
  myGLCD.print("Sicaklik (c):",LEFT,10); //S�cakl�k ekrana yazd�r�ld�
  myGLCD.setFont(BigNumbers); //B�y�k Numara fontu ayarland�
  myGLCD.printNumI(bmp.readTemperature(),20,20); //S�cakl�k ekrana yaz�d�ld�
 Serial.println(bmp.readTemperature()); //Seriporta s�cakl�k yazd�r�ld�  
 Serial.print("c"); //Seri porta s�cakl�k birimi yazd�r�ld�
  delay(3000); //3sn bekleme
}
