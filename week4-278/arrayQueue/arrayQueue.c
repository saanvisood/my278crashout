#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// IMPLEMENTING QUEUE WITH ARRAY

#define MAX_SIZE 10

int q[MAX_SIZE];
int count = 0, front = 0, end = 0;

bool isEmpty(void)
{
    return (count == 0);
}

bool isFull(void)
{
    return (count == MAX_SIZE);
}

bool enqueue(int n)
{
    if (isFull())
        return false; // already full?
    // add to end of queue
    q[end] = n;
    end = (end + 1) % MAX_SIZE; // wrap around
    count++;
    return true;
}

bool dequeue(int *n)
{
    if (isEmpty())
        return false; // already empty?
    // remove from front of queue
    *n = q[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return true;
}

// Testing queue array implementation

int main(void)
{
    int i, value;

    // enqueue 10 items
    for (i = 0; i < 10; i++)
    {
        enqueue(100 - i);
    }

    // dequeue and display
    while (dequeue(&value))
    {
        printf("    %d", value);
    }

    putchar('\n');
    return 0;
}