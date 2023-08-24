#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        stack->top++;
        stack->data[stack->top] = item;
        printf("%d pushed to the stack.\n", item);
        
    }
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    } else {
        int item = stack->data[stack->top];
        stack->top--;
        return item;
    }
}

int peak(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot perform peak operation.\n");
        return -1;
    } else {
        return stack->data[stack->top];
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, item;
    
    printf("Stack Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peak\n");
    printf("4. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != -1)
                    printf("%d popped from the stack.\n", item);
                break;
            case 3:
                item = peak(&stack);
                if (item != -1)
                    printf("Top element: %d\n", item);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}