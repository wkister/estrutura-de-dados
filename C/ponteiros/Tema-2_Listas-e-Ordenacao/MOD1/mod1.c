#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_ITENS 10
#define TAM_STRING 50

typedef struct {
  char itens[MAX_ITENS][TAM_STRING];
  int totalItens;
} Mochila;

// Definir a "mochila mágica": uma lista ordenada do tipo Mochila
struct listaMochila {
  char item[TAM_STRING]; // Nome do item na mochila
  struct listaMochila* proximo; // Ponteiro para o próximo nó
};

// Definição do total de itens na mochila mágica
int totalItensMochilaMagica = 0;

// --- Protótipos das Funções Gerais ---
void limparBufferEntrada();
void mostarMenu();

// --- Protótipos das Funções para lista estática ---
void cadastrarItens(Mochila *mochila);
void removerItens(Mochila *mochila, char item[TAM_STRING]);
void listarItens(Mochila mochila);

// -- Protótipos das Funções para lista dinâmica ---
void cadastrarItensMochilaMagica(struct listaMochila** inicio, int *totalItens);
void removerItemInicioMochilaMagica(struct listaMochila** inicio, const char* item, int *totalItens);
void listarItensMochilaMagica(struct listaMochila* inicio, int totalItens);


// --- Função Principal ---
int main(){
  // Definir e inicializar a mochila
  Mochila minhaMochila;
  minhaMochila.totalItens = 0;

  // Definindo e inicializando a mochila mágica
  struct listaMochila* mochilaMagica;
  mochilaMagica = (struct listaMochila*) malloc(sizeof(struct listaMochila));

  // Verificar se a alocação foi bem sucedida
  if (mochilaMagica == NULL){
    printf("Erro na alocação de memória.\n");
    return 1;
  }
  // mochilaMagica->proximo = NULL; // Inicializa o próximo como NULL

  // Variável para armazenar a opção do menu
  int opcao = 0;

  // Loop do menu
  do {
    mostarMenu();

    scanf("%d", &opcao);
    limparBufferEntrada();

    switch (opcao) {
      case 1:
        cadastrarItens(&minhaMochila);
        break;
      case 2: {
        char item[TAM_STRING];
        printf("Digite o nome do item a ser removido: ");
        fgets(item, TAM_STRING, stdin);
        item[strcspn(item, "\n")] = 0; // Remover o caractere de nova linha

        removerItens(&minhaMochila, item);
        break;
      }
      case 3:
        listarItens(minhaMochila);
        break;
      case 4: {
        cadastrarItensMochilaMagica(&mochilaMagica, &totalItensMochilaMagica);
        break;
      }
      // case 5: {
      //   removerItemInicioMochilaMagica(&mochilaMagica, &totalItensMochilaMagica);
      //   break;
      // }
      case 6:
        listarItensMochilaMagica(mochilaMagica, totalItensMochilaMagica);
        break;
      case 0:
        printf("Liberando memória da mochila mágica...\n");
        free(mochilaMagica);
        printf("Saindo do programa.\n");
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
        break;
    }
  } while (opcao != 0);
  return 0;
}

// --- Funções Gerais ---
/**
 * @brief Função para mosntrar o menu de opções *
 */
void mostarMenu(){
  printf("\n--- MENU ---\n");
  printf("1. Cadastrar itens na mochila\n");
  printf("2. Remover itens da mochila\n");
  printf("3. Listar itens da mochila\n");
  printf("4. Cadastrar itens na mochila mágica\n");
  printf("5. Remover itens da mochila mágica\n");
  printf("6. Listar itens da mochila mágica\n");
  printf("0. Sair\n");
  printf("Escolha uma opção: ");
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
 * @brief Funçãoa para cadastrar os itens na mochila
 * @param mochila Ponteiro para a estrutura da mochila
*/
void cadastrarItens(Mochila *mochila){
  // Variável para armazenar o nome do item
  char item[TAM_STRING];

  // Imprimir o endereço da mochila
  printf("Endereço da mochila: %p\n", (void*)mochila);
  // Testar se a mochila está cheia
  if (mochila->totalItens >= MAX_ITENS){
    printf("A mochila está cheia. Não é possível adicionar mais itens.\n");
  } else {
    // Loop para adicionar um item, parando quando entrar um item vazio
    do {
      // Solicitar o nome do item
      printf("Digite o nome do item a ser adicionado na mochila (ou pressione Enter para sair): ");
      fgets(item, TAM_STRING, stdin);
      // Remover o caractere de nova linha, se presente
      item[strcspn(item, "\n")] = 0;
      // Copiar o item para a mochila se o item não estiver vazio
      if (strlen(item) > 0){
        strcpy(mochila->itens[mochila->totalItens], item);
        mochila->totalItens++;
        printf("Item adicionado com sucesso!\n");
      }
    } while (mochila->totalItens < MAX_ITENS && strlen(item) > 0);

    if (mochila->totalItens == MAX_ITENS){
      printf("A mochila está cheia. Não é possível adicionar mais itens.\n");
    }
  }
}

/**
 * @brief Função para listar os itens da mochila
 * @param mochila estrutura tipo mochila
*/
void listarItens(Mochila mochila){
  if (mochila.totalItens == 0){
    printf("A mochila está vazia.\n");
  } else {
    printf("Itens na mochila:\n");
    for (int i = 0; i < mochila.totalItens; i++){
      printf("%d. %s\n", i + 1, mochila.itens[i]);
    }
  }
}

/**
 * @brief Função para remover itens da mochila
 * @param mochila Ponteiro para a estrutura da mochila
*/
void removerItens(Mochila *mochila, char item[TAM_STRING]){
  for (int i = 0; i < mochila->totalItens; i++){
    if (strcmp(mochila->itens[i], item) == 0){
      // Item encontrado, remover deslocando os itens seguintes
      for (int j = i; j < mochila->totalItens - 1; j++){
        strcpy(mochila->itens[j], mochila->itens[j + 1]);
      }
      // Apaganado o último item duplicado
      mochila->itens[mochila->totalItens - 1][0] = '\0';
      // Decrementar o total de itens
      mochila->totalItens--;
      printf("Item '%s' removido com sucesso!\n", item);
      return;
    }
  }
  printf("Item '%s' não encontrado na mochila.\n", item);
}

/**
 * @brief Função para cadastras um item na mochila mágica (lista dinâmica)
 * @param inicio Ponteiro duplo para o início da lista
 * @param item Nome do item a ser adicionado
 */
void cadastrarItensMochilaMagica(struct listaMochila** inicio, int *totalItens){
  char item[TAM_STRING];
  if (*totalItens >= MAX_ITENS){
    printf("A mochila mágica está cheia. Não é possível adicionar mais itens.\n");
  } else {
    // Loop para adicionar itens, parando quando entrar um item vazio
    do {
      // Solicitar o nome do item
      printf("Digite o nome do item a ser adicionado na mochila mágica (ou pressione Enter para sair): ");
      fgets(item, TAM_STRING, stdin);
      // Remover o caractere de nova linha, se presente
      item[strcspn(item, "\n")] = 0;
      // Verificar se o item não está vazio
      if (strlen(item) > 0){
        // Se for o primeiro item, adicionar diretamente em inicio
        if (*totalItens == 0){
          strcpy((*inicio)->item, item);
          (*totalItens)++;
          printf("Item '%s' adicionado com sucesso na mochila mágica!\n", item);
          continue; // Pular para a próxima iteração do loop
        } else {
          // Criar um novo nó
          struct listaMochila* novoNo = (struct listaMochila*) malloc(sizeof(struct listaMochila));
          if (novoNo == NULL){
            printf("Erro na alocação de memória.\n");
            return;
          }
          strcpy(novoNo->item, item);
          novoNo->proximo = NULL;

          // Inserir o novo nó na lista ordenada
          if (*inicio == NULL || strcmp((*inicio)->item, item) > 0){
            // Inserir no início
            novoNo->proximo = *inicio;
            *inicio = novoNo;
          } else {
            // Inserir em outra posição
            struct listaMochila* atual = *inicio;
            while (atual->proximo != NULL && strcmp(atual->proximo->item, item) < 0){
              atual = atual->proximo;
            }
            novoNo->proximo = atual->proximo;
            atual->proximo = novoNo;
          }
          (*totalItens)++;
          printf("Item '%s' adicionado com sucesso na mochila mágica!\n", item);
        }
      }
    } while (strlen(item) > 0);
  }

}

/**
 * @brief Função para remover um item da mochila mágica (lista dinâmica)
 * @param inicio Ponteiro duplo para o início da lista
 * @param item Nome do item a ser removido
 */
void removerItemInicioMochilaMagica(struct listaMochila** inicio, const char* item, int *totalItens){
  struct listaMochila* atual = *inicio;
  *inicio = (*inicio)->proximo;
  free(atual);
  (*totalItens)--;
}

/**
 * @brief Função para listar os itens da mochila mágica (lista dinâmica)
 * @param inicio Ponteiro para o início da lista
 */
void listarItensMochilaMagica(struct listaMochila* inicio, int totalItens){
  struct listaMochila *atual = inicio;
  int indice = 1;
  printf("\nItens na mochila mágica:\n");
  while (atual != NULL){
    printf("%d. %s\n", indice, atual->item);
    atual = atual->proximo;
    indice++;
  }
}
