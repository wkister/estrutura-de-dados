# estrutura-de-dados
Repositório para compartilhar códigos da disciplina de Estrutura de Dados

## 📁 Estrutura do Repositório

Este repositório está organizado por linguagens de programação, cada uma com sua própria estrutura de pastas e ferramentas de build:

```
estrutura-de-dados/
├── .vscode/              # Configurações do VSCode
│   ├── c_cpp_properties.json
│   └── tasks.json
└── C/                    # Linguagem C
    ├── Makefile          # Build automation para C
    ├── .gitignore        # Ignorar arquivos específicos de C
    └── ponteiros/        # Exemplos de ponteiros
        ├── Makefile      # Build específico para ponteiros
        └── .gitignore    # Ignorar arquivos de ponteiros
```

## 🛠️ Como Usar

### Pré-requisitos
- GCC (GNU Compiler Collection)
- Make
- VSCode (opcional, mas recomendado)
- Valgrind (opcional, para análise de memória)

### Compilação

#### Para projetos em C:
```bash
cd C/
make all                 # Compila todos os arquivos .c no diretório
make run                 # Compila e executa todos os programas
make clean              # Limpa arquivos compilados
make all-recursive      # Compila todos os subdiretórios
```

#### Para exemplos de ponteiros:
```bash
cd C/ponteiros/
make all                # Compila exemplos de ponteiros
make run                # Executa todos os programas
make valgrind           # Executa com verificação de memória
make debug              # Compila com AddressSanitizer
make clean              # Limpa arquivos compilados
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

- **C/**: Contém exemplos gerais em C
- **C/ponteiros/**: Exemplos específicos sobre ponteiros, alocação de memória, etc.

Cada diretório tem seu próprio Makefile otimizado para o tipo de código que contém.

## 🔧 Funcionalidades dos Makefiles

### Makefile Principal (C/)
- Compilação automática de todos os .c no diretório
- Organização em diretórios obj/ e bin/
- Compilação recursiva de subdiretórios
- Flags de compilação: `-Wall -Wextra -std=c99 -g -O0`

### Makefile de Ponteiros (C/ponteiros/)
- Flags adicionais para ponteiros: `-Wpointer-arith -Wcast-align`
- Suporte para Valgrind (detecção de vazamentos de memória)
- Modo debug com AddressSanitizer
- Verificações específicas para trabalho com memória
