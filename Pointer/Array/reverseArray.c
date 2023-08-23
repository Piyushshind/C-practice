#include <stdio.h>

void reverse(int arr[], int n);
void printVal(int arr[], int n);

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    reverse(arr1, 6);
    printVal(arr1, 6);

    return 0;
}

void reverse(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int firstVal = arr[i]; /// swap the values.
        int lastVal = arr[n - i - 1];
        arr[i] = lastVal;
        arr[n - i - 1] = firstVal;
    }
};

void printVal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
}