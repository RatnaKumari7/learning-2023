#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void encode(char* str, char* encoded)
 {
    for (int i = 0; i < 256; i++) {
        substitution_table[i] = (char)(rand() % 256);
    }
    for (int i = 0; i < strlen(str); i++) {
        encoded[i] = substitution_table[(unsigned char)str[i]];
    }
    encoded[strlen(str)] = '\0'; 
void decode(char* encoded, char* decoded) {
    char substitution_table[256] = {0}; 

    for (int i = 0; i < 256; i++) {
        substitution_table[i] = (char)i;
    }
    for (int i = 0; i < strlen(encoded); i++) {
        decoded[i] = substitution_table[(unsigned char)encoded[i]];
    }
    decoded[strlen(encoded)] = '\0'; 
}

int main() {
    char original[100];
    char encoded[100];
    char decoded[100];

    printf("Enter a string to encode: ");
    fgets(original, sizeof(original), stdin);
    original[strcspn(original, "\n")] = '\0'; 

    encode(original, encoded);
    printf("Encoded string: %s\n", encoded);

    decode(encoded, decoded);
    printf("Decoded string: %s\n", decoded);

    return 0;
}
