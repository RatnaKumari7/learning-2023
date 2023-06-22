#include <stdio.h>
int findLargestNumber(int num)
 {
    int largest = 0;
    int divisor = 1;
    
    while (divisor <= 1000) {
        int currentNum = (num / (divisor * 10)) * divisor + (num % divisor);
        if (currentNum > largest) {
            largest = currentNum;
        }
        divisor *= 10;
    }
    
    return largest;
}

int main() {
    int number = 5872;
    int largestNumber = findLargestNumber(number);
    printf("The largest number after deleting a digit from %d is %d\n", number, largestNumber);
    
    number = 9856;
    largestNumber = findLargestNumber(number);
    printf("The largest number after deleting a digit from %d is %d\n", number, largestNumber);
    
    return 0;
}
