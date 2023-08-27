# Esse Makefile é apenas um wrapper para cumprir com as especificações do trabalho.

MAKE = make

OUTRELEASEPATH = src/build/release/main

all: release

release:
	$(MAKE) -C src/
	cp -f $(OUTRELEASEPATH) ./trab1

clean:
	$(MAKE) -C src/ clean
	rm -f trab1
	rm -f valgrind-out.txt

valgrind:
	$(MAKE) -C src/ valgrind
	cp -f src/valgrind-out.txt ./valgrind-out.txt
