#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL;

void insert_end(struct node **head) {
    int x;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void display(struct node *head) {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    while (temp->next!= NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

void sort_list(struct node *head) {
    struct node *i, *j;
    int temp;
    if (head == NULL)
        return;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted\n");
}

void reverse_list(struct node **head) {
    struct node *prev = NULL, *curr = *head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("List reversed\n");
}

void concatenate() {
    struct node *temp;
    if (head1 == NULL) {
        head1 = head2;
        return;
    }
    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    printf("Lists concatenated\n");
}

int main() {
    int choice, listchoice;
    while (1) {
        printf("\n1.Insert List1\n2.Insert List2\n3.Display List1\n4.Display List2\n5.Sort List1\n6.Reverse List1\n7.Concatenate\n8.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_end(&head1);
                break;
            case 2:
                insert_end(&head2);
                break;
            case 3:
                display(head1);
                break;
            case 4:
                display(head2);
                break;
            case 5:
                sort_list(head1);
                break;
            case 6:
                reverse_list(&head1);
                break;
            case 7:
                concatenate();
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

