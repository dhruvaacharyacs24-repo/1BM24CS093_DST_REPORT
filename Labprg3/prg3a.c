#include <stdio.h>

int queue[100], front = -1, rear = -1, n;

void insert() {
    int x;
    if (rear == n - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    printf("Enter element: ");
    scanf("%d", &x);
    queue[++rear] = x;
    printf("Element inserted\n");
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front++]);
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Enter queue size: ");
    scanf("%d", &n);

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
