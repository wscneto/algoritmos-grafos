#include <stdio.h>
#include <stdlib.h>
#include "../../include/heap.h"

/* CRIAR HEAP */
MinHeap* createHeap(int capacity) 
{
    MinHeap* heap = malloc(sizeof(MinHeap));
    heap->nodes = malloc(capacity * sizeof(HeapNode));
    heap->pos = malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

/* TROCAR NOS DA HEAP DE LUGAR */
void swapHeapNode(HeapNode* a, HeapNode* b) 
{
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

/* ORGANIZAR A HEAP  */
void minHeapify(MinHeap* heap, int index) 
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->nodes[left].dist < heap->nodes[smallest].dist) smallest = left;
    if (right < heap->size && heap->nodes[right].dist < heap->nodes[smallest].dist) smallest = right;

    if (smallest != index) 
    {
        HeapNode smallestNode = heap->nodes[smallest];
        HeapNode indexNode = heap->nodes[index];

        heap->pos[smallestNode.vertex] = index;
        heap->pos[indexNode.vertex] = smallest;

        swapHeapNode(&heap->nodes[smallest], &heap->nodes[index]);
        minHeapify(heap, smallest);
    }
}

/* VERIFICAR SE A HEAP ESTÁ VAZIA */
int isEmpty(MinHeap* heap) { return heap->size == 0; }

/* EXTRAI O TOPO DA HEAP(PROXIMO VERTICE NÃO PROCESSADO) */
HeapNode extractMin(MinHeap* heap) 
{
    if (isEmpty(heap)) 
    {
        HeapNode empty = {-1, -1};
        return empty;
    }

    HeapNode root = heap->nodes[0];
    HeapNode lastNode = heap->nodes[heap->size - 1];
    heap->nodes[0] = lastNode;

    heap->pos[root.vertex] = heap->size - 1;
    heap->pos[lastNode.vertex] = 0;

    --heap->size;
    minHeapify(heap, 0);

    return root;
}

/* ATUALIZA A DISTANCIA DE UM VERTICE */
void decreaseKey(MinHeap* heap, int v, int dist) 
{
    int i = heap->pos[v];
    heap->nodes[i].dist = dist;

    while (i && heap->nodes[i].dist < heap->nodes[(i - 1) / 2].dist) 
    {
        heap->pos[heap->nodes[i].vertex] = (i - 1) / 2;
        heap->pos[heap->nodes[(i - 1) / 2].vertex] = i;
        swapHeapNode(&heap->nodes[i], &heap->nodes[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

/* VERIFICAR SE O VERTICE AINDA ESTÁ NA HEAP*/
int isInMinHeap(MinHeap* heap, int v) 
{
    if (heap->pos[v] < heap->size) return 1;

    return 0;
}

/* LIBERAR MEMÓRIA */
void freeHeap(MinHeap* heap) 
{
    if (heap == NULL) return;
    free(heap->pos);
    free(heap->nodes);
    free(heap);
}
