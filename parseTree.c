#include <stdio.h>
#include <string.h>
#define NON_TERMINALS 5
#define TERMINALS 6


char *nonTerminals[NON_TERMINALS] = {"E", "E'", "T", "T'", "F"};

char *terminals[TERMINALS] = {"id", "+", "*", "(", ")", "$"};


char parsingTable[NON_TERMINALS][TERMINALS][20];

void constructParsingTable() {
    int i, j;

    for (i = 0; i < NON_TERMINALS; i++) {
        for (j = 0; j < TERMINALS; j++) {
            strcpy(parsingTable[i][j], "error");
        }
    }


    if (1) {
        strcpy(parsingTable[0][0], "T E'");
        strcpy(parsingTable[0][3], "T E'");
    }

    if (1) {
        strcpy(parsingTable[1][1], "+ T E'");
        strcpy(parsingTable[1][4], "ε");
        strcpy(parsingTable[1][5], "ε");
    }

    if (1) {
        strcpy(parsingTable[2][0], "F T'");
        strcpy(parsingTable[2][3], "F T'");
    }

    if (1) {
        strcpy(parsingTable[3][2], "* F T'");
        strcpy(parsingTable[3][1], "ε");
        strcpy(parsingTable[3][4], "ε");
        strcpy(parsingTable[3][5], "ε");
    }


    if (1) {
        strcpy(parsingTable[4][0], "id");
        strcpy(parsingTable[4][3], "( E )");
    }
}

void printParsingTable() {
    int i, j;
    printf("LL(1) Parsing Table:\n\n\t");
    for (j = 0; j < TERMINALS; j++) {
        printf("%s\t", terminals[j]);
    }
    printf("\n");

    for (i = 0; i < NON_TERMINALS; i++) {
        printf("%s\t", nonTerminals[i]);
        for (j = 0; j < TERMINALS; j++) {
            printf("%s\t", parsingTable[i][j]);
        }
        printf("\n");
    }
}

int main() {
    constructParsingTable();
    printParsingTable();
    return 0;
}

