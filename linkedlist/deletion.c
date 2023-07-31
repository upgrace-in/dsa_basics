#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int linkedlistTransversal(struct Node *ptr)
{
    if (ptr == NULL)
        return 0;
    printf("%d \n", ptr->data);
    linkedlistTransversal(ptr->next);
}

struct Node *deleteAtFirst(struct Node *head)
{
    head = head->next;
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

struct Node *deleteValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = p->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;

        // deleting node
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    
    return head;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = first;

    first->data = 47;
    first->next = second;

    second->data = 74;
    second->next = NULL;

    linkedlistTransversal(head);
    printf("LinkedList After deletion: \n");
    // head = deleteAtFirst(head);
    // head = deleteAtIndex(head, 1);
    // head = deleteAtEnd(head);
    head = deleteValue(head, 7);

    linkedlistTransversal(head);

    return 0;
}