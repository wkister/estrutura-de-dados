#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do número máximo de territórios
#define MAX_TERRITORIOS 5


// Definição da Estrutura do Território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Definição dos times
struct Territorio times[MAX_TERRITORIOS];

void main(){
    // Entrada dos dados
    for(int i=0; i < MAX_TERRITORIOS; i++){
        printf("Digite o nome do %do. território: ", i + 1);
        scanf("%s", times[i].nome);
        printf("Digite a cor do %do. território: ", i + 1);
        scanf("%s", times[i].cor);
        printf("Digite o número de tropas do %do. território: ", i + 1);
        scanf("%d", &times[i].tropas);
    }

    // Listando os territórios criados
    for(int i=0; i < MAX_TERRITORIOS; i++){
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", times[i].nome);
        printf("Cor: %s\n", times[i].cor);
        printf("Tropas: %d\n\n", times[i].tropas);
    }
}

