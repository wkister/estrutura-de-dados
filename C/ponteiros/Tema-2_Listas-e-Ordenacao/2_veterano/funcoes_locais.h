#ifndef FUNCOES_LOCAIS_H
#define FUNCOES_LOCAIS_H

// --- Constantes ---
#define MAX_JOGADORES 10
#define TAM_STRING 50

// -- Estruturas de Dados ---
// Estrutura para representar um jogador
typedef struct {
    char nome[TAM_STRING];
    int pontuacao;
} Jogador;

// Estrutura para lista encadeada de jogadores
typedef struct listaJogador {
    Jogador jogador;
    struct listaJogador* proximo;
} listaJogador;

// Protótipos das funções
void exibirMenu();
// Para vetor
void cadastrarJogadoresVetor(Jogador *jogadoresVetor);
void removerJogadorVetor();
void listarJogadoresVetor();
void visualizarRankingVetor();
void buscarJogador_sequencialVetor();
void buscarJogador_binariaVetor();
void testeEntreOrdenadoresVetor();

// Para lista
void cadastrarJogadoresLista();
void removerJogadorLista();
void listarJogadoresLista();
void visualizarRankingLista();
void buscarJogador_sequencialLista();
void buscarJogador_binariaLista();
void testeEntreOrdenadoresLista();

#endif