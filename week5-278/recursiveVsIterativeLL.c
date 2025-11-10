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
node *insertSortedRecursive(node *head, int value)
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

/*
int main(void)
{
    struct node *head = NULL;
    head = insertSortedRecursive(head, 27);
    head = insertSortedRecursive(head, 92);
    head = insertSortedRecursive(head, 12);
    head = insertSortedRecursive(head, 14);
    printList(head);
}
*/

// Linked list iterative insert (sorted)

node *insertSortedIterative(node *head, int value)
{
    node *new_node = newNode(value, NULL);

    // base case: empty list or insert at beginning (first node)
    if (head == NULL || value < head->value)
    {
        new_node->next = head;
        return new_node;
    }

    // find position to insert
    node *current = head;
    // traverse until node whose next node's value is greater than value we want to insert is found
    while (current->next != NULL && current->next->value < value)
    {
        current = current->next;
    }

    // insert node at correct position
    new_node->next = current->next;
    current->next = new_node;

    // head unchanged
    return head;
}