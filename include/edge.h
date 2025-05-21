#ifndef EDGE_H
#define EDGE_H

// DATA STRUCTURES:
typedef struct Edge
{
    int src;
    int dest;
    int weight;
} Edge;

// FUNCTIONS:
int compareEdges(const void* a, const void* b);

#endif