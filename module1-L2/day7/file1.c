#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int id;
    char name[100];
} 
Member;

Member* addMember(Member* array, int size) 
{
    size++;
    Member* newArray = (Member*)realloc(array, size * sizeof(Member));
    if (newArray == NULL) {
        printf("Memory allocation failed.\n");
        return array;  
    }
    Member newMember;
    printf("Enter the ID of the new member: ");
    scanf("%d", &newMember.id);
    printf("Enter the name of the new member: ");
    scanf("%s", newMember.name);
    newArray[size - 1] = newMember;
    
    printf("Member added successfully!\n");
    
    return newArray;
}

int main() {
    Member* array = NULL;
    int size = 0;
    array = addMember(array, size);
    size++;
    printf("Member ID: %d\n", array[0].id);
    printf("Member Name: %s\n", array[0].name);
    free(array);
    
    return 0;
}
