#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "celula.h"
#include "lista.h"
#include "pilha.h"
#include "grafo.h"
#include "buscadfs.h"
#include "utils.h"
#include "fila.h"
#include "heap.h"

int main(int argc, char **argv) {

  // Controle do numero de parametros passados
  // na chamada do executavel em linha de comando
  // correto: ./tp0 input.txt output.txt

  if (argc != 3) {
    printf("Numero de parametros incorreto\n");
    exit(1);
  }

  // Medicao de tempo
  double total = 0;
  double user = 0;
  MedeTempo(&total, &user);

  Arquivo(argv[1], argv[2]);

  MedeTempo(&total, &user);
  printf("Tempo Total: %f\nTempo de Usuario: %f\n", total, user);
  return 0;
}
