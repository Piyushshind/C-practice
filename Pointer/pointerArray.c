#include <stdio.h>

int main(){ // Every array is a pointer ;
    int age[] = {23,45,32};
    int *_age = &age[1];
    printf("address of 2nd is %u" , _age);
     _age++;
    printf(" \n address of 2nd is %u" , _age);
    _age--;
    printf(" \n address of 2nd is %u" , _age);
    return 0;
}