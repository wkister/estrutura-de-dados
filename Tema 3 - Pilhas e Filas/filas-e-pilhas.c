#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char nome[30];
    int idade;
} Pessoa;

typedef struct {
    Pessoa dados[MAX];
    int inicio, fim;
} Fila;

typedef struct {
    Pessoa dados[MAX];
    int topo;
} Pilha;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

void inserir(Fila *f, Pessoa p) {
    if (f->fim < MAX) {
        f->dados[f->fim++] = p;
    }
}

Pessoa remover(Fila *f) {
    return f->dados[f->inicio++];
}

void push(Pilha *p, Pessoa pes) {
    if (p->topo < MAX - 1) {
        p->dados[++p->topo] = pes;
    }
}

Pessoa pop(Pilha *p) {
    return p->dados[p->topo--];
}

Pessoa peek(Pilha *p) {
    return p->dados[p->topo];
}

void exibirPilha(Pilha p) {
    while (p.topo >= 0) {
        Pessoa atual = pop(&p);
        printf("Nome: %s | Idade: %d\n", atual.nome, atual.idade);
    }
}

void exibirFila(Fila f) {
    for (int i = f.inicio; i < f.fim; i++) {
        printf("Nome: %s | Idade: %d\n", f.dados[i].nome, f.dados[i].idade);
    }
}

int main() {
    Fila fila;
    Pilha pilhaPrioridade;

    inicializarFila(&fila);
    inicializarPilha(&pilhaPrioridade);

    Pessoa pessoas[] = {
        {"Carlos", 45}, {"Joana", 62}, {"Lucas", 30}, {"Maria", 75}
    };

    for (int i = 0; i < 4; i++) {
        inserir(&fila, pessoas[i]);
    }

    printf("Pessoas na fila:\n");
    exibirFila(fila);


    while (fila.inicio < fila.fim) {
        Pessoa atual = remover(&fila);
        if (atual.idade > 60) {
            push(&pilhaPrioridade, atual);
        }
    }

    printf("Pessoas com prioridade:\n");
    exibirPilha(pilhaPrioridade);

    printf("\nPessoas sem prioridade:\n");
    exibirFila(fila);

    return 0;
}