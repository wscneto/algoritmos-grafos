
# 🧭 Dijkstra em C – Lista e Matriz de Adjacência

Este projeto implementa o algoritmo de Dijkstra em C, com duas versões distintas:
- 📘 `dijkstraLA.c`: usa **Lista de Adjacência**
- 📗 `dijkstraMA.c`: usa **Matriz de Adjacência**

Ambas as versões utilizam argumentos via linha de comando para configurar entrada, saída e vértice inicial.

---

## 🛠️ Compilação

Compile os programas com:

```bash
gcc dijkstraLA.c -o dijkstraLA
gcc dijkstraMA.c -o dijkstraMA
```

---

## ▶️ Execução

```bash
./dijkstraLA -f entrada.txt -o saida.txt -i 1
./dijkstraMA -f entrada.txt -o saida.txt -i 1
```

### 🔧 Parâmetros:

| Parâmetro | Descrição |
|----------|-----------|
| `-h`     | Mostra a mensagem de ajuda |
| `-f <arquivo>` | Arquivo de entrada contendo o grafo |
| `-o <arquivo>` | Arquivo de saída (se omitido, imprime no terminal) |
| `-i <vértice>` | Vértice de origem (numerado a partir de 1) |

---

## 📥 Formato do Arquivo de Entrada

O arquivo de entrada deve conter:

```
n m
v1 w1 c1
v2 w2 c2
...
```

Onde:
- `n` = número de vértices
- `m` = número de arestas
- `vi`, `wi` = vértices conectados
- `ci` = custo da aresta

### Exemplo:
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

---

## 📤 Saída

O resultado mostra a **menor distância de cada vértice a partir do vértice inicial**, no formato:

```
1:0 2:5 3:4 4:2 5:8 6:6
```

---

## 📚 Arquivos

| Arquivo | Descrição |
|--------|-----------|
| `dijkstraLA.c` | Implementação com **lista de adjacência** |
| `dijkstraMA.c` | Implementação com **matriz de adjacência** |
| `graph.h`, `queue.h` | (Necessários para `dijkstraLA.c`; você deve implementá-los ou adaptá-los conforme sua estrutura de dados) |

---

## 📌 Observações

- Os vértices são numerados a partir de **1** na entrada e saída.
- As arestas são consideradas **direcionadas** em ambas as versões.

---

## 🤝 Créditos

Implementação feita para fins educacionais em Ciência da Computação, com suporte ao uso acadêmico e aprendizado de algoritmos de grafos.
