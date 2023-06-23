#include <stdio.h>
#define BCD_MASK 0x0F

unsigned char decimalToBCD(unsigned char decimal) 
{
    unsigned char tens = decimal / 10;
    unsigned char units = decimal % 10;
    return (tens << 4) | (units & BCD_MASK);
}

int main() {
    unsigned char decimalNumber = 23; 
    
    unsigned char bcdNumber = decimalToBCD(decimalNumber);
    
    printf("Decimal: %d\nBCD: 0x%02X\n", decimalNumber, bcdNumber);
    
    return 0;
}
