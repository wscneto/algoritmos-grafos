# Makefile para o algoritmo de Prim

CC = gcc
CFLAGS = -Wall -O2
TARGET = prim.bin
SRC = prim.c
GRAPH_SRC = ../../include/graph.c  

.PHONY: all clean help

all: $(TARGET)

$(TARGET): $(SRC) $(GRAPH_SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(GRAPH_SRC)

run: $(TARGET)
	./$(TARGET)

help:
	@echo "Comandos disponíveis:"
	@echo "  make       - Compila o programa (gera $(TARGET))"
	@echo "  make run   - Executa o programa"
	@echo "  make clean - Remove o executável"
	@echo "  make help  - Mostra esta ajuda"

clean:
	rm -f $(TARGET)
