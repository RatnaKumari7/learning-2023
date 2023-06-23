#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Record 
{
    char date[20];
    float temperature;
};

int compare(const void *a, const void *b)
 {
    float tempA = ((struct Record *)a)->temperature;
    float tempB = ((struct Record *)b)->temperature;
    return (tempB - tempA);
}

int main() 
{
    FILE *file;
    struct Record records[100];
    int numRecords = 0;
    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%f", records[numRecords].date, &records[numRecords].temperature);
        numRecords++;
    }

    fclose(file);
    qsort(records, numRecords, sizeof(struct Record), compare);
    file = fopen("sorted_data.csv", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    for (int i = 0; i < numRecords; i++) {
        fprintf(file, "%s,%.2f\n", records[i].date, records[i].temperature);
    }

    fclose(file);

    printf("Data sorted successfully!\n");

    return 0;
}
