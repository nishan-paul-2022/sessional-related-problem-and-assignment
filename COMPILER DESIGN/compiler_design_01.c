#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LIMIT 10000


void remove_spaces(char* s) {
    char* d = s;
    do while(isspace(*s))
        s++;
    while(*d++ = *s++);
}


int main()
{
    char str[MAX_LIMIT];
    char result[MAX_LIMIT];

    while( scanf("%[^\n]%*c", str) != EOF) {
        char *pch;
        pch = strtok(str, " ");
        while(pch != NULL) {
            remove_spaces(pch);
            strcat(result, pch);
            strcat(result, " ");
            pch = strtok(NULL, " ");
        }

        if(strcmp(str, "paul")==0)
            break;
    }

    char *pch;
    pch = strtok(result, " ");
    while(pch != NULL) {
        printf("%s\n", pch);
        pch = strtok(NULL, " ");
    }

    return 0;
}


// https://www.hackerrank.com/contests/lexical-analysis-section-b/challenges/find-the-lexemes/problem