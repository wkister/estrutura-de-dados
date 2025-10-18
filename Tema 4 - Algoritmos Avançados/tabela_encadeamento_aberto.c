#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

typedef struct {
  char nome[50];
  int ocupado; // 0 = vazio, 1 = ocupado, -1 = removido
} Entrada;

Entrada tabela_hash[TAMANHO_TABELA];

// --- Protótipos das funções ---
int funcao_hash(const char* chave);
void inserir(const char* nome);
int buscar(const char* nome);
void remover(const char* nome);

int main() {
  // Inicializa a tabela
  for (int i = 0; i < TAMANHO_TABELA; i++) {
      tabela_hash[i].ocupado = 0;
  }

  inserir("Ana");
  inserir("Bruno");
  inserir("Carlos");
  inserir("Amanda"); // Pode colidir com Ana

  int pos_bruno = buscar("Bruno");
  printf("Buscando 'Bruno': %s (posição: %d)\n", pos_bruno != -1 ? "Encontrado" : "Não encontrado", pos_bruno);

  int pos_joao = buscar("João");
  printf("Buscando 'João': %s (posição: %d)\n",
         pos_joao != -1 ? "Encontrado" : "Não encontrado", pos_joao);

  int pos_ana = buscar("Ana");
  printf("Buscando 'Ana': %s (posição: %d)\n",
         pos_ana != -1 ? "Encontrado" : "Não encontrado", pos_ana);

  int pos_amanda = buscar("Amanda");
  printf("Buscando 'Amanda': %s (posição: %d)\n",
         pos_amanda != -1 ? "Encontrado" : "Não encontrado", pos_amanda);

  remover("Carlos");
  remover("João");

  return 0;
}

/**
 * @brief Calcula o índice hash para uma chave de string.
 * @param chave String utilizada como chave de hash.
 * @return Índice calculado na faixa [0, TAMANHO_TABELA-1].
 */
int funcao_hash(const char* chave) {
  int soma = 0;
  for (int i = 0; chave[i] != '\0'; i++) {
    soma += chave[i];
  }
  return soma % TAMANHO_TABELA;
}

/**
 * @brief Insere um nome na tabela hash usando sondagem linear para colisões.
 * @param nome String com o nome a ser inserido.
 */
void inserir(const char* nome) {
  int indice = funcao_hash(nome);
  printf("Índice hash inicial para '%s': %d\n", nome, indice);

  for (int i = 0; i < TAMANHO_TABELA; i++) {
    int pos = (indice + i) % TAMANHO_TABELA;

    if (tabela_hash[pos].ocupado == 0 || tabela_hash[pos].ocupado == -1) {
      strcpy(tabela_hash[pos].nome, nome);
      tabela_hash[pos].ocupado = 1;
      printf("'%s' inserido na posição %d.\n", nome, pos);
      return;
    }
  }

  printf("Tabela cheia. Não foi possível inserir '%s'.\n", nome);
}

/**
 * @brief Busca um nome na tabela hash.
 * @param nome String com o nome a ser buscado.
 * @return Índice do nome na tabela, ou -1 se não encontrado.
 */
int buscar(const char* nome) {
  int indice = funcao_hash(nome);

  for (int i = 0; i < TAMANHO_TABELA; i++) {
    int pos = (indice + i) % TAMANHO_TABELA;

    if (tabela_hash[pos].ocupado == 0) {
      return -1; // Paramos: posição nunca foi usada
    }

    if (tabela_hash[pos].ocupado == 1 && strcmp(tabela_hash[pos].nome, nome) == 0) {
      return pos;
    }
  }

  return -1; // Não encontrou
}

/**
 * @brief Remove um nome da tabela hash.
 * @param nome String com o nome a ser removido.
 */
void remover(const char* nome) {
  int pos = buscar(nome);
  if (pos == -1) {
    printf("'%s' não encontrado.\n", nome);
    return;
  }

  tabela_hash[pos].ocupado = -1;
  printf("'%s' removido da tabela.\n", nome);
}

