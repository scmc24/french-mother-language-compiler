#!/bin/bash

# Create French examples for C compiler
cd /home/zaz/Documents/Github/french-mother-language-compiler/C/Francais/example_programs

# Example 1: Valeur absolue
cat > valeur_absolue.fr << 'PROG'
debut
    entier nombre;
    entier absolu;
    
    lire nombre;
    
    si (nombre >= 0) alors
        absolu <- nombre;
    sinon
        absolu <- 0 - nombre;
    finsi
    
    ecrire absolu;
fin
PROG

# Example 2: Carré d'un nombre
cat > carre_nombre.fr << 'PROG'
debut
    entier nombre;
    entier carre;
    
    lire nombre;
    carre <- nombre * nombre;
    ecrire carre;
fin
PROG

# Example 3: Somme des carrés
cat > somme_carres.fr << 'PROG'
debut
    entier i;
    entier somme;
    entier limite;
    entier carre;
    
    lire limite;
    i <- 1;
    somme <- 0;
    
    tant_que (i <= limite) faire
        carre <- i * i;
        somme <- somme + carre;
        i <- i + 1;
    fintant
    
    ecrire somme;
fin
PROG

# Example 4: Nombre premier simple
cat > nombre_premier.fr << 'PROG'
debut
    entier nombre;
    entier i;
    entier divisible;
    
    lire nombre;
    i <- 2;
    divisible <- 0;
    
    tant_que (i < nombre) faire
        si ((nombre / i) * i == nombre) alors
            divisible <- 1;
        finsi
        i <- i + 1;
    fintant
    
    si (divisible == 0) alors
        ecrire 1;
    sinon
        ecrire 0;
    finsi
fin
PROG

# Example 5: PGCD simple
cat > pgcd_simple.fr << 'PROG'
debut
    entier a;
    entier b;
    entier temp;
    
    lire a;
    lire b;
    
    tant_que (b != 0) faire
        temp <- a - (a / b) * b;
        a <- b;
        b <- temp;
    fintant
    
    ecrire a;
fin
PROG

# Example 6: Suite arithmétique
cat > suite_arithmetique.fr << 'PROG'
debut
    entier premier;
    entier raison;
    entier n;
    entier i;
    entier terme;
    
    lire premier;
    lire raison;
    lire n;
    
    i <- 0;
    tant_que (i < n) faire
        terme <- premier + i * raison;
        ecrire terme;
        i <- i + 1;
    fintant
fin
PROG

# Example 7: Inversion de nombre
cat > inversion_nombre.fr << 'PROG'
debut
    entier nombre;
    entier inverse;
    entier chiffre;
    
    lire nombre;
    inverse <- 0;
    
    tant_que (nombre > 0) faire
        chiffre <- nombre - (nombre / 10) * 10;
        inverse <- inverse * 10 + chiffre;
        nombre <- nombre / 10;
    fintant
    
    ecrire inverse;
fin
PROG

# Example 8: Somme chiffres
cat > somme_chiffres.fr << 'PROG'
debut
    entier nombre;
    entier somme;
    entier chiffre;
    
    lire nombre;
    somme <- 0;
    
    tant_que (nombre > 0) faire
        chiffre <- nombre - (nombre / 10) * 10;
        somme <- somme + chiffre;
        nombre <- nombre / 10;
    fintant
    
    ecrire somme;
fin
PROG

# Example 9: Nombre parfait
cat > nombre_parfait.fr << 'PROG'
debut
    entier nombre;
    entier i;
    entier somme;
    
    lire nombre;
    i <- 1;
    somme <- 0;
    
    tant_que (i < nombre) faire
        si ((nombre / i) * i == nombre) alors
            somme <- somme + i;
        finsi
        i <- i + 1;
    fintant
    
    si (somme == nombre) alors
        ecrire 1;
    sinon
        ecrire 0;
    finsi
fin
PROG

# Example 10: Conversion binaire
cat > conversion_binaire.fr << 'PROG'
debut
    entier nombre;
    entier binaire;
    entier puissance;
    entier reste;
    
    lire nombre;
    binaire <- 0;
    puissance <- 1;
    
    tant_que (nombre > 0) faire
        reste <- nombre - (nombre / 2) * 2;
        binaire <- binaire + reste * puissance;
        puissance <- puissance * 10;
        nombre <- nombre / 2;
    fintant
    
    ecrire binaire;
fin
PROG

echo "French examples created successfully!"
