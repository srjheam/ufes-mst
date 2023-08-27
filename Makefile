# Esse Makefile é apenas um wrapper para cumprir com as especificações do trabalho.

MAKE = make

OUTRELEASEPATH = src/build/release/main

all: release

release:
	$(MAKE) -C src/
	cp -f $(OUTRELEASEPATH) ./trab1

clean:
	$(MAKE) -C src/ clean

valgrind:
	$(MAKE) -C src/ valgrind
