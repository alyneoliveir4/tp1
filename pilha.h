#ifndef PILHA_H
#define PILHA_H

typedef struct TipoPilha {
  TipoApontador fundo, topo;
  int tamanho;
} TipoPilha;

void FPVazia(TipoPilha *pilha);
int PVazia(TipoPilha pilha);
void Empilha(TipoItem *x, TipoPilha *pilha);
void Desempilha(TipoPilha *pilha, TipoItem *item);
int PTamanho(TipoPilha pilha);
void ImprimePilha(TipoPilha *pilha);
void DestroiPilha(TipoPilha *pilha);

#endif
