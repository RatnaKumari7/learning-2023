#include <stdio.h>
void printExponent(double x) 
{
   unsigned long long* ptr = (unsigned long long*)&x; 
   unsigned long long exponent = (*ptr >> 52) & 0x7FF; 
   printf("Exponent (Hex): 0x%llx\n", exponent);
   printf("Exponent (Binary): 0b");
    for (int i = 11; i >= 0; i--) {
        unsigned long long bit = (exponent >> i) & 1;
        printf("%llu", bit);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}
