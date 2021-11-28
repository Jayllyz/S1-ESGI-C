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
                printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez saisir soit '1', soit '2' : ", 138);
                fflush(stdin);
                type_check = scanf("%d", &usr_inpt);
            }
            else
                check_step++;

            // Si la valeur est trop petite
            if (usr_inpt < 1)
            {
                printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez saisir soit '1', soit '2' : ");
                fflush(stdin);
                type_check = scanf("%d", &usr_inpt);
            }
            else
                check_step++;

            // Si la valeur est trop grande
            if (usr_inpt > 2)
            {
                printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez saisir soit '1', soit '2' : ");
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
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessyaer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &xa, &ya);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (xa <= 0 || ya <= 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessyaer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &xa, &ya);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (xa > 255 || ya > 255)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessyaer : ", 130);
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
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessyaer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &xb, &yb);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (xb < xa || yb < ya)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessyaer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &xb, &yb);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (xb > 255 || yb > 255)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessyaer : ", 130);
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
                
                // Calcul de largeur et longueur d'une zone3
                int horizontal = xb - xa;
                int vertical = yb - ya;

                int find = 0; // Stopper le programme si on trouve
                int zone_number_xb;// Coordonée xb et yb ou se situe les coord recherché
                int zone_number_yb;

                // Booléen visant a savoir si il existe une frontière en x a gauche (L = left) de la zone ou a droite (R = rigth)
                int is_frontier_x_R = 0;
                int is_frontier_x_L = 0;
                int is_frontier_y_down = 0;

                // Boucle afin de trouver dans quelle zone se situe les coord ainsi que définir si il y a des frontières en X
                for (int i = xa; i <= horizontal*3 && find == 0; i = i + horizontal) {
                    if (find_x <= i) {
                        if (find_x == i)
                        {
                            is_frontier_x_R = 1;
                        }
                        if (find_x == i-horizontal){
                            is_frontier_x_L = 1;
                        }
                        zone_number_xb = i;
                        find = 1;
                    }
                }
                find = 0;

                // Boucle afin de trouver dans quelle zone se situe les coord ainsi que définir si il y a des frontières en Y
                for (int j = ya; j <= vertical*3 && find == 0; j = j + vertical) {
                    if (find_y <= j) {
                        if (find_y == j)
                        {
                            is_frontier_y_down = 1;
                        }
                        zone_number_yb = j;
                        find = 1;
                    }
                }

                // Boucle principal parcourant les zones afin de calculer les coord des zones et vérifier si les coord sont dedans
                for (int i = 1; i <= 9; ++i)
                {
                    switch (i)
                    {
                        case 1 :
                            new_xa = 0;
                            new_ya = 0;
                            new_xb = xa;
                            new_yb = ya;

                            printf("\n================================\nZone 1\n");
                            printf("coord a(%d,%d) \n", new_xa, new_ya);
                            printf("coord b(%d,%d) \n", new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if (is_frontier_x_R == 1 && is_frontier_y_down == 0)
                                    printf("On se trouve zone %d et 2\n", i);

                                else if (is_frontier_x_R == 0 && is_frontier_y_down == 1)
                                    printf("On se trouve zone%d et 4\n", i);

                                else if (is_frontier_x_R == 1 && is_frontier_y_down == 1)
                                    printf("Nous avons une fronti%cre avec zone 1,2,4 et 5\n", 138);

                                else if(is_frontier_x_L == 1 && is_frontier_y_down == 1)
                                    printf("Nous avons une fronti%cre avec zone %d et 4\n", 138, i);

                                else
                                    printf("On se trouve zone %d", i);
                            }
                            break;

                        case 2 :
                            new_xa = xa;
                            new_ya = 0;
                            new_xb = xa + horizontal;
                            new_yb = ya;

                            printf("\n================================\nZone 2\n");
                            printf("coord a(%d,%d) \n", new_xa, new_ya);
                            printf("coord b(%d,%d) \n", new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if (is_frontier_x_R == 1 && is_frontier_y_down == 0)
                                    printf("Nous avons une fronti%cre avec %d et 3\n", 138, i);

                                else if (is_frontier_x_R == 0 && is_frontier_y_down == 1)
                                    printf("d'ailleur on se trouve zone %d et 5\n", i);

                                else if(is_frontier_x_R == 1 && is_frontier_y_down == 1)
                                    printf("nous avons une fronti%cre avec zone 2,3,5 et 6\n", 138);

                                else if (is_frontier_x_L == 0 && is_frontier_y_down == 1)
                                    printf("nous avons une fronti%cre avec %d et 5\n", 138, i);

                                else
                                    printf("On se trouve zone %d\n", i);
                            }
                            break;

                        case 3 :
                            new_xa = xa + horizontal;
                            new_ya = 0;
                            new_xb = xa + 2 * horizontal;
                            new_yb = ya;

                            printf("\n================================\nZone 3\n");
                            printf("coord a(%d,%d) \n", new_xa, new_ya);
                            printf("coord b(%d,%d) \n", new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if(is_frontier_x_L == 0  && is_frontier_y_down == 1)
                                    printf("nous avons une fronti%cre avec %d et 6\n", 138, i);

                                else if(is_frontier_x_R == 1 && is_frontier_y_down == 1)
                                    printf("nous avons une fronti%cre avec zone %d et 6\n", 138, i);

                                else
                                    printf("On se trouve zone %d\n", i);
                            }
                            break;

                        case 4 :
                            new_xa = 0;
                            new_ya = ya;
                            new_xb = xa;
                            new_yb = ya + vertical;

                            printf("\n================================\nZone 4\n");
                            printf("coord a(%d,%d) \n", new_xa, new_ya);
                            printf("coord b(%d,%d) \n", new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if(is_frontier_x_R == 1  && is_frontier_y_down == 0)
                                    printf("nous avons une fronti%cre avec %d et 5\n", 138, i);
                                
                                else if(is_frontier_x_R == 1 && is_frontier_y_down ==1)
                                    printf("nous avons une fronti%cre avec %d,5,7 et 8\n", 138, i);

                                else if(is_frontier_x_R == 0 && is_frontier_y_down ==1)
                                    printf("nous avons une fronti%cre avec %d et 7 \n", 138, i);

                                else if(is_frontier_x_L == 1 && is_frontier_y_down ==1)
                                    printf("nous avons une fronti%cre avec %d et 7", 138, i);

                                else
                                    printf("On se trouve zone %d\n", i);
                            }
                            break;

                        case 5 :
                            new_xa = xa;
                            new_ya = ya;
                            new_xb = xb;
                            new_yb = yb;

                            printf("\n================================\nZone 5\n");
                            printf("coord a(%d,%d) \n", new_xa, new_ya);
                            printf("coord b(%d,%d) \n", new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if(is_frontier_x_R == 1  && is_frontier_y_down == 0)
                                    printf("nous avons une fronti%cre avec %d et 6\n", 138, i);

                                else if(is_frontier_x_R == 1 && is_frontier_y_down ==1)
                                    printf("nous avons une fronti%cre avec %d,6,8 et 9\n", 138, i);

                                else if(is_frontier_x_R == 0 && is_frontier_y_down ==1)
                                    printf("nous avons une fronti%cre avec %d et 8 \n", 138, i);

                                else
                                    printf("On se trouve zone %d\n", i);
                            }
                            break;

                        case 6 :
                            new_xa = xb;
                            new_ya = yb - vertical;
                            new_xb = xb + horizontal;
                            new_yb = yb;

                            printf("\n================================\nZone 6\n");
                            printf("coord a(%d,%d) \n", new_xa, new_ya);
                            printf("coord b(%d,%d) \n", new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if(is_frontier_x_L == 0  && is_frontier_y_down == 1)
                                    printf("nous avons une fronti%cre avec %d et 9\n", 138, i);

                                else if(is_frontier_x_L == 1  && is_frontier_y_down == 1)
                                    printf("nous avons une fronti%cre avec %d,8 et 9\n", 138, i);

                                else if(is_frontier_x_R == 1  && is_frontier_y_down == 1)
                                    printf("nous avons une fronti%cre avec %d et 9\n", 138, i);

                                else
                                    printf("On se trouve zone %d\n", i);
                            }
                            break;

                        case 7 :
                            new_xa = 0;
                            new_ya = yb;
                            new_xb = xa;
                            new_yb = yb + vertical;

                            printf("\n================================\nZone 7\n");
                            printf("coord a(%d,%d) \n", new_xa, new_ya);
                            printf("coord b(%d,%d) \n", new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if(is_frontier_x_R == 1  && is_frontier_y_down == 0)
                                    printf("nous avons une fronti%cre avec %d et 8\n", 138, i);

                                else
                                    printf("On se trouve zone %d\n", i);
                            }
                            break;

                        case 8 :
                            new_xa = xb - horizontal;
                            new_ya = yb;
                            new_xb = xb;
                            new_yb = yb + vertical;

                            printf("\n================================\nZone 8\n");
                            printf("coord a(%d,%d) \n", new_xa, new_ya);
                            printf("coord b(%d,%d) \n", new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if(is_frontier_x_R == 1  && is_frontier_y_down == 0)
                                    printf("nous avons une fronti%cre avec %d et 9\n", 138, i);

                                else
                                    printf("On se trouve zone %d\n", i);
                            }
                            break;

                        case 9 :
                            new_xa = xb;
                            new_ya = yb;
                            new_xb = xb + horizontal;
                            new_yb = yb + vertical;

                            printf("\n================================\nZone 9\n");
                            printf("coord a(%d,%d) \n", new_xa, new_ya);
                            printf("coord b(%d,%d) \n", new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                                printf("On se trouve zone %d\n", i);

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
