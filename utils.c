#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <math.h>
#include "celula.h"

// Obtem o numero de digitos do vertice funcao utilizada no busca.c para alocar
// memoria equivalente ao numero de digitos do numero de vertices

int GetNumberOfDigits (TipoValorVertice i) {
  return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

void MedeTempo(double *total, double *user) {
  // Estrutura que armazena informacoes sobre recursos
  struct rusage resources;
  int    rc;
  double utime, stime, total_time;

  // Obtem informacoes
  if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
    perror("getrusage failed");
  }

  utime = (double) resources.ru_utime.tv_sec
  + 1.e-6 * (double) resources.ru_utime.tv_usec;
  stime = (double) resources.ru_stime.tv_sec
  + 1.e-6 * (double) resources.ru_stime.tv_usec;

  total_time = utime+stime;
  (*total) = total_time - (*total);
  (*user) = utime - (*user);
}
