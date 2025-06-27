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


run: compilateur	
	./compilateur < $(fichier)
	gcc -o output programme.c
	./output

# Test simple
test_simple: compilateur
	@echo "🇫🇷 === TEST SIMPLE ==="
	@echo "📝 Programme:"
	@cat $(FOLDER)/test_simple.fr
	@echo ""
	@echo "🔧 Compilation français → C:"
	./compilateur < $(FOLDER)/test_simple.fr
	@echo ""
	@echo "📝 Code C généré:"
	@cat programme.c
	@echo ""
	@echo "🔧 Compilation C → exécutable:"
	gcc -o test_exe programme.c
	@echo "✅ Exécutable créé: test_exe"
	@echo ""
	@echo "🚀 Exécution:"
	./test_exe

# Test avec entrées
test_interactif: compilateur
	@echo "🇫🇷 === TEST INTERACTIF ==="
	@echo "📝 Programme:"
	@cat $(FOLDER)/test_lecture.fr
	@echo ""
	@echo "🔧 Compilation français → C:"
	./compilateur < $(FOLDER)/test_lecture.fr
	@echo ""
	@echo "🔧 Compilation C → exécutable:"
	gcc -o test_interactif_exe programme.c
	@echo "✅ Exécutable créé"
	@echo ""
	@echo "🚀 Exécution (entrez des nombres quand demandé):"
	./test_interactif_exe

# Test avec toutes les fonctionnalités
test_complet: compilateur
	@echo "=== TEST COMPLET ==="
	@echo "Programme:"
	@cat $(FOLDER)/test_complet.fr
	@echo ""
	@echo "Compilation français → C:"
	./compilateur < $(FOLDER)/test_complet.fr
	@echo ""
	@echo "Code C généré:"
	@cat programme.c
	@echo ""
	@echo "Compilation C → exécutable:"
	gcc -o test_complet_exe programme.c
	@echo "Exécutable créé"
	@echo ""
	@echo "Exécution:"
	./test_complet_exe

clean:
	rm -f duala.lex.c duala.tab.c duala.h duala.output
	rm -f compilateur programme.c output
	rm -f test_exe test_interactif_exe test_complet_exe

.PHONY: all test_simple test_interactif test_complet clean