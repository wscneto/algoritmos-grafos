#ifndef MINHEAP_H
#define MINHEAP_H

// DATA STRUCTURES:
typedef struct minHeapNode
{
    int vertex;
    int key;
} minHeapNode;

typedef struct minHeap
{
    int size;
    int capacity;
    int* pos;
    minHeapNode** array;
} minHeap;

// FUNCTIONS:
minHeapNode* createMinHeapNode(int vertex, int key);
minHeap* createMinHeap(int capacity);
void swapMinHeapNodes(minHeapNode** v, minHeapNode** w);
void minHeapify(minHeap* heap, int idx);
int isEmpty(minHeap* heap);
minHeapNode* extractMin(minHeap* heap);
void decreaseKey(minHeap* heap, int vertex, int key);
int isInMinHeap(minHeap* heap, int vertex);

#endif