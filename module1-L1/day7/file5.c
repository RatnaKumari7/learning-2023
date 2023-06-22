#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100
typedef struct 
{
    char name[MAX_NAME_LENGTH];
    int age;
} Student;

int searchStudentByName(Student students[], int numStudents, const char* name) 
{
    for (int i = 0; i < numStudents; i++) 
    {
        if (strcmp(students[i].name, name) == 0)
         {
            return i;  
        }
    }
    return -1;  
}

int main()
 {
    Student students[MAX_STUDENTS];
    int numStudents;
    numStudents = 3;
    strcpy(students[0].name, "John");
    students[0].age = 20;
    strcpy(students[1].name, "Alice");
    students[1].age = 19;
    strcpy(students[2].name, "Bob");
    students[2].age = 21;
    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);

    int index = searchStudentByName(students, numStudents, searchName);

    if (index != -1) {
        printf("Student found at index %d\n", index);
        printf("Name: %s\n", students[index].name);
        printf("Age: %d\n", students[index].age);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}
