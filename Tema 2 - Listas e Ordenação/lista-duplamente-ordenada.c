#include <stdio.h>
#include <stdlib.h>

struct no {
  int valor;
  struct no *proximo;
  struct no *anterior;
};

int main() {
  struct no *primeiro = (struct no*) malloc(sizeof(struct no));
  struct no *segundo = (struct no*) malloc(sizeof(struct no));
  struct no *terceiro = (struct no*) malloc(sizeof(struct no));

  primeiro->valor = 10;
  primeiro->proximo = segundo;
  primeiro->anterior = NULL;

  segundo->valor = 20;
  segundo->proximo = terceiro;
  segundo->anterior = primeiro;

  terceiro->valor = 30;
  terceiro->proximo = NULL;
  terceiro->anterior = segundo;

  // struct no *atual = primeiro; // Iniciando do primeiro nó
  struct no *atual = terceiro; // Iniciando do primeiro nó
  while (atual != NULL){
    printf("Valor: %d\n", atual->valor);
    printf("Endereço: %p\n", (void*)atual);
    printf("Anterior: %p\n", (void*)atual->anterior);
    printf("Próximo: %p\n\n", (void*)atual->proximo);
    // atual = atual->proximo; // Movendo para o próximo nó
    atual = atual->anterior; // Movendo para o nó anterior
  }

  return 0;
}