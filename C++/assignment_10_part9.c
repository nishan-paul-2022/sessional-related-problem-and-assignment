#include <stdio.h>


void Replace(char arr[], char oldChar, char newChar) {

   for(int i = 0; arr[i] != '\0'; i++) {
        if(arr[i] == oldChar)
            arr[i] = newChar;
   }

   printf("new string: %s", arr);
}


int main()
{
    char arr[1000];
    printf("old character: ");
    char oldChar = getchar();
    getchar();
    printf("new character: ");
    char newChar = getchar();
    getchar();

    printf("old string: ");
    gets(arr);
    Replace(arr, oldChar, newChar);

    return 0;
}