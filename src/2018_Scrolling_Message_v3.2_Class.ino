/*----------------------------------------------------------------------------------------
  17/07/2019
  Author: R WILSON
  Platforms: ESP8266 NODEMCU
  Version: 4.0.0 - 11 JAN 2022
  Language: C/C++/Arduino
  File: 2022_Scrolling_Message_v4.ino
  ----------------------------------------------------------------------------------------
  Description:
  ESP8266 connected to MAX7219 LED matrix displays using Hardware SPI
  HARDWARE_TYPE MD_MAX72XX::FC16_HW
  MAX_DEVICES 4
  CLK_PIN  D5  ESP8266 SCK  (brown)
  DATA_PIN D7  ESP8266 MOSI (orange)
  CS_PIN   D6  ESP8266 SS   (red)
  RTC DS3231 I2C - SDA(D3) and SCL(D4)
  TEMP SENSOR BUILD INTO DS3231
  ----------------------------------------------------------------------------------------
  Libraries:
  https://arduino.esp8266.com/stable/package_esp8266com_index.json
  Boards URL for ESP8266 http://arduino.esp8266.com/stable/package_esp8266com_index.json
  MAX7219 Dot matrix lib https://github.com/MajicDesigns/MD_MAX72xx (lib version 3.3.0)
  MAX7219 Effects lib https://github.com/MajicDesigns/MD_Parola     (lib version 3.5.6)
  Adafruit RTC Lib: https://github.com/adafruit/RTClib              (lib version 2.0.1)
  ArduinoJson Benoit Blanchon: https://arduinojson.org              (lib version 6.18.5)
  
  Connect to ESPMessageBoard WIFI AP created by ESP8266  
  Open browser to http://1.2.3.4 or www.message.com
  Password: password or 12345678
  Enter message to be displayed on the MAX7219 scrolling display
----------------------------------------------------------------------------------------*/

void setup()  // add your code here
{

}

void loop()
{

}