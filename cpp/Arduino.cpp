#include "Arduino.h"
#include <stdint.h>
#include <emscripten.h>

void delay(int milliseconds)
{
    emscripten_sleep(milliseconds);
}


