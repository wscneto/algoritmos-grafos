#ifndef QUEUE_H
#define QUEUE_H

// DATA STRUCTURES:
typedef struct StackNode
{
    int vertex;
    struct StackNode* next;
} StackNode;

typedef struct Stack
{
    StackNode* top;
} Stack;

// FUNCTIONS:
Stack* createStack();
void push(Stack* s, int vertex);
int pop(Stack* s);
void freeStack(Stack* s);

#endif
