# stolen from
#  - ../tsplib/Makefile

# Makefile que percorre toda a biblioteca, procurando os códigos fontes .c para compilar

# INCLUDE   - é o diretório que contém os headers
# BUILDIR   - é o diretório onde estarão os binários
# LIBNAME   - nome base da biblioteca do projeto
# LIBTARGET - é o caminho para a biblioteca compilada
# SRCS      - lista com os caminhos para todos .c
INCLUDE = include
BUILDIR = build
DEBUGDIR = $(BUILDIR)/debug
RELEASEDIR = $(BUILDIR)/release
LIBNAME = tour
LIBTARGET = lib$(LIBNAME).a
SRCS = $(shell find . -type f -name '*.c' | sed 's|^./||')

# OBJS_DEBUG   - lista com os caminhos para todos .o
# OBJS_RELEASE - lista com os caminhos para todos .o
OBJSDEBUG = $(patsubst %.c, $(BUILDIR)/debug/%.o, $(notdir $(SRCS)))
OBJSRELEASE = $(patsubst %.c, $(BUILDIR)/release/%.o, $(notdir $(SRCS)))

LIBTSPDIR       = ../tsplib
LIBTSP          = tsp
LIBTSPDIRRELEASE = $(LIBTSPDIR)/build/release
LIBTSPDIRDEBUG   = $(LIBTSPDIR)/build/debug

LIBCONTAINERSDIR       = ../containerslib
LIBCONTAINERS          = containers
LIBCONTAINERSDIRRELEASE = $(LIBTSPDIR)/build/release
LIBCONTAINERSDIRDEBUG   = $(LIBTSPDIR)/build/debug

# CCompiler - é o compilador usado
# CFLAGS - são as flags dadas ao compilador durante a compilação
CC = gcc
override CFLAGS += -Wall -Wextra -g -I $(INCLUDE) -I $(LIBTSPDIR)/include -I $(LIBCONTAINERSDIR)/include -lm

DEBUGFLAGS = -ggdb3 -O0 -DDEBUG
RELEASEFLAGS = -O3 -DNDEBUG

# ARchive - é o comando arquivador da biblioteca
# ARFLAGS - são as flags dadas ao arquivador
AR = ar
ARFLAGS = rcs

# vpath diretiva que adiciona todos os diretórios com códigos fontes para busca com o padrão %.c
#   - https://www.gnu.org/software/make/manual/html_node/Selective-Search.html
#   - não me pergunte mais nada, eu não sei como funciona
vpath %.c $(shell dirname $(SRCS) | uniq)

all : release

release : pre-build-release build-release

debug: pre-build-debug build-debug

# Compila todos os .o
$(BUILDIR)/release/%.o : %.c
	$(CC) -o $@ -c $< -L $(LIBTSPDIRRELEASE) -l$(LIBTSP) -L $(LIBCONTAINERSDIRRELEASE) -l$(LIBCONTAINERS) $(CFLAGS) $(RELEASEFLAGS)

$(BUILDIR)/debug/%.o : %.c
	$(CC) -o $@ -c $< -L $(LIBTSPDIRDEBUG) -l$(LIBTSP) -L $(LIBCONTAINERSDIRRELEASE) -l$(LIBCONTAINERS) $(CFLAGS) $(DEBUGFLAGS)

# Preparativos para o build; Garante que o diretório build/ existe
pre-build:
	mkdir -p $(BUILDIR)/

pre-build-release: pre-build
	mkdir -p $(RELEASEDIR)/
	$(MAKE) -C $(LIBTSPDIR)/
	$(MAKE) -C $(LIBCONTAINERSDIR)/

pre-build-debug: pre-build
	mkdir -p $(DEBUGDIR)/
	$(MAKE) -C $(LIBTSPDIR)/ debug
	$(MAKE) -C $(LIBCONTAINERSDIR)/ debug

build-release : $(OBJSRELEASE)
	$(AR) $(ARFLAGS) $(RELEASEDIR)/$(LIBTARGET) $^

build-debug : $(OBJSDEBUG)
	$(AR) $(ARFLAGS) $(DEBUGDIR)/$(LIBTARGET) $^

# Rode make clean para remover tudo que é gerado pela build
clean:
	rm -rf $(BUILDIR)/
