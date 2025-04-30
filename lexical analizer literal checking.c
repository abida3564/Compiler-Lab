#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
int isIntegerLiteral(char s[]) {
    int i = 0;
    // If first character is '-' or a digit
    if (s[i] == '-' || isdigit(s[i])) {
        i++;
        // Check if the rest of the characters are digits
        while (s[i] != '\0') {
            if (!isdigit(s[i])) {
                return 0; // Not a valid integer literal
            }
            i++;
        }
        return 1; // Valid integer literal
    }
    return 0; // Not an integer literal
}
int isFloatLiteral(char s[]) {
    int i = 0, dotCount = 0;
    if (s[i] == '-' || isdigit(s[i])) {
        i++;
        while (s[i] != '\0') {
            if (s[i] == '.') {
                dotCount++;
            }
            if (!isdigit(s[i]) && s[i] != '.') {
                return 0; // Invalid float literal
            }
            i++;
        }
    }
    return dotCount == 1; // Valid float literal must contain exactly one dot
}
int isCharacterLiteral(char s[]) {
    return (s[0] == '\'' && s[2] == '\'' && s[3] == '\0'); // Example: 'a'
}

int isStringLiteral(char s[]) {
    return (s[0] == '\"' && s[strlen(s) - 1] == '\"'); // Example: "hello"
}

int isBooleanLiteral(char s[]) {
    // Check if the string is either "true" or "false"
    return (strcmp(s, "true") == 0 || strcmp(s, "false") == 0);
}

int main() {
    char s[50];
    // clrscr(); // Optional, for clearing the screen.

    printf("\nEnter a value: ");
    gets(s); // Read user input (Note: gets() is unsafe, consider using fgets() in real applications)

    if (isIntegerLiteral(s)) {
        printf("\nInteger Literal\n");
    } else if (isFloatLiteral(s)) {
        printf("\nFloating-point Literal\n");
    } else if (isCharacterLiteral(s)) {
        printf("\nCharacter Literal\n");
    } else if (isStringLiteral(s)) {
        printf("\nString Literal\n");
    } else if (isBooleanLiteral(s)) {
        printf("\nBoolean Literal\n");
    } else {
        printf("\nNot a literal\n");
    }

    getch(); // Wait for user input before exiting
    return 0;
}

