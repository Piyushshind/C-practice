# include <stdio.h>

 int addTable(int arr[][10],int n , int m , int num);

int main(){
    int tables[2][10];
     addTable(tables,10,0,2);
     addTable(tables,10,1,3);
    return 0;
}

int addTable(int arr[][10],int n , int m , int num){
    for (int i = 0; i < n; i++)
    {
          arr[m][i] = (i+1) * num;
    }
    
}