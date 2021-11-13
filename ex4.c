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
long long int goodValue=0;
int goodCounter=0;


//varibale pour la conversion d'un nb négatif
int negative = 0;
int find_first_0 = 0;
long long int binary_negative;
long long int binary_switch = 0;
long long int actual_value;

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
            scanf("%lld %lld",&aDecimal,&bDecimal);
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
                if (i <= 0)
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
                    // recherche du premier 0 dans le nombre binaire et sauvegarde de la place du 0 dans find_first_0
                    while(aBinary%2 != 0)
                    {
                        find_first_0 = find_first_0 + 1;
                        aBinary = aBinary/10;
                    }

                    j = 1;
                    //boucle permettant de faire +1 a notre nombre binaire et nb sauvegarde dans binary_negative
                    while(find_first_0 > 0)
                    {
                        binary_negative = binary_negative - j;
                        j = j*10;
                        find_first_0 = find_first_0 - 1;
                    }
                    binary_negative = binary_negative + j;

                    //boucle de transformation de notre nb binaire en transformant les 1 en 0 et vice-versa
                    //valeur récupérer dans binary_switch
                    numberOf0 = 0;
                    numberOf1 = 0;
                    while(binary_negative > 0)
                    {
                        if(binary_negative%2 == 0)
                        {
                            modulo = 1;
                            binary_switch = binary_switch+modulo*j;
                            j = j*10;
                        }
                        else
                        {
                            modulo = 0;
                            binary_switch = binary_switch+modulo*j;
                            j = j*10;
                        }
                        binary_negative = binary_negative/10;
                    }

                    // check du cas ou lon fini avec un binary_switch égal a 0
                    if(binary_switch == 0)
                    {
                        numberOf1++;
                    }

                    // calcul du nombre de 1 et 0 dans notre bianire final
                    while(binary_switch > 0)
                    {
                        if(binary_switch%2 ==0)
                        {
                            numberOf0++;
                        }
                        else
                        {
                            numberOf1++;
                        }
                        binary_switch = binary_switch/10;
                    }

                }

                //comparaison du nb de 0 et 1 pour savoir si on print ou non
                if (numberOf1 == numberOf0 && goodCounter == 0){
                    goodValue = actual_value;//le premier bon nombre est dans goodValue
                    goodCounter++; //on increment
                }
                else if(numberOf1 == numberOf0 && goodCounter == 1){
                    
                    printf("%lld",goodValue);//le premier bon nombre
                    goodValue = actual_value;
                    goodCounter++; //on increment
                }
                else if(numberOf1 == numberOf0 && goodCounter > 1){
                    printf(",%lld",goodValue);//on rajoute une , pour les prochains
                    goodValue = actual_value;
                }
                if( temp == bDecimal && goodCounter > 1){
                    printf(" et %lld",goodValue);
                }
                else if(numberOf1 == numberOf0  && temp == bDecimal && goodCounter == 1){
                    printf("%lld",goodValue);
                }
                else if(temp == bDecimal && goodCounter == 1 && numberOf1 != numberOf0){//si on trouve qu'un seul bon qui n'est pas le dernier
                    printf("%lld",goodValue);
                }

                //reset de l'ensemble des variables pour le prochain cas
                i = temp;
                aBinary=0;
                negative = 0;
                binary_switch = 0;
                find_first_0 = 0;
                j=1;
                numberOf0=0;
                numberOf1=0;
            }
            if(goodValue == 0){
                printf("\nAucun nombre sympatique trouvé dans [%lld,%lld]\n",aDecimal,bDecimal);
            }
            printf("\n\n");
            break;
        case 2:
            running = 0;
            break;
    }
    goodValue=0;
    goodCounter=0;

} while (running);

return 0;
}
