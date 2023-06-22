#include <stdio.h>
void swap(void *a, void *b, size_t size) 
{
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}
int main() 
{
    int a = 10;
    int b = 20;
    
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b, sizeof(int));
    
    printf("After swap: a = %d, b = %d\n", a, b);
    
    return 0;
}
