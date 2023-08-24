#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

typedef struct {
    int front, rear;
    int data[max];
} queue;

bool isFull(queue *Q) {
    return Q->rear == max - 1; // Fixed the condition
}

bool isEmpty(queue *Q) {
    return Q->rear == -1; // Fixed the condition
}

void init(queue *Q) {
    Q->front = -1;
    Q->rear = -1;
}

void enqueue(queue *Q, int num) {
    if (isFull(Q)) {
        printf("Queue is full\n"); // Added a newline character
    } else {
        if (isEmpty(Q)) {
            Q->front++;
        }
        Q->rear++;
        Q->data[Q->rear] = num;
    }
}

void dequeue(queue *Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty\n"); // Added a newline character
    } else {
        printf("%d is dequeued\n", Q->data[Q->front]); // Added a newline character
        Q->front++;
        if (Q->front > Q->rear) {
            init(Q);
        }
    }
}

void traverse(queue *Q) {
    if (isEmpty(Q)) {
        printf("The queue is empty\n"); // Added a newline character
    } else {
        for (int i = Q->front; i <= Q->rear; i++) {
            printf("%d ", Q->data[i]);
        }
        printf("\n"); // Added a newline character
    }
}

int main() {
    int choice, num;
    queue Q; // Declared the queue variable

    init(&Q); // Initialized the queue

    do {
        printf("Choose the operation to perform\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");
        printf("Enter the option number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number you want to enqueue: ");
                scanf("%d", &num);
                enqueue(&Q, num);
                break;

            case 2:
                dequeue(&Q);
                break;

            case 3:
                traverse(&Q);
                break;

            case 4:
                printf("Exiting the menu.....\n"); // Added a newline character
                exit(0);

            default:
                printf("Invalid choice\n"); // Added a default case for invalid choices
        }
        
        printf("\n");
    } while (choice != 4); // Fixed the loop condition

    return 0;
}
