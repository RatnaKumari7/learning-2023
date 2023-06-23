#include <stdio.h>
#include <string.h>

void bubbleSort(char *names[], int count) {
    int i, j;
    char *temp;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the pointers
                temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
}

int main() {
    char *names[] = {
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
    };
    int count = sizeof(names) / sizeof(names[0]);
    int i;

    printf("Original order:\n");
    for (i = 0; i < count; i++) {
        printf("%s\n", names[i]);
    }

    bubbleSort(names, count);

    printf("\nSorted order:\n");
    for (i = 0; i < count; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
