#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int vertex;
    int dist;
} HeapNode;

typedef struct {
    HeapNode* nodes;
    int size;
    int capacity;
    int* pos;
} MinHeap;


#endif