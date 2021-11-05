/*
    Objectif : Exercice 5, Calcul de salaire
    Autheurs : Anto BENEDETTI, Antony DAVID, Anthony JABRE
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int nb_jour_travail = 0;
    double salaire=0;
    double CA=0;
    double trajet_km=0;
    double commission = 0;
    double indemnite = 0;
    int indemnite_etranger;
    int choice=0;
    int running=1;
    do{
        printf("Exercice 5 :\n1. Lancer\n2. Quitter\nEntrez votre choix: ");
        fflush(stdin); // Vide le buffer d'entrées pour éviter les conflits
        if (scanf("%d", &choice) != 1) {
            printf("ERREUR : Vous n'avez pas entré un nombre.\n");
            return EXIT_FAILURE;
        }
        switch (choice) {
            case 1:
                printf("rentrez le salaire du commerciaux\n");
                scanf("%lf",&salaire);
                printf("rentrez le CA du commerciaux\n");
                scanf("%lf",&CA);
                printf("rentrez le trajet du commerciaux\n");
                scanf("%lf",&trajet_km);
                printf("l'employe de se trouve t'il a l'etranger ? appuyer sur 1 pour oui et 0 pour non\n");
                scanf("%d",&indemnite_etranger);

                //calcule de l'indemnité si le commercial travaille a l'étranger
                if (indemnite_etranger==1){
                    printf("combien de jour a travaille l'employer ?\n");
                    scanf("%d",&nb_jour_travail);
                }

                //calcule de la commission (check la sécurité si on rentre un chiffre néagatif)
                if(CA > 0 && CA <= 13000){
                    commission = commission+(CA*1.6)/100;
                }
                else if (CA <= 22000){
                    commission = commission+(CA*2.2)/100;
                }
                else if (CA > 22000){
                    commission = commission+(CA*3)/100;
                }
                else{
                    commission = 100;
                }
                printf("%d",nb_jour_travail);

                //calcul de l'indemnite de trajet
                indemnite = 0.5 * trajet_km;
                if(indemnite < 50){
                    indemnite = 50;
                }
                else if (indemnite > 250){
                    indemnite = 250;
                }
                if(indemnite_etranger){
                    commission = commission + nb_jour_travail*100;
                }

                //calcul du salaire final
                salaire = salaire + commission + indemnite;
                printf("le salaire du commercial est %lf\n",salaire);
                
                break;

            case 2:
                running = 0;
                break;
        }
    }while(running);
    return 0;
}
