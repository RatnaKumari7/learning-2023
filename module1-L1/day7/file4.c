#include <stdio.h>
typedef struct 
{
    char name[20];
    int marks;
} Student;

void sortStudents(Student arr[], int size)
 {
    int i, j;
    Student temp;

    for (i = 0; i < size - 1; i++) 
    {
        for (j = 0; j < size - i - 1; j++) 
        {
            if (arr[j].marks < arr[j + 1].marks) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student students[] = 
    {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"David", 90},
        {"Eve", 80}
    };

    int size = sizeof(students) / sizeof(students[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }

    sortStudents(students, size);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }

    return 0;
}
