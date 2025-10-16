#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// Protótipos das funções gerais
#include "../../../funcoes.h"

// -- Protótipos de funções ---
#include "funcoes_locais.h"

// Programa principal
int main(){
  // Definição da estrutura de vetor de Jogadores
  typedef struct {
    Jogador vetorJogadores[MAX_JOGADORES];
    int totalJogadores;
  } JogadorVetor;

  // Definição do vetor de jogadores
  JogadorVetor jogadoresVetor;
  jogadoresVetor.totalJogadores = 0;

  // Definição da quantidade de jogadores na lista para controle
  int totalJogadoresLista = 0;

  // Definição do início da lista encadeada de jogadores
  listaJogador* listaJogadores = NULL;

  // Alocação inicial da lista encadeada de jogadores
  listaJogador* listaJogadores = (listaJogador*) malloc(sizeof(listaJogador));
  if (listaJogadores == NULL){
    printf("Erro na alocação de memória.\n");
    return 1;
  }
  listaJogadores->proximo = NULL; // Inicializa o próximo como NULL

  // Variável para armazenar a opção do menu
  int opcao = 0;
  do {
    exibirMenu();

    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    limparBufferEntrada();

    switch (opcao){
      case 0:
        printf("Saindo do programa. Ate a proxima!\n");
        break;
      case 1:
        printf("Cadastro de jogadores (Vetor).\n");
        cadastrarJogadoresVetor(&jogadoresVetor);
        printf("Cadastro de jogadores (Lista).\n");
        cadastrarJogadoresLista();
        break;
      case 2:
        removerJogadorVetor();
        removerJogadorLista();
        break;
      case 3:
        listarJogadoresVetor();
        listarJogadoresLista();
        break;
      case 4:
        visualizarRankingVetor();
        visualizarRankingLista();
        break;
      case 5:
        buscarJogador_sequencialVetor();
        buscarJogador_sequencialLista();
        break;
      case 6:
        buscarJogador_binariaVetor();
        buscarJogador_binariaLista();
        break;
      case 7:
        testeEntreOrdenadoresVetor();
        testeEntreOrdenadoresLista();
        break;
      default:
        printf("Opcao invalida. Tente novamente.\n");

        // Liberar a memória alocada para a lista encadeada de jogadores
        listaJogador* atual = listaJogadores;
        while (atual != NULL){
          listaJogador* temp = atual;
          atual = atual->proximo;
          free(temp);
        }
        break;
    }
  } while (opcao != 0);

  return 0;
}