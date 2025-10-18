#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

/* Estrutura de um nó da lista ligada */
typedef struct Nodo {
    char nome[50];         /* Armazena o nome */
    struct Nodo *proximo;  /* Ponteiro para o próximo nó */
} Nodo;

/* A tabela hash é um vetor de ponteiros para Nodo. Inicializa com NULL. */
static Nodo *tabela_hash[TAMANHO_TABELA] = { NULL };

/* Prototipação das funções */
int funcao_hash(const char *chave);
void inserir(const char *nome);
Nodo *buscar(const char *nome);
void remover(const char *nome);

int main(void)
{
    inserir("Ana");
    inserir("Bruno");
    inserir("Carlos");
    inserir("Amanda"); /* Pode colidir com "Ana" */

    printf("Buscando 'Bruno': %s\n", buscar("Bruno") ? "Encontrado" : "Não encontrado");
    printf("Buscando 'João': %s\n", buscar("João") ? "Encontrado" : "Não encontrado");

    remover("Carlos");
    remover("João");

    return 0;
}

/**
 * @brief Calcula o índice hash para uma chave de string.
 *
 * A função soma os códigos ASCII dos caracteres da chave e aplica o
 * operador módulo pelo tamanho da tabela para obter um índice entre
 * 0 e TAMANHO_TABELA-1.
 *
 * @param[in] chave String utilizada como chave de hash.
 * @return Índice calculado na faixa [0, TAMANHO_TABELA-1].
 */
int funcao_hash(const char *chave)
{
    int soma = 0;

    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (unsigned char)chave[i];
    }

    return soma % TAMANHO_TABELA;
}

/**
 * @brief Insere um nome na tabela hash usando encadeamento para colisões.
 *
 * A função calcula o índice a partir da chave (nome), aloca um novo nó e
 * insere-o no início da lista ligada correspondente ao índice (head insertion).
 *
 * @param[in] nome String com o nome a ser inserido.
 * @note A função termina o programa em caso de falha de alocação.
 */
void inserir(const char *nome)
{
    int indice = funcao_hash(nome);

    Nodo *novo = malloc(sizeof(Nodo));
    if (novo == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';

    /* Insere no início da lista */
    novo->proximo = tabela_hash[indice];
    tabela_hash[indice] = novo;
}

/**
 * @brief Busca um nome na tabela hash.
 *
 * @note Percorre a lista ligada no índice calculado para a chave e compara os
 * @note nomes com strcmp.
 *
 * @param[in] nome String com o nome a ser buscado.
 * @return Ponteiro para o Nodo encontrado, ou NULL se não existir.
 */
Nodo *buscar(const char *nome)
{
    int indice = funcao_hash(nome);
    Nodo *atual = tabela_hash[indice];

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual; /* Encontrou */
        }
        atual = atual->proximo;
    }

    return NULL; /* Não está na lista */
}

/**
 * @brief Remove um nome da tabela hash, se presente.
 *
 * Procura o nó na lista ligada correspondente ao índice e atualiza os
 * ponteiros para excluir o nó da lista. Libera a memória do nó removido.
 *
 * @param[in] nome String com o nome a ser removido.
 */
void remover(const char *nome)
{
    int indice = funcao_hash(nome);
    Nodo *atual = tabela_hash[indice];
    Nodo *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                tabela_hash[indice] = atual->proximo; /* Era o primeiro */
            } else {
                anterior->proximo = atual->proximo; /* "Pula" o nó atual */
            }

            free(atual);
            printf("'%s' removido.\n", nome);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("'%s' não encontrado.\n", nome);
}