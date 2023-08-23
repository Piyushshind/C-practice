# include <stdio.h>

void printFibo(int arr[], int n);
int fibo(int n);
void printVal(int arr[], int n);

int main(){
   int arr1[]= {};
    printFibo(arr1,8);
     printVal(arr1,8);
    return 0;
}

void printFibo(int arr[],int n){
    for (int i = 2; i <n; i++)
    {
        arr[i]= fibo(i);
    }
    
};

int fibo(int n){
    if( n==1) return 1;
    if(n==0) return 0;
      return fibo(n-1) + fibo(n-2);
}

void printVal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
}