#include <stdio.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int marks;
};

void readStudentData(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }
}

void writeStudentData(struct Student students[], int n) {
    printf("Student Data:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
    }
}

float computeAverageMarks(struct Student students[], int n) {
    int totalMarks = 0;

    for (int i = 0; i < n; i++) {
        totalMarks += students[i].marks;
    }

    return (float)totalMarks / n;
}

void studentsAboveAndBelowAverage(struct Student students[], int n) {
    float averageMarks = computeAverageMarks(students, n);
    printf("Average Marks: %.2f\n", averageMarks);

    printf("Students above average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks > averageMarks) {
            printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
        }
    }

    printf("Students below average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks < averageMarks) {
            printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
        }
    }
}

int main() {
    int numStudents;
    struct Student students[MAX_STUDENTS];

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Maximum number of students exceeded.\n");
        return 1;
    }

    readStudentData(students, numStudents);
    printf("\n");

    writeStudentData(students, numStudents);
    printf("\n");

    studentsAboveAndBelowAverage(students, numStudents);

    return 0;
}
