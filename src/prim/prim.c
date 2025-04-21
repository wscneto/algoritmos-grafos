#include <stdio.h>
#include <stdlib.h>
#include "../../include/graph.h"

void printHelpPrim()
{
    printf("Uso: ./prim -f <arquivo_entrada> -o <arquivo_saida> -i <vertice_inicial>\n");
    printf("Parâmetros:\n");
    printf("  -h               Mostra essa mensagem de ajuda\n");
    printf("  -f <arquivo>     Arquivo de entrada com o grafo\n");
    printf("  -o <arquivo>     Arquivo de saída para os resultados\n");
    printf("  -i <vértice>     Vértice inicial para o algoritmo de Prim\n");
}

int main(int argc, char* argv[])
{
    char* inputArg = NULL;
    char* outputArg = NULL;
    int origin = -1;

    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-h") == 0)
        {
            printHelp();
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) inputArg = argv[++i];
        else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) outputArg = argv[++i];
        else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) origin = atoi(argv[++i]);
    }

    if(inputArg == NULL || origin == -1)
    {
        printf("Erro: você deve fornecer o arquivo de entrada (-f) e o vértice inicial (-i).\n");
        exit(EXIT_FAILURE);
    }

    FILE *inputFile = fopen(inputArg, "r");
    if (!inputFile)
    {
        printf("Erro ao abrir arquivo de entrada");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = stdout;
    if(outputFile != NULL)
    {
        outputFile = fopen(outputArg, "w");
        if(!outputFile)
        {
            printf("Erro ao abrir arquivo de saída");
            fclose(inputFile);
            exit(EXIT_FAILURE);
        }
    }
}