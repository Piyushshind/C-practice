#include <stdio.h>

void square(int n);
void _square(int *n);

int main()
{
    int num = 7;
    square(num); // call by value :-  we pass value of variable as argument.
    printf("no. is :- %d \n", num);
    printf("address of num  is :- %d \n", &num);
    _square(&num);  // call by refrance :- we pass adderess of variable as argument.
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