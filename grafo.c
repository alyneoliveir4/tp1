#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "celula.h"
#include "lista.h"
#include "grafo.h"

void FGVazio(TipoGrafo *grafo) {
  short i;
  grafo->adj = (TipoLista*) malloc(grafo->num_vertices * sizeof(TipoLista));
  grafo->cores = (TipoCor*) malloc(grafo->num_vertices * sizeof(TipoCor));
  for (i = 0; i <= grafo->num_vertices - 1; i++) {
    FLVazia(&grafo->adj[i]);
    grafo->cores[i] = branco;
  }
}

void FGBranco(TipoGrafo *grafo) {
  short i;
  for (i = 0; i <= grafo->num_vertices - 1; i++) {
    grafo->cores[i] = branco;
  }
}

void InsereAresta(TipoValorVertice *V1,
                  TipoValorVertice *V2,
                  TipoPeso *peso,
                  TipoGrafo *grafo) {
  TipoItem x;
  x.vertice = *V2;
  x.peso = *peso;
  Insere(&x, &grafo->adj[*V1]);
}

char ExisteAresta(TipoValorVertice Vertice1,
                  TipoValorVertice Vertice2,
                  TipoGrafo *grafo) {
  TipoApontador aux;
  char encontrou_aresta = FALSE;
  aux = grafo->adj[Vertice1].primeiro->prox;
  while (aux != NULL && encontrou_aresta == FALSE) {
    if (Vertice2 == aux->item.vertice) {
      encontrou_aresta = TRUE;
    }
    aux = aux->prox;
  }
  return encontrou_aresta;
}

void ImprimeGrafo(TipoGrafo *grafo) {
  short i;
  for (i = 0; i <= grafo->num_vertices - 1; i++) {
    printf("Vertice%4d C%d: ", i, (int) grafo->cores[i]);
    if (!Vazia(grafo->adj[i])) {
      ImprimeLista(grafo->adj[i]);
    }
    putchar('\n');
  }
}

char ListaAdjVazia(TipoValorVertice *vertice, TipoGrafo *grafo) {
  return (grafo->adj[*vertice].primeiro == grafo->adj[*vertice].ultimo);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice vertice, TipoGrafo *grafo) {
  return (grafo->adj[vertice].primeiro->prox);
}

void ProxAdj(TipoValorVertice *vertice, TipoValorVertice *adj,
            TipoPeso *peso, TipoApontador *prox,
            char *fimListaAdj)
{ /* --Retorna Adj apontado por Prox--*/
  *adj = (*prox)->item.vertice;
  *peso = (*prox)->item.peso;
  *prox = (*prox)->prox;
  if (*prox == NULL) *fimListaAdj = TRUE;
}

void DestroiGrafo(TipoGrafo *grafo) {
  short i;
  for (i = 0; i <= grafo->num_vertices - 1; i++) {
    DestroiLista(&grafo->adj[i]);
  }
  free(grafo->adj);
  free(grafo->cores);
}
