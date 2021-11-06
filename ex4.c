/*
    Objectif : Chercher les noombres sympatiques entre [a,b]
    Autheurs : Anto BENEDETTI, Antony DAVID, Anthony JABRE
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int n=0;
    int running=1;
    long long int aDecimal=0;
    long long int bDecimal=0;
    long long int aBinary=0;
    long long int modulo=0;
    int numberOf1=0;
    int numberOf0=0;
    long long int j=1;
    long long int i = aDecimal;
    long long int temp = aDecimal;
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
                
                for( i=aDecimal; i<=bDecimal; i++){
                    temp = i;
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
                    if(numberOf1 == numberOf0){
                        printf("%lld,",aBinary);
                    }
                    i = temp;
                    aBinary=0;
                    modulo=0;
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