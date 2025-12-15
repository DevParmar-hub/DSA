#include <stdio.h>
#include <stdlib.h>
struct q
{
    int f;
    int r;
    int size;
    int *arr;
};

int isFull(struct q *ptr)
{
    if ((ptr->r + 1) % ptr->size == ptr->f)
        return 1;
    else
        return 0;
}
int isEmpty(struct q *ptr)
{
    if (ptr->f ==-1)
        return 1;
    else
        return 0;
}
void enqueue(struct q *ptr, int val)
{
    if (isFull(ptr))
        printf("The Q is full my guy.");
else if (isEmpty(ptr))
    {
        ptr->f = ptr->r = 0;
        ptr->arr[ptr->r] = val;
    }
    else
    {
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = val;
    }
}
int dequeue(struct q *ptr)
{
    if (isEmpty(ptr))
        return 0;
    else
    {
        int val = ptr->arr[ptr->f];
        if (ptr->f == ptr->r)
        {
            ptr->f = ptr->r = -1;
        }
        else
        {
            ptr->f = (ptr->f + 1) % ptr->size;
        }
        return val;
    }
}
void traverse(struct q *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return;
    }

    int i = ptr->f;
    while (1)
    {
        printf("%d\t", ptr->arr[i]);
        if (i == ptr->r)
            break;
        i = (i + 1) % ptr->size;
    }
    printf("\n");
}
void main()
{
    struct q *q = (struct q *)malloc(sizeof(struct q));
    q->f = -1;
    q->r = -1;
    q->size = 5;
    q->arr = (int *)malloc(q->size * sizeof(int));
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
}