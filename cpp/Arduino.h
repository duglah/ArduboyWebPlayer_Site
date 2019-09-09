#ifndef ARUDINO_H
#define ARUDINO_H

#include<stdio.h>
#include<time.h>
#include <math.h>
#include "avr.h"

#define max(val1, val2) fmax(val1, val2)
#define min(val1, val2) fmin(val1, val2)

void delay(int milliseconds);
uint64_t millis();

#endif /* ARUDINO_H */
