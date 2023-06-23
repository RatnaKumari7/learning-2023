#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100
#define MAX_FIELD_LENGTH 50
typedef struct {
    int entryNo;
    char name[MAX_FIELD_LENGTH];
    char address[MAX_FIELD_LENGTH];
} Entry;
void updateEntry(int entryNo, const char* newName, const char* newAddress) {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;
    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    while (fscanf(file, "%d,%[^,],%[^\n]", &entries[numEntries].entryNo, entries[numEntries].name, entries[numEntries].address) != EOF) {
        numEntries++;
    }
    fclose(file);
    int foundIndex = -1;
    for (int i = 0; i < numEntries; i++) {
        if (entries[i].entryNo == entryNo) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
     {
        printf("Entry not found!\n");
        return;
    }
    strcpy(entries[foundIndex].name, newName);
    strcpy(entries[foundIndex].address, newAddress);
    file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < numEntries; i++)
     {
        fprintf(file, "%d,%s,%s\n", entries[i].entryNo, entries[i].name, entries[i].address);
    }
    fclose(file);

    printf("Entry updated successfully!\n");
}

int main() {
    int entryNo;
    char newName[MAX_FIELD_LENGTH];
    char newAddress[MAX_FIELD_LENGTH];

    printf("Enter the entry number to update: ");
    scanf("%d", &entryNo);

    printf("Enter the new name: ");
    scanf(" %[^\n]", newName);

    printf("Enter the new address: ");
    scanf(" %[^\n]", newAddress);

    updateEntry(entryNo, newName, newAddress);

    return 0;
}
