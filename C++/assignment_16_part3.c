#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    int Registration_Number;
    char Name[100];
    int Age;
    char Gender[100];
    int Contact_Number;
    char Physician_name[100];
    char Corona_status[100];
} Patient;


Patient input_patient() {
    Patient pax;
    printf("Registration_Number: "); scanf("%d", &pax.Registration_Number);
    printf("Name: "); scanf("%s", &pax.Name);
    printf("Age: "); scanf("%d", &pax.Age);
    printf("Gender: "); scanf("%s", &pax.Gender);
    printf("Contact_Number: "); scanf("%d", &pax.Contact_Number);
    printf("Physician_name: "); scanf("%s", &pax.Physician_name);
    printf("Corona_status: "); scanf("%s", &pax.Corona_status);
    return pax;
}


void input(Patient *pa, int n) {
    for(int i=0; i<n; i++) {
        pa[i] = input_patient();
        printf("\n\n");
    }
}


void print_array(Patient *pa, int n) {
    for(int i=0; i<n; i++) {
        printf("Registration_Number: %d\n", pa[i].Registration_Number);
        printf("Name: %s\n", pa[i].Name);
        printf("Age: %d\n", pa[i].Age);
        printf("Gender: %s\n", pa[i].Gender);
        printf("Contact_Number: %d\n", pa[i].Contact_Number);
        printf("Physician_name: %s\n", pa[i].Physician_name);
        printf("Corona_status: %s\n\n", pa[i].Corona_status);
    }
    printf("\n\n");
}


void copy_patient(Patient *x, Patient *y) {
    x->Registration_Number = y->Registration_Number;
    strcpy(x->Name, y->Name);
    x->Age = y->Age;
    strcpy(x->Gender, y->Gender);
    x->Contact_Number = y->Contact_Number;
    strcpy(x->Physician_name, y->Physician_name);
    strcpy(x->Corona_status, y->Corona_status);
}


void display(Patient *pa, int n) {
    printf("display / \n");

    for(int i=0; i<n; i++) {
        if( strcmp(pa[i].Corona_status, "positive") == 0 ) {
            printf("Registration_Number: %d\n", pa[i].Registration_Number);
            printf("Name: %s\n", pa[i].Name);
        }
        printf("\n\n");
    }
}


void append(Patient *pa, int n) {
    printf("append / \n");
    Patient pb[n+1];

    for(int i=0; i<n; i++)
        copy_patient(pb+i, pa+i);

    pb[n] = input_patient();
    printf("\n\n");

    pa = pb;
    n++;
    print_array(pa, n);
}


void exclude_patient(Patient *pa, int n) {
    int pos;
    char Name[100];
    printf("exclude_patient / Name: ");
    scanf("%s", &Name);
    for(pos = 0; strcmp(pa[pos].Name, Name) != 0; pos++);
    for(int i = pos; i < n-1; i++)
        copy_patient(pa+i, pa+i+1);
    n--;
    print_array(pa, n);
}


void modify(Patient *pa, int n) {
    int i, Registration_Number;
    printf("modify / Registration_Number: ");
    scanf("%d", &Registration_Number);

    for(i = 0; pa[i].Registration_Number != Registration_Number; i++);
    printf("Contact_Number (modify): "); scanf("%d", &pa[i].Contact_Number);
    printf("Physician_name (modify): "); scanf("%s", &pa[i].Physician_name);
    print_array(pa, n);
}


int main()
{
    int n;
    scanf("%d", &n);

    Patient pa[n];
    input(pa, n);

    display(pa, n);
    append(pa, n); n++;
    exclude_patient(pa, n); n--;
    modify(pa, n);

    return 0;
}

