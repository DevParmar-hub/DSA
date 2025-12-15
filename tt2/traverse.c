#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        if (root->data == key)
            return;
        else if (root->data < key)
        {
            prev = root;
            root = root->right;
        }
        else
        {
            prev = root;
            root = root->left;
        }
    }
        struct node* new=createNode(key);
        if(prev->data<key)
        prev->right=new;
        else
        prev->left=new;
}
struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void search(struct node *root, int key)
{
    if (root == NULL)
        printf("Sorry bruv");
    else if (root->data == key)
        printf("It exists");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}
int main()
{
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);
    printf("\n");
    search(p, 2);
    return 0;
}