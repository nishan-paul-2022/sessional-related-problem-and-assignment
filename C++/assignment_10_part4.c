#include <stdio.h>


int main()
{
    int position, n;

    printf("Input the size of array: ");
    scanf("%d", &n);

	int arr[n];
    printf("Input %d elements in the array in ascending order:\n", n);

    for(int i = 0; i < n; i++) {
        printf("element – %d : ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Input the position where to delete: ");
    scanf("%d", &position);

    if (position < n+1 && position >= 1)
        for(int c = position - 1; c < n - 1; c++)
            arr[c] = arr[c+1];

        printf("Expected Output: The new list is: ");

        for(int c = 0; c < n - 1; c++)
            printf("%d ", arr[c]);
    }

    return 0;
}