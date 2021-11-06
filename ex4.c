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
    int aDecimal=0;
    int bDecimal=0;
    int aBinary=0;
    int modulo=0;
    int j=1;
    int i = aDecimal;
    int temp = aDecimal;
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
                printf("a b ?\n");
                scanf("%d %d",&aDecimal,&bDecimal);
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
                            i /= 2;
                            aBinary += modulo * j;
                            j *= 10;
                        }
                    printf("%d\n", aBinary);
                    i = temp;
                    aBinary=0;
                    modulo=0;
                    j=1;
                }
                break;
            case 2: 
                running = 0; 
                break;
        }

    } while (running);
    return 0;
}