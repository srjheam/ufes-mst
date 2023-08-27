# stolen from
#  - https://github.com/srjheam/ufes-csci/blob/dbc4c0b9e87dde27a2be233daf57db55fec9d9b4/csci/dsa/Makefile

# Makefile que percorre toda a biblioteca, procurando os códigos fontes .c para compilar

# INCLUDE   - é o diretório que contém os headers
# BUILDIR   - é o diretório onde estarão os binários
# LIBNAME   - nome base da biblioteca do projeto
# LIBTARGET - é o caminho para a biblioteca compilada
# SRCS      - lista com os caminhos para todos .c
# OBJS      - lista com os caminhos para todos .o
INCLUDE = include
BUILDIR = build
LIBNAME = tsp
LIBTARGET = lib$(LIBNAME).a
SRCS = $(shell find . -type f -name '*.c' | sed 's|^./||')
OBJS = $(patsubst %.c, $(BUILDIR)/%.o, $(notdir $(SRCS)))

# CCompiler - é o compilador usado
# CFLAGS - são as flags dadas ao compilador durante a compilação
CC = gcc
override CFLAGS += -Wall -Wextra -pedantic -I $(INCLUDE) -lm -O3

# ARchive - é o comando arquivador da biblioteca
# ARFLAGS - são as flags dadas ao arquivador
AR = ar
ARFLAGS = rcs

# vpath diretiva que adiciona todos os diretórios com códigos fontes para busca com o padrão %.c
#   - https://www.gnu.org/software/make/manual/html_node/Selective-Search.html
#   - não me pergunte mais nada, eu não sei como funciona
vpath %.c $(shell dirname $(SRCS) | uniq)

all : pre-build build

debug:
    CFLAGS -= -O3
	CFLAGS += -ggdb3

debug: pre-build build

# Compila todos os .o
$(BUILDIR)/%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

# Preparativos para o build; Garante que o diretório build/ existe
pre-build:
	mkdir -p $(BUILDIR)/

build : $(OBJS)
	$(AR) $(ARFLAGS) $(LIBTARGET) $^

# Rode make clean para remover tudo que é gerado pela build
clean:
	rm -rf $(BUILDIR)/ $(LIBTARGET)
