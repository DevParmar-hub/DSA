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
struct node *deleteFirst(struct node *ptr)
{
    struct node *temp = ptr->next;
    free(ptr);
    return temp;
}
void deleteEnd(struct node *ptr)
{
    struct node *temp = ptr;
    struct node *temp2 = ptr->next;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
        temp = temp->next;
    }
    temp->next = NULL;
    free(temp2);
}
void deleteAfter(struct node *ptr, int index)
{
    int i = 1;
    struct node *temp = ptr;
    struct node *temp2 = ptr->next;
    if (index == 1)
    {
        printf("Please use another method\n");
    }
    else
    {

        while (i != index)
        {
            temp = temp->next;
            temp2 = temp2->next;
            i++;
        }
        if (temp->next == NULL)
        {
            printf("Please use another method\n");
        }
        else
        {
            temp->next = temp2->next;
            free(temp2);
        }
    }
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
    // head=deleteFirst(head);
    // traverser(head);
    // deleteEnd(head);
    // traverser(head);
    deleteAfter(head, 3);
    traverser(head);
}