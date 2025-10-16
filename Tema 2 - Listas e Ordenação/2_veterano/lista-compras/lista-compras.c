#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "../../../../funcoes.h" // Inclui o cabeçalho de funcoes gerais

// Protótipos das funções
#include "funcoes_lista-compras.h"

// --- Função principal ---
int main(){
  // Lista de compras
  // a lista está em ordem alfabética por causa da busca binária
  const char* listaCompras[] = {
    "Arroz",
    "Carne",
    "Feijão",
    "Frango",
    "Leite",
    "Macarrão",
    "Manteiga",
    "Ovos",
    "Pão",
    "Queijo"
  };

  // Calcula o tamanho da lista
  // sizeof(listaCompras) dá o tamanho total em bytes do array
  // sizeof(listaCompras[0]) dá o tamanho em bytes do primeiro elemento (um ponteiro)
  int tamanhoLista = sizeof(listaCompras) / sizeof(listaCompras[0]);

  // Elementos a serem buscados
  const char* itemExistente = "Leite";
  const char* itemNaoExistente = "Chocolate";

  // Exibe a lista de compras
  listarCompras(listaCompras, tamanhoLista);

  // Busca Sequencial Iterativa
  int res1 = buscaSequencialIterativa(listaCompras, tamanhoLista, itemExistente);
  imprimirResultado("Sequencia Iterativa", itemExistente, res1);

  int res2 = buscaSequencialIterativa(listaCompras, tamanhoLista, itemNaoExistente);
  imprimirResultado("Sequencia Iterativa", itemNaoExistente, res2);

  // Busca Sequencial Recursiva
  int res3 = buscaSequencialRecursiva(listaCompras, tamanhoLista, itemExistente);
  imprimirResultado("Sequencia Recursiva", itemExistente, res3);

  int res4 = buscaSequencialRecursiva(listaCompras, tamanhoLista, itemNaoExistente);
  imprimirResultado("Sequencia Recursiva", itemNaoExistente, res4);

  // Busca Binária Iterativa
  int res5 = buscaBinariaIterativa(listaCompras, tamanhoLista, itemExistente);
  imprimirResultado("Binaria Iterativa", itemExistente, res5);

  int res6 = buscaBinariaIterativa(listaCompras, tamanhoLista, itemNaoExistente);
  imprimirResultado("Binaria Iterativa", itemNaoExistente, res6);

  // Busca Binária Recursiva
  int res7 = buscaBinariaRecursiva(listaCompras, tamanhoLista, itemExistente);
  imprimirResultado("Binaria Recursiva", itemExistente, res7);
  printf("Buscando por item não existente: %s\n", itemNaoExistente);
  int res8 = buscaBinariaRecursiva(listaCompras, tamanhoLista, itemNaoExistente);
  imprimirResultado("Binaria Recursiva", itemNaoExistente, res8);
}

