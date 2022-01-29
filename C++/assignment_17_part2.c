#include <stdio.h>
#include <stdlib.h>


void output(int * data, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", *(data+i));
    printf("\n");
}


int main()
{
    int size = 10;
    int *left = (int*) malloc(size * sizeof(int));
    int *right = (int*) malloc(size * sizeof(int));

    printf("Input array elements: ");
    for(int i = 0, j = 9; i < size; i++, j--) {
        scanf("%d", left+i);
        *(right+j) = *(left+i);
    }

    printf("Output: Reversed array: ");
    output(right, size);

    return 0;
}
