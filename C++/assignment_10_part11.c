#include <stdio.h>

int main()
{
    int n = 3, ans = 0, ans2 = 0;
    int arr[n][n];
    int x = 0, y = n-1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if(i == j)
                ans += arr[i][j];
            if(i==x && j==y) {
                ans2 += arr[i][j];
                x++;
                y--;
            }
        }
    }

    printf("main diagonal: %d\n", ans);
    printf("right diagonal: %d\n", ans2);
    
    return 0;
}