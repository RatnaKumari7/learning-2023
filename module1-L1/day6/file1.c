#include <stdio.h>
struct Box 
{
    double length;
    double width;
    double height;
};

int main() {
    struct Box myBox; 
    struct Box* ptrBox;  

    ptrBox = &myBox;  
    (*ptrBox).length = 5.0;
    (*ptrBox).width = 3.0;
    (*ptrBox).height = 2.0;
    double volume = ptrBox->length * ptrBox->width * ptrBox->height;
    double surfaceArea = 2 * (ptrBox->length * ptrBox->width + ptrBox->length * ptrBox->height + ptrBox->width * ptrBox->height);

    printf("Volume: %lf\n", volume);
    printf("Surface Area: %lf\n", surfaceArea);

    return 0;
}
