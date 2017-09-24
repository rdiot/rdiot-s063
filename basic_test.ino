/* Temperature and humidity DHT22 (DHT22) [S063] : http://rdiot.tistory.com/65 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
#define DHTPIN 2     // what pin we're connected to

DHT dht(DHTPIN, DHT22);

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  delay(1000);

  lcd.clear();
}

void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S063:DHT22");

  switch(dht.read())
  {
    case DHT_OK:
      lcd.setCursor(0,1);
      lcd.print("temperature=" + (String)dht.temperature + "'C");
      lcd.setCursor(0,2);
      lcd.print("humidity=" + (String)dht.humidity + "% ");
      break;
    case DHT_ERR_CHECK:
      lcd.setCursor(0,3);
      lcd.print("DHT CHECK ERROR  ");
      break;
    case DHT_ERR_TIMEOUT:
      lcd.setCursor(0,3);
      lcd.print("DHT TIMEOUT ERROR");
      break;
    default:
      lcd.setCursor(0,3);
      lcd.print("UNKNOWN ERROR    ");
      break;

    }
    delay(2000);
}
