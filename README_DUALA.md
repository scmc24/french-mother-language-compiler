# Compilateur Duala - Documentation

## Vue d'ensemble
Ce projet contient maintenant des compilateurs pour la langue **Duala** (langue camerounaise) en plus du français, disponibles en versions Assembleur et C.

## Structure du projet

```
french-mother-language-compiler/
├── Assembleur/
│   ├── Francais/          # Compilateur français vers assembleur
│   └── Duala/             # Compilateur duala vers assembleur
├── C/
│   ├── Francais/          # Compilateur français vers C
│   └── Duala/             # Compilateur duala vers C
└── example_programs/      # Programmes d'exemple
```

## Mots-clés Duala

| Français | Duala | Signification |
|----------|-------|---------------|
| `debut` | `mbɔmbɔ` | début/commencement |
| `fin` | `suka` | fin/terminer |
| `entier` | `ndambo` | entier/nombre |
| `lire` | `yɛnɛ` | lire/prendre |
| `ecrire` | `kɔma` | écrire/dire |
| `si` | `sɔ` | si |
| `alors` | `tɛ` | alors |
| `sinon` | `kɛma` | sinon/autrement |
| `finsi` | `sukasi` | fin si |
| `tant_que` | `mbɛlɛ` | tant que/aussi longtemps que |
| `faire` | `sala` | faire/fabriquer |
| `fintant` | `sukambɛlɛ` | fin tant que |

## Opérateurs
Les opérateurs restent identiques: `<-`, `==`, `!=`, `>=`, `<=`, `>`, `<`, `+`, `-`, `*`, `/`

## Exemples de programmes

### Programme simple
```duala
mbɔmbɔ
    ndambo x;
    x <- 42;
    kɔma x;
suka
```

### Programme avec condition
```duala
mbɔmbɔ
    ndambo a;
    ndambo b;
    ndambo max;
    
    yɛnɛ a;
    yɛnɛ b;
    
    sɔ (a > b) tɛ
        max <- a;
        kɔma max;
    kɛma
        max <- b;
        kɔma max;
    sukasi
suka
```

### Programme avec boucle
```duala
mbɔmbɔ
    ndambo i;
    ndambo somme;
    
    i <- 1;
    somme <- 0;
    
    mbɛlɛ (i <= 5) sala
        somme <- somme + i;
        kɔma somme;
        i <- i + 1;
    sukambɛlɛ
    
    kɔma somme;
suka
```

## Compilation et exécution

### Version C
```bash
cd C/Duala
make compilateur          # Compiler le compilateur
make test_simple          # Tester avec un programme simple
make test_avance          # Tester avec un programme avancé
```

### Version Assembleur
```bash
cd Assembleur/Duala
make compilateur          # Compiler le compilateur
make test                 # Tester avec le programme d'exemple
```

## Fonctionnalités supportées

✅ **Variables entières** (`ndambo`)  
✅ **Affectation** (`<-`)  
✅ **Lecture/Écriture** (`yɛnɛ`/`kɔma`)  
✅ **Conditions** (`sɔ`...`tɛ`...`kɛma`...`sukasi`)  
✅ **Boucles** (`mbɛlɛ`...`sala`...`sukambɛlɛ`)  
✅ **Expressions arithmétiques** (`+`, `-`, `*`, `/`)  
✅ **Expressions de comparaison** (`>`, `<`, `==`, `!=`, `>=`, `<=`)  
✅ **Génération de code C**  
✅ **Génération de code Assembleur**  

## Messages du compilateur
Le compilateur affiche des messages en français et duala:
- `Mbɔmbɔ compilation...` - Début de compilation
- `Compilation suka na malamu!` - Compilation terminée avec succès
- `Tɔlɛ programme na wo:` - Entrez votre programme
- `Yɛnɛ: variable` - Lecture de variable
- `Kɔma expression` - Écriture d'expression

## Extension de fichiers
- Programmes Duala: `.du`
- Programmes Français: `.fr`


## Contributeurs
- ZOGO ABOUMA ZOZIME ACHAIRE (https://github.com/Achaire-Zogo)