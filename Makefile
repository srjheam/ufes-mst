GIOVANNI    = giovanni
VALGRINDOUT = valgrind-out.txt

CC = gcc
override CFLAGS += -Wall -Wextra -pedantic -lm

all: build-release

build-release: giovanni.c
	$(CC) -o $(GIOVANNI) $< $(CFLAGS) -O3

build-debug: giovanni.c
	$(CC) -o $(GIOVANNI) $< $(CFLAGS) -ggdb3

valgrind: build-debug
	rm -f $(VALGRINDOUT)

	valgrind --leak-check=full \
			 --show-leak-kinds=all \
			 --track-origins=yes \
			 --verbose \
			 --log-file=$(VALGRINDOUT) \
			 ./$(GIOVANNI) $(VALARGS)

	@echo "Head to $(VALGRINDOUT)"
