/*
    Objectif : Définir si un chiffre/nombre est magique, selon sa représentation graphique.
    Auteurs  : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 02/11/2021
*/

#include <stdio.h>

int main(int argc, char **arg) {
    char is_good; // Egal à 1 si le nombre est magique.
    char scanf_verif; // 1 : scanf a bien récupéré un nombre, et non un autre type de valeur.
    char input_verif; // Doit être égal à 3 pour que la valeur entrée par l'utilisateur soit conforme.
    char number; // Nombre entré par l'utilisateur. Sert aussi à stocker le choix dans le menu principal.
    char running = 1; // 0 : arrêt du programme, 1 : execution du programme.
    char getAddNumber;
    

    // Boucle permettant de répéter le programme
    do {
        printf("\nExercice 2 :\n1. Lancer\n2. Quitter\nEntrez votre choix : ");
        scanf_verif = scanf("%d", &number); // Sert également à stocker le choix de l'utilisateur


        // Vérifications des valeurs entrées par l'utilisateur
        while (input_verif != 2) {
            input_verif = 0; // Réinitialisation de la variable
            
            // Si l'utilisateur entre une valeur autre qu'un nombre
            if (scanf_verif != 1) {
                printf("ERREUR : Vous avez entr%c une valeur autre qu'un nombre.\nVeuillez entrer un nombre entre 1 et 2 (inclus): ", 130);
                fflush(stdin); // Nécessité de vider le buffer d'entrées lorsqu'un charactère est entré
                scanf_verif = scanf("%d", &number);
            }
            else
                input_verif++; // La valeur entrée est bien un nombre

            // Si l'utilisateur entre une valeur non-commprise entre 1 et 2 (inclus)
            if (number < 1 || number > 2) {
                printf("ERREUR : Vous avez entr%c un nombre trop grand.\nVeuillez entrer un nombre entre 1 et 2 (inclus): ", 130);
                scanf_verif = scanf("%d", &number);
            }
            else
                input_verif++; // Le nombre entré est inférieur ou égale à 99
        }
        input_verif = 0; // Réinitialisation de la variable, sinon, les vérifications ne seront pas pris en compte lorsqu'on recomencera le programme.
        

        switch (number) {
            // 1. Lancer
            case 1:
                printf("\nVeuillez entrer un nombre compris entre 0 et 99 (inclus) : ");
                scanf_verif = scanf("%d", &number);

                // Vérifications des valeurs entrées par l'utilisateur
                while (input_verif != 3) {
                    input_verif = 0; // Réinitialisation de la variable
                    
                    // Si l'utilisateur entre une valeur autre qu'un nombre
                    if (scanf_verif != 1) {
                        printf("ERREUR : Vous avez entr%c une valeur autre qu'un nombre.\nVeuillez entrer un nombre entre 0 et 99 (inclus): ", 130);
                        fflush(stdin); // Nécessité de vider le buffer d'entrées lorsqu'un charactère est entré
                        scanf_verif = scanf("%d", &number);
                    }
                    else
                        input_verif++; // La valeur entrée est bien un nombre

                    // Si l'utilisateur entre une valeur supérieur à 99
                    if (number > 99) {
                        printf("ERREUR : Vous avez entr%c un nombre trop grand.\nVeuillez entrer un nombre entre 0 et 99 (inclus): ", 130);
                        scanf_verif = scanf("%d", &number);
                    }
                    else
                        input_verif++; // Le nombre entré est inférieur ou égale à 99

                    // Si l'utilisateur rentre une valeur négative
                    if (number < 0) {
                        printf("ERREUR : Vous avez entr%c un nombre n%cgatif.\nVeuillez entrer un nombre entre 0 et 99 (inclus): ", 130, 130);
                        scanf_verif = scanf("%d", &number);
                    }
                    else
                        input_verif++; // Le nombre entré est supérieur ou égale à 99
                }
                input_verif = 0; // Réinitialisation de la variable, sinon, les vérifications ne seront pas pris en compte lorsqu'on recomencera le programme.


                // Premier cas le nombre que l'on nous donne comporte 2 chiffres
                if (number > 9) {
                    char first = number / 10;
                    char second = number % 10;
                    char test_number = first;
                    char first_add_number = 0; //addition des barres des chiffre du nombre
                    printf("Premier chiffre :%d\nDeuxieme chiffre : %d\nNombre de base : %d\n", first, second, number);
                    getAddNumber = first + second; //addition des 2 chifffres
                    printf("%d + %d = %d\n", first, second, getAddNumber);

                    // Boucle de calcul de l'addition des barres des chiffre du nombre
                    for (int i = 0; i < 2; ++i) {
                        if (i == 1)
                            test_number = second;

                        switch (test_number) {
                            case 0:
                                first_add_number += 6;
                                break;
                            case 1:
                                first_add_number += 2;
                                break;

                            case 2:
                                first_add_number += 5;
                                break;

                            case 3:
                                first_add_number += 5;
                                break;

                            case 4:
                                first_add_number += 4;
                                break;
                            
                            case 5:
                                first_add_number += 5;
                                break;
                            
                            case 6:
                                first_add_number += 6;
                                break;

                            case 7:
                                first_add_number += 3;
                                break;

                            case 8:
                                first_add_number += 7;
                                break;

                            case 9:
                                first_add_number += 6;
                                break;
                        }
                    }
                    // Si le nombre de barres des 2 chiffres composant le nombre
                    // et la somme des 2 chiffres sont égaux,
                    // on affecte la valeur 1 à "is_good" afin d'indiquer que c'est un nombre magique.
                    if (first_add_number == getAddNumber)
                        is_good = 1;
                    else
                        printf("%d =/= %d\n",getAddNumber, first_add_number);
                }

                // Cas le plus simple où l'on nous donne 1 seul chiffre
                switch (number) {
                    case 4:
                    case 5:
                    case 6:
                        is_good = 1;
                        break;
                }

                // Test final pour voir si c'est un nombre magique
                if (is_good && number < 10)
                    printf("Le chiffre est magique.\n");
                else if (is_good && number >= 10)
                    printf("Le nombre est magique.\n");
                else if (number < 10)
                    printf("Le chiffre n'est pas magique.\n");
                else
                    printf("Le nombre n'est pas magique.\n");
                
                break;


            // Quitter
            case 2:
                running = 0; // Arrête le programme
                break;
        }
        
    } while (running);


    return 0;
}
