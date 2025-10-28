# DGT1335 - Estrutura de Dados

Repositório da disciplina de Estrutura de Dados do curso de Ciência da Computação da Estácio.

## 📁 Estrutura do Repositório

O repositório está organizado da seguinte forma:

```
estrutura-de-dados/
├── .vscode/              # Configurações do VSCode
│   ├── c_cpp_properties.json
│   └── tasks.json
├── aulas/               # Material teórico e exemplos das aulas
├── avaliacoes/         # Avaliações e trabalhos
├── desafios/           # Desafios de programação
└── exercicios/         # Exercícios práticos
    ├── Makefile        # Build automation
    ├── exemplo_basico.c
    └── ponteiros/      # Exemplos de ponteiros

```

## 🛠️ Como Usar

### Pré-requisitos
- GCC (GNU Compiler Collection)
- Make
- VSCode (opcional, mas recomendado)
- Valgrind (opcional, para análise de memória)

### Compilação

#### Para compilar exercícios:
```bash
cd exercicios/
make all                # Compila todos os arquivos .c no diretório
make run               # Compila e executa todos os programas
make clean             # Limpa arquivos compilados
make all-recursive     # Compila todos os subdiretórios incluindo ponteiros/
```

### Usando no VSCode

Este repositório está configurado para trabalhar perfeitamente com o VSCode (tanto online no GitHub Codespaces quanto localmente):

1. **Intellisense**: Configurado para C99 com caminhos de include apropriados
2. **Tasks integradas**: Use `Ctrl+Shift+P` → "Tasks: Run Task" para:
   - Build C Project
   - Run C Program  
   - Clean C Project
   - Build All C Projects
   - Debug with Valgrind (Ponteiros)

3. **Compilação rápida**: `Ctrl+Shift+B` para build rápido

## 📚 Organização do Código

- **aulas/**: Material teórico, slides e exemplos das aulas
- **avaliacoes/**: Provas, trabalhos e projetos avaliativos
- **desafios/**: Desafios de programação para prática extra
- **exercicios/**: Exercícios práticos, incluindo:
  - Exemplos básicos em C
  - Ponteiros e alocação de memória
  - Implementações de estruturas de dados
  
## 🔧 Funcionalidades do Makefile

### Makefile dos Exercícios
- Compilação automática de todos os .c no diretório
- Organização em diretórios obj/ e bin/
- Compilação recursiva de subdiretórios
- Flags de compilação padrão: `-Wall -Wextra -std=c99 -g -O0`
- Flags adicionais para ponteiros quando necessário
- Suporte para Valgrind e debug com AddressSanitizer

## 📝 Tópicos da Disciplina

1. Introdução e Conceitos Básicos
   - Tipos abstratos de dados
   - Análise de complexidade
   - Ponteiros e alocação de memória

2. Estruturas de Dados Básicas
   - Arrays e strings
   - Listas encadeadas
   - Pilhas e filas

3. Estruturas de Dados Avançadas
   - Árvores
   - Tabelas hash
   - Grafos

4. Algoritmos de Ordenação e Busca
   - Bubble Sort, Selection Sort, Insertion Sort
   - Quick Sort, Merge Sort
   - Busca linear e binária
