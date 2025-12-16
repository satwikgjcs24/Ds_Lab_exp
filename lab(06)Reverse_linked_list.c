#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

/* insert at beginning */
void insert(struct node **head, int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = *head;
    *head = newnode;
}

/* display list */
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* reverse linked list */
void reverse(struct node **head)
{
    struct node *prev = NULL;
    struct node *curr = *head;
    struct node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

/* sort linked list */
void sort(struct node *head)
{
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

/* concatenate two lists */
void concatenate()
{
    struct node *temp = head1;

    if (head1 == NULL)
    {
        head1 = head2;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
}

void main()
{
    int n, k, ch;

    while (1)
    {
        printf("\n1 Insert List1");
        printf("\n2 Insert List2");
        printf("\n3 Sort List1");
        printf("\n4 Reverse List1");
        printf("\n5 Concatenate List1 & List2");
        printf("\n6 Display List1");
        printf("\n7 Exit\n");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &k);
            insert(&head1, k);
            break;

        case 2:
            printf("Enter element: ");
            scanf("%d", &k);
            insert(&head2, k);
            break;

        case 3:
            sort(head1);
            printf("List sorted\n");
            break;

        case 4:
            reverse(&head1);
            printf("List reversed\n");
            break;

        case 5:
            concatenate();
            printf("Lists concatenated\n");
            break;

        case 6:
            display(head1);
            break;

        case 7:
            exit(0);
        }
    }
}
