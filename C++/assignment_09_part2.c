#include <stdio.h>


int main()
{
    int cnst, flag = 0;
    scanf("%d", &cnst);
    int tva = cnst;

    for(int i = 0; i < 2*cnst-1; i++) {

        for(int j = 0; j < tva; j++)
            printf(" ");
        for(int j = 0; j < tva; j++)
            printf("*");
        printf("\n");

        if(tva==1)
            flag = 1;
        tva = flag==0? tva-1 : tva+1;

    }

	return 0;
}