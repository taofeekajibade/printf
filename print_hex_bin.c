#include "main.h"
/**
 * print_hex - prints hexadecimal values
 * @num: number to write i hexamdecimal
 * @total: total number written
 * @use_uppercase: converts to uppercase
 */
void print_hex(unsigned int num, int *total, bool use_uppercase)
{
    char hex_str[20];
    sprintf(hex_str, use_uppercase ? "%X" : "%x", num);
    print_str(hex_str, total);
}

/**
 * print_binary - prints binary values
 * @num: number to write in binary
 * @total total number written
 */
void print_binary(unsigned int num, int *total)
{
    char bin_str[33];
    int i = 0;
    for (; i < 32; i++)
    {
        bin_str[i] = (num & 0x80000000) ? '1' : '0';
        num <<= 1;
    }
    bin_str[i] = '\0';
    print_str(bin_str, total);
}
