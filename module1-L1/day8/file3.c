#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100
typedef struct 
{
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
}
 LogEntry;
int extractData(LogEntry logEntries[]) 
{
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open data.csv file.\n");
        return 0;
    }
    
    char line[MAX_LINE_LENGTH];
    int entryCount = 0;
    while (fgets(line, sizeof(line), file)) 
    {
    char *token = strtok(line, ",");
        logEntries[entryCount].entryNo = atoi(token);
        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].sensorNo, token);
        token = strtok(NULL, ",");
        logEntries[entryCount].temperature = atof(token);
        token = strtok(NULL, ",");
        logEntries[entryCount].humidity = atoi(token);
        token = strtok(NULL, ",");
        logEntries[entryCount].light = atoi(token);
        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].timestamp, token);

        entryCount++;
    }

    fclose(file);
    return entryCount;
}
void displayData(const LogEntry logEntries[], int entryCount)
 {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n",
            logEntries[i].entryNo,
            logEntries[i].sensorNo,
            logEntries[i].temperature,
            logEntries[i].humidity,
            logEntries[i].light,
            logEntries[i].timestamp
        );
    }
}

int main() 
{
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount = extractData(logEntries);
    
    if (entryCount > 0) {
        displayData(logEntries, entryCount);
    } else {
        printf("No data found.\n");
    }
    
    return 0;
}