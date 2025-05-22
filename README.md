# Algoritmos de Grafos

**Professor:** [Rian Gabriel Santos Pinheiro, D.Sc.](https://ic.ufal.br/professor/rian/)

**Equipe:**

-   John Wallex Kennedy Moreira Silva
-   Walter Soares Costa Neto

Implementação de 5 algoritmos de grafos em C. Requisitado pela disciplina de Teoria dos Grafos.
Os algoritmos solicitados pelo professor foram: Dijkstra, Prim, Kruskal, e Kosaraju. Além desses, nós também implementamos o algoritmo de Bellman-Ford.

Cada algoritmo possui seu próprio Makefile para compilação e execução.

## Instruções

Primeiro, copie o repositório para sua máquina local:

```bash
git clone https://github.com/wscneto/algoritmos-grafos.git
cd algoritmos-grafos
```

### Compilação e execução com Makefile

Para a compilação, navegue para o diretório `src/` e depois para o diretório do algoritmo que deseja compilar:

```bash
cd src/<nome-do-algoritmo>
```

Então execute:

```bash
make
```

Isso criará o arquivo binário do algoritmo `<nome-do-algoritmo>.bin` (e.g. dijkstra.bin, bellman.bin, kruskal.bin).

Para executar o binário:

```bash
make run
```

Esse comando executará o algoritmo em questão a partir de um arquivo que contém as entradas do grafo. Cada algoritmo já possui um arquivo de entrada como exemplo, chamado `arquivo-entrada.dat`.

### Bateria de testes

Para executar a bateria de testes, compile cada um dos algoritmos e copie os binários gerados para a pasta `Bat1`

```bash
cp <nome-do-algoritmo> ../../Bat1/
```
