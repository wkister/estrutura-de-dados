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

// Definições das funções
void limparBufferEntrada();
void listarLivros(int totalLivros,const struct Livro *Biblioteca); // 'const' para evitar modificação acidental
void cadastrarLivros(struct Livro *Biblioteca, int* totalLivros);
void emprestarLivros(int* totalEmprestimos, int totalLivros, struct Livro *Biblioteca, struct Emprestimo *Emprestimos);
void listarEmprestimos(int totalEmprestimos,const struct Livro *Biblioteca,const struct Emprestimo *Emprestimos);
void liberarMemoria(struct Livro *Biblioteca, struct Emprestimo *Emprestimos);
void exibirMenu();

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
        exibirMenu();

        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
        case 1:
            // Adicionar livro
            cadastrarLivros(Biblioteca, &totalLivros);
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
            break;

        case 4:
            // Emprestar livro
            emprestarLivros(&totalEmprestimos, totalLivros, Biblioteca, Emprestimos);
            break;

        case 5:
            // Devolver livro
            printf("Ainda implementando.\n");
            break;

        case 6:
            // Listar empréstimos
            listarEmprestimos(totalEmprestimos, Biblioteca, Emprestimos);
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
    printf("Programa encerrado.\n");

    return 0;
}

// ---------------
// --- FUNCÕES ---
// ---------------

/**
 * @brief Exibe o menu de opções da Biblioteca
 */
void exibirMenu(){
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
}

/**
 * @brief Liberar a memória alocada para as estruturas
 * @param Biblioteca Ponteiro para a estrutura de livros
 * @param Emprestimos Ponteiro para a estrutura de empréstimos
 */
void liberarMemoria(struct Livro *Biblioteca, struct Emprestimo *Emprestimos){
    free(Biblioteca);
    free(Emprestimos);
    printf("Memória liberada.\n");
}

/**
 * @brief Função para listar os livros que foram emprestados
 * @param totalEmprestimos Total de empréstimos registrados
 * @param Biblioteca Ponteiro para a estrutura de livros
 * @param Emprestimos Ponteiro para a estrutura de empréstimos
 */
void listarEmprestimos(int totalEmprestimos,const struct Livro *Biblioteca,const struct Emprestimo *Emprestimos){
    if (totalEmprestimos > 0) {
        printf("\n--------------------------------\n");
        printf("Empréstimos registrados\n");
        printf("--------------------------------\n");
        for (int i = 0; i < totalEmprestimos; i++) {
            int numLivro = Emprestimos[i].numeroLivro;
            printf("Empréstimo %d:\n", i + 1);
            printf("Livro  : %s\n", Biblioteca[numLivro].nome);
            printf("Usuário: %s", Emprestimos[i].usuario);
            printf("\n");
        }
    } else {
        printf("Não há empréstimos registrados.\n");
    }
    printf("Pressione Enter para continuar...");
    getchar();
}

/**
 * @brief Função para emprestar um livro
 * @param totalEmprestimos Ponteiro para o total de empréstimos registrados
 * @param totalLivros Total de livros cadastrados na Biblioteca
 * @param Biblioteca Ponteiro para a estrutura de livros
 * @param Emprestimos Ponteiro para a estrutura de empréstimos
 */
void emprestarLivros(int* totalEmprestimos, int totalLivros, struct Livro *Biblioteca, struct Emprestimo *Emprestimos){
    int numeroLivro;          // Número do livro a ser emprestado
    char usuario[TAM_STRING]; // Nome do usuário que pegará o livro emprestado

    // Testar se existem livros disponíveis para empréstimo
    if (*totalEmprestimos >= totalLivros){
        printf("Não existem livros disponíveis para empréstimo.\n");
    } else {
        // Verificar se o total de empréstimos atingiu o limite
        if (*totalEmprestimos >= MAX_EMPRESTIMOS) {
            printf("Limite de empréstimos atingido.\n");
        } else {
            // Listar livros disponíveis
            printf("\n--------------------------------\n");
            printf("Livros disponíveis para empréstimo\n");
            printf("--------------------------------\n");
            for (int i = 0; i < totalLivros; i++) {
                if (Biblioteca[i].disponivel) {
                    printf("Livro %d: %s\n", i + 1, Biblioteca[i].nome);
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
                Emprestimos[*totalEmprestimos].numeroLivro = numeroLivro - 1;

                // Registrar o nome do usuário
                strncpy(Emprestimos[*totalEmprestimos].usuario, usuario, TAM_STRING);

                // Atualiza o status do livro para indisponível
                Biblioteca[numeroLivro - 1].disponivel = 0;
                (*totalEmprestimos)++;
            }
        }
    }
}

/**
 * @brief Função para limpar o buffer de entrada
 * @note Evita problemas com entradas de dados
 */
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Função para listar os livros da Biblioteca
 * @param totalLivros Total de livros cadastrados na Biblioteca
 * @param Biblioteca Ponteiro para a estrutura de livros (const para evitar modificação acidental)
 */
void listarLivros(int totalLivros,const struct Livro *Biblioteca){
    // Listar livros
    if (totalLivros > 0) {
        printf("\n--------------------------------\n");
        printf("Livros cadastrados:\n");
        printf("--------------------------------\n");
        for (int i = 0; i < totalLivros; i++) {
            printf("Livro %d\n\n", i + 1);
            printf("Nome   : %s\n", Biblioteca[i].nome);
            printf("Autor  : %s\n", Biblioteca[i].autor);
            printf("Editora: %s\n", Biblioteca[i].editora);
            printf("Edicao : %d\n\n", Biblioteca[i].edicao);
        }
        printf("--------------------------------\n");
    } else {
        printf("Nao ha livros cadastrados.\n");
    }
    printf("Pressione Enter para continuar...");
    getchar();
}

/**
 * @brief Função para cadastrar um novo livro na Biblioteca
 * @param Biblioteca Ponteiro para a estrutura de livros
 * @param totalLivros Ponteiro para o total de livros cadastrados (para atualização)
 */
void cadastrarLivros(struct Livro *Biblioteca, int* totalLivros){
    int indice = *totalLivros;
    // if (indice < MAX_LIVROS) {
    //     printf("\n--------------------------------\n");
    //     printf("Adicionando um novo livro\n");
    //     printf("--------------------------------\n");
    //     printf("Digite o nome do livro: ");
    //     fgets(Biblioteca[indice].nome, TAM_STRING, stdin);
    //     printf("Digite o autor do livro: ");
    //     fgets(Biblioteca[indice].autor, TAM_STRING, stdin);
    //     printf("Digite a editora do livro: ");
    //     fgets(Biblioteca[indice].editora, TAM_STRING, stdin);
    //     printf("Digite a edicao do livro: ");
    //     scanf("%d", &Biblioteca[indice].edicao);
    //     limparBufferEntrada();
    //     Biblioteca[indice].disponivel = 1; // Livro disponível
    //     printf("\n--------------------------------\n");
    //     printf("Livro adicionado com sucesso!\n");
    //     printf("--------------------------------\n");
    //     totalLivros++;
    // } else {
    //     printf("Limite de livros atingido.\n");
    // }
    strcpy(Biblioteca[0].nome, "Cálculo Diferencial e Integral");
    strcpy(Biblioteca[0].autor, "James Stewart");
    strcpy(Biblioteca[0].editora, "Cengage Learning");
    Biblioteca[0].edicao = 8;
    Biblioteca[0].disponivel = 1;
    *totalLivros = 1;
    strcpy(Biblioteca[1].nome, "Análise Real");
    strcpy(Biblioteca[1].autor, "Walter Rudin");
    strcpy(Biblioteca[1].editora, "McGraw-Hill");
    Biblioteca[1].edicao = 3;
    Biblioteca[1].disponivel = 1;
    *totalLivros = 2;
    strcpy(Biblioteca[2].nome, "Álgebra Linear e Suas Aplicações");
    strcpy(Biblioteca[2].autor, "David C. Lay");
    strcpy(Biblioteca[2].editora, "Pearson");
    Biblioteca[2].edicao = 5;
    Biblioteca[2].disponivel = 1;
    *totalLivros = 3;
    strcpy(Biblioteca[3].nome, "Introdução à Teoria dos Números");
    strcpy(Biblioteca[3].autor, "Niven, Zuckerman e Montgomery");
    strcpy(Biblioteca[3].editora, "John Wiley & Sons");
    Biblioteca[3].edicao = 5;
    Biblioteca[3].disponivel = 1;
    *totalLivros = 4;

}