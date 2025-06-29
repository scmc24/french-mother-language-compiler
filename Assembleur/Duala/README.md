# Compilateur Duala vers Assembleur

## Vue d'ensemble
Ce compilateur traduit des programmes écrits en langue **Duala** (langue camerounaise) vers du code assembleur x86 32-bit. Il utilise Flex pour l'analyse lexicale et Bison pour l'analyse syntaxique.

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

### 1. Compilation d'un programme Duala
```bash
./compilateur < mon_programme.du
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

## Structure d'un programme Duala

### Syntaxe de base
```
mbɔmbɔ
    ndambo variable;
    yɛnɛ variable;
    kɔma variable;
suka
```

### Mots-clés Duala supportés

| Duala | Français | Signification |
|-------|----------|---------------|
| `mbɔmbɔ` | `debut` | début/commencement |
| `suka` | `fin` | fin/terminaison |
| `ndambo` | `entier` | nombre/entier |
| `yɛnɛ` | `lire` | lire/prendre |
| `kɔma` | `ecrire` | écrire/dire |
| `sɔ` | `si` | si/condition |
| `tɛ` | `alors` | alors/donc |
| `kɛma` | `sinon` | sinon/autrement |
| `sukasi` | `finsi` | fin si |
| `mbɛlɛ` | `tant_que` | tant que/aussi longtemps que |
| `sala` | `faire` | faire/fabriquer |
| `sukambɛlɛ` | `fintant` | fin tant que |
| `pɔ` | `pour` | pour |
| `na` | `de` | de/depuis |
| `tɛ` | `a` | à/vers |
| `sukapɔ` | `finpour` | fin pour |
| `sɔŋɔlɔ` | `repeter` | répéter/refaire |
| `tɛmbɛlɛ` | `jusqua` | jusqu'à/tant que |
| `ndɔŋ` | `selon` | selon/suivant |
| `kɛs` | `cas` | cas/situation |
| `bɔsɔ` | `defaut` | défaut/normal |
| `sukandɔŋ` | `finselon` | fin selon |
| `bima` | `sortir` | sortir/partir |

### Opérateurs
Les opérateurs restent identiques : `<-`, `+`, `-`, `*`, `/`, `%`, `==`, `!=`, `>`, `<`, `>=`, `<=`

### Exemples de programmes
Consultez le dossier `example_programs/` pour des exemples complets :
- `01_addition.du` - Addition de deux nombres
- `02_soustraction.du` - Soustraction de deux nombres
- `09_boucle_tant_que.du` - Boucle mbɛlɛ (while)
- `10_boucle_pour.du` - Boucle pɔ (for)
- `12_structure_selon.du` - Structure ndɔŋ (switch-case)

### Exemple complet
```duala
mbɔmbɔ
    ndambo a;
    ndambo b;
    ndambo resultat;
    
    yɛnɛ a;
    yɛnɛ b;
    
    sɔ (a > b) tɛ
        resultat <- a + b;
        kɔma "Somme des nombres";
        kɔma resultat;
    kɛma
        resultat <- a - b;
        kɔma "Difference des nombres";
        kɔma resultat;
    sukasi
suka
```

## Code assembleur généré
Le compilateur génère du code assembleur x86 32-bit avec :
- Section `.data` pour les variables
- Section `.text` pour le code
- Appels système Linux pour les E/S
- Gestion de la pile pour les variables locales
- Messages en français et duala dans les commentaires

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

### Caractères Duala non affichés
Assurez-vous que votre terminal supporte l'UTF-8 :
```bash
export LANG=fr_FR.UTF-8
```

## À propos de la langue Duala
Le Duala est une langue bantoue parlée principalement au Cameroun. Ce compilateur permet de programmer dans cette langue tout en générant du code assembleur efficace.
