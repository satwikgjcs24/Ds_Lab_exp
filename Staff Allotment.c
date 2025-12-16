#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Staff {
    int staffID;
    char name[50];
    char department[10];
    struct Staff *next;
};

struct Staff *head = NULL;

struct Staff* createNode(int id, char name[], char dept[]) {
    struct Staff *newNode = (struct Staff*)malloc(sizeof(struct Staff));
    newNode->staffID = id;
    strcpy(newNode->name, name);
    strcpy(newNode->department, dept);
    newNode->next = NULL;
    return newNode;
}

void addAtBeginning() {
    int id;
    char name[50], dept[10];
    scanf("%d %s %s", &id, name, dept);

    struct Staff *newNode = createNode(id, name, dept);
    newNode->next = head;
    head = newNode;
}

void addAtEnd() {
    int id;
    char name[50], dept[10];
    scanf("%d %s %s", &id, name, dept);

    struct Staff *newNode = createNode(id, name, dept);

    if (head == NULL)
        head = newNode;
    else {
        struct Staff *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    int choice;
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1: addAtBeginning(); break;
            case 2: addAtEnd(); break;
            case 7: exit(0);
        }
    }
}
