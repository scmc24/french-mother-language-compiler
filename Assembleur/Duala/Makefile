CC = gcc
FLEX = flex
BISON = bison
# Dossier contenant les programmes d'exemple
FOLDER = example_programs

all: compilateur

compilateur: duala.tab.c duala.lex.c
	$(CC) -o compilateur duala.lex.c duala.tab.c -lfl

duala.tab.c duala.h: duala.y
	$(BISON) --defines=duala.h -o duala.tab.c duala.y

duala.lex.c: duala.lex duala.h
	$(FLEX) -o duala.lex.c duala.lex

test: compilateur
	@echo "=== Test du compilateur assembleur Duala ==="
	@echo "Contenu de test_avance.du:"
	@cat $(FOLDER)/test_avance.du
	@echo ""
	@echo "=== Compilation ==="
	./compilateur < $(FOLDER)/test_avance.du
	@echo ""
	@echo "=== Code assembleur genere ==="
	@if [ -f programme.asm ]; then cat programme.asm; else echo "Pas de fichier asm genere"; fi

clean:
	rm -f duala.lex.c duala.tab.c duala.h
	rm -f compilateur programme.asm
	rm -f duala.output

.PHONY: all test clean
