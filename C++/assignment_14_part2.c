#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    int number, sum = 0;
    scanf("%d",&number);
    int n = number;

    while(n!=0) {
        int digit = n % 10;
        int value = digit * digit * digit;
        sum += value;
        n = n/10;
    }
    
    if(sum == number)
        printf("yes");
    else
        printf("no");

    return 0;
}