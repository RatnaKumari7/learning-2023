#include <stdio.h>
unsigned char setBit(unsigned char num, int pos) 
{
    unsigned char mask = (1 << pos);
    return (num | mask);
}
unsigned char clearBit(unsigned char num, int pos)
 {
    unsigned char mask = ~(1 << pos);
    return (num & mask);
}
unsigned char toggleBit(unsigned char num, int pos) 
{
    unsigned char mask = (1 << pos);
    return (num ^ mask);
}

int main() {
    unsigned char number = 0b01010101; 
    unsigned char setBitResult = setBit(number, 3);
    printf("Set bit result: 0x%02X\n", setBitResult);
    unsigned char clearBitResult = clearBit(number, 5);
    printf("Clear bit result: 0x%02X\n", clearBitResult);
    unsigned char toggleBitResult = toggleBit(number, 2);
    printf("Toggle bit result: 0x%02X\n", toggleBitResult);

    return 0;
}
