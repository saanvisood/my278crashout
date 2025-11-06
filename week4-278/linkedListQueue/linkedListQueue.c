#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// IMPLEMENTING QUEUES WITH SINGLY LINKED LIST

// define node in queue
struct item
{
    struct item *next;
    int value;
};

// global vars
struct item *front, *end; // pointers to first node in queue (next dequeue) and last node (most recently enqueued), both NULL initially (empty)
int count = 0;            // tracks how many nodes are in queue

// checks if queue is empty to handle underflow before dequeuing
bool isEmpty(void)
{
    return (count == 0);
}

// adds element to end of queue
void enqueue(int n)
{
    // create new node (pointer because it will point to NULL) and allocate memory for it
    struct item *pnew = malloc(sizeof(struct item));
    pnew->value = n;   // set its value member to value n
    pnew->next = NULL; // set its pointer to the next node to NULL (no next node, at end of queue)
    // update current end node (if there is one)
    if (end != NULL)
    {                     // end itself points to the current last node (before enqueuing)
        end->next = pnew; // current end's next will point to new node (new end)
    }
    end = pnew; // end will point to new enqueued node now
    // if the queue was empty, new node is also the front node
    if (front == NULL)
    {
        front = pnew;
    }
    count++;
}

bool dequeue(int *n)
{                              // removes and return variable in node
    struct item *temp = front; // store the front of queue in temp var, needed so we can free its memory later
    if (count == 0)
        return false;    // if queue empty nothing to dequeue, return false
    *n = (front->value); // store value at front
    front = front->next; // second node becomes new front
    if (front == NULL)
        end = NULL; // if we removed only node in queue, reset both pointers to NULL
    free(temp);     // free old node
    count--;        // decrement count
    return true;
}

// Testing queue singly linked list implementation

int main(void)
{
    int i, value;

    // enqueue 5 items
    for (i = 0; i < 5; i++)
    {
        enqueue(100 + i);
    }

    // dequeue and display
    while (dequeue(&value))
    {
        printf("    %d", value);
    }

    putchar('\n');
    return 0;
}