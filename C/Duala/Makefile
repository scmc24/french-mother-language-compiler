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
	@echo "🇨🇲 === TEST SIMPLE DUALA ==="
	@echo "📝 Programme:"
	@cat $(FOLDER)/test_simple.du
	@echo ""
	@echo "🔧 Compilation duala → C:"
	./compilateur < $(FOLDER)/test_simple.du
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
	@echo "🇨🇲 === TEST INTERACTIF DUALA ==="
	@echo "📝 Programme:"
	@cat $(FOLDER)/test_lecture.du
	@echo ""
	@echo "🔧 Compilation duala → C:"
	./compilateur < $(FOLDER)/test_lecture.du
	@echo ""
	@echo "📝 Code C généré:"
	@cat programme.c
	@echo ""
	@echo "🔧 Compilation C → exécutable:"
	gcc -o test_exe programme.c
	@echo "✅ Exécutable créé: test_exe"
	@echo ""
	@echo "🚀 Exécution (entrez des valeurs quand demandé):"
	./test_exe

# Test avancé
test_avance: compilateur
	@echo "🇨🇲 === TEST AVANCÉ DUALA ==="
	@echo "📝 Programme:"
	@cat $(FOLDER)/test_avance.du
	@echo ""
	@echo "🔧 Compilation duala → C:"
	./compilateur < $(FOLDER)/test_avance.du
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

clean:
	rm -f duala.lex.c duala.tab.c duala.h
	rm -f compilateur programme.c test_exe
	rm -f duala.output

.PHONY: all run test_simple test_interactif test_avance clean
