/*
    Objectif : Exercice 3
    Auteurs  : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 05/11/2021
*/


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
    // Variables relatives au bon fonctionnement du programme
    unsigned char running = 1; // 1: le programme est répété, 0: le programme s'arrête
    int usr_inpt; // Saisie de l'utilisateur
    unsigned char type_check; // Nombre de valeurs correctement scannées
    unsigned char check_step; // Nombre d'étapes de vérification validées

    // Variables relatives à l'exercice
    // Coordonnées de base
    int xa = 0;
    int ya = 0;
    int xb = 0;
    int yb = 0;
    // Coordonnées des autres zones à initialiser au fur et à mesure du programme
    int new_xa = 0;
    int new_ya = 0;
    int new_xb = 0;
    int new_yb = 0;
    // Coordonnées données par l'utilisateur à replacer dans une zone
    int find_x = 0;
    int find_y = 0;


    do {
        printf("\nExercice 3 :\n1. Lancer\n2. Quitter\nSaisissez votre choix : ");
        fflush(stdin); // Purge du buffer d'entrées pour éviter tout conflit. Valable pour tous
        type_check = scanf("%d", &usr_inpt);
        
        // Vérification de la saisie
        while (check_step != 3)
        {
            check_step = 0; // Réinitialisation de la variable pour répéter le processus de vérification

            // Si l'utilisateur a saisi un caractère
            if (type_check != 1)
            {
                printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez saisir soit '1', soit '2' : ", 138, 130);
                fflush(stdin);
                type_check = scanf("%d", &usr_inpt);
            }
            else
                check_step++;

            // Si la valeur est trop petite
            if (usr_inpt < 1)
            {
                printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez saisir soit '1', soit '2' : ", 130);
                fflush(stdin);
                type_check = scanf("%d", &usr_inpt);
            }
            else
                check_step++;

            // Si la valeur est trop grande
            if (usr_inpt > 2)
            {
                printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez saisir soit '1', soit '2' : ", 130);
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
            case 1:
                // Récupération des coordonnées du point 'a'
                printf("Saisissez les coordonn%ces du point 'a' (x, y) : ", 130);
                fflush(stdin);
                type_check = scanf("%d %d", &xa, &ya);
                
                // Vérification de la saisie
                while (check_step != 3)
                {
                    check_step = 0; // Réinitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 2)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &xa, &ya);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (xa < 0 || ya < 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &xa, &ya);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (xa > 255 || ya > 255)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &xa, &ya);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Réinitialisation de la variable pour les futures vérifications

                // Récupération des coordonnées du point 'b'
                printf("Saisissez les coordonn%ces du point 'b' (x, y) : ", 130);
                fflush(stdin);
                type_check = scanf("%d %d", &xb, &yb);
                
                // Vérification de la saisie
                while (check_step != 3)
                {
                    check_step = 0; // Réinitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 2)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &xb, &yb);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (xb < xa || yb < ya)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &xb, &yb);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (xb > 255 || yb > 255)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &xb, &yb);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Réinitialisation de la variable pour les futures vérifications

                // Récupération des coordonnées à rechercher
                printf("Saisissez les coordonn%ces 'x' et 'y' %c rechercher : ", 130, 133);
                fflush(stdin);
                type_check = scanf("%d %d", &find_x, &find_y);
                
                // Vérification de la saisie
                while (check_step != 3)
                {
                    check_step = 0; // Réinitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 2)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessyAer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &find_x, &find_y);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (find_x < 0 || find_y < 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessyAer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &find_x, &find_y);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (find_x > 255 || find_y > 255)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessyAer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &find_x, &find_y);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Réinitialisation de la variable pour les futures vérifications
            
                // Calcul de largeur et longueur d'une zone
                int width = xb - xa;
                int height = yb - ya;

                // Boucle principal parcourant les zones afin de calculer les coord des zones et vérifier si les coord sont dedans
                for (int i = 1; i <= 9; ++i)
                {
                    switch (i)
                    {
                        case 1 :
                            printf("=============================================\nZone 1\n");
                            printf("Coordonn%ces du coin sup%crieur gauche : (0, 0)\n", 130, 130);
                            printf("Coordonn%ces du coin inf%crieur droit  : (%d, %d)\n", 130, 130, xa, ya);
                            break;

                        case 2 :
                            printf("=============================================\nZone 2\n");
                            printf("Coordonn%ces du coin sup%crieur gauche : (%d, 0)\n", 130, 130, xa);
                            printf("Coordonn%ces du coin inf%crieur droit  : (%d, %d)\n", 130, 130, xb, ya);
                            break;

                        case 3 :
                            printf("=============================================\nZone 3\n");
                            printf("Coordonn%ces du coin sup%crieur gauche : (%d, 0)\n", 130, 130, xb);
                            printf("Coordonn%ces du coin inf%crieur droit  : (%d, %d)\n", 130, 130, xb + width, ya);
                            break;

                        case 4 :
                            printf("=============================================\nZone 4\n");
                            printf("Coordonn%ces du coin sup%crieur gauche : (0, %d)\n", 130, 130, ya);
                            printf("Coordonn%ces du coin inf%crieur droit  : (%d, %d)\n", 130, 130, xa, yb);
                            break;

                        case 5 :
                            printf("=============================================\nZone 5\n");
                            printf("Coordonn%ces du coin sup%crieur gauche : (%d, %d)\n", 130, 130, xa, ya);
                            printf("Coordonn%ces du coin inf%crieur droit  : (%d, %d)\n", 130, 130, xb, yb);
                            break;

                        case 6 :
                            printf("=============================================\nZone 6\n");
                            printf("Coordonn%ces du coin sup%crieur gauche : (%d, %d)\n", 130, 130, xb, ya);
                            printf("Coordonn%ces du coin inf%crieur droit  : (%d, %d)\n", 130, 130, xb + width, yb);
                            break;

                        case 7 :
                            printf("=============================================\nZone 7\n");
                            printf("Coordonn%ces du coin sup%crieur gauche : (0, %d)\n", 130, 130, yb);
                            printf("Coordonn%ces du coin inf%crieur droit  : (%d, %d)\n", 130, 130, xa, yb + height);
                            break;

                        case 8 :
                            printf("=============================================\nZone 8\n");
                            printf("Coordonn%ces du coin sup%crieur gauche : (%d, %d)\n", 130, 130, xa, yb);
                            printf("Coordonn%ces du coin inf%crieur droit  : (%d, %d)\n", 130, 130, xb, yb + height);
                            break;

                        case 9 :
                            printf("=============================================\nZone 9\n");
                            printf("Coordonn%ces du coin sup%crieur gauche : (%d, %d)\n", 130, 130, xb, yb);
                            printf("Coordonn%ces du coin inf%crieur droit  : (%d, %d)\n", 130, 130, xb + width, yb + height);
                            printf("=============================================\n");
                            break;
                    }
                }
                break;
        case 2:
            running=0;
            break;
        
        default:
            printf("Mauvaise entrée. Taper un chiffre uniquement entre 1 et 2.\n");
            break;
        }
    } while (running);

    return 0;
}