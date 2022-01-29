#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char name[50];
    int id;
    char dept[20];
    double cgpa;
} student;


void saveByDept(char *fileName, char *deptName, student allStudents[], int size) {
    FILE * fptr = fopen (fileName, "w");

    for(int i=0; i<size; i++) {
        student omg = allStudents[i];
        
        if( strcmp(omg.dept, deptName) == 0 ) {
            fprintf(fptr, "name: %s\n", omg.name);
            fprintf(fptr, "id: %d\n", omg.id);
            fprintf(fptr, "dept: %s\n", omg.dept);
            fprintf(fptr, "cgpa: %lf\n\n", omg.cgpa);
        }
    }

    fclose(fptr);
}


int main()
{
    int size;
    char fileName[100], deptName[100];
    scanf("%s", fileName);
    scanf("%s", deptName);
    scanf("%d", &size);

    student allStudents[size];
    for(int i=0; i<size; i++) {
        student omg;
        scanf("%s", &omg.name);
        scanf("%d", &omg.id);
        scanf("%s", &omg.dept);
        scanf("%lf", &omg.cgpa);
        allStudents[i] = omg;
    }

    saveByDept(fileName, deptName, allStudents, size);

    return 0;
}