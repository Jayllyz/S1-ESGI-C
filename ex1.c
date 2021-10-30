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

                // Ligne 1 à n / 2
                for (i = 0; i < n / 2; i++) {
                    for (j = 0; j <= i; j++) {
                        printf("* ");
                    }
                    for (j = i + 2; i + j < n; j++) {
                        printf("  ");
                    }
                    for (k = 0; k <= n - j; k++) {
                        printf("* ");
                    }
                    printf("\n");
                }

                // Ligne centrale
                for (i = 0; i < n; i++) {
                    printf("* ");
                }
                printf("\n");

                for(i = 0; i < n + 1; i++) {
                    for(j = i; j <= n; j++) {
                        printf("*");
                    }
                    for(j = 0; j <= i; j++) {
                        printf(" ");
                    } 
                    for(j = 0; j < i; j++) {
                        printf(" ");
                    }
                    for(j = i; j <= n; j++) {
                        printf("*");
                    }
                }
                printf("\n");
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

/*

    *               * 
    * *           * * 
    * * *       * * * 
    * * * *   * * * * 
    * * * * * * * * * 
    * * * *   * * * * 
    * * *       * * * 
    * *           * * 
    *               * 

*/
