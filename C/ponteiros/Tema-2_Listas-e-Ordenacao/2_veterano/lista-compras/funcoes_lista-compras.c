#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../../funcoes.h" // Inclui o cabeçalho de funcoes gerais
#include "funcoes_lista-compras.h"

// -- Protótipo das funções ---
// -------------------------
// -- BUSCAS SEQUENCIAIS ---
// -------------------------

/**
 * @brief Função para busca sequencial iterativa
 * @note  A busca sequancial iterativa percorre a lista do início ao fim, comparando cada elemento com o item buscado.
 * @note  Se encontrar o item, retorna o índice; caso contrário, retorna -1.
 * @param listaCompras Lista de compras (array de strings)
 * @param tamanhoLista Tamanho da lista
 * @param item Item a ser buscado
 * @return Índice do item se encontrado, -1 caso contrário
 */
int buscaSequencialIterativa(const char* listaCompras[], int tamanhoLista, const char* item){
  printf("\n-----------------------------\n");
  printf("--- Busca Sequencial Iterativa ---\n");
  printf("-----------------------------\n");
  for (int i = 0; i < tamanhoLista; i++){
    if (strcmp(listaCompras[i], item) == 0){
      return i; // Item encontrado, retorna o índice
    }
  }
  return -1; // Item não encontrado
}

/**
 * @brief Função para busca sequencial recursiva
 * @note  A busca sequencial recursiva verifica o último elemento da lista.
 * @note  Se for o item buscado, retorna o índice; caso contrário, chama a si mesma com o tamanho reduzido.
 * @note  Esta função varre a lista do fim para o início.
 * @param listaCompras Lista de compras (array de strings)
 * @param tamanhoLista Tamanho da lista
 * @param item Item a ser buscado
 * @return Índice do item se encontrado, -1 caso contrário
 */
int buscaSequencialRecursivaFim(const char* listaCompras[], int tamanhoLista, const char* item){
  printf("\n-----------------------------\n");
  printf("--- Busca Sequencial Recursiva ---\n");
  printf("-----------------------------\n");
  if (listaCompras[tamanhoLista - 1] == item){
    return tamanhoLista - 1; // Item encontrado, retorna o índice
  } else if (tamanhoLista == 1){
    return -1; // Item não encontrado
  } else {
    return buscaSequencialRecursiva(listaCompras, tamanhoLista - 1, item);
  }
}

/**
 * @brief Função para busca sequencial recursiva (varrendo do início para o fim)
 * @note  A busca sequencial recursiva verifica o primeiro elemento da lista.
 * @note  Se for o item buscado, retorna o índice; caso contrário, chama a si mesma com o início avançado.
 * @param listaCompras Lista de compras (array de strings)
 * @param tamanhoLista Tamanho da lista
 * @param item Item a ser buscado
 * @return Índice do item se encontrado, -1 caso contrário
 */
int buscaSequencialRecursiva(const char* listaCompras[], int tamanhoLista, const char* item){
  printf("\n-----------------------------\n");
  printf("--- Busca Sequencial Recursiva ---\n");
  printf("-----------------------------\n");
  return buscaSequencialRecursivaAux(listaCompras, tamanhoLista, item, 0);
}

// Função auxiliar para busca sequencial recursiva
int buscaSequencialRecursivaAux(const char* listaCompras[], int tamanhoLista, const char* item, int indiceAtual){
  if (indiceAtual >= tamanhoLista){
    return -1; // Item não encontrado
  }
  if (strcmp(listaCompras[indiceAtual], item) == 0){
    return indiceAtual; // Item encontrado, retorna o índice
  }
  return buscaSequencialRecursivaAux(listaCompras, tamanhoLista, item, indiceAtual + 1);
}

// -------------------------
// -- BUSCAS BINÁRIAS ---
// -------------------------

/**
 * @brief Função para busca binária iterativa
 * @note  A busca binária iterativa divide a lista em metades, comparando o item do meio com o item buscado.
 * @note  Se encontrar o item, retorna o índice; caso contrário, ajusta os limites da busca.
 * @param listaCompras Lista de compras (array de strings)
 * @param tamanhoLista Tamanho da lista
 * @param item Item a ser buscado
 */
int buscaBinariaIterativa(const char* listaCompras[], int tamanhoLista, const char* item){
  printf("\n-----------------------------\n");
  printf("--- Busca Binária Iterativa ---\n");
  printf("-----------------------------\n");
  int esquerda = 0;
  int direita = tamanhoLista - 1;
  while (esquerda <= direita){
    int meio = esquerda + (direita - esquerda) / 2;
    int cmp = strcmp(listaCompras[meio], item);
    if (cmp == 0){
      return meio; // Item encontrado, retorna o índice
    } else if (cmp < 0){
      esquerda = meio + 1; // Continua na metade direita
    } else {
      direita = meio - 1; // Continua na metade esquerda
    }
  }
  return -1; // Item não encontrado
}

/**
 * @brief Função para busca binária recursiva
 * @note  A busca binária recursiva verifica o item do meio da lista.
 * @note  Se for o item buscado, retorna o índice; caso contrário, chama a si mesma na metade apropriada.
 * @param listaCompras Lista de compras (array de strings)
 * @param tamanhoLista Tamanho da lista
 * @param item Item a ser buscado
 */
int buscaBinariaRecursiva(const char* listaCompras[], int tamanhoLista, const char* item){
  printf("\n-----------------------------\n");
  printf("--- Busca Binária Recursiva ---\n");
  printf("-----------------------------\n");
  // if (tamanhoLista <= 0){
  //   return -1; // Item não encontrado
  // }
  // int meio = tamanhoLista / 2;
  // int cmp = strcmp(listaCompras[meio], item);
  // if (cmp == 0){
  //   return meio; // Item encontrado, retorna o índice
  // } else if (cmp < 0){
  //   return buscaBinariaRecursiva(listaCompras + meio + 1, tamanhoLista - meio - 1, item);
  // } else {
  //   return buscaBinariaRecursiva(listaCompras, meio, item); // Continua na metade esquerda
  return buscaBinariaRecursivaAux(listaCompras, item, 0, tamanhoLista);
}

/**
 * @brief função auxiliar para a busca binária recursiva
 * @note  Esta função ajusta o índice retornado para refletir a posição correta na lista original.
 * @param listaCompras Lista de compras (array de strings)
 * @param tamanhoLista Tamanho da lista
 * @param item Item a ser buscado
 * @param offset Deslocamento para ajustar o índice retornado
 */
int buscaBinariaRecursivaAux(const char* listaCompras[], char* item, int inicio, int fim){
  int meio = inicio + (fim - inicio) / 2;
  if (inicio > fim){
    return -1; // Item não encontrado
  }
  int cmp = strcmp(listaCompras[meio], item);
  if (cmp == 0){
    return meio; // Item encontrado, retorna o índice
  } else if (cmp < 0){
    return buscaBinariaRecursivaAux(listaCompras, item, meio + 1, fim); // Continua na metade direita
  } else {
    return buscaBinariaRecursivaAux(listaCompras, item, inicio, meio - 1); // Continua na metade esquerda
  }
}

void listarCompras(const char* listaCompras[], int tamanhoLista){
  printf("\n-----------------------------\n");
  printf("--- Lista de Compras ---\n");
  printf("-----------------------------\n");
  printf("--- DEMONSTRAÇÃO DE BUSCAS EM LISTA DE COMPRAS EM LISTA DE TEXTO ---\n");
  printf("Lista utilizada: %s",listaCompras[0]);
  for (int i = 1; i < tamanhoLista; i++){
    printf(", %s", listaCompras[i]);
  }
  printf("\n------------------------------\n");
}

/**
 * @brief Função para imprimir o resultado da busca
 * @param msg Mensagem indicando o tipo de busca
 * @param itemExistente Item que foi buscado
 * @param res1 Resultado da busca (índice ou -1)
 */
void imprimirResultado(char* msg, const char* itemExistente, int res1){
  if (res1 != -1){
    printf("%s: Item '%s' encontrado no índice %d.\n", msg, itemExistente, res1);
  } else {
    printf("%s: Item '%s' não encontrado na lista.\n", msg, itemExistente);
  }
  printf("Pressione Enter para continuar...");
  getchar(); // Espera o usuário pressionar Enter
  printf("-----------------------------\n");
}