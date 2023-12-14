// Write a program to implement circular queue using array.

#include <stdio.h>
#define max 6
int queue[max];
int front = -1;
int rear = -1;
void enqueue(int item)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = item;
    }
    else if ((rear + 1) % max == front)
    {
        printf("\n Queue is full");
    }
    else
    {
        rear = (rear + 1) % max; // increment rear
        queue[rear] = item;
    }
}
int dequeue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\n Queue is empty");
    }
    else if (front == rear)
    {
        printf("\n The delete item is:%d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\n The delete item is:%d", queue[front]);
        front = (front + 1) % max;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\nItem in Queue are:");
        while (i <= rear)
        {
            printf("\n%d", queue[i]);
            i = (i + 1) % max;
        }
    }
}
int main()
{
    int ch, x;
    while (ch != 4)
    {
        printf("\n1.Insert an item");
        printf("\n2.Delete an item");
        printf("\n3.Display an item");
        printf("\n Exit");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to insert:");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        }
    }
}
