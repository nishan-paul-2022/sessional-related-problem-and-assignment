#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Player {
    char name[20];
    int age;
    char country[20];
    double Salary;
};


void input() {
    struct Player player;
    FILE * fptr;

	fptr = fopen ("assignment_15_part1_f1.txt", "w");

	scanf("%s", player.name);
    scanf("%d", &player.age);
    scanf("%s", player.country);
    scanf("%lf", &player.Salary);

    fprintf(fptr, "%s\n", player.name);
    fprintf(fptr, "%d\n", player.age);
    fprintf(fptr, "%s\n", player.country);
    fprintf(fptr, "%lf\n", player.Salary);

    fclose (fptr);
}


void display() {
    struct Player player;
	FILE * fptr = fopen ("assignment_15_part1_f1.txt", "r");

    fscanf(fptr, "%s\n", player.name);
    fscanf(fptr, "%d\n", &player.age);
    fscanf(fptr, "%s\n", player.country);
    fscanf(fptr, "%lf\n", &player.Salary);

	printf("%s\n", player.name);
    printf("%d\n", player.age);
    printf("%s\n", player.country);
    printf("%lf\n", player.Salary);

    fclose (fptr);
}


void BD_Players(struct Player *pl, int size) {
    for(int i = 0; i < size; i++) {
        struct Player player = pl[i];
        if(strcmp(player.country, "Bangladesh") == 0)
            printf("%s\n", player.name);
    }
}



int main()
{
    input();
    display();

    return 0;
}