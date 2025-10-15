#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file fila.c
 * @brief Implementação de uma fila usando arrays circulares
 * @note A fila segue a estrutura FIFO (First In, First Out)
 * @author Wellington Kister do Nascimento
 */

// Definições gerais
// --- Constantes ---
#define MAX 5 // Tamanho máximo da fila

// Estrutura de dados a ser armazenada na fila
typedef struct {
    char nome[30];
    int idade;
} Pessoa;

// Estrutura da fila
typedef struct {
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

// Protótipos das funções
void inicializarFila(Fila* fila);
int filaVazia(Fila* fila);
int filaCheia(Fila* fila);
void inserir(Fila* fila, Pessoa p);
void remover(Fila* fila, Pessoa* p);
void mostrarFila(Fila* fila);

// Função principal
int main(){
  Fila f;
  inicializarFila(&f);  // Inicializa a fila

  // Insere algumas pessoas na fila
  Pessoa p1 = {"João", 25};
  Pessoa p2 = {"Maria", 30};
  inserir(&f, p1);
  inserir(&f, p2);

  mostrarFila(&f);  // Mostra a fila antes da remoção

  // Remove uma pessoa da fila
  Pessoa removida;
  remover(&f, &removida);  // Aqui usamos a função de remoção

  printf("Pessoa removida: [%s, %d]\n", removida.nome, removida.idade);

  mostrarFila(&f);  // Mostra a fila após a remoção

  return 0;
}

// Funções da fila
/**
 * @brief Inicializa a fila
 * @param f Ponteiro para a fila a ser inicializada
 */
void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->total = 0;
}

/**
 * @brief Verifica se a fila está vazia
 * @param f Ponteiro para a fila a ser verificada
 * @return 1 se a fila estiver vazia, 0 caso contrário
 */
int filaCheia(Fila *fila) {
    return fila->total == MAX;
}

/**
 * @brief Verifica se a fila está vazia
 * @param f Ponteiro para a fila a ser verificada
 * @return 1 se a fila estiver vazia, 0 caso contrário
 */
int filaVazia(Fila *fila) {
    return fila->total == 0;
}

/**
 * @brief Insere um elemento no fim da fila
 * @param f Ponteiro para a fila onde o elemento será inserido
 * @param p Elemento a ser inserido na fila
 */
void inserir(Fila *fila, Pessoa p) {
    if (fila->total == MAX) {
        printf("Fila cheia. Não é possível inserir.\n");
        return;
    }

    fila->itens[fila->fim] = p;
    fila->fim = (fila->fim + 1) % MAX;
    fila->total++;
}

/**
 * @brief Remove um elemento do início da fila
 * @param f Ponteiro para a fila de onde o elemento será removido
 * @param p Ponteiro para armazenar o elemento removido
 */
void remover(Fila *fila, Pessoa *p) {
    if (filaVazia(fila)) {
        printf("Fila vazia. Não é possível remover.\n");
        return;
    }

    *p = fila->itens[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->total--;
}

/**
 * @brief Exibe os elementos da fila
 * @param f Ponteiro para a fila a ser exibida
 */
void mostrarFila(Fila *fila) {
    printf("Fila: ");
    for (int i = 0, idx = fila->inicio; i < fila->total; i++, idx = (idx + 1) % MAX) {
        printf("[%s, %d] ", fila->itens[idx].nome, fila->itens[idx].idade);
    }
    printf("\n");
}