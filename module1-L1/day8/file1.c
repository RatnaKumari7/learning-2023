#include <stdio.h>
#define BUFFER_SIZE 1024

int main() 
{
    FILE *sourceFile, *targetFile;
    char sourcePath[100], targetPath[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    printf("Enter the source file path: ");
    scanf("%s", sourcePath);
    printf("Enter the target file path: ");
    scanf("%s", targetPath);
    sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }
    targetFile = fopen(targetPath, "wb");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, targetFile);
    }

    printf("File copied successfully.\n");
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}