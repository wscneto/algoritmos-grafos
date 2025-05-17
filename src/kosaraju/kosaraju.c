#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/graph.h"
#include "../../include/stack.h"

Graph* transposeGraph(Graph* G) 
{
    int V = G->numVertices;
    Graph* GT = createGraph(V);

    for (int v = 0; v < V; v++) 
    {
        Vertex* w = G->adjLists[v];
        while (w) 
        {
            addEdge(GT, w->vertex, v, 0);
            w = w->next;
        }
    }
    return GT;
}

void DFS(Graph* G, int start, int* visited, Stack* finishOrder, Stack* component) 
{
    Stack* dfsStack = createStack();
    push(dfsStack, start);
    visited[start] = 1;
    
    if (component) push(component, start);

    while (dfsStack->top != NULL) 
    {
        int v = dfsStack->top->vertex;
        int hasUnvisited = 0;

        Vertex* w = G->adjLists[v];
        while (w) 
        {
            if (!visited[w->vertex]) 
            {
                visited[w->vertex] = 1;
                push(dfsStack, w->vertex);
                if (component) push(component, w->vertex);
                hasUnvisited = 1;
                break;
            }

            w = w->next;
        }

        if (!hasUnvisited) 
        {
            pop(dfsStack);
            if (finishOrder) push(finishOrder, v);
        }
    }

    freeStack(dfsStack);
}

void kosaraju(Graph* G, FILE* saida) 
{
    int V = G->numVertices;
    int* visited = (int*)calloc(V, sizeof(int));
    Stack* finishOrder = createStack();

    /* 1º DFS no grafo original */
    for (int v = 0; v < V; v++) 
        if (!visited[v]) DFS(G, v, visited, finishOrder, NULL);

    /* 2º Calcular a transposta de G  */
    Graph* GT = transposeGraph(G);

    /* 3º DFS no grafo transposto */
    memset(visited, 0, V * sizeof(int));
    while (finishOrder->top != NULL) 
    {
        int v = pop(finishOrder);
        if (!visited[v]) {
            Stack* component = createStack();
            DFS(GT, v, visited, NULL, component);
            
            /* Imprime o componente na ordem correta */
            int* nodes = (int*)malloc(V * sizeof(int));
            int count = 0;
            while (component->top != NULL)
                nodes[count++] = pop(component) + 1;

            /* Ordena e imprime */
            for (int i = count-1; i >= 0; i--)
            {
                if(!saida) printf("%d ", nodes[i]);
                else fprintf(saida, "%d ", nodes[i]);
            }
                
            if(!saida) printf("\n");
                else fprintf(saida, "\n");
            
            free(nodes);
            freeStack(component);
        }
    }

    /* Liberação de memória */
    free(visited);
    freeStack(finishOrder);
    deleteGraph(GT);
}

void printHelp()
{
    printf("Uso: ./kosaraju -f <arquivo_entrada> -o <arquivo_saida>\n");
    printf("Parametros:\n");
    printf("  -h               Mostra essa mensagem de ajuda\n");
    printf("  -f <arquivo>     Arquivo de entrada com o grafo\n");
    printf("  -o <arquivo>     Arquivo de saída para os resultados\n");
}

int main(int argc, char *argv[])
{
    char *inputFile = NULL;
    char *outputFile = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            printHelp();
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) inputFile = argv[++i];
        else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) outputFile = argv[++i];
    }

    if (inputFile == NULL)
    {
        printf("Erro: você deve fornecer o arquivo de entrada (-f)\n");
        exit(EXIT_FAILURE);
    }

    FILE *entrada = fopen(inputFile, "r");
    if (!entrada)
    {
        printf("Erro ao abrir arquivo de entrada");
        exit(EXIT_FAILURE);
    }

    FILE *saida = stdout;
    if (outputFile != NULL)
    {
        saida = fopen(outputFile, "w");
        if (!saida)
        {
            printf("Erro ao abrir arquivo de saída");
            fclose(entrada);
            exit(EXIT_FAILURE);
        }
    }

    int numVertices, numArestas, v, w;
    fscanf(entrada, "%d %d", &numVertices, &numArestas);

    Graph *G = createGraph(numVertices);
    for (int count = 0; count < numArestas; count++)
    {
        fscanf(entrada, "%d%d", &v, &w);
        addEdge(G, v-1, w-1, 0);
    }
    
    /* CHAMANDO O ALGORITMO */
    kosaraju(G, saida);

    deleteGraph(G);
    fclose(entrada);
    if (saida != stdout) fclose(saida);

    return 0;
}
