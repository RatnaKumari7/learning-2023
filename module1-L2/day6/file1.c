#include <stdio.h>
#include <string.h>

#define MAX_DATA_LEN 50
#define MAX_SENSORS 10

typedef struct {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
} SensorData;

void parseData(const char* data, SensorData* sensorArray, int* numSensors) {
    char buffer[MAX_DATA_LEN];
    char* token;

    strcpy(buffer, data);

    token = strtok(buffer, "-");
    *numSensors = 0;

    while (token != NULL) {
        sscanf(token, "%[^:]:%f", sensorArray[*numSensors].sensorID, &sensorArray[*numSensors].temperature);
        token = strtok(NULL, "-");
        sscanf(token, "%[^:]:%d", sensorArray[*numSensors].sensorID, &sensorArray[*numSensors].humidity);
        token = strtok(NULL, "-");
        sscanf(token, "%[^:]:%d", sensorArray[*numSensors].sensorID, &sensorArray[*numSensors].lightIntensity);
        token = strtok(NULL, "-");

        (*numSensors)++;
    }
}

void printSensorInfo(const SensorData* sensorArray, int numSensors) {
    printf("Sensor Info:\n");
    printf("---------------------\n");

    for (int i = 0; i < numSensors; i++) {
        printf("Sensor ID: %s\n", sensorArray[i].sensorID);
        printf("Temperature: %.1f C\n", sensorArray[i].temperature);
        printf("Humidity: %d\n", sensorArray[i].humidity);
        printf("Light Intensity: %d%%\n", sensorArray[i].lightIntensity);
        printf("---------------------\n");
    }
}

int main() {
    const char* data = "S1-T:36.5-H:100-L:50";
    SensorData sensorArray[MAX_SENSORS];
    int numSensors;

    parseData(data, sensorArray, &numSensors);
    printSensorInfo(sensorArray, numSensors);

    return 0;
}
