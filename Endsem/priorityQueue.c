#include <stdio.h>
#include <stdlib.h>

struct pq {
    int f;
    int r;
    int size;
    int *data;
    int *priority;
};

int isFull(struct pq *ptr) {
    return ptr->r == ptr->size - 1;
}

int isEmpty(struct pq *ptr) {
    return ptr->f > ptr->r;
}
void enqueue(struct pq *ptr, int val, int pri) {
    int i;
    if (isFull(ptr)) {
        printf("Priority Queue is full\n");
        return;
    }

    if (ptr->f == -1) { 
        ptr->f = ptr->r = 0;
        ptr->data[0] = val;
        ptr->priority[0] = pri;
    } else {
        i = ptr->r;
        while (i >= ptr->f && ptr->priority[i] > pri) {
            ptr->data[i + 1] = ptr->data[i];
            ptr->priority[i + 1] = ptr->priority[i];
            i--;
        }

        ptr->data[i + 1] = val;
        ptr->priority[i + 1] = pri;
        ptr->r++;
    }
}
int dequeue(struct pq *ptr) {
    if (isEmpty(ptr)) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    int val=ptr->data[ptr->f];
    if(ptr->f==ptr->r)
        {
            ptr->f=ptr->r=-1;
        }
        else{
            ptr->f++;
        }
    return val;
}


void traverse(struct pq *ptr) {
    int i;
    if (isEmpty(ptr)) {
        printf("Queue empty\n");
        return;
    }

    printf("Data  Priority\n");
    for (i = ptr->f; i <= ptr->r; i++) {
        printf("%d\t%d\n", ptr->data[i], ptr->priority[i]);
    }
}

int main() {
    struct pq *q = (struct pq *)malloc(sizeof(struct pq));

    q->f = -1;
    q->r = -1;
    q->size = 5;
    q->data = (int *)malloc(q->size * sizeof(int));
    q->priority = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 10, 2);
    enqueue(q, 3, 1);
    enqueue(q, 17, 4);
    enqueue(q, 7, 3);

    traverse(q);

    printf("Dequeued: %d\n", dequeue(q));
    traverse(q);

    return 0;
}
