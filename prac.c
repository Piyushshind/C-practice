// Online C compiler to run C program online
#include <stdio.h>
 int mergeSort(int arr1[],int arr2[],int arr3[] ,int n, int m){
    //  int n=4, m=6,
     // int k=n+m;
    // int arr1[n],arr2[m],
//     int arr3[k];
    int i=0;
    int j=0;
    int k=0;
    int p =0;
    
    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            k++;
            i++;
    }else{
         arr3[k++] = arr2[j++];
      }
    }
    while(i<n){
        arr3[k++] = arr1[i++];
    }
    while(j<m){
        arr3[k++] = arr2[j++];
    }

  for(p =0; p<k;p++){
     printf(" the arr is %d" , arr3[p]);
  } 
    return 0;
 }
int main() {
    int a[]={2,3,4,8};
    int b[]={9,6,34,12,4};
    int n=4;
    int m=5;
    int k = n+m;
    int cd[k];
    mergeSort(a, b,cd, n , m);

    return 0;
}