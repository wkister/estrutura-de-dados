# Makefile para projetos C - Estrutura de Dados
# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O0
LDFLAGS = 

# Diretórios
SRCDIR = .
OBJDIR = obj
BINDIR = bin

# Encontra todos os arquivos .c no diretório atual (não recursivo)
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGETS = $(SOURCES:$(SRCDIR)/%.c=$(BINDIR)/%)

# Regra padrão
all: dirs $(TARGETS)

# Cria diretórios necessários
dirs:
	@mkdir -p $(OBJDIR) $(BINDIR)

# Regra para compilar objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para criar executáveis
$(BINDIR)/%: $(OBJDIR)/%.o
	$(CC) $(LDFLAGS) $< -o $@

# Compila subdiretórios
subdirs:
	@for dir in */; do \
		if [ -f "$$dir/Makefile" ]; then \
			echo "Compilando $$dir"; \
			$(MAKE) -C "$$dir"; \
		fi \
	done

# Limpa arquivos compilados
clean:
	rm -rf $(OBJDIR) $(BINDIR)
	@for dir in */; do \
		if [ -f "$$dir/Makefile" ]; then \
			$(MAKE) -C "$$dir" clean; \
		fi \
	done

# Executa todos os programas compilados
run: all
	@for exe in $(BINDIR)/*; do \
		if [ -x "$$exe" ]; then \
			echo "=== Executando $$exe ==="; \
			"$$exe"; \
			echo; \
		fi \
	done

# Compila tudo (incluindo subdiretórios)
all-recursive: all subdirs

.PHONY: all dirs subdirs clean run all-recursive