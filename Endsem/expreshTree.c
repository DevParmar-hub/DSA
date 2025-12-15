#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
struct stack
{
    int top;
    struct node *arr[50];
};
struct node *createNode(char data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
struct stack *createStack()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    return s;
}
void push(struct stack *s, struct node *ptr)
{
    s->top++;
    s->arr[s->top] = ptr;
}
struct node *pop(struct stack *s)
{
    struct node *rem = s->arr[s->top];
    s->top--;
    return rem;
}
int isOp(char temp)
{
    return (temp == '+' || temp == '-' || temp == '*' || temp == '/');
}
struct node *build(char postfix[])
{
    struct stack *s = createStack();
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isOp(postfix[i]))
        {
            struct node *n = createNode(postfix[i]);
            n->right = (pop(s));
            n->left = (pop(s));
            push(s, n);
        }
        else
        {
            push(s, createNode(postfix[i]));
        }
    }
    return pop(s);
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
void main()
{
    char postfix[] = "ab+ef*g*-";
    struct node *root = build(postfix);
    inorder(root);
}
