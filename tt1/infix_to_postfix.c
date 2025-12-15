#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

void printStack(struct stack *ptr)
{
    int i;
    for (i = 0; i <= ptr->top; i++)
    {
        printf("%d\n", ptr->arr[i]);
    }
}
int precedence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else
        return 0;
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
char stackTop(struct stack *ptr)
{
    int val = ptr->arr[ptr->top];
    return val;
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Sorry bruv the stacks empty");
        return 0;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
        return 1;
    else
        return 0;
}
void push(struct stack *ptr, int val)
{
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
    else
        printf("Sorry bruv The stack aint Empty\n");
}
char *infix_to_postfix(char *infix)
{
    int i = 0;
    int j = 0;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperator(infix[i]))
        {
            if (isEmpty(s) || precedence(infix[i]) > precedence(stackTop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                while (!isEmpty(s) &&
                       precedence(stackTop(s)) >= precedence(infix[i]))
                {
                    postfix[j] = pop(s);
                    j++;
                }
            }
        }
        else
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
    }
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
char*infix_prefix(char* infix)
{
    char temp;
    for(int i=0;i<strlen(infix)/2;i++)
    {
        temp=infix[i];
        infix[i]=infix[strlen(infix)-i-1];
        infix[strlen(infix)-i-1]=temp;
    }
    char *new=infix_to_postfix(infix);
     for(int i=0;i<strlen(new)/2;i++)
    {
        temp=new[i];
        new[i]=new[strlen(new)-i-1];
        new[strlen(new)-i-1]=temp;
    }
    return new;

}
void main()
{
    char infix[] = "a+b*c";
    printf("Answer is %s", infix_to_postfix(infix));
    printf("\n");
    printf("Answer is %s", infix_prefix(infix));
}