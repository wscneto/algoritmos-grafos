#include <stdio.h>
#include "../../include/edge.h"

int compareEdges(const void* a, const void* b)
{
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}