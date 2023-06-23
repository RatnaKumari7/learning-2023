#include <stdio.h>
typedef struct 
{
    int id;
    char name[20];
    float salary;
} Employee;

void rotateArray(Employee arr[], int n, int k) 
{
    k = k % n;
    Employee temp;
    for (int i = 0; i < k; i++) {
        temp = arr[n - 1];
        
        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        
        arr[0] = temp;
    }
}

int main() {
    Employee employees[] = {
        {1, "John", 5000.0},
        {2, "Alice", 6000.0},
        {3, "Bob", 4500.0},
        {4, "Lisa", 5500.0},
        {5, "Mike", 7000.0}
    };
    
    int n = sizeof(employees) / sizeof(Employee);
    int k = 2; 
    
    printf("Before rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    
    rotateArray(employees, n, k);
    
    printf("\nAfter rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    
    return 0;
}
