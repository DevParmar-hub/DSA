#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *newNode()
{
    return (struct node *)malloc(sizeof(struct node));
}

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->info);
        ptr = ptr->next;
    }
}

struct node *insertBeg(struct node *ptr, int val)
{
    struct node *p = newNode();
    p->info = val;
    p->next = ptr;
    return p;
}

void insertEnd(struct node *ptr, int val)
{
    struct node *p = newNode();
    p->info = val;
    p->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
}
void insertAfter(struct node *ptr, int val, int index)
{
    struct node *p = newNode();
    p->info = val;
    int i = 0;
    while (i < index)
    {
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    ptr->next = p;
}

void main()
{
    struct node *head = newNode();
    struct node *second = newNode();
    struct node *third = newNode();
    head->info = 1;
    head->next = second;
    second->info = 2;
    second->next = third;
    third->info = 3;
    third->next = NULL;
    head = insertBeg(head, 20);
    insertEnd(head, 50);
    insertAfter(head, 67, 2);
    head = insertBeg(head, 100);
    head = insertBeg(head, 69);
    traverse(head);
    traverse(head);
}