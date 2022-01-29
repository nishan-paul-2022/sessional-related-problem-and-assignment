#include <stdio.h>
#include <stdlib.h>


int main()
{
    int size = 5;
    int data[size];
    int mx;
    bool check = true;

    for(int i = 0; i < size; i++) {
        scanf("%d", data+i);
        mx = i==0? data[i] : (data[i]>mx? data[i]:mx);
    }

    for(int i = 0; i < size; i++) {
        if(mx % data[i])
            check = false;
    }

    check? printf("Good Maximum") : printf("Bad Maximum");

    return 0;
}
