CC = gcc
FLEX = flex
BISON = bison
# Dossier contenant les programmes d'exemple
FOLDER = example_programs

all: compilateur

compilateur: francais.tab.c francais.lex.c
	$(CC) -o compilateur francais.lex.c francais.tab.c -lfl

francais.tab.c francais.h: francais.y
	$(BISON) --defines=francais.h -o francais.tab.c francais.y

francais.lex.c: francais.lex francais.h
	$(FLEX) -o francais.lex.c francais.lex

run: compilateur
	nasm -f elf -o programme.o programme.asm
	ld -s -o programme programme.o -melf_i386 -I/lib/ld-linux.so.2 -lc
	./programme

test: compilateur
	@echo "=== Test du compilateur assembleur ==="
	@echo "Contenu de test_avance.fr:"
	@cat $(FOLDER)/test_avance.fr
	@echo ""
	@echo "=== Compilation ==="
	./compilateur < $(FOLDER)/test_avance.fr
	@echo ""
	@echo "=== Code assembleur genere ==="
	@if [ -f programme.asm ]; then cat programme.asm; else echo "Pas de fichier asm genere"; fi

clean:
	rm -f francais.lex.c francais.tab.c francais.h
	rm -f compilateur programme.asm programme.o programme
	rm -f francais.output

.PHONY: all test clean