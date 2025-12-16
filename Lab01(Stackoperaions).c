#include <stdio.h>

#define size 100

void push(int arr[], int *top)
{
    if (*top == size - 1)
    {
        printf("stack is overflow\n");
    }
    else
    {
        int k;
        printf("enter the element : ");
        scanf("%d", &k);
        *top += 1;
        arr[*top] = k;
    }
}

void pop(int arr[], int *top)
{
    if (*top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        int j = arr[*top];
        printf("The element removed is %d\n", j);
        *top -= 1;
    }
}

void display(int arr[], int top)
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack elements:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", arr[i]);
        }
    }
}

void main()
{
    int stack[size], top = -1, n;

    printf("enter the number of elements for push : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        push(stack, &top);
    }

    printf("Enter the elements to pop : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        pop(stack, &top);
    }

    display(stack, top);
}
