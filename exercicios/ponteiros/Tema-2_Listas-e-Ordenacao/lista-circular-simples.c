#include <stdio.h>
#include <stdlib.h>

struct no {
  int valor;
  struct no *proximo;
};

int main() {
  struct no *primeiro = (struct no*) malloc(sizeof(struct no));
  struct no *segundo = (struct no*) malloc(sizeof(struct no));
  struct no *terceiro = (struct no*) malloc(sizeof(struct no));

  primeiro->valor = 10;
  primeiro->proximo = segundo;

  segundo->valor = 20;
  segundo->proximo = terceiro;

  terceiro->valor = 30;
  terceiro->proximo = primeiro;

  struct no *atual = primeiro;
  int count = 0; // Contador para evitar loop infinito
  do {
    printf("Iteração %d:\n", count + 1);
    printf("Valor: %d\n", atual->valor);
    printf("Endereço: %p\n", (void*)atual);
    printf("Próximo: %p\n\n", (void*)atual->proximo);
    atual = atual->proximo;
  } while (count++ < 8); // Limita a 10 iterações para demonstração

  return 0;
}