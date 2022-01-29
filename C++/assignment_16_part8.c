#include <stdio.h>


int power(int x, int y) {
    return y == 0? 1 : (x * power(x, y - 1));
}


int main() {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    int result = power(x, y);
    printf("%d^%d is %d", x, y, result);
    return 0;
}


