#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "celula.h"
#include "lista.h"

TipoLista *lista;

void FLVazia(TipoLista *lista) {
  lista->primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  lista->ultimo = lista->primeiro;
  lista->primeiro->prox = NULL;
}

char Vazia(TipoLista lista) {
  return (lista.primeiro == lista.ultimo);
}

void Insere(TipoItem *x, TipoLista *lista) {
  TipoApontador aux = lista->primeiro;

  // Percorra a lista ate que encontre o ultimo elemento ou,
  // ate que o proximo elemento seja superior ao a ser inserido
  // dessa forma inserimos de forma ordenada na lista
  while (aux->prox != NULL && aux->prox->item.vertice < x->vertice) {
    aux = aux->prox;
  }
  TipoApontador aux2 = aux->prox;
  aux->prox = (TipoApontador) malloc(sizeof(TipoCelula));
  aux->prox->item = *x;
  aux->prox->prox = aux2;

  // Se estamos inserindo ao final da lista, atualize o apontador ultimo
  if (aux2 == NULL) {
    lista->ultimo = aux->prox;
  }
}

void ImprimeLista(TipoLista lista) {
  TipoApontador aux;
  aux = lista.primeiro->prox;
  while (aux != NULL) {
    printf("%d ", aux->item.vertice);
    aux = aux->prox;
  }
}

void DestroiLista(TipoLista *lista) {
  TipoApontador aux;
  while (lista->primeiro != NULL) {
    aux = lista->primeiro;
    lista->primeiro = lista->primeiro->prox;
    free(aux);
  }
  lista->ultimo = NULL;
}
