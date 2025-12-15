#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node
{
    int data;
    int priority;
    struct node *next;
};

/* Priority Queue structure */
struct pq
{
    struct node *front;
    struct node *rear;
};

/* Create a new node */
struct node *createNode(int data, int priority)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

struct node *enqueue(struct pq *q, int data, int priority) {
    struct node *newNode = createNode(data, priority);

    // Empty queue
    if (q->front == NULL) {
        q->front = q->rear = newNode;
        return q->front;
    }

    struct node *temp = q->front;
    struct node *prev = NULL;

    // Move while temp has lower or equal priority
    while (temp != NULL && temp->priority <= priority) {
        prev = temp;
        temp = temp->next;
    }

    // Insert newNode between prev and temp
    if (prev == NULL) { // Insert at front
        newNode->next = q->front;
        q->front = newNode;
    } else {
        newNode->next = temp;
        prev->next = newNode;
    }

    // Update rear if inserted at end
    if (temp == NULL) {
        q->rear = newNode;
    }

    return q->front;
}


/* Dequeue (remove front node) */
int dequeue(struct pq *q)
{
    if (q->front == NULL)
    {
        printf("Priority Queue is empty\n");
        return -1;
    }

    struct node *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    // If queue becomes empty, update rear
    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return val;
}

/* Traverse */
void traverse(struct pq *q)
{
    if (q->front == NULL)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    struct node *temp = q->front;
    printf("Data  Priority\n");
    while (temp!=NULL)
    {
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main()
{
    struct pq *q = (struct pq *)malloc(sizeof(struct pq));
    q->front = q->rear = NULL;

    enqueue(q, 10, 2);
    enqueue(q, 3, 1);
    enqueue(q, 17, 4);
    enqueue(q, 7, 3);

    printf("Priority Queue after enqueue:\n");
    traverse(q);

    int val = dequeue(q);
    printf("\nDequeued: %d\n", val);

    printf("\nPriority Queue after dequeue:\n");
    traverse(q);

    return 0;
}
