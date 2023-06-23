#include <stdio.h>
int compareBoxes(int A[], int B[], int size)
 {
    int i, j, found;

    for (i = 0; i < size; i++) {
        found = 0;

        for (j = 0; j < size; j++) {
            if (A[i] == B[j]) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int A[3] = {200, 10, -90};
    int B[3] = {-90, 200, 10};

    int size = sizeof(A) / sizeof(A[0]);
    int result = compareBoxes(A, B, size);

    printf("Result: %d\n", result);

    return 0;
}
