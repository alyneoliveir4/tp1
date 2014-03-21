#ifndef CELULA_H
#define CELULA_H

#define TRUE            1
#define FALSE           0

/*#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1
#define INFINITO       INT_MAX*/


typedef int TipoValorVertice;
typedef int TipoPeso;

//typedef TipoValorVertice Apontador;

//typedef int TipoIndice;

typedef struct TipoItem {
  TipoValorVertice vertice;
  TipoPeso peso;
} TipoItem;

typedef struct TipoCelula * TipoApontador;

typedef struct TipoCelula {
  TipoItem item;
  TipoApontador prox;
} TipoCelula;

//typedef TipoItem TipoVetor[MAXNUMVERTICES + 1];

#endif

