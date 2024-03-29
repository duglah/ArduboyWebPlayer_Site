#ifndef AVR_H
#define AVR_H

#include <stdint.h>
#define 	pgm_read_byte_near(address_short)   ((unsigned char *)(address_short))[0]
#define 	pgm_read_byte(address_short)    pgm_read_byte_near(address_short)
#define __ATTR_PROGMEM__ __attribute__((__progmem__))
#define PROGMEM __ATTR_PROGMEM__

typedef char PROGMEM prog_char;
typedef unsigned char PROGMEM prog_uchar;

typedef uint8_t boolean;

#define _BV(bit) \
	(1 << (bit)) 

typedef unsigned char byte;

#endif /* AVR_H */