#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

typedef struct {
    int front, rear;
    int data[max];
} queue;

void init(queue *Q) {
    Q->front = -1;
    Q->rear = -1;
}

bool isEmpty(queue *Q) {
    return Q->rear == -1;
}

bool isFull(queue *Q) {
    return (Q->rear + 1) % max == Q->front;
}

void enqueue(queue *Q, int num) {
    if (isFull(Q)) {
        printf("The queue is full\n");
    } else {
        if (isEmpty(Q)) {
            Q->front = 0;
            Q->rear = 0;
        } else {
            Q->rear = (Q->rear + 1) % max;
        }
        Q->data[Q->rear] = num;
    }
}

void dequeue(queue *Q) {
    if (isEmpty(Q)) {
        printf("The queue is empty\n");
    } else {
        printf("%d is dequeued\n", Q->data[Q->front]);
        if (Q->front == Q->rear) {
            init(Q);
        } else {
            Q->front = (Q->front + 1) % max;
        }
    }
}

void display(queue *Q) {
    if (isEmpty(Q)) {
        printf("The queue is empty\n");
    } else {
        int i = Q->front;
        while (i != Q->rear) {
            printf("%d ", Q->data[i]);
            i = (i + 1) % max;
        }
        printf("%d\n", Q->data[i]); // Print the last element
    }
}

int main() {
    int choice, num;
    queue Q; // Declared the queue variable

    init(&Q); // Initialized the queue

    do {
        printf("Choose among the following\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");
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
                display(&Q);
                break;

            case 4:
                printf("Exiting the menu.....\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}