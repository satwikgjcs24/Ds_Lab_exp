#include <stdio.h>
#include <stdlib.h>

#define size 100

int arr[size];
int front = -1, rear = -1;

void insertion(int k)
{
    if (front == (rear + 1) % size)
    {
        printf("The circular queue is full");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        arr[rear] = k;
        rear = (rear + 1) % size;
    }
}

void deletion()
{
    if (front == -1)
    {
        printf("Queue are empty");
    }
    else
    {
        int j;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            j = arr[front];
            front = (front + 1) % size;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue empty");
    }
    else
    {
        int i = front;
        while (1)
        {
            if (i == rear)
            {
                break;
            }
            else
            {
                printf("The elements are %d", arr[i]);
                i = (i + 1) % size;
            }
        }
    }
}

void main()
{
    int n;
    printf("enter the choices\n1 for insertion\n2 for deletion\n3 for display\n4 for exit");

    while (1)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("enter the ele");
            scanf("%d", &n);
            insertion(n);
            break;

        case 2:
            deletion();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        }
    }
}
