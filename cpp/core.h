#ifndef ArduboyCore_h
#define ArduboyCore_h

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "avr.h"

#define WIDTH 128
#define HEIGHT 64

#define INVERT 2 //< lit/unlit pixel
#define WHITE 1 //< lit pixel
#define BLACK 0 //< unlit pixel

class ArduboyCore
{
public:
    ArduboyCore();
    void static idle();
    void static LCDDataMode();
    void static LCDCommandMode();
    uint8_t static width();
    uint8_t static height();
    uint8_t static getInput(); __attribute__ ((deprecated("use buttonsState() instead")));
    uint8_t static buttonsState();
    void static paint8Pixels(uint8_t pixels);
    void static paintScreen(const unsigned char *image);
    void static paintScreen(unsigned char image[]);
    void static blank();
    void static invert(boolean inverse);
    void static allPixelsOn(boolean on);
    void static flipVertical(boolean flipped);
    void static flipHorizontal(boolean flipped);
    void static sendLCDCommand(uint8_t command);
    void setRGBled(uint8_t red, uint8_t green, uint8_t blue);

protected:
    void static inline safeMode() __attribute__((always_inline));
    void static inline bootLCD() __attribute__((always_inline));
    void static inline bootPins() __attribute__((always_inline));
    void static inline slowCPU() __attribute__((always_inline));
    void static inline saveMuchPower(); __attribute__((always_inline));

};

#endif