/*
    Objectif : Afficher un pattern de '*' avec un nombre n de lignes.
    Autheurs : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 30/10/2021
*/

#include <stdio.h>

int main(int argc, char **argv) {
    int n; // Nombre de lignes constituant le pattern.
    char i, j, k; // Variable pour les boucles.
    char running = 1; //1: le programme est répété, 0: le programme s'arrête. 

    do {
        printf("Exercice 1 :\n1. Lancer\n2. Quitter\nEntrez votre choix: ");
        fflush(stdin); // Vide le buffer d'entrées pour éviter les conflits
        scanf("%d", &n); // La variable n sert également à stocker le choix de l'utilisateur

        switch (n) {
            // Lance le programme.
            case 1:
                printf("Entrez le nombre de lignes: ");
                scanf("%d", &n);

                // Partie haute
                for (i = 0; i < n / 2; i++) { // n/2 -> nombre de ligne de la figure (partie haute)
                    for (j = 0; j <= i; j++) { // premier triangle
                        printf("* ");
                    }
                    for (j = i+1; i + j < n; j++) {//"pyramide" d'espace entre les 2 triangles
                        printf("  ");
                    }
                    for (k = 0; k <= n - j; k++) {// deuxième triangle
                        printf("* ");
                    }
                    printf("\n");
                }

                // Ligne centrale
                for (i = 0; i <= n; i++) {
                    printf("* ");
                }
                printf("\n");

                // Partie basse
                for(i = 0; i < n / 2; i++) {// n/2 -> nombre de ligne de la figure (partie basse)
                    for(j = 0; j + i < n/2; j++) { // premier triangle
                        printf("* ");
                    }
                    for(j = 0; j <= (n %2 == 0 ? i*2 : i*2 +1); j++) {//"pyramide" d'espace entre les 2 triangles (i*2 -> pyramide compléte)
                        printf("  ");
                    }
                    for(j = i; j < n/2; j++) { // deuxième triangle
                        printf("* ");
                    }
                printf("\n");
                  }
                break;
            
            // Arrête le programme.
            case 2:
                running = 0;
                break;

            // Mauvaise valeur tapée par l'utilisateur.
            default:
                printf("Mauvaise entrée. Taper un chiffre uniquement entre 1 et 2.\n\n");
                break;
        }
    } while (running);
    
    return 0;
}