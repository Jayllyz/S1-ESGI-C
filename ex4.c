/*
    Objectif : Chercher les noombres sympatiques entre [a,b]
    Autheurs : Anto BENEDETTI, Antony DAVID, Anthony JABRE
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    //variable sécurité
    int n=0;
    int running=1;

    //variable boucle principal
    long long int aDecimal=0;
    long long int bDecimal=0;
    long long int aBinary=0;
    long long int modulo;

    //variable de comptage
    int numberOf1=0;
    int numberOf0=0;
    long long int j=1;
    long long int i;
    long long int temp;

    //varibale pour la conversion d'un nb négatif
    int negative = 0;
    int find_first_1 = 1;
    long long int binary_negative;
    long long int binary_switch = 0;
    long long int binary_compare;
    int actual_value;

    do
    {
        printf("Exercice 4 :\n1. Lancer\n2. Quitter\nEntrez votre choix: ");
        fflush(stdin); // Vide le buffer d'entrées pour éviter les conflits
        if (scanf("%d", &n) != 1) {
            printf("ERREUR : Vous n'avez pas entré un nombre.\n");
            return EXIT_FAILURE;
        }
        switch (n) {
            // Lance le programme.
            case 1:
                printf("Votre intervalle [a,b] ?\n");
                scanf("%lld %lldd",&aDecimal,&bDecimal);
                printf("\n");
                //si aDecimal > bDecimal, on inverse les deux
                if(aDecimal > bDecimal){
                    temp = aDecimal;
                    aDecimal = bDecimal;
                    bDecimal = temp;
                }
                //parcours et traitement des nombres entre a et b
                for( i=aDecimal; i<=bDecimal; i++){
                    actual_value = i;
                    temp = i;
                    //cas spécial du nombre négatif -> initialisation du bool negative a 1 et transformation en nb positif
                    if (i < 0)
                    {
                        negative = 1;
                        i = i * -1;
                    }
                    // boucle decimal to binary
                    // et récupération de la valeur dans abinary ( on calcul en même temps le nb de 0 et 1)
                    while (i!=0) {
                        modulo = i % 2;
                        if (modulo == 1) {
                            numberOf1++;
                        }
                        else {
                            numberOf0++;
                        }
                        i /= 2;
                        aBinary += modulo * j;
                        j *= 10;
                    }
                    // traitement du cas négatif
                    if(negative)
                    {
                        binary_negative = aBinary;
                        binary_compare = aBinary;

                        // recherche du premier 0 dans le nombre binaire et sauvegarde de la place du 0 dans find_first_1
                        while(aBinary%2 != 1)
                        {
                            find_first_1 = find_first_1*10;
                            aBinary = aBinary/10;
                        }

                        //boucle permettant de faire +1 a notre nombre binaire et nb sauvegarde dans binary_negative
                        do {
                            binary_negative = binary_negative - find_first_1;
                            binary_compare = binary_compare/10;
                            find_first_1 = find_first_1*10;
                        }while(binary_compare%find_first_1 == 1);
                        binary_negative = binary_negative + find_first_1;

                        //boucle de transformation de notre nb binaire en transformant les 1 en 0 et vice-versa
                        //valeur récupérer dans binary_switch (calcul du nb de 0 et 1 en même temps)
                        j = 1;
                        numberOf0 = 0;
                        numberOf1 = 0;
                        while(binary_negative > 0)
                        {
                            if(binary_negative%2 == 0)
                            {
                                modulo = 1;
                                binary_switch = binary_switch+modulo*j;
                                numberOf1++;
                                j = j*10;
                            }
                            else
                            {
                                modulo = 0;
                                binary_switch = binary_switch+modulo*j;
                                numberOf0++;
                                j = j*10;
                            }
                            binary_negative = binary_negative/10;
                        }

                    }

                    //comparaison du nb de 0 et 1 pour savoir quelle variable print
                    // (abinary si le nb est positif) (binary_switch si le nb était négatif)
                    if(numberOf1 == numberOf0 && !negative) {
                        printf("%lld in binary and %d in decimal\n", aBinary,actual_value);
                    }
                    else if (numberOf1 == numberOf0)
                    {
                        printf("%lld in binary et %d in decimal\n",binary_switch,actual_value);
                    }

                    //reset de l'ensemble des variables pour le prochain cas
                    i = temp;
                    aBinary=0;
                    negative = 0;
                    binary_switch = 0;
                    find_first_1 = 1;
                    j=1;
                    numberOf0=0;
                    numberOf1=0;
                }
                printf("\n\n");
                break;
            case 2:
                running = 0;
                break;
        }

    } while (running);

    return 0;
}
