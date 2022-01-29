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
    int number_of_word = 0, number_of_character=0;
    char fname[100], line[100];

	scanf("%s", fname);   
    printf("The content of the file %s are: \n", fname); 

    FILE *fptr = fopen(fname, "r"); 

    while( fgets(line, sizeof(line), fptr) ) {
        trim(line);
        if( strlen(line) != 0 ) {
            printf("%s\n", line);

            int i = 0;
            while( line[i] != '\0' ) {
                if( line[i]==' ' || line[i]=='\n' || line[i]=='\t' )
                    number_of_word++;
                else
                    number_of_character++;
                i++;
            }
            number_of_word++;
        }
    }

    printf("The number of words in the file %s are: %d\n", fname, number_of_word);
    printf("The number of characters in the file %s are: %d\n", fname, number_of_character);

    fclose(fptr); 
}