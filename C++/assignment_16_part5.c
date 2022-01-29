#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int number_of_line = 0;
    char fname[100], line[100];

	scanf("%s", fname);   
    printf("The content of the file %s are: \n", fname); 

    FILE *fptr = fopen(fname, "r"); 

    while( fgets(line, sizeof(line), fptr) ) {
        trim(line);
        if( strlen(line) != 0 ) {
            printf("%s\n", line);
            number_of_line++;
        }
    }

    printf("The number of lines in the file %s are: %d\n", fname, number_of_line);

    fclose(fptr); 
}