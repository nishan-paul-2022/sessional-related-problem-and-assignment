#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int addition(int x, int y) {
    int sum = x + y;
    return sum;
}


int main()
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    int sum = addition(x, y);
    printf("%d", sum);

    return 0;
}