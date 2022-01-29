#include <stdio.h>

int takeinput() {
    int value;
    scanf("%d", &value);
    return value;
}


void dis_res(int num) {
    int sum = 0;

    while(num) {
        int digit = num % 10;
        num = num / 10;
        printf("%d ", digit);
        sum += digit;
    }

    if(sum % 9 == 0)
        printf("\ndivisible by 9");
    else
        printf("\nnot divisible by 9");
}

int main()
{
    int num = takeinput();
    dis_res(num);
    
    return 0;
}
