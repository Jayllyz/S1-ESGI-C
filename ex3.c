/*
    Objectif : Exercice 3
    Autheurs : Anto BENEDETTI, Antony DAVID, Anthony JABRE
*/
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
    int running=1;
    int n=0;
    // coordonnées de base
    double aX=0;
    double aY=0;
    double bX=0;
    double bY=0;
    // coordonnée des autres zones a initialisé au fur et a mesure du programme
    double new_aX = 0;
    double new_aY = 0;
    double new_bX = 0;
    double new_bY = 0;
    // coordonnée donnée par l'utilisateur a replacer dans une zone
    double find_aX=0;
    double find_aY=0;


 do {
        printf("Exercice 3 :\n1. Lancer\n2. Quitter\nEntrez votre choix: ");
        fflush(stdin); // Vide le buffer d'entrées pour éviter les conflits
        if(scanf("%d", &n) != 1) {
            printf("ERREUR : Vous n'avez pas entré un nombre.\n");
            return EXIT_FAILURE;
        }
        switch (n) {
            case 1:
                // récupération des coord de l'utilisateur
                printf("coord a(x,y) :\n");
                scanf("%lf %lf",&aX,&aY);
                printf("coord b(x,y) :\n");
                fflush(stdin);
                scanf("%lf %lf",&bX,&bY);

                //calcul de largeur et longueur d'une zone
                double horizontal = bX - aX;
                double vertical = bY - aY;
                printf("\n");

                fflush(stdin);
                // récupération de l'utilisateur des coordonnée a rechercher
                printf("Entrer les coord x et y a rechercher :\n");
                scanf("%lf %lf",&find_aX,&find_aY);
                int find = 0; // stopper le programme si on trouve
                int zone_number_bX;//coordonée Bx et By ou se situe les coord recherché
                int zone_number_bY;

                // booléen visant a savoir si il existe une frontière en x a gauche (L = left) de la zone ou a droite (R = rigth)
                int is_frontier_x_R = 0;
                int is_frontier_x_L = 0;
                int is_frontier_y_down = 0;

                //boucle afin de trouver dans quelle zone se situe les coord ainsi que définir si il y a des frontières en X
                for (double i = horizontal; i <= horizontal*3 && find == 0; i = i + horizontal) {
                    if (find_aX <= i) {
                        if (find_aX == i)
                        {
                            is_frontier_x_R = 1;
                        }
                        if (find_aX == i-horizontal){
                            is_frontier_x_L = 1;
                        }
                        zone_number_bX = i;
                        find = 1;
                    }
                }
                find = 0;

                //boucle afin de trouver dans quelle zone se situe les coord ainsi que définir si il y a des frontières en Y
                for (double j = vertical; j <= vertical*3 && find == 0; j = j + vertical) {
                    if (find_aY <= j) {
                        if (find_aY == j)
                        {
                            is_frontier_y_down = 1;
                        }
                        zone_number_bY = j;
                        find = 1;
                    }
                }

                // boucle principal parcourant les zones afin de calculer les coord des zones et vérifier si les coord sont dedans
                for (int i = 1; i <= 9; ++i) {
                    switch (i) {
                        case 1 :
                            new_aX = aX - horizontal;
                            new_aY = aY - vertical;
                            new_bX = aX;
                            new_bY = aY;
                            printf("\n================================\nzone 1\n");
                            printf("coord a(%.2lf,%.2lf) \n", new_aX, new_aY);
                            printf("coord b(%.2lf,%.2lf) \n", new_bX, new_bY);
                            if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                            {
                                if (is_frontier_x_R == 1 && is_frontier_y_down == 0)
                                {
                                    printf("On se trouve zone %d et 2\n",i);
                                }
                                else if (is_frontier_x_R == 0 && is_frontier_y_down == 1){
                                    printf("On se trouve zone%d et 4\n",i);
                                }
                                else if (is_frontier_x_R == 1 && is_frontier_y_down == 1){
                                    printf("Nous avons une frontiere avec zone 1,2,4 et 5\n");
                                }
                                else if(is_frontier_x_L == 1 && is_frontier_y_down == 1){
                                    printf("Nous avons une frontiere avec zone %d et 4\n",i);
                                }
                                else
                                {
                                    printf("On se trouve zone %d",i);
                                }
                            }
                            break;
                        case 2 :
                            new_aX = aX;
                            new_aY = aY - vertical;
                            new_bX = aX + horizontal;
                            new_bY = aY;
                            printf("\n================================\nzone 2\n");
                            printf("coord a(%.2lf,%.2lf) \n", new_aX, new_aY);
                            printf("coord b(%.2lf,%.2lf) \n", new_bX, new_bY);
                            if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                            {
                                if (is_frontier_x_R == 1 && is_frontier_y_down == 0)
                                {
                                    printf("Nous avons une frontiere avec %d et 3\n",i);
                                }
                                else if (is_frontier_x_R == 0 && is_frontier_y_down == 1)
                                    printf("d'ailleur on se trouve zone %d et 5\n",i);
                                else if(is_frontier_x_R == 1 && is_frontier_y_down == 1){
                                    printf("nous avons une frontiere avec zone 2,3,5 et 6\n");
                                }
                                else if (is_frontier_x_L == 0 && is_frontier_y_down == 1){
                                    printf("nous avons une frontiere avec %d et 5\n",i);
                                }
                                else{
                                    printf("On se trouve zone %d\n",i);
                                }
                            }
                            break;
                        case 3 :
                            new_aX = aX + horizontal;
                            new_aY = aY - vertical;
                            new_bX = aX + 2 * horizontal;
                            new_bY = aY;
                            printf("\n================================\nzone 3\n");
                            printf("coord a(%.2lf,%.2lf) \n", new_aX, new_aY);
                            printf("coord b(%.2lf,%.2lf) \n", new_bX, new_bY);
                            if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                            {
                                if(is_frontier_x_L == 0  && is_frontier_y_down == 1){
                                    printf("nous avons une frontiere avec %d et 6\n",i);
                                }
                                else if(is_frontier_x_R == 1 && is_frontier_y_down == 1){
                                    printf("nous avons une frontiere avec zone %d et 6\n",i);
                                }
                                else{
                                        printf("On se trouve zone %d\n",i);
                                }
                            }
                            break;
                        case 4 :
                            new_aX = aX - horizontal;
                            new_aY = aY;
                            new_bX = aX;
                            new_bY = aY + vertical;
                            printf("\n================================\nzone 4\n");
                            printf("coord a(%.2lf,%.2lf) \n", new_aX, new_aY);
                            printf("coord b(%.2lf,%.2lf) \n", new_bX, new_bY);
                            if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                            {
                                if(is_frontier_x_R == 1  && is_frontier_y_down == 0){
                                    printf("nous avons une frontiere avec %d et 5\n",i);
                                }else if(is_frontier_x_R == 1 && is_frontier_y_down ==1){
                                    printf("nous avons une frontiere avec %d,5,7 et 8\n",i);
                                }
                                else if(is_frontier_x_R == 0 && is_frontier_y_down ==1){
                                    printf("nous avons une frontiere avec %d et 7 \n",i);
                                }
                                else if(is_frontier_x_L == 1 && is_frontier_y_down ==1){
                                    printf("nous avons une frontiere avec %d et 7",i);
                                }
                                else{
                                    printf("On se trouve zone %d\n",i);
                                }
                            }
                            break;
                        case 5 :
                            new_aX = aX;
                            new_aY = aY;
                            new_bX = bX;
                            new_bY = bY;
                            printf("\n================================\nzone 5\n");
                            printf("coord a(%.2lf,%.2lf) \n", new_aX, new_aY);
                            printf("coord b(%.2lf,%.2lf) \n", new_bX, new_bY);
                            if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                            {
                                if(is_frontier_x_R == 1  && is_frontier_y_down == 0){
                                    printf("nous avons une frontiere avec %d et 6\n",i);
                                }
                                else if(is_frontier_x_R == 1 && is_frontier_y_down ==1){
                                    printf("nous avons une frontiere avec %d,6,8 et 9\n",i);
                                }
                                else if(is_frontier_x_R == 0 && is_frontier_y_down ==1){
                                    printf("nous avons une frontiere avec %d et 8 \n",i);
                                }
                                else{
                                    printf("On se trouve zone %d\n",i);
                                }
                            }
                            break;
                        case 6 :
                            new_aX = bX;
                            new_aY = bY - vertical;
                            new_bX = bX + horizontal;
                            new_bY = bY;
                            printf("\n================================\nzone 6\n");
                            printf("coord a(%.2lf,%.2lf) \n", new_aX, new_aY);
                            printf("coord b(%.2lf,%.2lf) \n", new_bX, new_bY);
                            if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                            {
                                if(is_frontier_x_L == 0  && is_frontier_y_down == 1){
                                    printf("nous avons une frontiere avec %d et 9\n",i);
                                }
                                else if(is_frontier_x_L == 1  && is_frontier_y_down == 1){
                                    printf("nous avons une frontiere avec %d,8 et 9\n",i);
                                }
                                else if(is_frontier_x_R == 1  && is_frontier_y_down == 1){
                                    printf("nous avons une frontiere avec %d et 9\n",i);
                                }
                                else{
                                    printf("On se trouve zone %d\n",i);
                                    }
                            }
                            break;
                        case 7 :
                            new_aX = aX - horizontal;
                            new_aY = bY;
                            new_bX = aX;
                            new_bY = bY + vertical;
                            printf("\n================================\nzone 7\n");
                            printf("coord a(%.2lf,%.2lf) \n", new_aX, new_aY);
                            printf("coord b(%.2lf,%.2lf) \n", new_bX, new_bY);
                            if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                            {
                                if(is_frontier_x_R == 1  && is_frontier_y_down == 0){
                                    printf("nous avons une frontiere avec %d et 8\n",i);
                                }
                                else{
                                    printf("On se trouve zone %d\n",i);
                                }
                            }
                            break;
                        case 8 :
                            new_aX = bX - horizontal;
                            new_aY = bY;
                            new_bX = bX;
                            new_bY = bY + vertical;
                            printf("\n================================\nzone 8\n");
                            printf("coord a(%.2lf,%.2lf) \n", new_aX, new_aY);
                            printf("coord b(%.2lf,%.2lf) \n", new_bX, new_bY);
                            if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                            {
                                if(is_frontier_x_R == 1  && is_frontier_y_down == 0){
                                    printf("nous avons une frontiere avec %d et 9\n",i);
                                }
                                else{
                                    printf("On se trouve zone %d\n",i);
                                }
                            }
                            break;
                        case 9 :
                            new_aX = bX;
                            new_aY = bY;
                            new_bX = bX + horizontal;
                            new_bY = bY + vertical;
                            printf("\n================================\nzone 9\n");
                            printf("coord a(%.2lf,%.2lf) \n", new_aX, new_aY);
                            printf("coord b(%.2lf,%.2lf) \n", new_bX, new_bY);
                            if (zone_number_bX == new_bX && zone_number_bY == new_bY){
                                printf("On se trouve zone %d\n",i);
                            }
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
