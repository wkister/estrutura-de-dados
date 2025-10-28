#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100

// -- Definição da Estrutura de Dados
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 - Disponível e 0 - Emprestado
};

// Estrutura para armazenar as informações dos empréstimos
struct Emprestimo {
    int numeroLivro; // Número do livro a ser emprestado
    char usuario[TAM_STRING]; // Nome do usuário que pegou o livro emprestado
};

// Função para limpar o buffer de entrada
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para listar os livros da Biblioteca
void listarLivros(int totalLivros, struct Livro *Biblioteca){
    // Listar livros
    if (totalLivros > 0) {
        printf("\n--------------------------------\n");
        printf("Livros cadastrados:\n");
        printf("--------------------------------\n");
        for (int i = 0; i < totalLivros; i++) {
            printf("Livro %d\n\n", i + 1);
            printf("Nome   : %s", Biblioteca[i].nome);
            printf("Autor  : %s", Biblioteca[i].autor);
            printf("Editora: %s", Biblioteca[i].editora);
            printf("Edicao : %d\n\n", Biblioteca[i].edicao);
        }
        printf("--------------------------------\n");
    } else {
        printf("Nao ha livros cadastrados.\n");
    }
}

// Função principal
int main() {
    // Alocação dinâmica de momória
    // struct Livro Biblioteca[MAX_LIVROS];
    struct Livro *Biblioteca;
    struct Emprestimo *Emprestimos;

    // Alocação da memória
    Biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));
    Emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    // Verifica se a alocação foi bem sucedida
    if (Biblioteca == NULL || Emprestimos == NULL){
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    int totalLivros = 0;      // Total de livros cadastrados na Biblioteca
    int totalEmprestimos = 0; // Total de livros emprestados
    int opcao;

    do {
        // Exibe o menu de opções
        printf("\n\n--------------------------\n");
        printf("-- BIBLIOTECA - PARTE 2 --\n");
        printf("--------------------------\n\n");

        printf("1 - Adicionar livro\n");
        printf("2 - Remover livro\n");
        printf("3 - Listar livros\n");
        printf("4 - Emprestar livro\n");
        printf("5 - Devolver livro\n");
        printf("6 - Listar empréstimos\n");
        printf("0 - Sair\n\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
        case 1:
            // Adicionar livro
            if (totalLivros < MAX_LIVROS) {
                printf("\n--------------------------------\n");
                printf("Adicionando um novo livro\n");
                printf("--------------------------------\n");
                printf("Digite o nome do livro: ");
                fgets(Biblioteca[totalLivros].nome, TAM_STRING, stdin);
                printf("Digite o autor do livro: ");
                fgets(Biblioteca[totalLivros].autor, TAM_STRING, stdin);
                printf("Digite a editora do livro: ");
                fgets(Biblioteca[totalLivros].editora, TAM_STRING, stdin);
                printf("Digite a edicao do livro: ");
                scanf("%d", &Biblioteca[totalLivros].edicao);
                limparBufferEntrada();
                Biblioteca[totalLivros].disponivel = 1; // Livro disponível
                printf("\n--------------------------------\n");
                printf("Livro adicionado com sucesso!\n");
                printf("--------------------------------\n");
                totalLivros++;
            } else {
                printf("Limite de livros atingido.\n");
            }
            break;

        case 2:
            // Remover livro
            if (totalLivros > 0) {
                // Removendo o último livro
                // Biblioteca[totalLivros - 1] = (struct Livro) {0};
                // totalLivros--;
                printf("Ainda implementando.\n");
            } else {
                printf("Nao ha livros para remover.\n");
            }
            break;

        case 3:
            // Listar livros
            listarLivros(totalLivros, Biblioteca);
            printf("Pressione Enter para continuar...");
            getchar();
            break;

        case 4:
            // Emprestar livro
            // Testar se existem livros disponíveis para empréstimo
            if (totalEmprestimos >= totalLivros){
                printf("Não existem livros disponíveis para empréstimo.\n");
            } else {
                int numeroLivro;          // Número do livro a ser emprestado
                char usuario[TAM_STRING]; // Nome do usuário que pegará o livro emprestado

                // Verificar se o total de empréstimos atingiu o limite
                if (totalEmprestimos >= MAX_EMPRESTIMOS) {
                    printf("Limite de empréstimos atingido.\n");
                    break;
                }

                // Listar livros disponíveis
                printf("\n--------------------------------\n");
                printf("Livros disponíveis para empréstimo\n");
                printf("--------------------------------\n");
                for (int i = 0; i < totalLivros; i++) {
                    if (Biblioteca[i].disponivel) {
                        printf("Livro %d: %s", i + 1, Biblioteca[i].nome);
                    }
                }

                // Solicitar o número do livro a ser emprestado
                printf("Digite o número do livro a ser emprestado: ");
                scanf("%d", &numeroLivro);
                limparBufferEntrada();

                // Verifica se o número do livro é válido
                if (numeroLivro < 1 || numeroLivro > totalLivros || !Biblioteca[numeroLivro - 1].disponivel) {
                    printf("Número de livro inválido ou livro indisponível.\n");
                } else {
                    // Solicitar o nome do usuário
                    printf("Digite o nome do usuário: ");
                    fgets(usuario, TAM_STRING, stdin);

                    // Registrar o empréstimo (retira 1 para ajustar ao índice do vetor de livros que começa com 0)
                    Emprestimos[totalEmprestimos].numeroLivro = numeroLivro - 1;

                    // Registrar o nome do usuário
                    strncpy(Emprestimos[totalEmprestimos].usuario, usuario, TAM_STRING);

                    // Atualiza o status do livro para indisponível
                    Biblioteca[numeroLivro - 1].disponivel = 0;
                    totalEmprestimos++;
                }
            }
            break;

        case 5:
            // Devolver livro
            printf("Ainda implementando.\n");
            break;

        case 6:
            // Listar empréstimos
            if (totalEmprestimos > 0) {
                printf("\n--------------------------------\n");
                printf("Empréstimos registrados\n");
                printf("--------------------------------\n");
                for (int i = 0; i < totalEmprestimos; i++) {
                    int numLivro = Emprestimos[i].numeroLivro;
                    printf("Empréstimo %d:\n", i + 1);
                    printf("Livro  : %s", Biblioteca[numLivro].nome);
                    printf("Usuário: %s", Emprestimos[i].usuario);
                    printf("\n");
                }
            } else {
                printf("Não há empréstimos registrados.\n");
            }
            printf("Pressione Enter para continuar...");
            getchar();
            break;

        case 0:
            // Sair
            printf("Saindo do sistema...\n");
            break;

        default:
            break;
        }
    } while (opcao != 0);

    // Liberar a memória alocada
    free(Biblioteca);
    free(Emprestimos);

    printf("Memória liberada. Programa encerrado.\n");

    return 0;
}
