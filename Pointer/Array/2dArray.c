#include <stdio.h>
// print table od 2 & 3 in 2D array ;
int addTable(int arr[][10], int n, int m, int num);

int main()
{
    int tables[2][10];
    addTable(tables, 10, 0, 2);
    addTable(tables, 10, 1, 3);

    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", tables[0][i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", tables[1][i]);
    }
    return 0;
}

int addTable(int arr[][10], int n, int m, int num)
{
    for (int i = 0; i < n; i++)
    {
        arr[m][i] = (i + 1) * num;
    }
}