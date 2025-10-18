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
#include <stdbool.h>

// Definição da estrutura de um nó na árvore binária
typedef struct No {
  char valor[50];
  struct No *esquerda;
  struct No *direita;
} No;

// Protótipos das funções
No* criarNo(const char* valor);
int altura(No* raiz);
int profundidade(No* raiz, No* alvo, int nivel);
void preOrdem(No* raiz);
void emOrdem(No* raiz);
void posOrdem(No* raiz);
void liberar(No* raiz);
No* inserir(struct No* raiz, const char* valor);
int buscar(struct No* raiz, const char* chave);
struct No* encontrarMinimo(struct No* raiz);

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

  raiz = NULL;

  raiz = inserir(raiz, "Pegadas de Lama");
  raiz = inserir(raiz, "Chave perdida");
  raiz = inserir(raiz, "Livro com página faltando");
  raiz = inserir(raiz, "Lençol manchado");
  raiz = inserir(raiz, "Gaveta perdida");

  printf("\nElementos em ordem: ");
  emOrdem(raiz);

  printf("\nBusca por ‘Lençol manchado’: %s", buscar(raiz, "Lençol manchado") ? "Encontrado" : "Não encontrado");
  printf("\nBusca por ‘Óculos’: %s\n", buscar(raiz, "Óculos") ? "Encontrado" : "Não encontrado");

  return 0;
}

/**
 * @brief Função para criar um novo nó na árvore
 * @param valor Valor a ser armazenado no nó
 * @return Ponteiro para o novo nó criado
 */
No* criarNo(const char* valor) {
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
    printf("'%s' ", raiz->valor);
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
    printf("'%s' ", raiz->valor);
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
    printf("'%s' ", raiz->valor);
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

/**
 * @brief Função para inserir um novo valor na árvore binária de busca
 * @note Os menores valores vão para a esquerda e os maiores para a direita
 * @param raiz Ponteiro para a raiz da árvore
 * @param valor Valor a ser inserido
 * @return Ponteiro para a raiz atualizada da árvore
 */
No* inserir(struct No* raiz, const char* valor) {
  if (raiz == NULL){
    return criarNo(valor);
  }

  if (strcmp(valor, raiz->valor) < 0){
      raiz->esquerda = inserir(raiz->esquerda, valor);
  } else if (strcmp(valor, raiz->valor) > 0){
      raiz->direita = inserir(raiz->direita, valor);
  }

  return raiz;
}

/**
 * @brief Função para buscar um valor na árvore binária de busca
 * @param raiz Ponteiro para a raiz da árvore
 * @param chave Valor a ser buscado
 * @return 1 se encontrado, 0 caso contrário
 */
int buscar(struct No* raiz, const char* chave) {
  if (raiz == NULL){
    return 0;
  }

  if (strcmp(chave, raiz->valor) == 0){
    return 1;
  } else if (strcmp(chave, raiz->valor) < 0){
    return buscar(raiz->esquerda, chave);
  } else {
    return buscar(raiz->direita, chave);
  }
}

struct No* remover(struct No* raiz, const char* valor) {
  if (raiz == NULL){
    return NULL;
  }

  if (strcmp(valor, raiz->valor) < 0) {
    raiz->esquerda = remover(raiz->esquerda, valor);
  } else if (strcmp(valor, raiz->valor) > 0) {
    raiz->direita = remover(raiz->direita, valor);
  } else {
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
      // Caso 1: sem filhos
      // free(raiz->valor);
      free(raiz);
      return NULL;

      // Caso 2: um único filho
    } else if (raiz->esquerda == NULL) {
      struct No* temp = raiz->direita;
      // free(raiz->valor);
      free(raiz);
      return temp;
    } else if (raiz->direita == NULL) {
      struct No* temp = raiz->esquerda;
      // free(raiz->valor);
      free(raiz);
      return temp;

      // Caso 3: dois filhos
    } else {
      struct No* sucessor = encontrarMinimo(raiz->direita);
      free(raiz->valor);
      // raiz->valor = strdup(sucessor->valor);
      strcpy(raiz->valor, sucessor->valor);
      raiz->direita = remover(raiz->direita, sucessor->valor);
    }
  }

  return raiz;
}
/**
 * @brief Função auxiliar para encontrar o nó mínimo em uma subárvore
 * @param raiz Ponteiro para a raiz da subárvore
 * @return Ponteiro para o nó com o valor mínimo
 */
struct No* encontrarMinimo(struct No* raiz) {
    struct No* atual = raiz;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}
