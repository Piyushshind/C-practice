# include <stdio.h>

int main(){
   int x = 7 ;
int *ptr = &x;
int **pptr = &ptr;

printf( "%d\n", ptr);
printf( "%d \n", *ptr);
printf( "%d \n", &ptr);
printf( "%d \n", **pptr);
printf( "%d \n", &pptr);

return 0;
}
