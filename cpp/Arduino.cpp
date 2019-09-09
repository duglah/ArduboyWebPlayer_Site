#include "Arduino.h"
#include <stdint.h>
#include <emscripten.h>

void delay(int milliseconds)
{
    emscripten_sleep(milliseconds);
}

time_t startTime = time(0);

uint64_t millis() {
    return time(0) - startTime;
}
