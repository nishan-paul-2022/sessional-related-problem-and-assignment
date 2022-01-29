#include <stdio.h>


void count(char arr[]) {
    int vowels = 0, consonants = 0;
    for(int i = 0; arr[i] != '\0'; i++) {
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            vowels++;
        else if((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z'))
            consonants++;
    }

    printf("vowels: %d\n", vowels);
    printf("consonants: %d\n", consonants);
}


int main()
{
    char arr[1000];
    printf("Input string: ");
    gets(arr);
    count(arr);

    return 0;
}