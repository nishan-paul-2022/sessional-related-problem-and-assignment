#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void calculate() {
    int no;
	FILE * fptr1 = fopen ("assignment_15_part2_f1.txt", "r");
    FILE * fptr2 = fopen ("assignment_15_part2_f2.txt", "w");

    while(fscanf(fptr1, "%d", &no) != EOF) {
        int payment = no<=5? no*1000 : 5000+(no-5)*500;
        fprintf(fptr2, "%d\n", payment);
    }

    fclose(fptr1);
    fclose(fptr2);
}


int main()
{
    calculate();

    return 0;
}