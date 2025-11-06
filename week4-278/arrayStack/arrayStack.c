#include <stdio.h>

// IMPLEMENTING STACK WITH ARRAY

// int top = -1; // unique value for top element: -1
// int stack[100]; // define stack size as 100 (max no of elements)
//
// int push (int n) {
//     if (top == 99) return 0; // handling push overflow
//     stack[++top] = n;
//     return 1;
//     // ++top is a pre-increment operator
//     // meaning first increment top, then use its new value
//     // top = -1 --> ++top makes it 0 --> assignment becomes stack[0] = n --> first element goes into stack[0]
//     // top = 0 --> ++top makes it 1 --> assignment becomes stack[1] = n --> next element stored in stack[1]
// }
//
// int pop (int *value) { // value is a pointer to an integer, i.e. instead of passing the actual int, we are passing the address of an int var in memory
//     if (top == -1) return 0; // handling pop underflow
//     *value = stack[top--]; // use, decrement, store in memory location that value points to
//     return 1;
//     // top-- is a post-decrement operator
//     // meaning use current value of top, then decrement it
//     // top = 2 (pre-pop) --> stack[top--] means return stack[2], then reduce top to 1
//     // retrieve last inserted element at index 2, and move top pointer down one position
//
//     // top = 0 (pre-pop) --> stack[top--] returns stack[0], then top = -1 meaning stack is empty again
// }

// IMPLEMENTING STACKS WITH ARRAY
// for multiple stacks, can create as many instances as needed

typedef struct
{
    // define members top, and data array (each of the 100 elements is a member of the stack)
    int top;
    int data[100];
} ArrayStack;

ArrayStack s = {.top = -1}; // cannot initialize top in struct, must do so like this

int push(ArrayStack *stack, int n)
{ // params: pointer to a stack structure, value to push
    if (stack->top == 99)
        return 0; // handling overflow
    stack->data[++(stack->top)] = n;
    // stack->data : accesses data member of struct pointed to by stack (equiv to *stack.top)
    // -> means follow the pointer, then access the member
    // ++stack->top : accesses top member of struct, pre-increments and uses top as index
    return 1;
}

int pop(ArrayStack *stack, int *value)
{
    if (stack->top == -1)
        return 0;
    *value = stack->data[(stack->top)--];
    return 1;
}

// Testing stack array implementation

// peek function tos - doesn't pop top element but gives caller a way to access + modify top element directly
int tos(ArrayStack *stack, int **pptop)
{ // params: pointer to stack struct (pass by reference), pointer to a pointer to int used to return address of top element
    if (stack->top == -1)
        return 0;
    *pptop = &(stack->data[stack->top]); // pptop contains the address of top element
    return 1;
}

int main(void)
{
    int i, value, *ptr_top;

    for (i = 0; i < 5; i++)
    {
        // initialized s as an instance of ArrayStack (a stack) earlier for initializing top
        push(&s, 100 + i);
    }

    // find top element, return its address, then add 50 to it in place
    while (pop(&s, &value))
    { // while stack is not empty (same as while (1)), pop only returns 1 if stack had element to pop
        printf("    %d\n", value);
        if (tos(&s, &ptr_top)) // if tos returns 1
            *ptr_top = *ptr_top + 50;
    }
    putchar('\n');
    return 0;
}