/*
    Objectif : Définir si un chiffre/nombre est magique, selon sa représentation graphique.
    Auteurs  : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 02/11/2021
*/


#include <stdio.h>


int main(int argc, char **arg)
{
    // Variables relatives au bon fonctionnement du programme
    unsigned char running = 1; // 1: le programme est répété, 0: le programme s'arrête
    int usr_inpt; // Saisie de l'utilisateur
    unsigned char type_check; // Nombre de valeurs correctement scannées
    unsigned char check_step; // Nombre d'étapes de vérification validées
    
    // Variables relatives à l'exercice
    unsigned char n; // Nombre choisi par l'utilisateur
    unsigned char bars; // Barres nécessaires pour un chiffre
    unsigned char i; // Compteur pour boucle
    unsigned char digit1; // Premier chiffre du nombre
    unsigned char digit2; // Deuxième chiffre du nombre
    unsigned char test_digit; // Sélection du chiffre à traiter
    unsigned char bars_sum; // Somme des barres des deux chiffres 
    unsigned char is_good=0; // Egal à 1 si le nombre est magique

    // Boucle principale permettant de répéter le programme
    do
    {
        printf("\nExercice 2 :\n1. Lancer\n2. Quitter\nEntrez votre choix : ");
        fflush(stdin); // Purge du buffer d'entrées pour éviter tout conflit. Valable pour tous
        type_check = scanf("%d", &usr_inpt);
        
        
        // Vérification de la saisie de "usr_inpt" pour le menu
        while (check_step != 3)
        {
            check_step = 0; // Rénitialisation de la variable pour répéter le processus de vérification

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
        check_step = 0; // Rénitialisation de la variable pour les futures vérifications


        switch (usr_inpt)
        {
            // 1. Lancer
            case 1:
                printf("Saisissez un nombre entre 0 et 99 : ");
                fflush(stdin);
                type_check = scanf("%d", &usr_inpt);
                
                // Vérification de la saisie
                while (check_step != 3)
                {
                    check_step = 0; // Rénitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 1)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%d", &usr_inpt);
                    }
                    else
                        check_step++;

                    // Si la valeur est négative
                    if (usr_inpt < 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur n%cgative.\nVeuillez r%cessayer : ", 130, 130);
                        fflush(stdin);
                        type_check = scanf("%d", &usr_inpt);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (usr_inpt > 99)
                    {
                        printf("ERREUR : Vous avez saisi une valeur sup%crieure %c 99.\nVeuillez r%cessayer : ", 130, 133, 130);
                        fflush(stdin);
                        type_check = scanf("%d", &usr_inpt);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Réinitialisation de la variable pour les futures vérifications

                n = usr_inpt; // Affection de la saisie de l'utilisateur à la variable n

                // Si 'n' est un chiffre
                if (n < 10)
                {
                    switch (n)
                    {
                        // Les chiffres sont regroupés par le nombre de barres nécessaires                                
                        case 0:
                        case 6:
                        case 9:
                            bars = 6;
                            break;    
                        
                        case 1:
                            bars = 2;
                            break;
                        
                        case 2:
                        case 3:
                        case 5:
                            bars = 5;
                            break;
                        
                        case 4:
                            bars = 4;
                            break;
                        
                        case 7:
                            bars = 3;
                            break;
                        
                        case 8:
                            bars = 7;
                            break;
                    }
                }
                
                // Si 'n' est un nombre
                else
                {
                    // Affectation des chiffres aux variables correspondantes
                    digit1 = n / 10;
                    digit2 = n % 10;
                    test_digit = digit1;
                    bars_sum = 0;

                    // Boucle pour l'addition des barres des chiffres
                    for (i = 1; i <= 2; ++i)
                    {
                        // Changement du chiffre à traiter
                        if (i == 2)
                            test_digit = digit2;

                        // Les chiffres sont regroupés par le nombre de barres nécessaires
                        switch (test_digit)
                        {
                            case 0:
                            case 6:
                            case 9:
                                bars = 6;
                                bars_sum += bars;
                                break;

                            case 1:
                                bars = 2;
                                bars_sum += bars;
                                break;

                            case 2:
                            case 3:
                            case 5:
                                bars = 5;
                                bars_sum += bars;
                                break;

                            case 4:
                                bars = 4;
                                bars_sum += bars;
                                break;

                            case 7:
                                bars = 3;
                                bars_sum += bars;
                                break;

                            case 8:
                                bars = 7;
                                bars_sum += bars;
                                break;
                        }
                        if (i == 1)
                            printf("\nPremier chiffre    : %d --> %d barres", digit1, bars);
                        
                        else 
                            printf("\nDeuxi%cme chiffre   : %d --> %d barres", 138, digit2, bars);
                    }
                    printf("\nSomme des barres   : %d", bars_sum);
                    printf("\nSomme des chiffres : %d\n", digit1 + digit2);

                    /* 
                        Si le nombre de barres des 2 chiffres composant le nombre
                        et la somme des 2 chiffres sont égaux,
                        on affecte la valeur 1 à "is_good"
                        afin d'indiquer que c'est un nombre magique. 
                    */
                    if (bars_sum == digit1 + digit2)
                        is_good = 1;
                }

                // Test final pour voir si c'est un chiffre/nombre magique
                if ((n < 10 && n == 4) || n == 5 || n == 6)
                    printf("\nBarres n%ccessaires : %d\nLe chiffre est magique (chiffre = barres n%ccessaires).\n", 130, bars, 130);
                else if (is_good && n >= 10)
                    printf("Le nombre est magique (somme des chiffres = somme des barres).\n");
                else if (n < 10)
                    printf("\nBarres n%ccessaires : %d\nLe chiffre n'est pas magique (chiffre != barres n%ccessaires).\n", 130, bars, 130);
                else
                    printf("Le nombre n'est pas magique (somme des chiffres != somme des barres).\n");
                
                break;

            // Quitter
            case 2:
                running = 0; // Arrête le programme
                break;
        }
    } while (running);

    return 0;
}
