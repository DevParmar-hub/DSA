#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void traverser(struct node *ptr)
{
    {
        while (ptr != NULL)
        {
            printf("%d\t", ptr->value);
            ptr = ptr->next;
        }
    }
    printf("\n");
}
struct node *newNode()
{

    return (struct node *)malloc(sizeof(struct node));
}
struct node *insertBeginning(struct node *ptr, int val)
{
    struct node *p = newNode();
    p->value=val;
    p->next = ptr;
    return p;
}
 void insertEnd(struct node*ptr,int val)
 {
    struct node *p = newNode();
    p->value=val;
    struct node* temp=ptr;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->next=NULL;
 }
 void insertAfter(struct node*ptr,int val,int index)
 {
    int i=1;
    struct node *p = newNode();
    p->value=val;
    struct node* temp=ptr;
    while(i!=index)
    {
        temp=temp->next;
        i++;
    }
    p->next=temp->next;
    temp->next=p;
 }
void main()
{
    struct node *head = newNode();
    struct node *second = newNode();
    struct node *third = newNode();
    struct node *fourth = newNode();
    head->value = 3;
    head->next = second;
    second->value = 7;
    second->next = third;
    third->value = 10;
    third->next = fourth;
    fourth->value = 17;
    fourth->next = NULL;
    traverser(head);
    head = insertBeginning(head, 47);
    traverser(head);
    insertEnd(head,21);
    traverser(head);
    insertAfter(head,11,3);
    traverser(head);
}
