#include <stdio.h>


int main()
{
    int x, y, value;
    scanf("%d %d", &x, &y);

    if(x<=y)
        value = 10 + 9 + y*4;
    else
        value = 10 + 9 + x*4 + (x-y)*4;

    printf("%d", value);

	return 0;
}