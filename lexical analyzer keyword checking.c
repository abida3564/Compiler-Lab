#include<stdio.h>
#include<string.h>
#include<conio.h>

int main() {
    char s[20]; // Increased size for keywords
    // clrscr(); // Commented out because it's not portable across compilers.

    printf("\nEnter a word: ");
    gets(s); // Read user input (Note: gets() is unsafe, consider using fgets() in real applications)

    // List of C keywords to check
    if (strcmp(s, "int") == 0) {
        printf("\nKeyword: int\n");
    } else if (strcmp(s, "float") == 0) {
        printf("\nKeyword: float\n");
    } else if (strcmp(s, "char") == 0) {
        printf("\nKeyword: char\n");
    } else if (strcmp(s, "if") == 0) {
        printf("\nKeyword: if\n");
    } else if (strcmp(s, "else") == 0) {
        printf("\nKeyword: else\n");
    } else if (strcmp(s, "while") == 0) {
        printf("\nKeyword: while\n");
    } else if (strcmp(s, "for") == 0) {
        printf("\nKeyword: for\n");
    } else if (strcmp(s, "return") == 0) {
        printf("\nKeyword: return\n");
    } else if (strcmp(s, "break") == 0) {
        printf("\nKeyword: break\n");
    } else if (strcmp(s, "continue") == 0) {
        printf("\nKeyword: continue\n");
    } else if (strcmp(s, "void") == 0) {
        printf("\nKeyword: void\n");
    } else if (strcmp(s, "switch") == 0) {
        printf("\nKeyword: switch\n");
    } else if (strcmp(s, "case") == 0) {
        printf("\nKeyword: case\n");
    } else if (strcmp(s, "default") == 0) {
        printf("\nKeyword: default\n");
    } else if (strcmp(s, "goto") == 0) {
        printf("\nKeyword: goto\n");
    } else if (strcmp(s, "sizeof") == 0) {
        printf("\nKeyword: sizeof\n");
    } else {
        printf("\nNot a keyword\n");
    }

    getch(); // Wait for user input before exiting
    return 0;
}


