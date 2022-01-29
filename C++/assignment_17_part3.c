#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    int size = 10;
    char data[size];
    char data2[100];

    scanf("%s", &data2);

    int n;
    for(n = 0; data2[n] != '\0' && n < size; n++)
        data[n] = data2[n];

    for(int i = n; i < size-1; i++)
        data[i] = '*';
    data[size-1] = '\0';

    printf("%s", data);

    return 0;
}

