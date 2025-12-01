#include "util.h"
#include "../drivers/ports.h"

void memory_copy(char *source, char *dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

void memory_set(u8 *dest, u8 val, u32 len) {
    u8 *temp = (u8 *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

/**
 * K&R implementation
 */
void int_to_ascii(int n, char str[]) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    /* TODO: implement "reverse" */
}

void init_timer(unsigned int frequency) {
    unsigned int divisor = 1193180 / frequency;  // PIT base freq

    port_byte_out(0x43, 0x36);              // comando al PIT
    port_byte_out(0x40, divisor & 0xFF);    // byte bajo
    port_byte_out(0x40, (divisor >> 8) & 0xFF); // byte alto
}
