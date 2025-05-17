#ifndef HEAP_H
#define HEAP_H

// DATA STRUCTURES:
typedef struct HeapNode
{
    int vertex;
    int dist;
} HeapNode;

typedef struct MinHeap
{
    HeapNode* nodes;
    int size;
    int capacity;
    int* pos;
} MinHeap;

// FUNCTIONS:
/* CRIAR HEAP */
MinHeap* createHeap(int capacity);
/* TROCAR NOS DA HEAP DE LUGAR */
void swapHeapNode(HeapNode* a, HeapNode* b);
/* ORGANIZAR A HEAP  */
void minHeapify(MinHeap* heap, int index);
/* VERIFICAR SE A HEAP ESTÁ VAZIA */
int isEmpty(MinHeap* heap);
/* EXTRAI O TOPO DA HEAP(PROXIMO VERTICE NÃO PROCESSADO) */
HeapNode extractMin(MinHeap* heap);
/* ATUALIZA A DISTANCIA DE UM VERTICE */
void decreaseKey(MinHeap* heap, int v, int dist);
/* VERIFICAR SE O VERTICE AINDA ESTÁ NA HEAP*/
int isInMinHeap(MinHeap* heap, int v);
/* LIBERAR MEMÓRIA */
void freeHeap(MinHeap* heap);

#endif
