/*#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "heap.h"
#include "grafo.h"

TipoIndice n;

void Constroi(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos){

  TipoIndice Esq;
  Esq = n / 2 + 1;
  while (Esq > 1)
    { Esq--;
      RefazInd(Esq, n, A, P, Pos);
    }
}

void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *A, TipoPeso *P,
            TipoValorVertice *Pos){

  TipoIndice i = Esq;  int j;  TipoItem x;
  j = i * 2;  x = A[i];
  while (j <= Dir)
    { if (j < Dir)
      { if (P[A[j].peso] > P[A[j+1].peso]) j++;
      }
      if (P[x.peso] <= P[A[j].peso])  goto L999;
      A[i] = A[j]; Pos[A[j].peso] = i;
      i = j;   j = i * 2;
    }
  L999:  A[i] = x;  Pos[x.peso] = i;
}

TipoItem RetiraMinInd(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos){

  TipoItem Result;
  if (n < 1)
  { printf("Erro: heap vazio\n");
    return Result;
  }
  Result = A[1];
  A[1] = A[n]; Pos[A[n].peso] = 1;
  n--;
  RefazInd(1, n, A, P, Pos);
  return Result;
}

void ProxAdjDijkstra(TipoValorVertice *Vertice, TipoGrafo *Grafo,
         TipoValorVertice *Adj, TipoPeso *Peso, Apontador *Prox,
         short *FimListaAdj)
{ // --Retorna Adj apontado por Prox--
  *Adj = *Prox;
  *Peso = Grafo->Mat[*Vertice][*Prox];
  (*Prox)++;
  while (*Prox < Grafo->num_vertices && Grafo->Mat[*Vertice][*Prox] == 0)
    (*Prox)++;
  if (*Prox == Grafo->num_vertices)  *FimListaAdj = TRUE;
}

short ListaAdjVaziaDijkstra(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{ Apontador Aux = 0;
  short ListaVazia = TRUE;
  while (Aux < Grafo->num_vertices && ListaVazia)
    { if (Grafo->Mat[*Vertice][Aux] > 0)
      ListaVazia = FALSE;
      else
      Aux++;
    }
  return (ListaVazia == TRUE);
}

Apontador PrimeiroListaAdjDijkstra(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{ TipoValorVertice Result;
  Apontador Aux = 0;
  short Listavazia = TRUE;
  while (Aux < Grafo->num_vertices && Listavazia)
    { if (Grafo->Mat[*Vertice][Aux] > 0)
      { Result = Aux; Listavazia = FALSE;
      }
      else  Aux++;
    }
  if (Aux == Grafo->num_vertices)
  printf("Erro: Lista adjacencia vazia (PrimeiroListaAdj)\n");
  return Result;
}

void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *A,
             TipoPeso *P,  TipoValorVertice *Pos){

  TipoItem x;
  if (ChaveNova > P[A[i].peso])
  { printf("Erro: ChaveNova maior que a peso atual\n");
    return;
  }
  P[A[i].peso] = ChaveNova;
  while (i > 1 && P[A[i / 2].peso] > P[A[i].peso])
    { x = A[i / 2];
      A[i / 2] = A[i];
      Pos[A[i].peso] = i / 2;
      A[i] = x;
      Pos[x.peso] = i;
      i /= 2;
    }
}*/
