#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 5

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void initializeEmployees(Employee employees[], int size) {
    for (int i = 0; i < size; i++) {
        employees[i].id = i + 1;
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", employees[i].name);
        printf("Enter the salary of employee %d: ", i + 1);
        scanf("%f", &employees[i].salary);
    }
}

int main() {
    Employee employees[ARRAY_SIZE];

    initializeEmployees(employees, ARRAY_SIZE);

    printf("Employee Details:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    return 0;
}
