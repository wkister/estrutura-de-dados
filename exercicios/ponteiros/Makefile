# Makefile para exemplos de Ponteiros - Estrutura de Dados
# Compilador e flags específicas para ponteiros
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O0 -Wpointer-arith -Wcast-align
LDFLAGS =


# Diretórios
SRCDIR = .
OBJDIR = obj
BINDIR = bin

# Encontra todos os arquivos .c recursivamente
SOURCES = $(shell find $(SRCDIR) -name '*.c')
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES:./%=%))
TARGETS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%,$(SOURCES:./%=%))


# Permite compilar um arquivo específico: make file=exemplo.c


ifeq ($(file),)
all: dirs $(TARGETS)
else
# Permite compilar arquivo em subpasta, ex: make file=Tema-2_Listas-e-Ordenacao/MOD1/mod1.c
FILE_PATH = $(file)
FILE_NAME = $(notdir $(FILE_PATH))
FILE_BASE = $(basename $(FILE_NAME))
FILE_OBJ = $(OBJDIR)/$(FILE_BASE).o
FILE_BIN = $(BINDIR)/$(FILE_BASE)
all: dirs $(FILE_BIN)
$(FILE_BIN): $(FILE_PATH)
	@mkdir -p $(dir $(FILE_OBJ))
	@mkdir -p $(dir $(FILE_BIN))
	$(CC) $(CFLAGS) -c $(FILE_PATH) -o $(FILE_OBJ)
	$(CC) $(LDFLAGS) $(FILE_OBJ) -o $(FILE_BIN)
endif

# Cria diretórios necessários
dirs:
	@mkdir -p $(OBJDIR) $(BINDIR)



# Regra para compilar objetos de arquivos em subpastas
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@



# Regra para criar executáveis de objetos em subpastas
$(BINDIR)/%: $(OBJDIR)/%.o
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $< -o $@

# Limpa arquivos compilados
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Executa todos os programas compilados
run: all
	@for exe in $(BINDIR)/*; do \
		if [ -x "$$exe" ]; then \
			echo "=== Executando $$exe ==="; \
			"$$exe"; \
			echo; \
		fi \
	done

# Executa com valgrind para verificar vazamentos de memória
valgrind: all
	@for exe in $(BINDIR)/*; do \
		if [ -x "$$exe" ]; then \
			echo "=== Verificando $$exe com valgrind ==="; \
			valgrind --leak-check=full --show-leak-kinds=all "$$exe"; \
			echo; \
		fi \
	done

# Compila com debugging extra para ponteiros
debug: CFLAGS += -DDEBUG -fsanitize=address -fno-omit-frame-pointer
debug: LDFLAGS += -fsanitize=address
debug: clean all

.PHONY: all dirs clean run valgrind debug