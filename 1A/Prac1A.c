#include <stdio.h>

int main()
{
    int arr[100], i, n;
    int sum_even = 0, sum_odd = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            sum_even += arr[i];
        else
            sum_odd += arr[i];
    }

    printf("Sum of elements at even positions = %d\n", sum_even);
    printf("Sum of elements at odd positions = %d\n", sum_odd);

    return 0;
}
