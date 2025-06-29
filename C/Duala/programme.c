#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 0;  // Variable déclarée
    int b = 0;  // Variable déclarée
    int max = 0;  // Variable déclarée
    printf("Tɔlɛ valeur na a: ");
    scanf("%d", &a);
    printf("Tɔlɛ valeur na b: ");
    scanf("%d", &b);
    if ((a > b)) {
    max = a;
    printf("Résultat: %d\n", max);
    } else {
    max = b;
    printf("Résultat: %d\n", max);
    }  // Suka SƆ
    printf("\n--- Suka programme ---\n");
    return 0;
}
