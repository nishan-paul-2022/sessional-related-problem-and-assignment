#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000


int countString(char primary[], char secondary[]) {
    int count = 0;

    int flength = strlen(primary);
    int slength = strlen(secondary);

    for(int i = 0; i <= flength-slength; i++) {
        int found = 1;
        for(int j = i; j < i + slength; j++) {
            if(primary[j] != secondary[j-i])
                found = 0;
        }

        if(found)
            count++;
    }

    return count;
}


int main()
{
    char primary[MAX_SIZE], secondary[] = "the ";

    printf("Input the string: ");
    gets(primary);

    int n = countString(primary, secondary);
    printf("Expected Output: The frequency of the word 'the ' is: %d", n);

    return 0;
}