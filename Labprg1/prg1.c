#include <stdio.h>

int stack[100], top = -1, n;

void push() {
    int x;
    if (top == n - 1) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    stack[++top] = x;
    printf("Element pushed\n");
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;
    printf("Enter stack size: ");
    scanf("%d", &n);

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
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

