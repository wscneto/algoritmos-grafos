# 🔄 Kosaraju – Componentes Fortemente Conexas (CFCs)

Este projeto implementa o **Algoritmo de Kosaraju** para identificar as **Componentes Fortemente Conexas** de um grafo dirigido. A entrada e saída são feitas por arquivos, tornando o programa versátil para testes em grandes volumes de dados.

## 🧠 Visão Geral

O algoritmo de Kosaraju realiza duas buscas em profundidade (DFS) e uma transposição do grafo para identificar subconjuntos de vértices onde cada vértice é alcançável a partir de qualquer outro — as chamadas **Componentes Fortemente Conexas (CFCs)**.

---

## ▶️ Compilação e Execução

### ✅ Requisitos

-   Compilador C (ex: `gcc`)
-   Makefile (opcional)
-   Estrutura de diretórios como descrita acima

### 🔧 Compilação

```bash
make
ou
gcc -o kosaraju kosaraju.c ../headers/graph.c ../headers/stack.c
```

### 🏃 Execução

```bash
make run (você pode editar o arquivo de entrada e saida no arquivo Makefile)
ou
./kosaraju -f <arquivo_entrada> -o <arquivo_saida>
```

### 📌 Parâmetros

| Parâmetro      | Descrição                              |
| -------------- | -------------------------------------- |
| `-h`           | Mostra a mensagem de ajuda             |
| `-f <arquivo>` | Arquivo de entrada com o grafo         |
| `-o <arquivo>` | (Opcional) Arquivo para salvar a saída |

---

## 📄 Formato do Arquivo de Entrada

O arquivo de entrada deve seguir o formato:

```
n m
u1 v1
u2 v2
...
um vm
```

Onde:

-   `n` é o número de vértices.
-   `m` é o número de arestas.
-   Cada linha seguinte representa uma aresta do grafo do vértice `u` para o vértice `v`.
-   Os vértices são indexados a partir de **1**.

### Exemplo:

```
12 17
1 2
1 4
2 3
3 1
3 7
4 6
5 4
6 7
7 5
8 6
8 11
9 8
10 9
11 10
11 12
12 10
12 7
```

---

## 📤 Formato da Saída

Cada linha representa uma CFC (Componente Fortemente Conexa), com os vértices listados em ordem crescente.

### Exemplo de saída:

```
8 9 10 11 12
1 3 2
7 6 4 5
```

---

## 🤝 Créditos

Implementação feita para fins educacionais em Ciência da Computação, com suporte ao uso acadêmico e aprendizado de algoritmos de grafos.
