/**
 * @file arvore.c
 * @brief Exemplo de manipulação de árvore binária: criação, percursos e liberação de memória
 * @author Wellington Kister do Nascimento
 *
 * Este programa demonstra a criação de uma árvore binária simples,
 * com funções para percorrer a árvore em pré-ordem, em ordem e pós-ordem,
 * além de funções para calcular altura, profundidade e liberar a memória alocada.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de um nó na árvore binária
typedef struct No {
  char valor[50];
  struct No *esquerda;
  struct No *direita;
} No;

// Protótipos das funções
No* criarNo(char* valor);
int altura(No* raiz);
int profundidade(No* raiz, No* alvo, int nivel);
void preOrdem(No* raiz);
void emOrdem(No* raiz);
void posOrdem(No* raiz);
void liberar(No* raiz);

// Função main
int main() {
  No* raiz = criarNo("Hall de Entrada");
  raiz->esquerda = criarNo("Sala de Estar");
  raiz->direita = criarNo("Biblioteca");
  raiz->esquerda->esquerda = criarNo("Quarto");

  printf("Pré-ordem: ");
  preOrdem(raiz);
  printf("\n");

  printf("Em ordem: ");
  emOrdem(raiz);
  printf("\n");

  printf("Pós-ordem: ");
  posOrdem(raiz);
  printf("\n");

  liberar(raiz);
  return 0;
}

/**
 * @brief Função para criar um novo nó na árvore
 * @param valor Valor a ser armazenado no nó
 * @return Ponteiro para o novo nó criado
 */
No* criarNo(char* valor) {
  No* novo = (No*) malloc(sizeof(No));
  strcpy(novo->valor, valor);
  novo->esquerda = NULL;
  novo->direita = NULL;
  return novo;
}

/**
 * @brief Função para calcular a altura de uma árvore binária
 * @param raiz Ponteiro para a raiz da árvore
 * @return Altura da árvore (0 se vazia)
 */
int altura(No* raiz){
  if (raiz == NULL){
    return 0;
  }
  int alturaEsquerda = altura(raiz->esquerda);
  int alturaDireita = altura(raiz->direita);
  return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

/**
 * @brief Função para calcular a profundidade de um nó na árvore binária
 * @param raiz Ponteiro para a raiz da árvore
 * @param alvo Ponteiro para o nó alvo
 * @param nivel Nível atual (inicialmente 0)
 * @return Profundidade do nó alvo (-1 se não encontrado)
 */
int profundidade(No* raiz, No* alvo, int nivel) {
  if (raiz == NULL){
    return -1;
  }
  if (raiz == alvo){
    return nivel;
  }

  int esq = profundidade(raiz->esquerda, alvo, nivel + 1);
  if (esq != -1){
    return esq;
  }

  return profundidade(raiz->direita, alvo, nivel + 1);
}

/**
 * @brief Funções para percorrer a árvore em pré-ordem
 * @note Na seguinte ordem: raiz, esquerda, direita
 * @param raiz Ponteiro para a raiz da árvore
 */
void preOrdem(No* raiz) {
  if (raiz != NULL) {
    printf("%s ", raiz->valor);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
  }
}

/**
 * @brief Funções para percorrer a árvore em ordem
 * @note Na seguinte ordem: esquerda, raiz, direita
 * @param raiz Ponteiro para a raiz da árvore
 */
void emOrdem(No* raiz) {
  if (raiz != NULL) {
    emOrdem(raiz->esquerda);
    printf("%s ", raiz->valor);
    emOrdem(raiz->direita);
  }
}

/**
 * @brief Funções para percorrer a árvore em pós-ordem
 * @note Na seguinte ordem: esquerda, direita, raiz
 * @param raiz Ponteiro para a raiz da árvore
 */
void posOrdem(No* raiz) {
  if (raiz != NULL) {
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%s ", raiz->valor);
  }
}

/**
 * @brief Função para liberar a memória alocada para a árvore
 * @param raiz Ponteiro para a raiz da árvore
 */
void liberar(No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}