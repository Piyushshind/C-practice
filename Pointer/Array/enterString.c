#include <stdio.h>
//  to wriiten a str manually
int main()
{
    char str[100];
    char letter;
    int i = 0;
    while (letter != '\n')
    {
        scanf("/c",& letter);
        str[i] = letter;
        i++;
    };

    str[i] = '\0';
    puts(str);

    return 0;
}