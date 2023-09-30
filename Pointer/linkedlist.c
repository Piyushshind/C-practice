#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *end = NULL;

// head--> 1 2 3 4 5
int n = 0;
void create()
{

    // int n;
    printf("give a number:");
    scanf("%d", &n);
    node *temp;
    if (n == 0)
    {
        return;
    }
    int i = 0;
    while (i != n)
    {
        if (head == NULL)
        {
            head = (node *)malloc(sizeof(node));
            node *newnode = (node *)malloc(sizeof(node));
            head->next = newnode;
            int d;
            printf("give data:");
            scanf("%d", &d);
            newnode->data = d;
            newnode->next = NULL;
            end = newnode;
        }
        else
        {
            node *newnode = (node *)malloc(sizeof(node));
            end->next = newnode;
            int d;
            printf("give data:");
            scanf("%d", &d);
            newnode->data = d;
            newnode->next = NULL;
            end = newnode;
        }
        i++;
    }
}
// head 1. 2 3 4 5
void display()
{

    if (head == NULL)
    {
        printf("\ncreate kar na ...\n");
        return;
    }

    node *temp = head->next;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->NULL", temp->data);
}
void deleteFirstNode()
{
    node *temp = head->next;
    head->next = temp->next;
    temp->next = NULL;
    free(temp);
}
void deleteLastNode()
{
    node *temp = head->next;
    while (temp->next->next != NULL)
    {

        temp = temp->next;
    }
    temp -> next = NULL;
    end=temp;
}
int main()
{
    create();
    display();
    deleteLastNode();
    display();
}