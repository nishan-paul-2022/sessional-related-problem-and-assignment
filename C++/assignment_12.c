#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    char str[1000];
    gets(str);

    for(int i = 0; str[i]!='\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }

    int value[26] = {0}, count = 0;

    for(int i=0; str[i]!='\0'; i++) {

        if('a'<=str[i] && str[i]<='z')
            value[str[i]-'a'] = 1;
    }

    for(int i=0; i<26; i++) {
        if(value[i]==1)
            count++;
    }

    if(count==26)
        printf("Pangram\n");
    else {
        printf("Not pangram\n");
        for(int i=0; i<26; i++) {
            if(value[i]==0) {
                if(i<25)
                    printf("%c, ", i+'a');
                else
                    printf("%c", i+'a');
            }
        }
    }

    return 0;
}