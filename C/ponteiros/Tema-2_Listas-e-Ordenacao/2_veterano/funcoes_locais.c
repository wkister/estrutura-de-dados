#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes_locais.h"
#include "../../../funcoes.h" // Inclui o cabeçalho de funcoes gerais

// --- Funções Gerais ---
/**
 * @brief Função para mosntrar o menu de opções *
 */
void exibirMenu(){
  printf("\n--- MENU ---\n");
  printf("1. Cadastro de jogadores\n");
  printf("2. Remover jogador\n");
  printf("3. Listar jogadores\n");
  printf("4. Visualizar ranking\n");
  printf("5. Buscar jogador (busca sequencial)\n");
  printf("6. Buscar jogador (busca binária)\n");
  printf("7. Teste entre ordenadores\n");
  printf("0. Sair\n");
  printf("Escolha uma opção: ");
}

// --- Funções do Programa ---
/**
 * @brief Função para cadastrar jogadores
 */
void cadastrarJogadoresVetor(Jogador *jogadoresVetor){
  printf("\n-----------------------------\n");
  printf("--- Cadastro de Jogadores (Vetor) ---\n");
  printf("-----------------------------\n");
}
void cadastrarJogadoresLista(){
  printf("\n-----------------------------\n");
  printf("--- Cadastro de Jogadores (Lista) ---\n");
  printf("-----------------------------\n");
}

/**
 * @brief Função para remover um jogador
 */
void removerJogadorVetor(){
  printf("\n-----------------------------\n");
  printf("--- Remover Jogador (Vetor) ---\n");
  printf("-----------------------------\n");
}
void removerJogadorLista(){
  printf("\n-----------------------------\n");
  printf("--- Remover Jogador (Lista) ---\n");
  printf("-----------------------------\n");
}

/**
 * @brief Função para listar os jogadores cadastrados
 */
void listarJogadoresVetor(){
  printf("\n-----------------------------\n");
  printf("--- Listar Jogadores (Vetor) ---\n");
  printf("-----------------------------\n");
}
void listarJogadoresLista(){
  printf("\n-----------------------------\n");
  printf("--- Listar Jogadores (Lista) ---\n");
  printf("-----------------------------\n");
}

/**
 * @brief Função para visualizar o ranking dos jogadores
 */
void visualizarRankingVetor(){
  printf("\n-----------------------------\n");
  printf("--- Visualizar Ranking (Vetor) ---\n");
  printf("-----------------------------\n");
}
void visualizarRankingLista(){
  printf("\n-----------------------------\n");
  printf("--- Visualizar Ranking (Lista) ---\n");
  printf("-----------------------------\n");
}

/**
 * @brief Função para buscar um jogador usando busca sequencial
 */
void buscarJogador_sequencialVetor(){
  printf("\n-----------------------------\n");
  printf("--- Busca Sequencial de Jogador (Vetor) ---\n");
  printf("-----------------------------\n");
}
void buscarJogador_sequencialLista(){
  printf("\n-----------------------------\n");
  printf("--- Busca Sequencial de Jogador (Lista) ---\n");
  printf("-----------------------------\n");
}

/**
 * @brief Função para buscar um jogador usando busca binária
 */
void buscarJogador_binariaVetor(){
  printf("\n-----------------------------\n");
  printf("--- Busca Binária de Jogador (Vetor) ---\n");
  printf("-----------------------------\n");
}
void buscarJogador_binariaLista(){
  printf("\n-----------------------------\n");
  printf("--- Busca Binária de Jogador (Lista) ---\n");
  printf("-----------------------------\n");
}

/**
 * @brief Função para testar e comparar diferentes algoritmos de ordenação
 */
void testeEntreOrdenadoresVetor(){
  printf("\n-----------------------------\n");
  printf("--- Teste Entre Ordenadores (Vetor) ---\n");
  printf("-----------------------------\n");
}
void testeEntreOrdenadoresLista(){
  printf("\n-----------------------------\n");
  printf("--- Teste Entre Ordenadores (Lista) ---\n");
  printf("-----------------------------\n");
}