#include <stdio.h>
int findCharType(char ch)
 {
    if (ch >= 'A' && ch <= 'Z')
     {
        return 1;
    } else if (ch >= 'a' && ch <= 'z') 
    {
        return 2;
    } else if (ch >= '0' && ch <= '9') 
    {
        return 3;
    } else if (ch >= 32 && ch <= 126) 
    {
        return 4;
    } else {
        return 5;
    }
}

int main() 
{
    char character;
    printf("Enter a character: ");
    scanf("%c", &character);
    
    int type = findCharType(character);
    
    switch (type) {
        case 1:
            printf("Type: Uppercase letter (A-Z)\n");
            break;
        case 2:
            printf("Type: Lowercase letter (a-z)\n");
            break;
        case 3:
            printf("Type: Digit (0-9)\n");
            break;
        case 4:
            printf("Type: Printable symbol\n");
            break;
        case 5:
            printf("Type: Non-printable symbol\n");
            break;
        default:
            printf("Invalid character.\n");
            break;
    }
    
    return 0;
}
