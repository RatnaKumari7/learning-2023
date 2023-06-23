#include <stdio.h>
#include <stdlib.h>
void deleteEntry(const char* filename, int entryNo)
 {
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Failed to open input file.\n");
        return;
    }

    FILE* tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Failed to create temporary file.\n");
        fclose(inputFile);
        return;
    }

    char line[100];
    int entryFound = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        int currentEntryNo;
        sscanf(line, "%d,", &currentEntryNo);

        if (currentEntryNo == entryNo) {
            entryFound = 1;
            continue;
        }

        fputs(line, tempFile);
    }

    fclose(inputFile);
    fclose(tempFile);

    if (!entryFound) {
        printf("Entry with EntryNo %d not found.\n", entryNo);
        remove("temp.csv");
        return;
    }

    remove(filename);
    rename("temp.csv", filename);
    printf("Entry with EntryNo %d deleted successfully.\n", entryNo);
}

int main() {
    int entryNo;
    printf("Enter the EntryNo to delete: ");
    scanf("%d", &entryNo);

    deleteEntry("data.csv", entryNo);

    return 0;
}
