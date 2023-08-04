#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if (top == NULL)
        return 1;
    return 0;
}

int isFull()
{
    // if we are unable to allocate memory in the RAM
    // it means our heap memory is full
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
        return 1;
    return 0;
}

void linkedlist_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull())
        printf("Stack overflow !!!\n");
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int peek(struct Node *top, int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int pop(struct Node **top)
{
    if (isEmpty(*top))
        printf("Stack empty !!!\n");
    else
    {
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 78);
    top = push(top, 728);
    top = push(top, 7280);
    top = push(top, 78000);

    printf("Value at position %d is %d\n", 0, peek(top, 0));
    // int ele = pop(&top);
    // printf("POPED %d\n", ele);
    // linkedlist_traversal(top);
    return 0;
}