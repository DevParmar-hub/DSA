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
struct node *newNode(int val)
{

    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->value=val;
    temp->next=NULL;
    return temp;
}
struct node *inserBef(struct node * head,int pos,int val)
{
    struct node * new=newNode(val);
    int i=1;
    struct node * ptr =head;
    if(pos==1)
    {
        new->next=head;
        return new;
    }
    else
    {
        while(i<pos-1&&ptr!=NULL)
        {
            ptr=ptr->next;
            i++;
        }
        new->next=ptr->next;
        ptr->next=new;
        return head;
    }
}
struct node *deleteBef(struct node * head,int pos)
{
    int i=1;
    if (pos==1)
    {
        printf("Sorry bruv\n");
        return head;
    }
    else if(pos==2)
    {
        struct node * ptr=head;
        head=head->next;
        free(ptr);
        return head;
    }
    else{
        struct node *temp=head;
        while(i<pos-1&& temp!=NULL){
            temp=temp->next;
            i++;
        }
        struct node* temp2=temp->next;
        temp->next=temp2->next;
        free(temp2);
        return head;

    }
}
void main()
{
    struct node * n=newNode(3);
    struct node * n2=newNode(17);
    struct node * n3=newNode(47);
    struct node * n4=newNode(44);
    n->next=n2;
    n2->next=n3;
    n3->next=n4;
    traverser(n);
    n=inserBef(n,1,11);
    traverser(n);
    n=deleteBef(n,2);
    traverser(n);

}