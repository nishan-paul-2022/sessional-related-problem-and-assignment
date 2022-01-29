#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char name[20];
    int age;
    char country[20];
    char Position[20];
    double Salary;
    double Rating;
} Player;


void highestPaidPlayer(Player *pl, int size) {
    char name[20];
    double Salary = -1;
    for(int i=0; i<size; i++) {
        if( pl[i].Salary >= Salary )
            memcpy(name, pl[i].name, sizeof(name));
    }
    printf("%s", name);
}


int main()
{
    int size;
    scanf("%d", &size);

    Player pl[size];
    for(int i=0; i<size; i++) {
        scanf("%s", &pl[i].name);
        scanf("%d", &pl[i].age);
        scanf("%s", &pl[i].country);
        scanf("%s", &pl[i].Position);
        scanf("%lf", &pl[i].Salary);
        scanf("%lf", &pl[i].Rating);
    }

    highestPaidPlayer(pl, size);

    return 0;
}