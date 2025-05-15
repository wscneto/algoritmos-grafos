#ifndef QUEUE_H
#define QUEUE_H

typedef struct StackNode {
    int vertex;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

Stack* createStack();
void push(Stack* s, int vertex);
int pop(Stack* s);
void freeStack(Stack* s);

#endif
