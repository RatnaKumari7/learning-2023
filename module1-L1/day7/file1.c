#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student 
{
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char *inputString, struct Student *students, int numStudents) {
    const char *delimiter = " ";
    char *token;

    for (int i = 0; i < numStudents; i++) {
        token = strtok((char *)inputString, delimiter);
        students[i].rollno = atoi(token);

        token = strtok(NULL, delimiter);
        strncpy(students[i].name, token, sizeof(students[i].name));

        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);

        inputString = NULL; 
    }
}

int main() {
    const char *inputString = "1001 Aron 100.00";
    const int numStudents = 1; 

    struct Student students[numStudents];
    parseString(inputString, students, numStudents);

   
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}
