#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "celula.h"
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "grafo.h"
#include "buscadfs.h"
#include "utils.h"
#include "heap.h"

/*#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1
#define INFINITO       INT_MAX*/


// Dado um vertice e o grafo a qual pertence, retorna, se existente, o vertice
// adjacente de cor branca com menor indice
TipoValorVertice ProxAdjBranco(TipoValorVertice vertice, TipoGrafo *grafo) {
  TipoApontador aux = PrimeiroListaAdj(vertice, grafo);
  while (aux != NULL) { //enquanto nao acaba lista de adj
    if(grafo->cores[aux->item.vertice] == branco) {
      return (TipoValorVertice) aux->item.vertice;
    } else {
      aux = aux->prox;
    }
  }
  return -1;
}

// Realiza a busca em profundidade com auxilio de uma pilha, dados o no inicial
// e final
void DFS(TipoValorVertice *inicial,
         TipoValorVertice *final,
         TipoGrafo *grafo,
         char *resultadodfs) {

  // Estruturas necessarias
  TipoPilha pilha1;
  FPVazia(&pilha1);
  char temp[10] = "";

  // Prepara para a busca
  TipoValorVertice atual = *inicial;

  sprintf(temp, "%d ", (*inicial + 1));
  strcpy(resultadodfs, temp);

  // Marca o no inicio como descoberto e coloca-o no topo da pilha
  grafo->cores[atual] = cinza;
  TipoItem x;
  x.vertice = *inicial;
  Empilha(&x, &pilha1);

  //enquanto a pilha não está vazia
  while (!PVazia(pilha1) && atual != *final) {
    atual = pilha1.topo->prox->item.vertice;
    TipoValorVertice prox_branco = ProxAdjBranco(atual, grafo);

    if (prox_branco != -1) {
      // Novo vertice visitado deve ser armazeado para o log de saida
      sprintf(temp, "%d ", (prox_branco + 1));
      strcat(resultadodfs, temp);
      atual = prox_branco;
      grafo->cores[atual] = cinza;
      x.vertice = atual;
      Empilha(&x, &pilha1);
    } else {
      // Vertice nao tem mais adjacentes, marca como preto
      grafo->cores[atual] = preto;
      Desempilha(&pilha1, &x);
    }
  }
  strcat(resultadodfs, "\n");

  DestroiPilha(&pilha1);
}


void BFS(TipoValorVertice *inicial,
         TipoValorVertice *final,
         TipoGrafo *grafo,
         char *resultadobfs){

  // Estruturas necessarias
  TipoFila fila1;
  FFVazia(&fila1);
  char temp[10] = "";
  TipoApontador aux;
  char fimListaAdj;
  TipoPeso peso;
  //Verificar estruturas necessárias

  // Prepara para a busca
  TipoValorVertice atual = *inicial;

  sprintf(temp, "%d ", (*inicial + 1));
  strcpy(resultadobfs, temp);

  // Marca o no inicio como descoberto e enfileira
  grafo->cores[atual] = cinza;
  //grafo->dist[atual] = 0;
  TipoItem x;
  x.vertice = atual;
  x.peso = 0;
  Enfileira(x, &fila1);
  printf("Visita origem %d\n", atual);
  //ImprimeFila(fila1);
  //getchar();

  //enquanto a fila não está vazia
  while (!FVazia(fila1)){
    Desenfileira(&fila1, &x);
    atual = x.vertice;
    printf("Atual1! %d\n", atual);


    if(!ListaAdjVazia(&atual, grafo)){
      aux = PrimeiroListaAdj(atual, grafo);
      printf("Atual2! %d\n", atual);
      fimListaAdj = FALSE;


      while(fimListaAdj==FALSE){
        ProxAdj(&atual, final, &peso, &aux, &fimListaAdj );
        printf("Atual3! %d\n", atual);
        printf("Final1! %d\n", *final);

        if(grafo->cores[*final] != branco){ continue; }
        // Novo vertice visitado deve ser armazeado para o log de saida
        printf("Atual4: %d\n ", (atual));
        printf("Final2: %d\n ", (*final));
        sprintf(temp, "%d ", (*final + 1));
        strcat(resultadobfs, temp);
        grafo->cores[*final] = cinza;
        //grafo->dist->[final] = grafo->dist->atual + 1;
        //grafo->pred->[final] = atual;
        x.vertice = *final;
        x.peso = peso;
        Enfileira(x, &fila1);
        printf("Atual5: %d\n ", (atual));
        printf("Final3: %d\n ", (*final));

        //printf("fim lista adj eh true, acabou a lista de adjacentes\n");
      }

   grafo->cores[atual] = preto;
  //getchar();
  //printf("Atual passo 2 %d\n", atual + 1);
  //printf("Final passo 2 %d\n", *final + 1);
  //break;
  //printf("Visita %d", atual);
  //ImprimeFila(fila1);
   printf("Atual6: %d\n ", (atual));
   printf("Final4: %d\n ", (*final));

    }

//break;
}
strcat(resultadobfs, "\n");

DestroiFila(&fila1);

}

/*void Dijkstra(TipoValorVertice *inicial,
         TipoValorVertice *final,
         TipoGrafo *grafo,
         char *resultadodijkstra){

  TipoPeso p[MAXNUMVERTICES + 1];
  TipoPeso peso;
  TipoValorVertice pos[MAXNUMVERTICES + 1];
  long antecessor[MAXNUMVERTICES + 1];
  short itensheap[MAXNUMVERTICES + 1];
  TipoVetor a;
  TipoValorVertice atual;
  TipoItem temp;
  TipoIndice n;
  Apontador aux;
  short FimListaAdj;

  // Prepara para a busca
  TipoValorVertice atual = *inicial;

  sprintf(temp, "%d ", (*inicial + 1));
  strcpy(resultadodijkstra, temp);

  for (atual = 0; atual <= grafo->num_vertices; atual++)
  { //Constroi o heap com todos os valores igual a INFINITO
    antecessor[atual] = -1; p[atual] = INFINITO;
    a[atual+1].peso = atual;   //Heap a ser construido
    itensheap[atual] = TRUE;  pos[atual] = atual + 1;
  }
  n = grafo->num_vertices;
  p[*(inicial)] = 0;
  Constroi(a, p, pos);
  while (n >= 1)
  { //enquanto heap nao vazio
    temp = RetiraMinInd(a, p, pos);
    atual = temp.peso; itensheap[atual] = FALSE;
    if (!ListaAdjVazia(&atual, grafo))
    { aux = PrimeiroListaAdjDijkstra(atual, *grafo); FimListaAdj = FALSE;
      while (!FimListaAdj)
      { ProxAdjDijkstra(&atual, grafo, final, &peso, &aux, &FimListaAdj);
        if (p[*final] > (p[atual] + peso))
        { p[*final] = p[atual] + peso; antecessor[*final] = atual;
          DiminuiChaveInd(pos[*final], p[*final], a, p, pos);
          printf("Caminho: final[%d] final[%ld] d[%d]",
           final, antecessor[*final], p[*final]);
          scanf("%*[^\n]");
          getchar();
        }
      }
    }
  }
}*/


  // Itera sobre o formato de entrada, conforme especificacao
void Arquivo(char * input_file, char * output_file) {
  FILE * input = fopen(input_file, "r");
  FILE * output = fopen(output_file, "w");

  if(!input || !output) {
    printf("Erro ao abrir arquivo de entrada ou saida\n");
    exit(1);
  }

  int num_instancias, contador1;
  fscanf(input, "%d", &num_instancias);
  printf("instancias: %d\n", num_instancias);

  // Para cada instancia
  for (contador1 = 0; contador1 < num_instancias; contador1++) {
    // Construa o grafo, a partir das arestas e pesos
    int num_vertices, num_arestas, contador2;
    fscanf(input, "%d %d", &num_vertices, &num_arestas);
    printf("vertices: %d e arestas: %d\n", num_vertices, num_arestas);

    TipoGrafo grafo;
    grafo.num_vertices = num_vertices;
    int digits = GetNumberOfDigits(num_vertices) + 1;
    FGVazio(&grafo);

    // Para cada aresta
    for (contador2 = 0; contador2 < num_arestas; contador2++) {
      TipoValorVertice aresta1, aresta2;
      TipoPeso peso;
      fscanf(input, "%d %d %d", &aresta1, &aresta2, &peso);
      printf("Aresta e peso %d %d %d\n", aresta1, aresta2, peso);

      // Arestas devem começar em 0
      aresta1--;
      aresta2--;

      InsereAresta(&aresta1, &aresta2, &peso, &grafo);
      InsereAresta(&aresta2, &aresta1, &peso, &grafo);
    }

    int num_consultas;
    fscanf(input, "%d", &num_consultas);
    printf("numero de consultas: %d\n", num_consultas);
    // Para cada consulta
    for (contador2 = 0; contador2 < num_consultas; contador2++) {
      TipoValorVertice inicio, final;
      int escolheconsulta;
      fscanf(input, "%d %d %d", &escolheconsulta, &inicio, &final);
      printf("escolhe consulta %d, inicio %d, final %d\n", escolheconsulta, inicio, final);
      inicio--;
      final--;

      char * resultadodfs = (char*) malloc(sizeof(char) *
                                        ((num_vertices * digits) + 1));
      char * resultadobfs = (char*) malloc(sizeof(char) *
                                        ((num_vertices * digits) + 1));
      //char * resultadodijkstra = (char*) malloc(sizeof(char) *
                                        //((num_vertices * digits) + 1));
      if(escolheconsulta==1){
      printf("escolheu largura\n");
      //aplica BFS
      BFS(&inicio, &final, &grafo, resultadobfs);
      fprintf(output, "%s\n", resultadobfs); // Escreve a saida, dada a solucao
      }
      else if(escolheconsulta==2){
      printf("escolheu profundidade\n");
      //aplica DFS
      DFS(&inicio, &final, &grafo, resultadodfs);
      fprintf(output, "%s\n", resultadodfs); // Escreve a saida, dada a solucao
      }
      else if(escolheconsulta==3){
      printf("escolheu menor caminho\n");
      //aplica dijkstra
      //dijkstra(&inicio, &final, &grafo, resultadodijkstra);
      }

      free(resultadodfs);
      free(resultadobfs);
      //free(resultadodijkstra);
      FGBranco(&grafo);
    }
    DestroiGrafo(&grafo);
  }

  fclose(input);
  fclose(output);
}



