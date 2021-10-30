/*
    Objectif : Afficher un pattern de '*' avec un nombre n de lignes.
    Autheurs : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 30/10/2021
*/

#include <stdio.h>

int main(int argc, char **argv) {
    char n; // Nombre de lignes constituant le pattern.
    char i, j, k; // Variable pour les boucles.
    char running = 1; //1: le programme est répété, 0: le programme s'arrête. 

    do {
        printf("Exercice 1 :\n1. Lancer\n2. Quitter\nEntrez votre choix: ");
        fflush(stdin); // Vide le buffer d'entrées pour éviter les conflits
        scanf("%d", &n); // La variable n sert également à stocker le choix de l'utilisateur

        switch (n) {
            // Lance le programme.
            case 1:
                printf("*running*\n");
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