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
    // Coordonnées du point à rechercher
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
                printf("\nSaisissez les coordonn%ces du point 'a' (x, y) : ", 130);
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
                    if (xa <= 0 || ya <= 0)
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
                
                // Calcul de largeur et longueur des deux dernières lignes/colonnes
                int width = xb - xa;
                int height = yb - ya;

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
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &find_x, &find_y);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (find_x < 0 || find_y < 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &find_x, &find_y);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (find_x > xb + width || find_y > yb + height)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d %d", &find_x, &find_y);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Réinitialisation de la variable pour les futures vérifications

                int find = 0; // Stopper le programme si on trouve
                int zone_number_xb; // Sert à comparer avec la coordonnée xb à rechercher
                int zone_number_yb; // Sert à comparer avec la coordonnée yb à rechercher

                int is_frontier_x_R = 0; // Vaut 1 si le point recherché se trouve à la frontière droite d'une zone
                int is_frontier_x_L = 0; // Vaut 1 si le point recherché se trouve à la frontière gauche d'une zone
                int is_frontier_y_down = 0; // Vaut 1 si le point recherché se trouve à la frontière inférieure d'une zone

                // Boucle afin de trouver dans quelle zone se situe les coordonnées à rechercher en X
                for (int i = xa; i <= width * 2 + xa && find == 0; i = i + width)
                {
                    if (find_x <= i)
                    {
                        if (find_x == i)
                            is_frontier_x_R = 1;
                        
                        if (find_x == i - width)
                            is_frontier_x_L = 1;
                        
                        zone_number_xb = i;
                        find = 1;
                    }
                }
                find = 0;

                // Boucle afin de trouver dans quelle zone se situe les coordonnées à rechercher en Y
                for (int j = ya; j <= height * 2 + ya && find == 0; j = j + height) {
                    if (find_y <= j)
                    {
                        if (find_y == j)
                            is_frontier_y_down = 1;
                        
                        zone_number_yb = j;
                        find = 1;
                    }
                }

                // Boucle principal parcourant les zones afin de calculer les coord des zones et vérifier si les coord sont dedans
                for (int i = 1; i <= 9; ++i)
                {
                    printf("\n================================================================\nZone %d", i);
                    
                    // Chaque "case" correspond à une zone
                    switch (i)
                    {
                        case 1:
                            new_xa = 0;
                            new_ya = 0;
                            new_xb = xa;
                            new_yb = ya;

                            printf("\nCoordonn%ces du coin sup%crieur gauche : (%d, %d)", 130, 130, new_xa, new_ya);
                            printf("\nCoordonn%ces du coin inf%crieur droit  : (%d, %d)", 130, 130, new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if (is_frontier_x_R == 1 && is_frontier_y_down == 0)
                                    printf("\n\nLe point recherch%c se trouve %d & 2.",130,i );

                                else if (is_frontier_x_R == 0 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve zone%d & 4.",130, i);

                                else if (is_frontier_x_R == 1 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d, 2, 4 & 5.", 130, 138, i);

                                else if (is_frontier_x_L == 1 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 4.", 130, 138, i);

                                else
                                    printf("\n\nLe point recherch%c se trouve ici.", 130);
                            }
                            break;

                        case 2:
                            new_xa = xa;
                            new_ya = 0;
                            new_xb = xa + width;
                            new_yb = ya;

                            printf("\nCoordonn%ces du coin sup%crieur gauche : (%d, %d)", 130, 130, new_xa, new_ya);
                            printf("\nCoordonn%ces du coin inf%crieur droit  : (%d, %d)", 130, 130, new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if (is_frontier_x_R == 1 && is_frontier_y_down == 0)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 3.", 130, 138, i);

                                else if (is_frontier_x_R == 0 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 5.", 130, 138, i);

                                else if (is_frontier_x_R == 1 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d, 3, 5 & 6.", 130, 138, i);

                                else if (is_frontier_x_L == 0 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 5.", 130, 138, i);

                                else
                                    printf("\n\nLe point recherch%c se trouve ici.", 130);
                            }
                            break;

                        case 3:
                            new_xa = xa + width;
                            new_ya = 0;
                            new_xb = xa + 2 * width;
                            new_yb = ya;

                            printf("\nCoordonn%ces du coin sup%crieur gauche : (%d, %d)", 130, 130, new_xa, new_ya);
                            printf("\nCoordonn%ces du coin inf%crieur droit  : (%d, %d)", 130, 130, new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if (is_frontier_x_L == 0  && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 6.", 130, 138, i);

                                else if (is_frontier_x_R == 1 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 6.", 130, 138, i);

                                else
                                    printf("\n\nLe point recherch%c se trouve ici.", 130);
                            }
                            break;

                        case 4:
                            new_xa = 0;
                            new_ya = ya;
                            new_xb = xa;
                            new_yb = ya + height;

                            printf("\nCoordonn%ces du coin sup%crieur gauche : (%d, %d)", 130, 130, new_xa, new_ya);
                            printf("\nCoordonn%ces du coin inf%crieur droit  : (%d, %d)", 130, 130, new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if (is_frontier_x_R == 1  && is_frontier_y_down == 0)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 5.", 130, 138, i);
                                
                                else if (is_frontier_x_R == 1 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d, 5, 7 & 8.", 130, 138, i);

                                else if (is_frontier_x_R == 0 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 7.", 130, 138, i);

                                else if (is_frontier_x_L == 1 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 7.", 130, 138, i);

                                else
                                    printf("\n\nLe point recherch%c se trouve ici.", 130);
                            }
                            break;

                        case 5:
                            new_xa = xa;
                            new_ya = ya;
                            new_xb = xb;
                            new_yb = yb;

                            printf("\nCoordonn%ces du coin sup%crieur gauche : (%d, %d)", 130, 130, new_xa, new_ya);
                            printf("\nCoordonn%ces du coin inf%crieur droit  : (%d, %d)", 130, 130, new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if (is_frontier_x_R == 1  && is_frontier_y_down == 0)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 6.", 130, 138, i);

                                else if (is_frontier_x_R == 1 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d, 6, 8 & 9.", 130, 138, i);

                                else if (is_frontier_x_R == 0 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 8.",130,  138, i);

                                else
                                    printf("\n\nLe point recherch%c se trouve ici.", 130);
                            }
                            break;

                        case 6:
                            new_xa = xb;
                            new_ya = yb - height;
                            new_xb = xb + width;
                            new_yb = yb;

                            printf("\nCoordonn%ces du coin sup%crieur gauche : (%d, %d)", 130, 130, new_xa, new_ya);
                            printf("\nCoordonn%ces du coin inf%crieur droit  : (%d, %d)", 130, 130, new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if (is_frontier_x_L == 0  && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 9.", 130, 138, i);

                                else if (is_frontier_x_L == 1 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d, 8 & 9.", 130, 138, i);

                                else if (is_frontier_x_R == 1 && is_frontier_y_down == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 9.", 130, 138, i);

                                else
                                    printf("\n\nLe point recherch%c se trouve ici.", 130);
                            }
                            break;

                        case 7:
                            new_xa = 0;
                            new_ya = yb;
                            new_xb = xa;
                            new_yb = yb + height;

                            printf("\nCoordonn%ces du coin sup%crieur gauche : (%d, %d)", 130, 130, new_xa, new_ya);
                            printf("\nCoordonn%ces du coin inf%crieur droit  : (%d, %d)", 130, 130, new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if (is_frontier_x_R == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 8.", 130, 138, i);

                                else
                                    printf("\n\nLe point recherch%c se trouve ici.", 130);
                            }
                            break;

                        case 8:
                            new_xa = xb - width;
                            new_ya = yb;
                            new_xb = xb;
                            new_yb = yb + height;

                            printf("\nCoordonn%ces du coin sup%crieur gauche : (%d, %d)", 130, 130, new_xa, new_ya);
                            printf("\nCoordonn%ces du coin inf%crieur droit  : (%d, %d)", 130, 130, new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                            {
                                if (is_frontier_x_R == 1)
                                    printf("\n\nLe point recherch%c se trouve sur la fronti%cre zones %d & 9.", 130, 138, i);

                                else
                                    printf("\n\nLe point recherch%c se trouve ici.", 130);
                            }
                            break;

                        case 9:
                            new_xa = xb;
                            new_ya = yb;
                            new_xb = xb + width;
                            new_yb = yb + height;

                            printf("\nCoordonn%ces du coin sup%crieur gauche : (%d, %d)", 130, 130, new_xa, new_ya);
                            printf("\nCoordonn%ces du coin inf%crieur droit  : (%d, %d)", 130, 130, new_xb, new_yb);

                            if (zone_number_xb == new_xb && zone_number_yb == new_yb)
                                printf("\n\nLe point recherch%c se trouve ici.", 130);

                            break;
                    }
                }
                printf("\n================================================================\n");
                break;

            case 2:
                running = 0;
                break;
        }
    } while (running);

    return 0;
}
