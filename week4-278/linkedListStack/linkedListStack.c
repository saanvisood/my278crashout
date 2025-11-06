#include <stdio.h>
#include <stdlib.h>

// IMPLEMENTING STACKS WITH SINGLY LINKED LIST

typedef struct stk_node
{
    struct stk_node *next; // next node
    int nodeval;           // value of node
} StkNode;

void push(StkNode **stkHead, int n)
{                                         // params: a pointer to a pointer to top node (allows fn to modify caller's head pointer), value
    StkNode *p = malloc(sizeof(StkNode)); // create new node/pointer p
    p->nodeval = n;                       // stores given value n into node's data field
    p->next = *stkHead;                   // links new node to current top of stack
    *stkHead = p;                         // updates caller's head pointer
}

int pop(StkNode **stkHead, int *rslt)
{ // params: a pointer to a pointer to top node, pointer to popped integer value
    StkNode *p = *stkHead;
    *rslt = 0;
    if (*stkHead != NULL)
    {
        *stkHead = p->next; // updates head pointer to skip over current top node, effectively removing it (we no longer where it is in memory)
        *rslt = p->nodeval; // extract integer value from node removed and write to *rslt
        free(p);            // discard node
        return 1;
    }
    return 0;
}

int tos(StkNode *stkHead, int **pptop)
{
    if (stkHead == NULL)
        return 0;
    *pptop = &(stkHead->nodeval);
    return 1;
}

// Testing stack singly linked list implementation

StkNode *stk = NULL; // create instance and point to NULL (empty)

int main(void)
{
    int i, value, *ptr_top;

    for (i = 0; i < 5; i++)
    {
        push(&stk, 100 + i);
    }

    while (pop(&stk, &value))
    {
        printf("    %d", value);
        if (tos(stk, &ptr_top))
        {
            *ptr_top = *ptr_top + 50;
        }
    }
    putchar('\n');
    return 0;
}