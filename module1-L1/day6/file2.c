#include <stdio.h>
typedef struct 
{
    float real;
    float imaginary;
} Complex;

void readComplex(Complex *c) 
{
    printf("Enter the real part: ");
    scanf("%f", &(c->real));
    printf("Enter the imaginary part: ");
    scanf("%f", &(c->imaginary));
}

void writeComplex(Complex c) 
{
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imaginary);
}

Complex addComplex(Complex c1, Complex c2)
 {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

Complex multiplyComplex(Complex c1, Complex c2) 
{
    Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return result;
}

int main() {
    Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&num1);

    printf("Enter the second complex number:\n");
    readComplex(&num2);

    printf("\n");

    printf("First complex number:\n");
    writeComplex(num1);

    printf("Second complex number:\n");
    writeComplex(num2);

    sum = addComplex(num1, num2);
    printf("Sum of the two complex numbers:\n");
    writeComplex(sum);

    product = multiplyComplex(num1, num2);
    printf("Product of the two complex numbers:\n");
    writeComplex(product);

    return 0;
}
