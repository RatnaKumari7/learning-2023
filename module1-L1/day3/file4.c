#include <stdio.h>
int findSmallestDigit(int number)
 {
    int smallest = 9;
    while (number > 0) {
        int digit = number % 10;
        if (digit < smallest) {
            smallest = digit;
        }
        number /= 10;
    }
    return smallest;
}

int findLargestDigit(int number) 
{
    int largest = 0;
    while (number > 0) {
        int digit = number % 10;
        if (digit > largest) {
            largest = digit;
        }
        number /= 10;
    }
    return largest;
}

int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Not Valid\n");
        return 0;
    }

    int i, number;
    for (i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &number);
        int smallest = findSmallestDigit(number);
        int largest = findLargestDigit(number);
        printf("Smallest digit: %d\n", smallest);
        printf("Largest digit: %d\n", largest);
    }

    return 0;
}
