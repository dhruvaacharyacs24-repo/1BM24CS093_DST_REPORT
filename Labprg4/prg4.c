#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_first() {
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    printf("Node inserted at beginning\n");
}

void insert_end() {
    int x;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        printf("Node inserted as first node\n");
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    printf("Node inserted at end\n");
}

void insert_position() {
    int x, pos, i;
    struct node *newnode, *temp;
    printf("Enter data: ");
    scanf("%d", &x);
    printf("Enter position: ");
    scanf("%d", &pos);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        printf("Node inserted at position %d\n", pos);
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node inserted at position %d\n", pos);
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked list elements:\t");
    temp = head;
    while (temp->next != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_first();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_position();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
