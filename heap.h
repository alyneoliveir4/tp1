/*#ifndef HEAP_H
#define HEAP_H
#include <grafo.h>

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1
#define INFINITO       INT_MAX


void Constroi(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos);

void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *A, TipoPeso *P,
            TipoValorVertice *Pos);

TipoItem RetiraMinInd(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos);

void ProxAdjDijkstra(TipoValorVertice *Vertice, TipoGrafo *Grafo,
         TipoValorVertice *Adj, TipoPeso *Peso, Apontador *Prox,
         short *FimListaAdj);
Apontador PrimeiroListaAdjDijkstra(TipoValorVertice *Vertice, TipoGrafo *Grafo);

short ListaAdjVaziaDijkstra(TipoValorVertice *Vertice, TipoGrafo *Grafo);

void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *A,
             TipoPeso *P,  TipoValorVertice *Pos);

#endif*/
