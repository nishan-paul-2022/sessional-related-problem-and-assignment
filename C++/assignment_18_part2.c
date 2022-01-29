#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main()
{
    int x, y;

    printf("Input – ");
    scanf("%d %d", &x, &y);

    int p = x>=y? x:y;
    int q = x<=y? x:y;

    int u = p*p + q*q;
    int v = p*p - q*q;
    int ur = sqrt(u);
    int vr = sqrt(v);

    if( ur*ur == u || vr*vr == v )
        printf("Output: possible Pythagorean triples");
    else
        printf("Output: not possible");

    return 0;
}