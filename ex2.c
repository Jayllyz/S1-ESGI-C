/*
    Objectif : Définir si un nombre est magique
    Autheurs : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 02/11/2021
*/
#include <stdio.h>

int main(int argc, char **arg){
    int is_good = 0; // variable permettant de savoir si le nombre est magique
    unsigned short number = 0;
    unsigned short getAddNumber;
    char running =1;
    int choice = 0;
    do
    {
        printf("\nExercice 2 :\n1. Lancer\n2. Quitter\nEntrez votre choix: ");
        fflush(stdin); // Vide le buffer d'entrées pour éviter les conflits
        scanf("%d", &choice); // La variable n sert également à stocker le choix de l'utilisateur
        switch (choice)
        {
        case 1:
                printf("Votre nombre (0-99) ? \n");
                scanf("%hu", &number);
                while(number > 99){//Securité si l'user entre un nombre trop grand
                    number /=10;
                }
                // premier cas le nombre que l'on nous donne comporte 2 chiffres
                if(number > 9) {
                    unsigned short first = number / 10;
                    unsigned short second = number % 10;
                    unsigned short test_number = first;
                    unsigned short first_add_number = 0; //addition des barres des chiffre du nombre
                    printf("Premier nombre:%hu\ndeuxieme: %hu\nnombre de base: %hu\n", first, second, number);
                    getAddNumber = first + second; //addition des 2 chifffres
                    printf("%d + %d = %d\n", first, second, getAddNumber);

                    //boucle de calcul de l'addition des barres des chiffre du nombre
                    for (int i = 0; i < 2; ++i) {
                        if (i == 1) {
                            test_number = second;
                        }
                        switch (test_number) {
                            case 0:
                                first_add_number = first_add_number + 6;
                                break;
                            case 1:
                                first_add_number = first_add_number + 2;
                                break;

                            case 2:
                                first_add_number = first_add_number + 5;
                                break;

                            case 3:
                                first_add_number = first_add_number + 5;
                                break;

                            case 7:
                                first_add_number = first_add_number + 3;
                                break;

                            case 8:
                                first_add_number = first_add_number + 7;
                                break;

                            case 9:
                                first_add_number = first_add_number + 6;
                                break;

                            case 4:
                                first_add_number = first_add_number + 4;
                                break;
                            case 5:
                                first_add_number = first_add_number + 5;
                                break;
                            case 6:
                                first_add_number = first_add_number + 6;
                                break;
                        }
                    }
                    // si le nombre de barres des 2 chiffres composant le nombre
                    // et la somme des 2 chiffres sont égaux
                    // on met la variable is_good a 1 afon d'indiquer que c'est un nombre magique
                    if (first_add_number == getAddNumber)
                    {
                        is_good = 1;
                    }else{
                        printf("%d =/= %d\n",getAddNumber, first_add_number);
                    }
                }

                // cas le +simple ou l'on nous donne 1 seul chiffre
                switch (number) {
                    case 4:
                    case 5:
                    case 6:
                        is_good = 1;
                        break;
                }

                //test final pour voir si c un nombre magique
                if(is_good)
                    printf("le chiffre est magique\n");
                else
                    printf("le chiffre n'est pas magique\n");
                break;

        case 2:
            running = 0;
            break;
        
        default:
            break;
        }
        
    } while (running);

    return 0;
}
