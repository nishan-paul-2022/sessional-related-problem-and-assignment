#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    float cgpa, age;
    scanf("%f", &cgpa);
    scanf("%f", &age); 

    if(cgpa >= 3.5 && age <= 30)
        printf("potential candidate");
    else
        printf("not eligible for this job");

    return 0;
}