# Makefile para o algoritmo de Dijkstra

CC = gcc
CFLAGS = -Wall -O2
TARGET = dijkstra.bin
SRC = dijkstra.c
GRAPH_SRC = ../headers/graph.c  
HEAP_SRC = ../headers/heap.c  

.PHONY: all clean help

all: $(TARGET)

$(TARGET): $(SRC) $(GRAPH_SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(GRAPH_SRC) $(HEAP_SRC)

run: $(TARGET)
	./$(TARGET) -f ./arquivo-entrada.dat -o ./arquivo-saida.dat -i 1

help:
	@echo "Comandos disponíveis:"
	@echo "  make       - Compila o programa (gera $(TARGET))"
	@echo "  make run   - Executa o programa"
	@echo "  make clean - Remove o executável"
	@echo "  make help  - Mostra esta ajuda"

clean:
	rm -f $(TARGET)
