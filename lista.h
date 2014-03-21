#ifndef LISTA_H
#define LISTA_H
#include <celula.h>

typedef struct TipoLista {
  TipoApontador primeiro, ultimo;
} TipoLista;

void FLVazia(TipoLista *lista);
char Vazia(TipoLista lista);
void Insere(TipoItem *x, TipoLista *lista);
void ImprimeLista(TipoLista lista);
void DestroiLista(TipoLista *lista);

#endif
