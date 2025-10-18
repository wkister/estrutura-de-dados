/**
 * Implementação de uma árvore Trie em C
 * @file arvore_trie.c
 * @author Wellington Kister do Nascimento
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO_ALFABETO 26

// Definição da estrutura do nó da Trie
struct NoTrie {
  struct NoTrie* filhos[TAMANHO_ALFABETO];
  bool ehFimDePalavra;
};

/**
 * @brief Função para criar um novo nó da Trie
 * @return Ponteiro para o novo nó criado
 */
struct NoTrie* criarNo() {
  struct NoTrie* novoNo = (struct NoTrie*) malloc(sizeof(struct NoTrie));
  novoNo->ehFimDePalavra = false;
  for (int i = 0; i < TAMANHO_ALFABETO; i++) {
    novoNo->filhos[i] = NULL;
  }

  return novoNo;
}

/**
 * @brief Função para inserir uma palavra na Trie
 * @param raiz Ponteiro para a raiz da Trie
 * @param palavra Palavra a ser inserida
 */
void inserir (struct NoTrie* raiz, const char* palavra) {
  struct NoTrie* atual = raiz;

  for (int i = 0; palavra[i] != '\0'; i++) {
    int indice = palavra[i] - 'a';

    if (atual->filhos[indice] == NULL) {
      atual->filhos[indice] = criarNo();
    }
    atual = atual->filhos[indice];
  }
  atual->ehFimDePalavra = true;
}

/**
 * @brief Função para buscar uma palavra na Trie
 * @param raiz Ponteiro para a raiz da Trie
 * @param palavra Palavra a ser buscada
 * @return true se a palavra for encontrada, false caso contrário
 */
bool buscar(struct NoTrie* raiz, const char* palavra) {
  struct NoTrie* atual = raiz;

  for (int i = 0; palavra[i] != '\0'; i++) {
    int indice = palavra[i] - 'a';

    if (atual->filhos[indice] == NULL)
      return false;

    atual = atual->filhos[indice];
  }
  return atual != NULL && atual->ehFimDePalavra;
}

/**
 * @brief Função para listar todas as palavras armazenadas na Trie
 * @param no Ponteiro para o nó atual
 * @param buffer Buffer para armazenar a palavra atual
 * @param nivel Nível atual na Trie
 */
void listarPalavras(struct NoTrie* no, char* buffer, int nivel) {
  if (no->ehFimDePalavra) {
    buffer[nivel] = '\0';
    printf("%s\n", buffer);
  }

  for (int i = 0; i < TAMANHO_ALFABETO; i++) {
    if (no->filhos[i] != NULL) {
      buffer[nivel] = 'a' + i;
      listarPalavras(no->filhos[i], buffer, nivel + 1);
    }
  }
}

/**
 * @brief Função para normalizar uma string (converter para minúsculas e remover caracteres não alfabéticos)
 * @param entrada String de entrada
 * @param saida String de saída normalizada
 */
void normalizar(const char* entrada, char* saida) {
  int j = 0;
  for (int i = 0; entrada[i] != '\0'; i++) {
    char c = entrada[i];
    if (c >= 'A' && c <= 'Z') c += 32; // Converte para minúsculo
    if (c >= 'a' && c <= 'z') saida[j++] = c; // Mantém apenas letras
  }
  saida[j] = '\0';
}

int main() {
  struct NoTrie* raiz = criarNo();
  char normalizada[100];

  normalizar("Pegadas de Lama", normalizada);
  inserir(raiz, normalizada);

  normalizar("Chave perdida", normalizada);
  inserir(raiz, normalizada);

  normalizar("Livro com página faltando", normalizada);
  inserir(raiz, normalizada);

  normalizar("Lençol manchado", normalizada);
  inserir(raiz, normalizada);

  normalizar("Gaveta perdida", normalizada);
  inserir(raiz, normalizada);

  char buffer[100]; // Tamanho máximo de palavra suportado
  listarPalavras(raiz, buffer, 0);

  return 0;
}