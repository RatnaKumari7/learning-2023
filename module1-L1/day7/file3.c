#include <stdio.h>
struct Person 
{
    char name[50];
    int age;
    float height;
};

void displayMembers(struct Person members[], int count)
 {
    for (int i = 0; i < count; i++) {
        printf("Member %d:\n", i + 1);
        printf("Name: %s\n", members[i].name);
        printf("Age: %d\n", members[i].age);
        printf("Height: %.2f\n", members[i].height);
        printf("\n");
    }
}

int main() 
{
    struct Person members[3] = 
    {
        {"John Doe", 25, 175.5},
        {"Jane Smith", 30, 163.2},
        {"Mark Johnson", 40, 180.1}
    };

    int count = sizeof(members) / sizeof(members[0]);

    displayMembers(members, count);

    return 0;
}
