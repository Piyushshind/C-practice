#include <stdio.h>
void address(int n);
int main(){
   int n = 8;
   address(n);
        printf("%p", &n); // tha address of this n is "0061FF00"
 return 0;  // both memory adderess are different ; ie. call by value ;
}

void address(int n){
    printf("%p \n", &n);  // tha address of this n is "0061FF1C"
};
