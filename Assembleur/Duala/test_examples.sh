#!/bin/bash

# Vérifier que le compilateur existe
if [ ! -f "compilateur" ]; then
    echo "Erreur: Le compilateur n'a pas été trouvé. Exécutez 'make' d'abord."
    exit 1
fi

# Créer un répertoire pour les résultats
TEST_DIR="test_results"
rm -rf "$TEST_DIR"
mkdir -p "$TEST_DIR"

# Fonction pour compiler et exécuter un exemple
test_example() {
    local example=$1
    local base_name=$(basename "$example" .du)
    local asm_file="$TEST_DIR/$base_name.asm"
    local obj_file="$TEST_DIR/$base_name.o"
    local exe_file="$TEST_DIR/$base_name"
    
    echo "\n=== Test de $example ==="
    
    # Étape 1: Compilation Duala vers assembleur
    echo "1. Compilation de $example..."
    if ! ./compilateur < "$example" > /dev/null 2>&1; then
        echo "❌ Échec de la compilation de $example"
        return 1
    fi
    
    # Déplacer le fichier généré
    mv programme.asm "$asm_file"
    
    # Étape 2: Assemblage
    echo "2. Assemblage de $asm_file..."
    if ! nasm -f elf32 -o "$obj_file" "$asm_file"; then
        echo "❌ Échec de l'assemblage de $asm_file"
        return 1
    fi
    
    # Étape 3: Édition des liens
    echo "3. Édition des liens pour $obj_file..."
    if ! gcc -m32 -o "$exe_file" "$obj_file" -no-pie 2>/dev/null; then
        # Essayer avec l'alternative
        echo "  - Tentative avec l'alternative d'édition de liens..."
        if ! ld -m elf_i386 -o "$exe_file" "$obj_file" -lc --dynamic-linker=/lib/ld-linux.so.2 2>/dev/null; then
            echo "❌ Échec de l'édition des liens pour $obj_file"
            return 1
        fi
    fi
    
    # Étape 4: Exécution
    echo "4. Exécution de $exe_file..."
    echo "--- Sortie ---"
    "$exe_file"
    local exit_code=$?
    echo "--- Fin de sortie ---"
    
    if [ $exit_code -eq 0 ]; then
        echo "✅ $example a été exécuté avec succès"
        return 0
    else
        echo "❌ $example a échoué avec le code de sortie $exit_code"
        return 1
    fi
}

# Tester tous les exemples
echo "Début des tests des exemples Duala"
echo "================================"

for example in example_programs/*.du; do
    test_example "$example"
    echo ""
done

echo "Tests terminés. Consultez les fichiers dans le répertoire $TEST_DIR pour plus de détails."
