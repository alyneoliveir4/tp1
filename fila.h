#ifndef FILA_H
#define FILA_H

typedef struct TipoFila {
  TipoApontador frente, tras;
} TipoFila;

void FFVazia(TipoFila *Fila);
int FVazia(TipoFila Fila);
void Enfileira(TipoItem x, TipoFila *Fila);
void Desenfileira(TipoFila *Fila, TipoItem *Item);
void ImprimeFila(TipoFila Fila);
void DestroiFila(TipoFila *fila);

#endif
