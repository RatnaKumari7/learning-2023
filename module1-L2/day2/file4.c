#include <stdio.h>
char *xstrchr(char *string, char ch) 
{
    while (*string != '\0') {
        if (*string == ch) {
            return string;
        }
        string++;
    }
    
    return NULL;
}

int main() {
    char str[] = "Hello, World!";
    char ch = 'W';
    
    char *result = xstrchr(str, ch);
    if (result != NULL) {
        printf("Character found at position: %ld\n", result - str);
    } else {
        printf("Character not found.\n");
    }
    
    return 0;
}
