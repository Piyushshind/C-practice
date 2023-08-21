# include <stdio.h>
  
  void square(int n);

  int main(){
      int num = 7;
      square(num);
   return 0;
  };

  void square(int n){
       n = n * n;
       printf(" square of n is %d \n" , n);
  }