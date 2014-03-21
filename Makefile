# src dir
SRC := .
# Header files dir
LIB := .
# Objects dir
OBJ := .
# Binary target dir
BIN := .

# Compilation Flags
CFLAGS := -I $(LIB) -g -lm -Wall -Wextra
# Compiler
CC := gcc

# BINARY OUTPUT NAMES
TP1 := tp1

all: tp1

tp1: $(OBJ)/main.o $(OBJ)/lista.o $(OBJ)/pilha.o $(OBJ)/grafo.o $(OBJ)/buscadfs.o $(OBJ)/utils.o $(OBJ)/fila.o $(OBJ)/heap.o
	@mkdir -p $(BIN)
	$(CC) -o $(BIN)/$(TP1) $^ $(CFLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -vf $(OBJ)/*.o
	rm -vf $(BIN)/${TP1}
	rm -vf output.txt
