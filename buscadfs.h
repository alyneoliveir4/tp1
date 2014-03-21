#ifndef BUSCA_H
#define BUSCA_H

void Arquivo(char * input_file, char * output_file);
TipoValorVertice ProxAdjBranco(TipoValorVertice inicial, TipoGrafo *grafo);
void DFS(TipoValorVertice *inicial,
         TipoValorVertice *final,
         TipoGrafo *grafo,
         char *resultado);

#endif
