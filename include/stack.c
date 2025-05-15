#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int vertex) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->vertex = vertex;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) return -1;
    StackNode* temp = s->top;
    int vertex = temp->vertex;
    s->top = temp->next;
    free(temp);
    return vertex;
}

void freeStack(Stack* s) {
    while (s->top != NULL) {
        pop(s);
    }
    free(s);
}
