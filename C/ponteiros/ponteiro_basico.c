/*
 * ponteiro_basico.c - Exemplo básico de ponteiros
 * Estrutura de Dados - Ponteiros
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Exemplo de Ponteiros ===\n");
    
    // Declaração de variável e ponteiro
    int numero = 42;
    int *ptr = &numero;
    
    printf("Valor da variável: %d\n", numero);
    printf("Endereço da variável: %p\n", (void*)&numero);
    printf("Valor do ponteiro: %p\n", (void*)ptr);
    printf("Valor apontado pelo ponteiro: %d\n", *ptr);
    
    // Modificando valor através do ponteiro
    *ptr = 100;
    printf("Após modificação via ponteiro: %d\n", numero);
    
    // Exemplo com alocação dinâmica
    int *ptr_dinamico = malloc(sizeof(int));
    if (ptr_dinamico != NULL) {
        *ptr_dinamico = 200;
        printf("Valor alocado dinamicamente: %d\n", *ptr_dinamico);
        free(ptr_dinamico);  // Importante: liberar memória
    }
    
    printf("============================\n");
    return 0;
}