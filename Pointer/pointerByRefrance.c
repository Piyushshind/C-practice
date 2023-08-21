#include <stdio.h>

void square(int n);
void _square(int *n);

int main()
{
    int num = 7;
    square(num);
    printf("no. is :- %d \n", num);
    printf("address of num  is :- %d \n", &num);
    _square(&num);
    printf("no. is :- %d \n", num);

    return 0;
};

void square(int n)
{
    n = n * n;
    printf(" square of n is %d \n", n);
}

void _square(int *n)
{
    *n = (*n) * (*n);
    printf(" square of pointer *n is %d \n", *n);
}