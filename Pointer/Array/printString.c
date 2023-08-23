#include <stdio.h>

void printStr(char str[]);

int main()
{
    char str1[] = "Piyush";
    char str2[] = "Shinde";
    printStr(str1);
    printStr(str2);

    return 0;
}

void printStr(char str[])
{
    for (char i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
}