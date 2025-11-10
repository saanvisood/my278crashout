#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int value;
} node;

// Linked list recursive insert (sorted)

// helper to create new node in LL dynamically (on the heap)
node *newNode(int value, node *next)
{
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = next;
    return tmp;
}

// recursive sorted insert
node *insertSorted(node *head, int value)
{
    // base case: insert at beginning or end of LL
    if (head == NULL || value < head->value)
    {
        return newNode(value, head);
    }

    // recursive step: insert into rest of list
    head->next = insertSorted(head->next, value);
    return head;
}

void freeList(node *head)
{
    while (head != NULL)
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

void printList(node *head)
{
    for (node *curr = head; curr != NULL; curr = curr->next)
        printf("%d -> ", curr->value);
    printf("NULL\n");
}

int main(void)
{
    struct node *head = NULL;
    head = insertSorted(head, 27);
    head = insertSorted(head, 92);
    head = insertSorted(head, 12);
    head = insertSorted(head, 14);
    printList(head);
}