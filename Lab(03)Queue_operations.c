#include <stdio.h>
#include <stdlib.h>

#define size 10

int arr[size];
int front = -1, rear = -1;

void insertion(int k)
{
    if (rear == size - 1)
    {
        printf("The queue is full");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        arr[rear] = k;
        rear = rear + 1;
    }
}

void deletion()
{
    if (front == -1)
    {
        printf("The queue is empty");
    }
    else
    {
        int j;
        j = arr[front];
        front = front + 1;
    }
}

void display()
{
    if (front == -1)
    {
        printf("The queue is empty");
    }
    for (int i = front; i <= rear; i++)
    {
        printf("The element in queue is %d", arr[i]);
    }
}

void main()
{
    int n;
    printf("enter 1 for insertion\n2 deletion\n3 display\n4 exit\n");

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
