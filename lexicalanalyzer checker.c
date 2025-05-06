#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check for keywords
int isKeyword(char s[]) {
    const char* keywords[] = {
        "int", "float", "char", "if", "else", "while", "for", "return",
        "break", "continue", "void", "switch", "case", "default",
        "goto", "sizeof", NULL
    };

    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(s, keywords[i]) == 0) {
            return 1;  // Keyword found
        }
    }
    return 0;  // Not a keyword
}

// Function to check for operators
int isOperator(char s[]) {
    if (strlen(s) == 1) {
        // Single-character operators
        char op = s[0];
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%' ||
            op == '=' || op == '>' || op == '<' || op == '!' ||
            op == '&' || op == '|') {
            return 1; // Valid operator
        }
    }
    // Check for multi-character operators
    if (strlen(s) == 2) {
        if ((s[0] == '=' && s[1] == '=') ||
            (s[0] == '!' && s[1] == '=') ||
            (s[0] == '&' && s[1] == '&') ||
            (s[0] == '|' && s[1] == '|') ||
            (s[0] == '>' && s[1] == '=') ||
            (s[0] == '<' && s[1] == '=')) {
            return 1; // Valid multi-character operator
        }
    }
    return 0;  // Not an operator
}

// Function to check for literals (integer, float, character, string, boolean)
int isIntegerLiteral(char s[]) {
    int i = 0;
    if (s[i] == '-' || isdigit(s[i])) {
        i++;
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
    return (strcmp(s, "true") == 0 || strcmp(s, "false") == 0);
}

// Function to check for identifiers
int isIdentifier(char s[]) {
    // Identifiers must not be a keyword and must start with a letter or underscore
    if (!isalpha(s[0]) && s[0] != '_') {
        return 0;  // Invalid identifier (must start with a letter or underscore)
    }
    for (int i = 1; s[i] != '\0'; i++) {
        if (!isalnum(s[i]) && s[i] != '_') {
            return 0;  // Invalid identifier (can only contain letters, digits, or underscores)
        }
    }
    return !isKeyword(s);  // Must not be a keyword
}

// Function to check if it's a preprocessor directive
int isPreprocessorDirective(char s[]) {
    return s[0] == '#';  // Preprocessor directives start with '#'
}

// Function to check for comments
int isComment(char s[]) {
    // Single-line comment 
    if (s[0] == '/' && s[1] == '/') {
        return 1;  
    }
   
    if (s[0] == '/' && s[1] == '*' && s[strlen(s) - 2] == '*' && s[strlen(s) - 1] == '/') {
        return 1;  
    }
    return 0;  
}

// Function to check for separators/punctuation
int isSeparator(char s[]) {
    return (strcmp(s, ";") == 0 || strcmp(s, ",") == 0 || strcmp(s, "(") == 0 ||
            strcmp(s, ")") == 0 || strcmp(s, "{") == 0 || strcmp(s, "}") == 0 ||
            strcmp(s, "[") == 0 || strcmp(s, "]") == 0);
}

int main() {
    char s[50];

    printf("\nEnter a value: ");
    gets(s); 

    // Check for keywords
    if (isKeyword(s)) {
        printf("\nKeyword\n");
    }
    // Check for operators
    else if (isOperator(s)) {
        printf("\nOperator\n");
    }
    // Check for literals
    else if (isIntegerLiteral(s)) {
        printf("\nInteger Literal\n");
    } else if (isFloatLiteral(s)) {
        printf("\nFloating-point Literal\n");
    } else if (isCharacterLiteral(s)) {
        printf("\nCharacter Literal\n");
    } else if (isStringLiteral(s)) {
        printf("\nString Literal\n");
    } else if (isBooleanLiteral(s)) {
        printf("\nBoolean Literal\n");
    }
    // Check for identifiers
    else if (isIdentifier(s)) {
        printf("\nIdentifier\n");
    }
    // Check for preprocessor directives
    else if (isPreprocessorDirective(s)) {
        printf("\nPreprocessor Directive\n");
    }
    // Check for comments
    else if (isComment(s)) {
        printf("\nComment\n");
    }
    // Check for separators/punctuation
    else if (isSeparator(s)) {
        printf("\nSeparator/Punctuation\n");
    }
    else {
        printf("\nNot a valid token\n");
    }

    return 0;
}
