#include <stdio.h>
typedef struct 
{
    int field1;
    float field2;
} MyStruct;

void swapFields(MyStruct *struct1, MyStruct *struct2) 
{
    MyStruct temp = *struct1;
    *struct1 = *struct2;
    *struct2 = temp;
}

int main() {
    MyStruct struct1, struct2;
    struct1.field1 = 10;
    struct1.field2 = 3.14;
    struct2.field1 = 20;
    struct2.field2 = 6.28;

    printf("Before swapping:\n");
    printf("struct1: field1 = %d, field2 = %.2f\n", struct1.field1, struct1.field2);
    printf("struct2: field1 = %d, field2 = %.2f\n", struct2.field1, struct2.field2);
    swapFields(&struct1, &struct2);

    printf("\nAfter swapping:\n");
    printf("struct1: field1 = %d, field2 = %.2f\n", struct1.field1, struct1.field2);
    printf("struct2: field1 = %d, field2 = %.2f\n", struct2.field1, struct2.field2);

    return 0;
}
