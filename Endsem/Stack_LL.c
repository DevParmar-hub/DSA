#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
struct node * top=NULL;
struct node* createNode(int data)
{
    struct node * newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void push(struct node * ptr,int data)
{  
    struct node * temp=createNode(data);
    temp->next=ptr;
    top=temp;
}
void pop(struct node * ptr)
{
    if(ptr==NULL){printf("Sorry bruv") ;return;}
    struct node * temp=top;
    top=top->next;
    printf("\nPopped %d\n",temp->data);
    free(temp);
}
void display(struct node *top){
    struct node* temp=top;
    while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }

}
void main(){
    struct node * n=createNode(3);
    top=n;
    push(top,17);
    push(top,10);
    display(top);
    pop(top);
    display(top);

}