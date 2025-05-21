# Algoritmo de Bellman-Ford

Este projeto implementa o algoritmo de **Bellman-Ford** para encontrar os menores caminhos a partir de um vértice de origem em um grafo, com suporte à **detecção de ciclos negativos**.

## 📌 Compilação

Certifique-se de ter os arquivos `graph.h` e `graph.c` disponíveis nos diretórios `include` e `src/headers`.

Compile com:

```bash
make
ou
gcc -o bellman bellman.c ../headers/graph.c
```

## 🚀 Execução

```bash
make run
ou
./bellman -f <arquivo_entrada> -i <vertice_inicial> -o <arquivo_saida>
```

### Parâmetros

- `-h`: Mostra a ajuda.
- `-f <arquivo_entrada>`: Caminho para o arquivo contendo o grafo.
- `-i <vertice_inicial>`: Vértice de origem para iniciar o algoritmo (indexado a partir de 1).
- `-o <arquivo_saida>` (opcional): Caminho do arquivo onde o resultado será salvo.

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
- Cada linha `vi wi ci` representa uma aresta do vértice `vi` ao vértice `wi` com custo `ci`

**Os vértices são numerados a partir de 1.**

## 📤 Saída

A saída do algoritmo segue este formato:

```
TRUE
1:0 2:3 3:8 4:-1 ...
```

- A primeira linha será `TRUE` se **não houver ciclo negativo**, ou `FALSE` se **for detectado um ciclo negativo**.
- A segunda linha apresenta a menor distância do vértice de origem até cada um dos demais vértices no formato:
  ```
  v:d
  ```
  Onde `v` é o número do vértice e `d` é a distância a partir do vértice de origem.
- Se um vértice for **inalcançável**, sua distância será representada por `-1`.

## 📚 Exemplo de Uso

**Entrada (grafo.txt):**

```
4 5
1 2 1
2 3 -1
3 4 -1
4 2 -1
1 3 4
```

**Comando:**

```bash
./bellman -f grafo.txt -i 1 -o resultado.txt
```

**Saída (resultado.txt):**

```
FALSE
1:0 2:1 3:0 4:-1
```

Esse exemplo detecta um **ciclo negativo** no ciclo 2 → 3 → 4 → 2.

---

## 📌 Observações

- Os vértices são numerados a partir de **1** na entrada e saída.
- As arestas são consideradas **direcionadas**.
- O algoritmo é capaz de detectar ciclos negativos e interrompe a execução caso encontre um.

---

## 🤝 Créditos

Implementação feita para fins educacionais no contexto da disciplina de Algoritmos em Grafos do curso de Ciência da Computação.
