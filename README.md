# 2022_Scrolling_Message_v4_class
files needed for Jan 2022 class project


# 2022_ESP32MessageBoard_Neomatrix

## Description
This project is intended for use with an ESP32 microcontroller, DS3231 I2C RTC module and 4 8x8 NeoMatrix boards.
The display will scroll through a sequence displaying:
* Current Time
* Temperature
* Day of the week
* Day and Month
* Custom Message
The time and message can be set using the build in webserver.

## Getting Started
Project build with Visual Studio Code and PlatformIO.

![Matrix Display](https://github.com/VostroDev/2022_ESP32MessageBoard_Neomatrix/blob/master/doc/matrix.png)

![Web Server](https://github.com/VostroDev/2022_ESP32MessageBoard_Neomatrix/blob/master/doc/webserver.png)

### Dependencies
* Arduino IDE - https://www.arduino.cc/en/software
* ESP8266 Dev board - https://www.communica.co.za/products/dfr-firebeetle-esp8266-iot-micro
* Max7219 Dot matrix display - https://www.communica.co.za/products/bmt-4xdot-matrix-module-max7219

## Authors

Contributors names and contact info

* [R Wilson](vostrodev@gmail.com)  

## Version History

* 4.0
    * Initial Release for Class
    
## Acknowledgments

All credit attributes of the various authors of the libraries used.

* [Adafruit - RTC Lib](https://github.com/adafruit/RTClib)
* [ArduinoJson - Benoit Blanchon](https://arduinojson.org)
* [MD_MAX72xx - MajicDesigns](https://github.com/MajicDesigns/MD_MAX72xx)
* [MD_Parola  - MajicDesigns](https://github.com/MajicDesigns/MD_Parola)

