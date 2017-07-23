/* ****************************************************************************************
   Example #4: Example of how to use light and dark greylevels besides black and white.
   More details can be found in the online tutorial @https://robpo.github.io/Paperino
   
   We invested time and resources providing this open source code. Please support Paperino 
   open source hardware by purchasing this product @Crowdsupply @Paperino @Plasticlogic 
   https://www.crowdsupply.com/robert-poser/paperino 
   Created by Robert Poser, May 18th 2017, Dresden/Germany
**************************************************************************************** */
#include "Adafruit_GFX.h"
#include "PL_microEPD.h"

#define EPD_RST     A0
#define EPD_BUSY    A1
#define EPD_CS      A2

PL_microEPD display(EPD_CS, EPD_RST, EPD_BUSY);

void setup() {
    SPI.begin();                    // SPI-Bus initialisation
    SPI.setBitOrder(MSBFIRST);                 
    SPI.setDataMode(SPI_MODE0); 
    SPI.setClockDivider(SPI_CLOCK_DIV4);
    
    display.begin();                // Paperino ePaper initialisation and refresh screen

    display.setCursor(8,28);
    display.setTextSize(2);
    display.println("Gray Levels");
    display.update();
    delay(2000);
    
    display.clear();
    display.setCursor(45,15);
    display.println("Black");
    display.update();
    delay(500);
    display.fillRect(10, 37, 128, 25, EPD_BLACK);   // Color = BLACK
    display.update(EPD_UPD_PART);
    delay(2000);
    
    display.clear();
    display.setCursor(19,15);
    display.println("Dark Gray");
    display.update();
    delay(500);
    display.fillRect(10, 37, 128, 25, EPD_DGRAY);   // Color = DARK GRAY
    display.update(EPD_UPD_PART);
    delay(2000);

    display.clear();
    display.setCursor(15,15);
    display.println("Light Gray");
    display.update();
    delay(500);
    display.fillRect(10, 37, 128, 25, EPD_LGRAY);   // Color = LIGHT GRAY
    display.update(EPD_UPD_PART);
    delay(2000);
    
    display.clear();
    display.setCursor(45,15);
    display.println("White");
    display.update();
    delay(500);
    display.drawRect(10, 37, 128, 25, EPD_BLACK);   
    display.update(EPD_UPD_PART);
    delay(2000);
    
    display.clear();
    display.drawRect(9, 21, 130, 30, EPD_BLACK);
    display.update();
    display.fillRect(10, 22, 33, 28, EPD_BLACK);
    display.update(EPD_UPD_PART);
    display.fillRect(43, 22, 33, 28, EPD_DGRAY);
    display.update(EPD_UPD_PART);
    display.fillRect(76, 22, 32, 28, EPD_LGRAY);
    display.update(EPD_UPD_PART);
}

void loop() {
}