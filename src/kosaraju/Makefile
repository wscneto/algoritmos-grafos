# Makefile para o algoritmo de Kosaraju

CC = gcc
CFLAGS = -Wall -O2
TARGET = kosaraju
SRC = kosaraju.c
GRAPH_SRC = ../headers/graph.c  
STACK_SRC = ../headers/stack.c

.PHONY: all clean help

all: $(TARGET)

$(TARGET): $(SRC) $(GRAPH_SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(GRAPH_SRC) $(STACK_SRC)

run: $(TARGET)
	./$(TARGET) -f ./arquivo-entrada.dat -o ./arquivo-saida.dat

help:
	@echo "Comandos disponíveis:"
	@echo "  make       - Compila o programa (gera $(TARGET))"
	@echo "  make run   - Executa o programa"
	@echo "  make clean - Remove o executável"
	@echo "  make help  - Mostra esta ajuda"

clean:
	rm -f $(TARGET)
