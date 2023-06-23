#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int id;
    char name[20];
}
 Member;

void deleteMemberAtStart(Member** members, int* numMembers)
 {
    if (*numMembers <= 0) {
        printf("No members to delete.\n");
        return;
    }
    Member* newMembers = (Member*)malloc((*numMembers - 1) * sizeof(Member));
    for (int i = 1; i < *numMembers; i++) 
    {
        newMembers[i - 1] = (*members)[i];
    }
    free(*members);
    *members = newMembers;
    (*numMembers)--;
}

int main() 
{
    
    Member* members = (Member*)malloc(3 * sizeof(Member));
    members[0].id = 1;
    strcpy(members[0].name, "John");
    members[1].id = 2;
    strcpy(members[1].name, "Alice");
    members[2].id = 3;
    strcpy(members[2].name, "Bob");

    int numMembers = 3;
    deleteMemberAtStart(&members, &numMembers);
    for (int i = 0; i < numMembers; i++) {
        printf("Member %d: ID=%d, Name=%s\n", i + 1, members[i].id, members[i].name);
    }
    free(members);

    return 0;
}
