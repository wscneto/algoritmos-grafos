# Algoritmo de Dijkstra com Min Heap

Este projeto implementa o algoritmo de Dijkstra para encontrar os menores caminhos a partir de um vértice de origem em um grafo direcionado e ponderado, utilizando uma fila de prioridade baseada em Min Heap.

## 📌 Compilação

Certifique-se de ter os arquivos `graph.h`, `heap.h` e suas respectivas implementações disponíveis nos diretórios `include` e `src/headers`.

Compile com:

```bash
make
ou
gcc -o dijkstra dijkstra.c ../headers/graph.c ../headers/heap.c
```

## 🚀 Execução

```bash
make run
ou
./dijkstra -f <arquivo_entrada> -i <vertice_inicial> -o <arquivo_saida>
```

### Parâmetros

-   `-h`: Mostra a ajuda.
-   `-f <arquivo_entrada>`: Caminho para o arquivo contendo o grafo.
-   `-i <vertice_inicial>`: Vértice de origem para iniciar o algoritmo (indexado a partir de 1).
-   `-o <arquivo_saida>` (opcional): Caminho do arquivo onde o resultado será salvo.

## 📝 Formato do Arquivo de Entrada

O arquivo de entrada deve conter:

```
n m
v1 w1 c1
v2 w2 c2
...
vm wm cm
```

Onde:

-   `n` é o número de vértices
-   `m` é o número de arestas
-   Cada linha `vi wi ci` representa uma aresta do vértice `vi` ao vértice `wi` com custo `ci`.

Os vértices devem estar indexados a partir de 1.

## 📤 Saída

A saída consiste na impressão da menor distância entre o vértice de origem e todos os demais vértices:

```
1:0 2:3 3:8 4:-1 ...
```

Se um vértice for inalcançável, sua distância será representada por `-1`.

## 📚 Exemplo de Uso

**Entrada(grafo.txt):**

```
6 8
1 2 5
1 3 4
1 4 2
1 6 6
2 4 1
2 5 3
3 6 2
4 6 4
```

**Comando:**

```bash
./dijkstra -f grafo.txt -i 1 -o resultado.txt
```

**Saída(resultado.txt):**

```
1:0 2:3 3:4 4:2 5:10 6:3
```

---

## 📌 Observações

-   Os vértices são numerados a partir de **1** na entrada e saída.
-   As arestas são consideradas **não direcionadas**.

---

## 🤝 Créditos

Implementação feita para fins educacionais em Ciência da Computação, com suporte ao uso acadêmico e aprendizado de algoritmos de grafos.
