#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char title[100];
    char author[100];
    int b_id;
} book;


int main()
{
    int size = 5;
    book data[size];

    for(int i = 0; i < size; i++) {
        scanf("%s", &data[i].title);
        scanf("%s", &data[i].author);
        scanf("%d", &data[i].b_id);
        printf("\n\n");
    }

    char title[100];
    scanf("%s", &title);

    int i;
    for(i = 0; strcmp(data[i].title, title) != 0 && i < size; i++);

    if(i==size)
        printf("error");
    else {
        printf("%s\n", data[i].title);
        printf("%s\n", data[i].author);
        printf("%d\n", data[i].b_id);
    }

    return 0;
}