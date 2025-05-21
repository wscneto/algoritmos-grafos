# Makefile para o algoritmo de Kruskal

CC = gcc
CFLAGS = -Wall -O2
TARGET = kruskal
SRC = kruskal.c
EDGE_SRC = ../headers/edge.c
SUBSET_SRC = ../headers/subset.c

.PHONY: all clean help

all: $(TARGET)

$(TARGET): $(SRC) $(EDGE_SRC) $(SUBSET_SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(EDGE_SRC) $(SUBSET_SRC)

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
