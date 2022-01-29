#include <stdio.h>

int main()
{
   char value[1000];
   
   printf("Input the string: ");
   gets(value);

   printf("Expected Output: ");

   for(int i = 0; value[i] != '\0'; i++)
      printf("%c ", value[i]);

   return 0;
}