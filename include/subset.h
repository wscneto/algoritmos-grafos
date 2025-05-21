#ifndef SUBSET_H
#define SUBSET_H

// DATA STRUCTURES:
typedef struct Subset
{
    int parent;
    int rank;
} Subset;

// FUNCTIONS:
int find(Subset subsets[], int i);

void unionSets(Subset subsets[], int x, int y);

#endif