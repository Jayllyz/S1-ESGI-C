/*
    Objectif : Afficher un pattern de '*' avec un nombre n de lignes.
    Auteurs  : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 30/10/2021
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv)
{
    // Variables relatives au bon fonctionnement du programme
    unsigned char running = 1; // 1: le programme est répété, 0: le programme s'arrête
    int usr_inpt; // Saisie de l'utilisateur
    unsigned char type_check; // Nombre de valeurs correctement scannées
    unsigned char check_step; // Nombre d'étapes de vérification validées

    // Variables relatives à l'algorithme
    int n; // Nombre de lignes constituant le pattern
    int i, j, k; // Variable pour les boucles
    
    srand(time(NULL)); // Initialisation de la fonction rand()

    // Boucle principale permettant de répéter le programme
    do
    {
        printf("\nExercice 1 :\n1. Lancer\n2. Quitter\nSaisissez votre choix : ");
        fflush(stdin); // Purge du buffer d'entrées pour éviter tout conflit. Valable pour tous
        type_check = scanf("%d", &usr_inpt);
        
        // Vérification de la saisie
        while (check_step != 3)
        {
            check_step = 0; // Réinitialisation de la variable pour répéter le processus de vérification

            // Si l'utilisateur a saisi un caractère
            if (type_check != 1)
            {
                printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                fflush(stdin);
                type_check = scanf("%d", &usr_inpt);
            }
            else
                check_step++;

            // Si la valeur est trop petite
            if (usr_inpt < 1)
            {
                printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessayer : ", 130);
                fflush(stdin);
                type_check = scanf("%d", &usr_inpt);
            }
            else
                check_step++;

            // Si la valeur est trop grande
            if (usr_inpt > 2)
            {
                printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessayer : ", 130);
                fflush(stdin);
                type_check = scanf("%d", &usr_inpt);
            }
            else
                check_step++;
        }
        check_step = 0; // Réinitialisation de la variable pour les futures vérifications

        // Choix du menu
        switch (usr_inpt)
        {
            // 1. Lancer
            case 1:
                printf("Saisissez un nombre de lignes entre 0 et 100 (0 pour g%cn%crer un nombre al%catoire entre 1 et 20) : ", 130, 130, 130);
                fflush(stdin);
                type_check = scanf("%d", &usr_inpt);
                
                // Vérification de la saisie
                while (check_step != 3)
                {
                    check_step = 0; // Rénitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 1)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%d", &usr_inpt);
                    }
                    else
                        check_step++;

                    // Si la valeur est négative
                    if (usr_inpt < 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur n%cgative.\nVeuillez r%cessayer : ", 130, 130);
                        fflush(stdin);
                        type_check = scanf("%d", &usr_inpt);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (usr_inpt > 100)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d", &usr_inpt);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Réinitialisation de la variable pour les futures vérifications

                n = usr_inpt; // Affection de la saisie de l'utilisateur à la variable n

                // Cas où l'utilisateur veut générer un nombre aléatoire de lignes
                if (n == 0)
                {
                    n = rand() % 20 + 1;
                    printf("Nombre de lignes al%catoirement g%cn%cr%c : %d\n", 130, 130, 130, 130, n);
                }

                // Cas particulier où l'utilisateur veut qu'une seule ligne
                if (n == 1)
                {
                    printf("* *\n");
                    break; // Permet de passer les étapes ci-dessous
                }

                // Partie haute
                for (i = 0; i < n / 2; i++) // n / 2 -> nombre de ligne de la partie haute de la figure
                { 
                    for (j = 0; j <= i; j++) // Premier triangle
                        printf("* ");

                    for (j = i + 2; i + j < n; j++) // "pyramide" d'espaces entre les 2 triangles
                        printf("  ");

                    for (k = 0; k <= n - j; k++) // Deuxième triangle
                        printf("* ");

                    printf("\n");
                }

                // Ligne centrale uniquement si n est impair
                if (n % 2 == 1)
                {
                    for (i = 0; i < n; i++)
                        printf("* ");

                    printf("\n");
                }

                // Partie basse
                for (i = 0; i < n / 2; i++) // n / 2 -> nombre de ligne de la partie basse de la figure
                {
                    for (j = 0; j + i < n/2; j++) // Premier triangle
                        printf("* ");

                    for (j = n % 2 == 0 ? 1 : 0; j <= 2 * i; j++) // "pyramide" d'espace entre les 2 triangles
                        printf("  ");

                    for (j = i; j < n/2; j++) // Deuxième triangle
                        printf("* ");

                    printf("\n");
                }
                break;
            
            // 2. Quitter
            case 2:
                running = 0;
                break;
        }
    } while (running);
    
    return 0;
}
