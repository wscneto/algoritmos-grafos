#include <stdio.h>
#include <stdlib.h>
#include "../../include/queue.h"

Queue* createQueue(unsigned capacity)
{
    Queue* queue = malloc(sizeof(Queue));

    if(!queue)
    {
        printf("Erro na alocação de memória para fila (queue).");
        exit(EXIT_FAILURE);
    }

    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = malloc(queue->capacity * sizeof(int));

    if(!queue->array)
    {
        printf("Erro na alocação de memória para array da fila (queue).");
        exit(EXIT_FAILURE);
    }

    return queue;
}

int isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item)
{
    if(isFull(queue)) return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue)
{
    if(isEmpty(queue)) return -1;

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    
    return item;
}