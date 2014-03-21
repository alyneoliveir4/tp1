#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "celula.h"
#include "fila.h"

void FFVazia(TipoFila *fila)
{ fila->frente = (TipoApontador) malloc(sizeof(TipoCelula));
  fila->tras = fila->frente;
  fila->frente->prox = NULL;
}

int FVazia(TipoFila fila)
{ return (fila.frente == fila.tras); }

void Enfileira(TipoItem x, TipoFila *fila)
{ fila->tras->prox = (TipoApontador) malloc(sizeof(TipoCelula));
  fila->tras = fila->tras->prox;
  fila->tras->item = x;
  fila->tras->prox = NULL;
}

void Desenfileira(TipoFila *fila, TipoItem *item)
{ TipoApontador q;
  if (FVazia(*fila)) { printf("Erro fila esta vazia\n"); return; }
  q = fila->frente;
  fila->frente = fila->frente->prox;
  *item = fila->frente->item;
  free(q);
}

void ImprimeFila(TipoFila fila)
{ TipoApontador aux;
  aux = fila.frente->prox;
  while (aux != NULL)
    { printf("%d\n", aux->item.vertice);
      aux = aux->prox;
    }
}

void DestroiFila(TipoFila *fila) {
  TipoApontador aux;
  while (fila->tras != NULL) {
    aux = fila->tras;
    fila->tras = fila->tras->prox;
    free(aux);
  }
  fila->frente = NULL;
}

