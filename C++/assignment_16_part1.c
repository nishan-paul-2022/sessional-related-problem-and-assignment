#include <stdio.h>

int max(int *p, int size) {
    for(int i = 1; i < size; ++i) {
        if(p[0] < p[i])
            p[0] = p[i];
    }
    return p[0];
}


int main()
{
    int n;
    int arr[100];
    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    int value = max(arr, n);
    printf("largest value %d", value);

    return 0;
}
