//doubly linked lists
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insert(int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;

    if (head == NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

void del(int k)
{
    struct node *temp = head;
    int j = 1;

    while (temp->next != NULL)
    {
        if (temp->next->data == k)
        {
            struct node *d = temp->next;
            temp->next = d->next;
            d->next->prev = temp;
            free(d);
            j = 0;
        }
        temp = temp->next;
    }

    if (j == 0)
    {
        printf("del is successful");
    }
    else if (j == 1)
    {
        printf("del not successful");
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

void main()
{
    int n, d;
    printf("1 for insertion\n2 for delete with value\n3 display\n4 exit");

    while (1)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("enter value");
            scanf("%d", &d);
            insert(d);
            break;

        case 2:
            printf("enter the val");
            scanf("%d", &d);
            del(d);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;
        }
    }
}
