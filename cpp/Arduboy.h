#ifndef Arduboy_h
#define Arduboy_h

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <emscripten.h>
#include "avr.h"
#include "Arduino.h"
#include "core.h"
#include "logo.h"

#ifdef __cplusplus
extern "C" {
#endif
    //exported functions
    void setup();
    void loop();
    //js functions
    extern void jsBegin();
	extern void jsSetFrameRate(uint8_t rate);
	extern bool jsNextFrame();
    extern void jsSetCursor(int16_t x, int16_t y);
	extern void jsDisplay(unsigned char* buffer);
  	extern void jsPrint(const char *text);
    extern void jsClear();
}

class Arduboy : public ArduboyCore {
    public:
        Arduboy();
        /// Initializes the hardware
        void begin();
        void boot();
        /// Scrolls in the Arduboy logo
        void bootLogo();
        /// Clears display.
        void clear();
        void setFrameRate(uint8_t rate);
        bool nextFrame();
        /// Sets the location of the screen cursor.
        void setCursor(int16_t x, int16_t y);

        /// Copies the contents of the screen buffer to the screen.
        /**
         * X and Y positions on the display are from the top left corner, thus a Y of 64
         * is the bottom of the screen and an X of 128 is the right side of the screen.
         * "Color" or "value" means choosing whether a pixel is lit or not - if color is
         * 0, the pixel is off (black), if color is 1, the pixel is on (white).
         */
        void display();


        /// Draws a bitmap from program memory to a specific X/Y
        void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t color);
        void fillScreen(uint8_t color);
        void drawPixel(int x, int y, uint8_t color);
  
        //<Print.h>
        void print(const char* text);

    protected:
        unsigned char sBuffer[(HEIGHT*WIDTH)/8];

};

#endif /* ARDUBOY_H */