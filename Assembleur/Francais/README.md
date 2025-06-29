# Compilateur Français vers Assembleur

## Vue d'ensemble
Ce compilateur traduit des programmes écrits en français vers du code assembleur x86 32-bit. Il utilise Flex pour l'analyse lexicale et Bison pour l'analyse syntaxique.

## Prérequis
- `gcc` (compilateur C avec support 32-bit)
- `flex` (générateur d'analyseur lexical)
- `bison` (générateur d'analyseur syntaxique)
- `nasm` (assembleur pour x86)
- `gcc-multilib` (support 32-bit pour gcc)
- `libc6-dev-i386` (bibliothèques 32-bit)

## Installation des prérequis (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install gcc flex bison nasm build-essential gcc-multilib libc6-dev-i386
```

## Compilation du compilateur
```bash
make
```
Cette commande génère l'exécutable `compilateur`.

## Utilisation

### 1. Compilation d'un programme français
```bash
./compilateur < mon_programme.fr
```
Cette commande génère un fichier `programme.asm` contenant le code assembleur.

### 2. Assemblage et édition de liens

**IMPORTANT** : Ce compilateur génère uniquement du code assembleur 32-bit. Vous devez utiliser les outils 32-bit.

#### Méthode recommandée (avec gcc)
```bash
nasm -f elf32 -o programme.o programme.asm
gcc -m32 -o programme programme.o -no-pie
```

#### Méthode alternative (avec ld)
```bash
nasm -f elf32 -o programme.o programme.asm
ld -m elf_i386 -o programme programme.o -lc --dynamic-linker=/lib/ld-linux.so.2
```

### 3. Exécution du programme
```bash
./programme
```

### Commande complète (compilation + assemblage + exécution)
```bash
make run
```

## Test du compilateur
```bash
make test
```
Cette commande teste le compilateur avec un programme d'exemple.

## Structure d'un programme français

### Syntaxe de base
```
debut
    entier variable;
    lire variable;
    ecrire variable;
fin
```

### Mots-clés supportés
- **Structure** : `debut`, `fin`
- **Types** : `entier`
- **E/S** : `lire`, `ecrire`
- **Conditions** : `si`, `alors`, `sinon`, `finsi`
- **Boucles** : `tant_que`, `faire`, `fintant`, `pour`, `de`, `a`, `finpour`, `repeter`, `jusqua`
- **Switch** : `selon`, `cas`, `defaut`, `finselon`, `sortir`
- **Opérateurs** : `<-`, `+`, `-`, `*`, `/`, `%`, `==`, `!=`, `>`, `<`, `>=`, `<=`

### Exemples de programmes
Consultez le dossier `example_programs/` pour des exemples complets :
- `01_addition.fr` - Addition de deux nombres
- `02_soustraction.fr` - Soustraction de deux nombres
- `09_boucle_tant_que.fr` - Boucle while
- `10_boucle_pour.fr` - Boucle for
- `12_structure_selon.fr` - Structure switch-case

## Code assembleur généré
Le compilateur génère du code assembleur x86 32-bit avec :
- Section `.data` pour les variables
- Section `.text` pour le code
- Appels système Linux pour les E/S
- Gestion de la pile pour les variables locales

## Nettoyage
```bash
make clean
```
Supprime les fichiers générés lors de la compilation.

## Dépannage

### Erreur "command not found"
Vérifiez que tous les prérequis sont installés.

### Erreur lors de l'édition de liens

#### Erreur "instruction not supported in 64-bit mode"
Cette erreur indique que vous essayez d'assembler du code 32-bit en mode 64-bit. **Solution** :
```bash
nasm -f elf32 -o programme.o programme.asm
gcc -m32 -o programme programme.o -no-pie
```

#### Erreur "ne peut pas trouver -lc" ou "incompatible"
Cela indique que les bibliothèques 32-bit ne sont pas installées. **Solution** :
```bash
sudo apt-get install libc6-dev-i386 gcc-multilib
nasm -f elf32 -o programme.o programme.asm
gcc -m32 -o programme programme.o -no-pie
```

### Programme ne s'exécute pas
Vérifiez les permissions d'exécution :
```bash
chmod +x programme
```
