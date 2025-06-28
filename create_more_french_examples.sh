#!/bin/bash

# Create more French examples for C compiler
cd /home/zaz/Documents/Github/french-mother-language-compiler/C/Francais/example_programs

# Example 11: Triangle rectangle
cat > triangle_rectangle.fr << 'PROG'
debut
    entier a;
    entier b;
    entier c;
    entier carre_a;
    entier carre_b;
    entier carre_c;
    
    lire a;
    lire b;
    lire c;
    
    carre_a <- a * a;
    carre_b <- b * b;
    carre_c <- c * c;
    
    si (carre_a + carre_b == carre_c) alors
        ecrire 1;
    sinon
        ecrire 0;
    finsi
fin
PROG

# Example 12: Calcul age
cat > calcul_age.fr << 'PROG'
debut
    entier annee_naissance;
    entier annee_actuelle;
    entier age;
    
    lire annee_naissance;
    lire annee_actuelle;
    
    age <- annee_actuelle - annee_naissance;
    ecrire age;
fin
PROG

# Example 13: Prix avec remise
cat > prix_remise.fr << 'PROG'
debut
    entier prix_initial;
    entier pourcentage_remise;
    entier remise;
    entier prix_final;
    
    lire prix_initial;
    lire pourcentage_remise;
    
    remise <- (prix_initial * pourcentage_remise) / 100;
    prix_final <- prix_initial - remise;
    ecrire prix_final;
fin
PROG

# Example 14: Conversion temperature
cat > conversion_temperature.fr << 'PROG'
debut
    entier celsius;
    entier fahrenheit;
    
    lire celsius;
    fahrenheit <- (celsius * 9) / 5 + 32;
    ecrire fahrenheit;
fin
PROG

# Example 15: Aire rectangle
cat > aire_rectangle.fr << 'PROG'
debut
    entier longueur;
    entier largeur;
    entier aire;
    
    lire longueur;
    lire largeur;
    aire <- longueur * largeur;
    ecrire aire;
fin
PROG

# Example 16: Perimetre rectangle
cat > perimetre_rectangle.fr << 'PROG'
debut
    entier longueur;
    entier largeur;
    entier perimetre;
    
    lire longueur;
    lire largeur;
    perimetre <- 2 * (longueur + largeur);
    ecrire perimetre;
fin
PROG

# Example 17: Aire cercle approximative
cat > aire_cercle.fr << 'PROG'
debut
    entier rayon;
    entier aire;
    
    lire rayon;
    aire <- 3 * rayon * rayon;
    ecrire aire;
fin
PROG

# Example 18: Volume cube
cat > volume_cube.fr << 'PROG'
debut
    entier cote;
    entier volume;
    
    lire cote;
    volume <- cote * cote * cote;
    ecrire volume;
fin
PROG

# Example 19: Moyenne pondérée
cat > moyenne_ponderee.fr << 'PROG'
debut
    entier note1;
    entier coeff1;
    entier note2;
    entier coeff2;
    entier somme_notes;
    entier somme_coeff;
    entier moyenne;
    
    lire note1;
    lire coeff1;
    lire note2;
    lire coeff2;
    
    somme_notes <- (note1 * coeff1) + (note2 * coeff2);
    somme_coeff <- coeff1 + coeff2;
    moyenne <- somme_notes / somme_coeff;
    ecrire moyenne;
fin
PROG

# Example 20: Jours en secondes
cat > jours_secondes.fr << 'PROG'
debut
    entier jours;
    entier heures;
    entier minutes;
    entier secondes;
    
    lire jours;
    heures <- jours * 24;
    minutes <- heures * 60;
    secondes <- minutes * 60;
    ecrire secondes;
fin
PROG

echo "More French examples created successfully!"
