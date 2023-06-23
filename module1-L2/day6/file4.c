#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int id;
    char name[20];
    float salary;
} Employee;
void modifyEmployee(Employee *emp) 
{
    
    emp->salary *= 1.1; 
    strcpy(emp->name, "John Doe"); 

}
Employee* createEmployee(int id, const char *name, float salary) {
    Employee *emp = (Employee*)malloc(sizeof(Employee));
    emp->id = id;
    strcpy(emp->name, name);
    emp->salary = salary;
    return emp;
}

int main() {
    
    Employee *empPtr;
 
    empPtr = createEmployee(1, "Jane Smith", 5000.0);
    printf("Initial Employee Details:\n");
    printf("ID: %d\n", empPtr->id);
    printf("Name: %s\n", empPtr->name);
    printf("Salary: %.2f\n\n", empPtr->salary);
    modifyEmployee(empPtr);
    printf("Modified Employee Details:\n");
    printf("ID: %d\n", empPtr->id);
    printf("Name: %s\n", empPtr->name);
    printf("Salary: %.2f\n", empPtr->salary);
    free(empPtr);

    return 0;
}
