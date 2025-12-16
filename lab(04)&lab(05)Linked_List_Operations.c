#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertion(int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void insertend(int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertionp(int p, int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if (p < 0)
    {
        printf("The invalid position");
        free(newnode);
    }
    else if (p == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        for (int i = 0; i < p - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("No ele to display");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("The data is %d", temp->data);
            temp = temp->next;
        }
    }
}

void deletionf()
{
    if (head == NULL)
    {
        printf("The ele is not present");
        return;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
}

void deletione()
{
    if (head == NULL)
    {
        printf("The ele is empty not del");
    }
    else
    {
        struct node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void deletionp(int p)
{
    if (head == NULL)
    {
        printf("No element");
    }
    else if (p < 0)
    {
        printf("The position is wrong");
    }
    else if (p == 0)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    else
    {
        struct node *temp = head;
        for (int i = 0; i < p && temp != NULL; i++)
        {
            temp = temp->next;
        }

        struct node *del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

void main()
{
    int n;
    while (1)
    {
        printf("\n1 for insertion at beginning");
        printf("\n2 for insertion at end");
        printf("\n3 at given pos");
        printf("\n4 display");
        printf("\n5 del f");
        printf("\n6 del e");
        printf("\n7 del p");
        printf("\n8 exit");

        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("enter the ele");
            scanf("%d", &n);
            insertion(n);
            break;

        case 2:
            printf("enter the ele");
            scanf("%d", &n);
            insertend(n);
            break;

        case 3:
        {
            int p, k;
            printf("enter the ele");
            scanf("%d", &k);
            printf("enter the pos");
            scanf("%d", &p);
            insertionp(p, k);
            break;
        }

        case 4:
            display();
            break;

        case 5:
            deletionf();
            break;

        case 6:
            deletione();
            break;

        case 7:
            deletionp(n);
            break;

        case 8:
            exit(0);
        }
    }
}
