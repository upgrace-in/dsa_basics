#include <stdio.h>
// for malloc
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int linkedListTransversal(struct Node *ptr)
{
    // while (ptr != NULL)
    // {
    //     printf("%d \n", ptr->data);
    //     ptr = ptr->next;
    // }
    if(ptr == NULL) return 0;
    printf("%d \n", ptr->data);
    ptr = ptr->next;
    linkedListTransversal(ptr);
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocation of memory in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 74;
    second->next = third;

    third->data = 47;
    third->next = NULL;

    linkedListTransversal(head);

    return 0;
}