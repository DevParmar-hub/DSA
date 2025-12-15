#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

/* Deque structure */
struct deque {
    struct node *front;
    struct node *rear;
};

/* Create an empty deque */
struct deque* createDeque() {
    struct deque *dq = (struct deque*)malloc(sizeof(struct deque));
    dq->front = dq->rear = NULL;
    return dq;
}

/* Check if deque is empty */
int isEmpty(struct deque *dq) {
    return dq->front == NULL;
}

/* Insert at rear */
void insertRear(struct deque *dq, int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
        newNode->next = newNode; // circular link
    } else {
        newNode->next = dq->front;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

/* Insert at front */
void insertFront(struct deque *dq, int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = dq->front;
        dq->rear->next = newNode;
        dq->front = newNode;
    }
}

/* Delete from front */
int deleteFront(struct deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque Empty\n");
        return -1;
    }
    int val = dq->front->data;
    if (dq->front == dq->rear) { // only one node
        free(dq->front);
        dq->front = dq->rear = NULL;
    } else {
        struct node *temp = dq->front;
        dq->front = dq->front->next;
        dq->rear->next = dq->front;
        free(temp);
    }
    return val;
}

/* Delete from rear */
int deleteRear(struct deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque Empty\n");
        return -1;
    }
    int val = dq->rear->data;
    if (dq->front == dq->rear) { // only one node
        free(dq->rear);
        dq->front = dq->rear = NULL;
    } else {
        struct node *temp = dq->front;
        while (temp->next != dq->rear) { // find node before rear
            temp = temp->next;
        }
        temp->next = dq->front;
        free(dq->rear);
        dq->rear = temp;
    }
    return val;
}

/* Display deque */
void display(struct deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque Empty\n");
        return;
    }
    struct node *temp = dq->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != dq->front);
    printf("\n");
}

/* Main function */
int main() {
    struct deque *dq = createDeque();

    insertRear(dq, 10);
    insertRear(dq, 20);
    insertRear(dq, 30);
    display(dq);  // 10 20 30

    insertFront(dq, 5);
    display(dq);  // 5 10 20 30

    deleteFront(dq);
    display(dq);  // 10 20 30

    deleteRear(dq);
    display(dq);  // 10 20

    insertFront(dq, 1);
    insertRear(dq, 40);
    display(dq);  // 1 10 20 40

    return 0;
}
