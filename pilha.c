#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "celula.h"
#include "pilha.h"

void FPVazia(TipoPilha *pilha){
  pilha->topo = (TipoApontador) malloc(sizeof(TipoCelula));
  pilha->fundo = pilha->topo;
  pilha->topo->prox = NULL;
  pilha->tamanho = 0;
}

int PVazia(TipoPilha pilha){
  return (pilha.topo == pilha.fundo);
}

void Empilha(TipoItem *x, TipoPilha *pilha){
  TipoApontador aux;
  aux = (TipoApontador) malloc(sizeof(TipoCelula));
  pilha->topo->item = *x;
  aux->prox = pilha->topo;
  pilha->topo = aux;
  pilha->tamanho++;
}

void Desempilha(TipoPilha *pilha, TipoItem *item){
  TipoApontador q;
  if (PVazia(*pilha)) {
    printf(" Erro pilha vazia\n");
    return;
  }
  q = pilha->topo;
  pilha->topo = q->prox;
  *item = q->prox->item;
  free(q);
  pilha->tamanho--;
}

int PTamanho(TipoPilha pilha){
  return (pilha.tamanho);
}

void ImprimePilha(TipoPilha *pilha){
  TipoPilha pilhaux;
  TipoItem x;
  FPVazia(&pilhaux);
  // Tomar cuidado, pois a pilha fica fazia após sua impressão
  while (!PVazia(*pilha)) {
    Desempilha(pilha, &x);
    Empilha(&x, &pilhaux);
  }
  while (!PVazia(pilhaux)) {
    Desempilha(&pilhaux, &x);
    printf("%d\n", x.vertice);
  }
}

void DestroiPilha(TipoPilha *pilha) {
  TipoApontador aux;
  while (pilha->topo != NULL) {
    aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(aux);
  }
  pilha->fundo = NULL;
}
