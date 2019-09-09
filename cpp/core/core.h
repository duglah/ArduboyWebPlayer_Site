#ifndef ArduboyCore_h
#define ArduboyCore_h

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../avr.h"

// main hardware compile flags

#if !defined(ARDUBOY_10) && !defined(AB_DEVKIT)
/// defaults to Arduboy Release 1.0 if not using a boards.txt file
/**
 * we default to Arduboy Release 1.0 if a compile flag has not been
 * passed to us from a boards.txt file
 *
 * if you wish to compile for the devkit without using a boards.txt
 * file simply comment out the ARDUBOY_10 define and uncomment
 * the AB_DEVKIT define like this:
 *
 *     // #define ARDUBOY_10
 *     #define AB_DEVKIT
 */     
#define ARDUBOY_10   //< compile for the production Arduboy v1.0
// #define AB_DEVKIT    //< compile for the official dev kit
#endif


#ifdef AB_DEVKIT
#define DEVKIT       //< for compatibilty with older sketches
#define SAFE_MODE    //< include safe mode (44 bytes)
#endif 


#ifdef ARDUBOY_10

#define CS 12
#define DC 4
#define RST 6

#define RED_LED 10
#define GREEN_LED 11
#define BLUE_LED 9
#define TX_LED 30
#define RX_LED 17

// pin values for buttons, probably shouldn't use these
#define PIN_LEFT_BUTTON A2
#define PIN_RIGHT_BUTTON A1
#define PIN_UP_BUTTON A0
#define PIN_DOWN_BUTTON A3
#define PIN_A_BUTTON 7
#define PIN_B_BUTTON 8

// bit values for button states
#define LEFT_BUTTON _BV(5)
#define RIGHT_BUTTON _BV(6)
#define UP_BUTTON _BV(7)
#define DOWN_BUTTON _BV(4)
#define A_BUTTON _BV(3)
#define B_BUTTON _BV(2)

#define PIN_SPEAKER_1 5
#define PIN_SPEAKER_2 13

#define PIN_SPEAKER_1_PORT &PORTC
#define PIN_SPEAKER_2_PORT &PORTC

#define PIN_SPEAKER_1_BITMASK _BV(6)
#define PIN_SPEAKER_2_BITMASK _BV(7)

#elif defined(AB_DEVKIT)

#define CS 6
#define DC 4
#define RST 12

// map all LEDs to the single TX LED on DEVKIT
#define RED_LED 17
#define GREEN_LED 17
#define BLUE_LED 17
#define TX_LED 17
#define RX_LED 17

// pin values for buttons, probably shouldn't use these
#define PIN_LEFT_BUTTON 9
#define PIN_RIGHT_BUTTON 5
#define PIN_UP_BUTTON 8
#define PIN_DOWN_BUTTON 10
#define PIN_A_BUTTON A0
#define PIN_B_BUTTON A1

// bit values for button states
#define LEFT_BUTTON _BV(5)
#define RIGHT_BUTTON _BV(2)
#define UP_BUTTON _BV(4)
#define DOWN_BUTTON _BV(6)
#define A_BUTTON _BV(1)
#define B_BUTTON _BV(0)

#define PIN_SPEAKER_1 A2
#define PIN_SPEAKER_2 A3

#define PIN_SPEAKER_1_PORT &PORTF
#define PIN_SPEAKER_2_PORT &PORTF

#define PIN_SPEAKER_1_BITMASK _BV(5)
#define PIN_SPEAKER_2_BITMASK _BV(4)

#endif

// OLED hardware (SSD1306)

#define OLED_PIXELS_INVERTED 0xA7 // All pixels inverted
#define OLED_PIXELS_NORMAL 0xA6 // All pixels normal

#define OLED_ALL_PIXELS_ON 0xA5 // all pixels on
#define OLED_PIXELS_FROM_RAM 0xA4 // pixels mapped to display RAM contents

#define OLED_VERTICAL_FLIPPED 0xC0 // reversed COM scan direction
#define OLED_VERTICAL_NORMAL 0xC8 // normal COM scan direction

// -----

#define COLUMN_ADDRESS_END (WIDTH - 1) & 0x7F   // 128 pixels wide
#define PAGE_ADDRESS_END ((HEIGHT/8)-1) & 0x07  // 8 pages high

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
    void static boot();
    void static inline safeMode() __attribute__((always_inline));
    void static inline bootLCD() __attribute__((always_inline));
    void static inline bootPins() __attribute__((always_inline));
    void static inline slowCPU() __attribute__((always_inline));
    void static inline saveMuchPower(); __attribute__((always_inline));

};

#endif