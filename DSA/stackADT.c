// Write a program to implement stack as an ADT.And perform conversion to infix -postfix.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //eachb digit each alphabet
#include <string.h>
char stack[100];
int top = -1, size;
void push(char item)
{
    if (top >= size - 1)
    {
        printf("\n stack overflow");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}
char pop()
{
    char item;
    if (top < 0)
    {
        printf("\nStack overflow");
    }
    else
    {
        item = stack[top];
        top--;
        return (item);
    }
}
int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '/' || symbol == '*' || symbol == '+' ||
        symbol == '-' || symbol == '%')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int percedence(char symbol)
{
    if (symbol == '^')
    {
        return 3;
    }
    else if (symbol == '*' || symbol == '/' || symbol == '%')
    {
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void InfixTopostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item, x;
    push('(');              // for stack is not empty just put this
    strcat(infix_exp, ")"); // to define end of infix expression so that stack will be empty at last
    i = 0;
    j = 0;
    item = infix_exp[i];
    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if (is_operator(item) == 1) // priority of scan symbol is check with    priority of stack symbol
        {
            x = pop();
            while ((is_operator(x) == 1) &&
                   (percedence(x) >= percedence(item)))
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("\n Invalid expression");
            exit(0);
        }
        i++;
        item = infix_exp[i]; // for eacn and every element of infix expression
    }
    postfix_exp[j] = '\0';
}
void main()
{
    char infix[100], postfix[100];
    printf("\n Enter the size of stack:");
    scanf("%d", &size);
    printf("Enter Infix expression:");
    scanf("%s", infix);
    InfixTopostfix(infix, postfix);
    printf("\n Postfix Expression:%s", postfix);
}
