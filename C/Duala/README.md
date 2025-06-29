# Compilateur Duala (Duala Language Compiler)

## Table of Contents
1. [Introduction](#introduction)
2. [Prérequis](#prérequis)
3. [Installation](#installation)
4. [Utilisation](#utilisation)
5. [Syntaxe du Langage](#syntaxe-du-langage)
   - [Structure de Base](#structure-de-base)
   - [Variables](#variables)
   - [Entrées/Sorties](#entréessorties)
   - [Structures de Contrôle](#structures-de-contrôle)
6. [Exemples](#exemples)
7. [Dépannage](#dépannage)
8. [Contribution](#contribution)

## Introduction

Le compilateur Duala est un outil qui traduit le langage de programmation Duala en langage C. Le langage Duala utilise des mots-clés inspirés de la langue duala, une langue bantoue parlée au Cameroun.

## Prérequis

- Un système d'exploitation Linux/Unix
- GCC (GNU Compiler Collection)
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- Make

## Installation

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/scm42/french-mother-language-compiler.git
   cd french-mother-language-compiler/C/Duala
   ```

2. Compilez le compilateur :
   ```bash
   make
   ```

## Utilisation

1. Écrivez votre programme dans un fichier avec l'extension `.du` (par exemple, `mon_programme.du`)

2. Compilez et exécutez le programme :
   ```bash
   ./compilateur < mon_programme.du
   gcc -o mon_programme programme.c
   ./mon_programme
   ```

## Syntaxe du Langage

### Structure de Base

```duala
mbɔmbɔ
    // Instructions du programme
suka
```

### Variables

- Déclaration : `ndambo identifiant;`
- Affectation : `identifiant <- valeur;`

### Entrées/Sorties

- Lecture : `yɛnɛ identifiant;`
- Écriture : `kɔma expression;`

### Opérateurs de Comparaison

Les opérateurs de comparaison sont utilisés dans les conditions pour comparer des valeurs :

- Égalité : `==`
- Inégalité : `!=`
- Inférieur : `<`
- Supérieur : `>`
- Inférieur ou égal : `<=`
- Supérieur ou égal : `>=`

Exemple :
```
a == b  // vrai si a est égal à b
a != b  // vrai si a est différent de b
a < b   // vrai si a est strictement inférieur à b
a > b   // vrai si a est strictement supérieur à b
a <= b  // vrai si a est inférieur ou égal à b
a >= b  // vrai si a est supérieur ou égal à b
```

### Structures de Contrôle

#### Condition Si-Alors-Sinon

sukasi
```

#### Boucles

##### Boucle POUR (For)
Exécute un bloc d'instructions un nombre spécifié de fois.

```duala
// Compter de 1 à 10
pɔ i na 1 tɛmbɛlɛ 10 sala
    kɔma i;
sukapɔ

// Avec un pas de 2
pɔ i na 0 tɛmbɛlɛ 10 pas 2 sala
    kɔma i;  // Affichera 0, 2, 4, 6, 8, 10
sukapɔ
```

##### Boucle TANT_QUE (While)
Exécute un bloc tant qu'une condition est vraie.

```duala
ndambo compteur <- 1;
mbɛlɛ (compteur <= 5) sala
    kɔma compteur;
    compteur <- compteur + 1;
sukambɛlɛ
```

##### Boucle REPETER-JUSQUA (Do-While)
Exécute un bloc au moins une fois, puis répète tant que la condition est vraie.

```duala
ndambo reponse;
sɔŋɔlɔ
    kɔma "Tapez 0 pour quitter: ";
    yɛnɛ reponse;
    kɔma "Vous avez tapé: ", reponse;
tɛmbɛlɛ (reponse != 0);
```

#### Structure SELON-CAS

```duala
ndɔŋ (choix)
    kɛs 1:
        kɔma "Premier cas";
        bima;  // Sortir du switch
    kɛs 2:
        kɔma "Deuxième cas";
        bima;
    bɔsɔ:  // Cas par défaut
        kɔma "Autre cas";
sukandɔŋ
```

## Exemples

### Programme d'exemple complet

```duala
mbɔmbɔ
    ndambo nombre;
    
    kɔma "Tɔlɛ nombre na wo: ";
    yɛnɛ nombre;
    
    sɔ (nombre % 2 == 0) tɛ
        kɔma "Nombre pair";
    kɛma
        kɔma "Nombre impair";
    sukasi
suka
```

## Dépannage

### Erreurs courantes

- **Caractère non reconnu** : Vérifiez que vous n'utilisez pas de caractères spéciaux non supportés
- **Erreur de syntaxe** : Vérifiez la ponctuation (points-virgules, parenthèses, etc.)
- **Variable non déclarée** : Toutes les variables doivent être déclarées avec `ndambo` avant utilisation

### Messages d'erreur

- `Variable non déclarée` : La variable n'a pas été déclarée avec `ndambo`
- `Erreur de syntaxe` : Vérifiez la syntaxe autour de la ligne indiquée
- `Caractère non reconnu` : Un caractère non valide a été trouvé dans le code source

## Contribution

Les contributions sont les bienvenues ! Pour contribuer :

1. Forkez le dépôt
2. Créez une branche pour votre fonctionnalité (`git checkout -b nouvelle-fonctionnalité`)
3. Committez vos modifications (`git commit -am 'Ajouter une fonctionnalité'`)
4. Poussez vers la branche (`git push origin nouvelle-fonctionnalité`)
5. Créez une Pull Request

## Licence

Ce projet est sous licence [MIT](LICENSE).

---

Développé avec ❤️ pour la promotion des langues africaines
