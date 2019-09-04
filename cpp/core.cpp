#include "core.h"

ArduboyCore::ArduboyCore() {}

void ArduboyCore::bootPins()
{
}

void ArduboyCore::bootLCD()
{
}

void ArduboyCore::LCDDataMode()
{
}

void ArduboyCore::LCDCommandMode()
{
}

void ArduboyCore::safeMode()
{
}


/* Power Management */

void ArduboyCore::idle()
{
}

void ArduboyCore::saveMuchPower()
{
}

uint8_t ArduboyCore::width() { return WIDTH; }

uint8_t ArduboyCore::height() { return HEIGHT; }


/* Drawing */

void ArduboyCore::paint8Pixels(uint8_t pixels)
{
//   SPI.transfer(pixels);
}

void ArduboyCore::paintScreen(const unsigned char *image)
{
}

void ArduboyCore::paintScreen(unsigned char image[])
{
}

void ArduboyCore::blank()
{
}

void ArduboyCore::sendLCDCommand(uint8_t command)
{
}

void ArduboyCore::invert(boolean inverse)
{
}

void ArduboyCore::allPixelsOn(boolean on)
{
}

void ArduboyCore::flipVertical(boolean flipped)
{
}

void ArduboyCore::flipHorizontal(boolean flipped)
{
}

/* RGB LED */

void ArduboyCore::setRGBled(uint8_t red, uint8_t green, uint8_t blue)
{
}

/* Buttons */

uint8_t ArduboyCore::getInput()
{
  return buttonsState();
}


uint8_t ArduboyCore::buttonsState()
{
  uint8_t buttons;
  return buttons;
}