#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

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

void delete_first() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void delete_last() {
    struct node *temp, *prev;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void delete_element() {
    int key;
    struct node *temp, *prev;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter element to delete: ");
    scanf("%d", &key);
    if (head->data == key) {
        temp = head;
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }
    temp = head;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked list elements:\n");
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
        printf("\n1.Insert at End\n2.Delete First\n3.Delete Specific\n4.Delete Last\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_end();
                break;
            case 2:
                delete_first();
                break;
            case 3:
                delete_element();
                break;
            case 4:
                delete_last();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
