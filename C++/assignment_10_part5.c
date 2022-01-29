#include <stdio.h>
 
int main()
{
    int n, position, value;

    printf("Input the size of array: ");
    scanf("%d", &n);

	int arr[n];
    printf("Input %d elements in the array in ascending order:\n", n);

    for(int i = 0; i < n-1; i++) {
        printf("element – %d : ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Input the position where to insert: ");
    scanf("%d", &position);
    
    printf("Input the number to insert: ");
    scanf("%d", &value);
    
    for(int c = n - 2; c >= position; c--)
        arr[c+1] = arr[c];
    
    arr[position] = value;

    printf("Expected Output: The new list is: ");

    for(int c = 0; c < n; c++)
        printf("%d ", arr[c]);

    return 0;
}