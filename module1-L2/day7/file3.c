#include <stdio.h>
typedef struct 
{
    int id;
    char name[50];
} Member;

void swapMembers(Member *array, int index1, int index2)
 {
    Member temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int main()
 {
    Member members[5] =
     {
        {1, "John"},
        {2, "Alice"},
        {3, "Bob"},
        {4, "Emma"},
        {5, "Michael"}
    };

    int index1, index2;
    printf("Enter the indexes to swap (0-4): ");
    scanf("%d %d", &index1, &index2);

    if (index1 >= 0 && index1 < 5 && index2 >= 0 && index2 < 5) {
        printf("Before swapping:\n");
        printf("Member 1: %d - %s\n", members[index1].id, members[index1].name);
        printf("Member 2: %d - %s\n", members[index2].id, members[index2].name);

        swapMembers(members, index1, index2);

        printf("After swapping:\n");
        printf("Member 1: %d - %s\n", members[index1].id, members[index1].name);
        printf("Member 2: %d - %s\n", members[index2].id, members[index2].name);
    } else {
        printf("Invalid indexes entered.\n");
    }

    return 0;
}
