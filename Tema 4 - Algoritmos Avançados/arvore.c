#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de um nó na árvore binária
typedef struct {
  char valor[50];
  No *esquerda;
  No *direita;
} No;

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