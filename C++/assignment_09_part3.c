#include <stdio.h>


int main()
{
    int test, number = 0;
    scanf("%d", &test);
    
    for(int i = 0; i < test; i++) {
        int count = 0;
        int x[3];
        scanf("%d %d %d", &x[0], &x[1], &x[2]);

        for(int j = 0; j < 3; j++)
            if(x[j] == 1)
                count++;

        if(count>1)
            number++;
    }

    printf("%d", number);

	return 0;
}