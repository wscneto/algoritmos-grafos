# Algoritmo de Prim com Min Heap

Este projeto implementa o algoritmo de **Prim** para encontrar a **Árvore Geradora Mínima (AGM)** de um grafo, utilizando uma **Min Heap** como fila de prioridade para otimização do desempenho.

## 📌 Compilação

Certifique-se de ter os arquivos `graph.h`, `heap.h` e suas respectivas implementações disponíveis nos diretórios `include` e `src/headers`.

Compile com:

```bash
make
ou
gcc -o prim prim.c ../headers/graph.c ../headers/heap.c
```

## 🚀 Execução

```bash
make run
ou
./prim -f <arquivo_entrada> -i <vertice_inicial> -o <arquivo_saida> -s
```

### Parâmetros

- `-h`: Mostra a ajuda.
- `-f <arquivo_entrada>`: Caminho para o arquivo contendo o grafo.
- `-i <vertice_inicial>`: Vértice de origem para iniciar o algoritmo (indexado a partir de 1). Padrão: 1
- `-o <arquivo_saida>` (opcional): Caminho do arquivo onde o resultado será salvo.
- `-s` (opcional): Imprime as arestas da AGM em vez do custo total.

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

- `n` é o número de vértices
- `m` é o número de arestas
- Cada linha `vi wi ci` representa uma aresta entre os vértices `vi` e `wi` com peso `ci`

**Os vértices são numerados a partir de 1.**

## 📤 Saída

A saída do algoritmo depende do uso do parâmetro `-s`:

- Sem `-s`: será impresso apenas o **custo total** da Árvore Geradora Mínima (AGM):
  ```
  9
  ```

- Com `-s`: serão impressas as arestas que compõem a AGM:
  ```
  (1,2) (1,3) (3,4)
  ```

## 📚 Exemplo de Uso

**Entrada (grafo.txt):**

```
4 5
1 2 1
1 3 4
2 3 2
3 4 3
2 4 5
```

**Comando (mostrar custo):**

```bash
./prim -f grafo.txt -i 1 -o resultado.txt
```

**Saída (resultado.txt):**

```
6
```

**Comando (mostrar solução):**

```bash
./prim -f grafo.txt -i 1 -o resultado.txt -s
```

**Saída (resultado.txt):**

```
(1,2) (2,3) (3,4)
```

---

## 📌 Observações

- Os vértices são numerados a partir de **1** na entrada e saída.
- As arestas são consideradas **não direcionadas**.
- A solução é impressa apenas se a flag `-s` for usada; caso contrário, apenas o custo é exibido.

---

## 🤝 Créditos

Implementação feita para fins educacionais no contexto da disciplina de Algoritmos em Grafos do curso de Ciência da Computação.
