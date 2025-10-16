#ifndef LISTA_COMPRAS_H
#define LISTA_COMPRAS_H

// -- Constantes ---
#define MAX_ITENS 100
#define TAM_STRING 100

// -- Protótipo das funções ---
int buscaSequencialIterativa(const char* listaCompras[], int tamanhoLista, const char* item);
int buscaSequencialRecursiva(const char* listaCompras[], int tamanhoLista, const char* item);
int buscaBinariaIterativa(const char* listaCompras[], int tamanhoLista, const char* item);
int buscaBinariaRecursiva(const char* listaCompras[], int tamanhoLista, const char* item);
int buscaBinariaRecursivaAux(const char* listaCompras[], char* item, int inicio, int fim);
int buscaSequencialRecursivaAux(const char* listaCompras[], int tamanhoLista, const char* item, int indiceAtual);

void imprimirResultado(char* msg, const char* itemExistente, int res1);

void listarCompras(const char* listaCompras, int tamanhoLista);

#endif
