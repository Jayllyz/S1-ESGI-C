#include <stdio.h>


int main(int argc, char **argv){

    double aX;
    double aY;
    double bX;
    double bY;
    double new_aX = 0;
    double new_aY = 0;
    double new_bX = 0;
    double new_bY = 0;
    double find_aX;
    double find_aY;
    double find_bX;
    double find_bY;
    int nb_zone;

    printf("coord a(x,y) :\n");
    scanf("%lf %lf",&aX,&aY);
    printf("coord b(x,y) :\n");
    fflush(stdin);
    scanf("%lf %lf",&bX,&bY);
    printf("rentrez les coordonnées afin de rechercher sa zone");


    double horizontal = bX - aX;
    double vertical = bY - aY;
    printf("\n");

    fflush(stdin);
    scanf("%lf %lf",&find_aX,&find_aY);
    fflush(stdin);
    scanf("%lf %lf",&find_bX,&find_bY);
    int find = 0;
    int zone_number_bX;
    int zone_number_bY;
    int is_frontier_x = 0;
    int is_frontier_y = 0;
    for (double i = horizontal; i <= horizontal*3 && find == 0; i = i + horizontal) {
        if (find_bX <= i) {
            if (find_bX == i)
            {
                is_frontier_x = 1;
            }
            zone_number_bX = i;
            find = 1;
        }
    }
    find = 0;
    for (double j = vertical; j <= vertical*3 && find == 0; j = j + vertical) {
        if (find_bY <= j) {
            if (find_bY == j)
            {
                is_frontier_y = 1;
            }
            zone_number_bY = j;
            find = 1;
        }
    }

    for (int i = 1; i <= 9; ++i) {
        switch (i) {
            case 1 :
                new_aX = aX - horizontal;
                new_aY = aY - vertical;
                new_bX = aX;
                new_bY = aY;
                printf("zone 1\n");
                printf("coord a(%lf,%lf) \n", new_aX, new_aY);
                printf("coord b(%lf,%lf) \n", new_bX, new_bY);
                if (zone_number_bX == new_bX && zone_number_bY == new_bY && is_frontier_x != 1 && is_frontier_y != 1)
                {
                    printf("d'ailleur on se trouve zone %d\n",i);
                }
                if (zone_number_bX == new_bX && zone_number_bY == new_bY && is_frontier_x != 0 && is_frontier_y != 1)
                {
                    printf("d'ailleur il y a frontiére avec zone 4 et zone %d",i);
                }
                break;
            case 2 :
                new_aX = aX;
                new_aY = aY - vertical;
                new_bX = aX + horizontal;
                new_bY = aY;
                printf("zone 2\n");
                printf("coord a(%lf,%lf) \n", new_aX, new_aY);
                printf("coord b(%lf,%lf) \n", new_bX, new_bY);
                if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                {
                    printf("d'ailleur on se trouve zone %d",i);
                }
                break;
            case 3 :
                new_aX = aX + horizontal;
                new_aY = aY - vertical;
                new_bX = aX + 2 * horizontal;
                new_bY = aY;
                printf("zone 3\n");
                printf("coord a(%lf,%lf) \n", new_aX, new_aY);
                printf("coord b(%lf,%lf) \n", new_bX, new_bY);
                if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                {
                    printf("d'ailleur on se trouve zone %d",i);
                }
                break;
            case 4 :
                new_aX = aX - horizontal;
                new_aY = aY;
                new_bX = aX;
                new_bY = aY + vertical;
                printf("zone 4\n");
                printf("coord a(%lf,%lf) \n", new_aX, new_aY);
                printf("coord b(%lf,%lf) \n", new_bX, new_bY);
                if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                {
                    printf("d'ailleur on se trouve zone %d",i);
                }
                break;
            case 5 :
                new_aX = aX;
                new_aY = aY;
                new_bX = bX;
                new_bY = bY;
                printf("zone 5\n");
                printf("coord a(%lf,%lf) \n", new_aX, new_aY);
                printf("coord b(%lf,%lf) \n", new_bX, new_bY);
                if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                {
                    printf("d'ailleur on se trouve zone %d\n",i);
                }
                break;
            case 6 :
                new_aX = bX;
                new_aY = bY - vertical;
                new_bX = bX + horizontal;
                new_bY = bY;
                printf("zone 6\n");
                printf("coord a(%lf,%lf) \n", new_aX, new_aY);
                printf("coord b(%lf,%lf) \n", new_bX, new_bY);
                if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                {
                    printf("d'ailleur on se trouve zone %d",i);
                }
                break;
            case 7 :
                new_aX = aX - horizontal;
                new_aY = bY;
                new_bX = aX;
                new_bY = bY + vertical;
                printf("zone 7\n");
                printf("coord a(%lf,%lf) \n", new_aX, new_aY);
                printf("coord b(%lf,%lf) \n", new_bX, new_bY);
                if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                {
                    printf("d'ailleur on se trouve zone %d",i);
                }
                break;
            case 8 :
                new_aX = bX - horizontal;
                new_aY = bY;
                new_bX = bX;
                new_bY = bY + vertical;
                printf("zone 8\n");
                printf("coord a(%lf,%lf) \n", new_aX, new_aY);
                printf("coord b(%lf,%lf) \n", new_bX, new_bY);
                if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                {
                    printf("d'ailleur on se trouve zone %d",i);
                }
                break;
            case 9 :
                new_aX = bX;
                new_aY = bY;
                new_bX = bX + horizontal;
                new_bY = bY + vertical;
                printf("zone 9\n");
                printf("coord a(%lf,%lf) \n", new_aX, new_aY);
                printf("coord b(%lf,%lf) \n", new_bX, new_bY);
                if (zone_number_bX == new_bX && zone_number_bY == new_bY)
                {
                    printf("d'ailleur on se trouve zone %d",i);
                }
                break;
        }

    }

    return 0;
}