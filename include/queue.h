#ifndef QUEUE_H
#define QUEUE_H

// DATA STRUCTURES:
typedef struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// FUNCTIONS:
Queue* createQueue(unsigned capacity);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);

#endif