#ifndef GRAFO_H
#define GRAFO_H
#include <limits.h>
#include <lista.h>

/*#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1
#define INFINITO       INT_MAX*/


typedef enum {
  branco,
  cinza,
  preto
} TipoCor;

typedef struct TipoGrafo {
  //TipoPeso Mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
  TipoLista * adj;
  TipoCor * cores;
  //TipoDist * dist;
  //TipoPred * pred;
  TipoValorVertice num_vertices;
} TipoGrafo;

void FGVazio(TipoGrafo *grafo);
void FGBranco(TipoGrafo *grafo);
void InsereAresta(TipoValorVertice *V1,
                  TipoValorVertice *V2,
                  TipoPeso *p,
                  TipoGrafo *grafo);
char ExisteAresta(TipoValorVertice Vertice1,
                  TipoValorVertice Vertice2,
                  TipoGrafo *grafo);
void ImprimeGrafo(TipoGrafo *grafo);
char ListaAdjVazia(TipoValorVertice *vertice, TipoGrafo *grafo);
TipoApontador PrimeiroListaAdj(TipoValorVertice vertice, TipoGrafo *grafo);
void ProxAdj(TipoValorVertice *vertice, TipoValorVertice *adj,
            TipoPeso *peso, TipoApontador *prox,
            char *fimListaAdj);
void DestroiGrafo(TipoGrafo *grafo);

#endif
