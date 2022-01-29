#include <stdio.h>


int main()
{
	int n, max = 0;
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

	int arr[n];
    printf("Input %d elements in the array:\n", n);

    for(int i = 0; i < n; i++) {
        printf("element – %d : ", i+1);
        scanf("%d", &arr[i]);
        int temp = arr[i] < 0? -1*arr[i] : arr[i];
        if(max < temp)
            max = temp; 
    }

    int ans = 0, brr[max+1];
    for(int i = 0; i <= max; i++)
        brr[i] = 0;

	for(int i = 0; i < n; i++)
		brr[arr[i]]++;
    
	for(int i = 0; i <= max; i++)
		if(brr[i]>1)
            ans++;

    printf("Expected Output: Total number of duplicate elements found in the array is: %d", ans);
	return 0;
}

