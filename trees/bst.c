/*BINARY SEARCH TREE*/
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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

struct node *searchIterativeMethod(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *ptr;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    /**
      BST
       4
     1   6
    5 2 N N
    */

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preorder(p);
    // printf("\n");
    // postorder(p);
    // printf("\n");
    // inorder(p);

    // printf("isBST: %d", isBST(p));

    // if (search(p, 7) != NULL)
    // {
    //     printf("!!! HARI BOL :)");
    // }
    // else
    // {
    //     printf("!!! HARI BOL :/");
    // }

    // if (searchIterativeMethod(p, 7) != NULL)
    // {
    //     printf("!!! HARI BOL :)");
    // }
    // else
    // {
    //     printf("!!! HARI BOL :/");
    // }

    insert(p, 16);

    preorder(p);

    return 0;
}