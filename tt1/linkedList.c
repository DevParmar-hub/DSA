#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void Traverser(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *newNode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = val;
    temp->next = NULL;
    return temp;
}

struct node *insertElement(struct node *ptr, int val)
{
    struct node *newElement = newNode(val);
    newElement->next = ptr;
    newElement->value = val;
    return newElement;
}

void main()
{

    struct node *first = newNode(5);
    struct node *second = newNode(10);
    struct node *third = newNode(3);
    first->next = second;
    second->next = third;
    third->next = NULL;
    first = insertElement(first, 99);
    Traverser(first);
}