#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../include/minHeap.h"

minHeapNode* createMinHeapNode(int vertex, int key)
{
    minHeapNode* node = malloc(sizeof(minHeapNode));
    node->vertex = vertex;
    node->key = key;
    return node;
}

minHeap* createMinHeap(int capacity)
{
    minHeap* heap = malloc(sizeof(minHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = malloc(capacity * sizeof(minHeapNode*));
    
    return heap;
}

void swapMinHeapNodes(minHeapNode** v, minHeapNode** w)
{
    minHeapNode* temp = *v;
    *v = *w;
    *w = temp;
}

void minHeapify(minHeap* heap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if(left < heap->size && heap->array[left]->key < heap->array[smallest]->key)
        smallest = left;
    else if(right < heap->size && heap->array[right]->key < heap->array[smallest]->key)
        smallest = right;

    if(smallest != idx)
    {
        // The nodes to be swapped in min heap
        minHeapNode* smallestNode = heap->array[smallest];
        minHeapNode* idxNode = heap->array[idx];

        // Swap positions
        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;

        // Swap nodes
        swapMinHeapNodes(&heap->array[smallest], &heap->array[idx]);

        minHeapify(heap, smallest);
    }
}

int isEmpty(minHeap* heap)
{
    return heap->size == 0;
}

minHeapNode* extractMin(minHeap* heap)
{
    if(isEmpty(heap)) return NULL;

    // Store the root node
    minHeapNode* root = heap->array[0];

    // Replace root node with last node
    minHeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    // Update position of last node
    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;

    // Reduce heap size and heapify root
    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(minHeap* heap, int vertex, int key)
{
    // Get the index of vertex in heap array
    int i = heap->pos[vertex];

    // Get the node and update its key value
    heap->array[i]->key = key;

    // Travel up while the complete tree is not heapified
    while(i && heap->array[i]->key < heap->array[(i - 1) / 2]->key)
    {
        // Swap this node with its parent
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;
        swapMinHeapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);

        // move to parent index
        i = (i - 1) / 2;
    }
}

int isInMinHeap(minHeap* heap, int vertex)
{
    return heap->pos[vertex] < heap->size;
}