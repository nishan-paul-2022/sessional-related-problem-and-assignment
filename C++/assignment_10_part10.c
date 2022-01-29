#include <stdio.h>

int main()
{
   char value[1000];
   
   printf("Input the string: ");
   gets(value);

   for(int i = 0; value[i] != '\0'; i++) {
        while(!(value[i] >= 'a' && value[i] <= 'z') && !(value[i] >= 'A' && value[i] <= 'Z') && !(value[i] == '\0')) {
            int j; 
            for(j = i; value[j] != '\0'; ++j)
                value[j] = value[j + 1];
            value[j] = '\0';
        }
   }

   printf("Expected Output: After removing the Output String: %s", value);
   return 0;
}