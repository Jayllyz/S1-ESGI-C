/*
    Objectif : Afficher un pattern de '*' avec un nombre n de lignes.
    Autheurs : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 30/10/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    int n=0; // Nombre de lignes constituant le pattern.
    int i, j, k=0; // Variable pour les boucles.
    char running = 1; // 1: le programme est répété, 0: le programme s'arrête. 
    srand(time(NULL)); // Initialisation de la fonction rand().
    do {
        printf("Exercice 1 :\n1. Lancer\n2. Quitter\nEntrez votre choix: ");
        fflush(stdin); // Vide le buffer d'entrées pour éviter les conflits
        if (scanf("%d", &n) != 1) {
            printf("ERREUR : Vous n'avez pas entré un nombre.\n");
            return EXIT_FAILURE;
        }
        switch (n) {
            // Lance le programme.
            case 1:
                printf("Entrez le nombre de lignes (0 pour générer aléatoirement entre 1 et 20): ");
                do {
                    if (scanf("%d", &n) != 1) {
                        printf("ERREUR : Vous n'avez pas entré un nombre.\n");
                        return EXIT_FAILURE;
                    }
                    if (n <0)
                    {
                        printf("ERREUR : Nombre négatif, recommencer votre saisie : ");
                    }
                    
                } while (n < 0);

                if (n == 0){
                    n = rand() % 20 + 1;
                    printf("Nombre de lignes aléatoirement généré: %d\n", n);
                }
                if (n == 1){
                    printf("* *\n");
                    break;
                }

                // Partie haute
                for (i = 0; i < n / 2; i++) { // n / 2 -> nombre de ligne de la figure (partie haute)
                    for (j = 0; j <= i; j++) { // Premier triangle
                        printf("* ");
                    }
                    for (j = i + 2; i + j < n; j++) { //"pyramide" d'espace entre les 2 triangles
                        printf("  ");
                    }
                    for (k = 0; k <= n - j; k++) { // Deuxième triangle
                        printf("* ");
                    }
                    printf("\n");
                }

                // Ligne centrale uniquement si n est impair
                if (n % 2 == 1) {
                    for (i = 0; i < n; i++) {
                        printf("* ");
                    }
                    printf("\n");
                }

                // Partie basse
                for(i = 0; i < n / 2; i++) { // n / 2 -> nombre de ligne de la figure (partie basse)
                    for(j = 0; j + i < n/2; j++) { // Premier triangle
                        printf("* ");
                    }
                    for(j = n % 2 == 0 ? 1 : 0; j <= 2 * i; j++) { //"pyramide" d'espace entre les 2 triangles
                        printf("  ");
                    }
                    for(j = i; j < n/2; j++) { // Deuxième triangle
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
                printf("Mauvaise entrée. Taper un chiffre uniquement entre 1 et 2.\n");
                break;
        }
    } while (running);
    
    return 0;
}