#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create() {
    node *head, *curr;
    int i,n;
    
    scanf("Enter the number of nodes to be created:%d", &n);

    head = (node *)malloc(sizeof(node));
    scanf("%d", &(head->data));
    head->next = NULL;

    curr = head;
    for (i = 1; i < n; i++) { // Start from 1 instead of 0
        curr->next = (node *)malloc(sizeof(node));
        curr = curr->next;
        scanf("%d", &(curr->data));
        curr->next = NULL;
    }
    return head; // Return the head of the linked list
}

node *insert(node *head, int x, int key) {
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    
    if (key == -1) {
        p->next = head;
        head = p;
    } else {
        q = head;
        while (q != NULL && q->data != key) {
            q = q->next;
        }
        if (q != NULL) {
            p->next = q->next;
            q->next = p;
        }
    }
    return head; // Return the updated head of the linked list
}

node *deleteNode(node *head, int x) {
    node *p, *q;

    if (head == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }

    if (x == head->data) {
        p = head;
        head = head->next;
        free(p);
    } else {
        p = head;
        while (p->next != NULL && p->next->data != x) {
            p = p->next;
        }
        if (p->next != NULL) {
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
    return head; // Return the updated head of the linked list
}

void traverse(node *head) {
    node *p;
    p = head;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    node *HEAD;
    int n, choice, x, key, position;
    
    HEAD = create();

    do {
        printf("Choose among the following\n1.Insert\n2.Delete\n3.Traverse\n4.Exit\n");
        printf("Enter the option number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number data you want to insert in linked list: ");
                scanf("%d", &x);
                printf("Enter the position in linked list at which you want to insert: ");
                scanf("%d", &position);
                key = position - 1; // Adjust the key value
                HEAD = insert(HEAD, x, key);
                break;

            case 2:
                printf("Enter the node you want to delete: ");
                scanf("%d", &x);
                HEAD = deleteNode(HEAD, x);
                break;

            case 3:
                traverse(HEAD);
                break;

            case 4:
                printf("Exiting the menu.......\n");
                exit(0);

            default:
                printf("Invalid Option\n");
                break;
        }
    } while (choice != 4);

    return 0;
}