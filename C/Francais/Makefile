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
	rm -f francais.lex.c francais.tab.c francais.h francais.output
	rm -f compilateur programme.c output
	rm -f test_exe test_interactif_exe test_complet_exe

.PHONY: all test_simple test_interactif test_complet clean