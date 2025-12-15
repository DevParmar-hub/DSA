// create , insert , delete , traversal
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void insertAtEnd(struct node *ptr, int data)
{
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    struct node *new = createNode(data);
    ptr->next = new;
    new->prev = ptr;
}

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

void deleteAtIndex(struct node *ptr, int index)
{
    if (index == 1)
    {
        printf("Use delete at Start");
    }
    int i=1;
    while(i!=index){
        ptr=ptr->next;
        i++;
    }
    struct node* temp=ptr->prev;
    struct node* temp2=ptr->next;
    temp->next=temp2;
    temp2->prev=temp;
    free(ptr);
}

struct node *deleteAtStart(struct node *ptr)
{
    if (ptr == NULL)
        return NULL;

    struct node *temp = ptr->next;
    if (temp != NULL)
        temp->prev = NULL;

    free(ptr);
    return temp;
}

void deleteAtEnd(struct node *ptr)
{
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    struct node *temp = ptr->prev;
    temp->next = NULL;
    free(ptr);
}

void main()
{
    struct node *n1 = createNode(3);
    insertAtEnd(n1, 17);
    insertAtEnd(n1, 44);
    insertAtEnd(n1, 47);
    // deleteAtEnd(n1);
    // n1 = deleteAtStart(n1);
    deleteAtIndex(n1,2);

    traverse(n1);
}
