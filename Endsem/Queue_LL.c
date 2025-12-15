#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * front=NULL;
struct node* rear=NULL;
struct node * createNode(int data){
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->next=NULL;
    n->data=data;
    return n;
}
void enqueue(int data){
struct node * newNode=createNode(data);
if(front==NULL && rear==NULL)
{front=rear=newNode;}
else
{
    rear->next=newNode;
    rear=rear->next;
}
}
void display(){
    struct node* temp=front;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void dequeue(){
    if (front==NULL)
    printf("Sorry bruv empty queue");
    struct node * temp=front;
    front=front->next;
    if(front==NULL)
    rear=NULL;
    free(temp);
    printf("\n");
}
void main(){
enqueue(3);
enqueue(17);
enqueue(44);
enqueue(10);
display();
dequeue();
display();
}