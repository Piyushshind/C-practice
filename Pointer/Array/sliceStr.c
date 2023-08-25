#include <stdio.h>

char slice(char str[100] , char n , char m);

int main(){
    
     char str[] = "piyushshinde" ;
     slice(str,4,9);
    return 0;
}

char slice(char str[100] , char n , char m){
    char newStr[100];
    int j =0;
    for (int i = n; i <= m; i++ ,j++)
    {
        newStr[j] = str[i];
    }
       newStr[j]= '\0';
       printf("%s", newStr);
}