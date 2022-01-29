#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


bool nexus(char a[], int n, char x, char y) {
    bool check = false;
    for(int i = 0; i < n; i++)
        if(a[i] >= x && a[i] <= y)
            check = true;
    return check;
}


bool nexus_(char a[], int n, char special[], int m) {
    bool check = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i] == special[j])
                check = true;
    return check;
}


int main()
{
    char Numbers[100] = "0123456789";
    char Lower_case[100] = "abcdefghijklmnopqrstuvwxyz";
    char Upper_case[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char Special_characters[100] = "!@#$^%&*()-+;";

    char a[100];
    printf("Input: ");
    gets(a);
    int n = strlen(a);
    int m = strlen(Special_characters);

    bool data[5];

    data[0] = n>=8;
    data[1] = nexus(a, n, '0', '9');
    data[2] = nexus(a, n, 'A', 'Z');
    data[3] = nexus(a, n, 'a', 'z');
    data[4] = nexus_(a, n, Special_characters, m);

    bool check = data[0] && data[1] && data[2] && data[3] && data[4];
    printf("Output:\n");

    if(check)
        printf("Good to go!!\n");
    else {
        printf("This is not a strong password.\n");
        printf("Message = ");
        if(data[0] == false) printf("Length is smaller than 8.\n");
        if(data[1] == false) printf("Digit missing.\n");
        if(data[2] == false) printf("Upper case letter missing.\n");
        if(data[3] == false) printf("Lower case letter missing.\n");
        if(data[4] == false) printf("Special Character missing.");
    }
}