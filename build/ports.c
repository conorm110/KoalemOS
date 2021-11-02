/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "ports.h"
#include <stdint.h>

/**
 * port_byte_in - read byte
 * 
 * read byte from port param and return
 * as unsigned char
 */
unsigned char port_byte_in (unsigned short port) {
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

/**
 * port_byte_out - write byte
 * 
 * write byte to port param with value from
 * the data param. Data should be a char
 */
void port_byte_out (unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

/**
 * port_word_in - read word
 * 
 * read uint16_t from port param and return
 * as uint16_t
 */
uint16_t port_word_in (uint16_t port) {
    uint16_t result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

/**
 * port_word_out - write word
 * 
 * write word to port param with value from
 * the data param. Data should be a short
 */
void port_word_out (unsigned short port, unsigned short data) {
    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}

/**
 * port_long_out - read long
 * 
 * write uint32_t to port param with value from
 * the data param. Data should be a uint32_t.
 */
void port_long_out(uint32_t port, uint32_t value) {
	   __asm__ __volatile__("outl %%eax,%%dx"::"d" (port), "a" (value));
};

/**
 * port_long_in - write long
 * 
 * read uint32_t from port param and return as 
 * uint32_t.
 */
uint32_t port_long_in(uint32_t port) {
    uint32_t result;
    __asm__ __volatile__("inl %%dx,%%eax":"=a" (result):"d"(port));
    return result;
}