#include <stdio.h>
#include <stdlib.h>
struct q {
    int f;
    int r;
    int size;
    int *arr;
};

int isFull(struct q*ptr)
{
    if(ptr->r==ptr->size-1)
    return 1;
    else
    return 0;
}
int isEmpty(struct q*ptr)
{
    if(ptr->f==ptr->r)
    return 1;
    else 
    return 0;
}
void enqueue(struct q*ptr,int val)
{
    if(isFull(ptr))
    printf("The Q is full my guy.");
    else
    {
        ptr->r++;
        ptr->arr[ptr->r]=val;
    }
}
int dequeue(struct q *ptr)
{
    if(isEmpty(ptr))
    return 0;
    else
    {
        int val=ptr->arr[ptr->f];
        ptr->f++;     
        if(ptr->f==ptr->r)ptr->r=ptr->f=-1;
        return val;     
    }
}
void traverse(struct q*ptr)
{
    int i=ptr->f+1;
    for(i;i<=ptr->r;i++)
    {
        printf("%d\t",ptr->arr[i]);
    }
    printf("\n");
}
void main()
{
    struct q * q=(struct q*)malloc(sizeof(struct q));
    q->f=-1;
    q->r=-1;
    q->size=5;
    q->arr=(int*)malloc(q->size*sizeof(int));
    enqueue(q,3);
    enqueue(q,7);
    enqueue(q,10);
    enqueue(q,17);
    traverse(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    traverse(q);
}