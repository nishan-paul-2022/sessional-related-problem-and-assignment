#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* trim(char *s) {
    char *ptr;
    if(!s)
        return NULL;
    if(!*s)
        return s;
    for(ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr);
    ptr[1] = '\0';
    return s;
}


int main()
{
    int size;
    char fileName[100] = "assignment_17_part5_f1.txt", line[100];
    FILE * fptr = fopen(fileName, "w");

    scanf("%d", &size);

    for(int i=0; i<size; i++) {
        int number;
        scanf("%d", &number);
        fprintf(fptr, "%d\n", number);
    }
    fclose(fptr);

    FILE *fptr2 = fopen(fileName, "r"); 
    FILE *fptr3 = fopen("assignment_17_part5_f3.txt", "w"); 
    FILE *fptr4 = fopen("assignment_17_part5_f4.txt", "w");
 
    int sumodd = 0, sumeven = 0;
    while( fgets(line, sizeof(line), fptr2) ) {
        trim(line);
        int number = atoi(line);
        if( number %2 )
            sumodd += number;
        else
            sumeven += number;
    }

    fprintf(fptr3, "%d\n", sumodd);
    fprintf(fptr4, "%d\n", sumeven);

    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr4);

    return 0;
}