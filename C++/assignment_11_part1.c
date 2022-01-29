#include <stdio.h>

int main()
{
    int arr[3], sum = 0, flag = 0;

    for(int i = 0; i < 3; i++) {
        printf("card value %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] == 1)
            flag = 1;
    }

    if( (flag == 1) && (sum + 10 <= 21) )
        sum += 10;

    printf("\nTotal value of cards: %d", sum);
    return 0;
}
