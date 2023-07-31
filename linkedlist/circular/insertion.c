#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTransversal(struct Node *head)
{
    struct Node *p = head;
    do
    {
        printf("%d \n", p->data);
        p = p->next;
    } while (p != head)
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *p = head->next;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = newNode;
    newNode->next = head;

    return newNode;
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    // allocation of memory in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 74;
    second->next = third;

    third->data = 47;
    third->next = forth;

    forth->data = 4274;
    forth->next = head;

    linkedlistTransversal(head);
    printf("Insertion At First: \n");
    head = insertAtFirst(head, 2);
    linkedlistTransversal(head);

    return 0;
}