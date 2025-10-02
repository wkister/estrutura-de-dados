/**
 * @file funcoes.c
 * @brief Implementação das funções utilizadas nos projetos de estrutura de dados
 */

#include <stdio.h>
#include "funcoes.h"

 /**
  * @brief Função para limpar o buffer de entrada
  */
void limparBufferEntrada(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}