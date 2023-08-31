#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->left = NULL;
    n->data = data;
    n->right = NULL;
    return n;
}

// root -> left -> right
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// left -> right -> root
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}

// left -> root -> right 
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);

    }
}

int main()
{
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);

    p->left = p1;
    p->right = p2;

    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);

    return 0;
}