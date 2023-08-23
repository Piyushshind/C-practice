#include <stdio.h>


int main()
{
    int n;
    printf("Enter a number upto which you want to print fibonnaci series :-  %d", n);
    scanf("%d", &n);
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        printf("%d \t", arr[i]);
    }
    return 0;
}
