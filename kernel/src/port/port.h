#include <stdint.h>

unsigned char port_byte_in(unsigned short port);
void port_byte_out(unsigned short port, unsigned char data);

uint16_t port_word_in(uint16_t port);
void port_word_out(unsigned short port, unsigned short data);

uint32_t port_long_in(uint32_t port);
void port_long_out(uint32_t port, uint32_t value);

extern void write_port(int port, int value);
extern int read_port(int port);