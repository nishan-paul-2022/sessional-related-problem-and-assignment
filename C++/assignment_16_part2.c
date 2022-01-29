#include <stdio.h>


int length(char *s) {
    int i;
    for(i=0; s[i]!='\0'; i++);
    return i;
}


int main()
{
    char str[100];
    scanf("%s", str);
    int n = length(str);
    printf("length: %d", n);
    return 0;
}