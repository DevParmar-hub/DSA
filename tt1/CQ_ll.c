#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node* next;
};

/* Queue structure */
struct circularQueue {
    struct node* front;
    struct node* rear;
};

/* Create an empty queue */
struct circularQueue* createQueue() {
    struct circularQueue* q = (struct circularQueue*)malloc(sizeof(struct circularQueue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

/* Enqueue */
void enqueue(struct circularQueue* q, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (q->front==NULL) { // empty queue
        q->front = q->rear = newNode;
        newNode->next = newNode; // points to itself
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

/* Dequeue */
int dequeue(struct circularQueue* q) {
    if (q->front==NULL) {
        printf("Queue empty\n");
        return -1;
    }
    int val = q->front->data;

    if (q->front == q->rear) { // only one element
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }

    return val;
}

/* Traverse */
void traverse(struct circularQueue* q) {
    if (q->front == NULL) {
        printf("Queue empty\n");
        return;
    }

    struct node* temp = q->front;
    while (1) {
        printf("%d\t", temp->data);
        temp = temp->next;
        if (temp == q->front)
            break;
    }
    printf("\n");
}
/* Main */
int main() {
    struct circularQueue* q = createQueue();

    enqueue(q, 3);
    enqueue(q, 7);
    enqueue(q, 10);
    enqueue(q, 17);
    traverse(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(q, 3);
    enqueue(q, 8);
    traverse(q);

    return 0;
}
