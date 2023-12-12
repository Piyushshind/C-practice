#include <stdio.h> 
int func() 
{ 
      int a = 10; 
     return a, a * 2; 
} 
int main() 
{ 
     printf("%d", func()); 
     return 0; 
}