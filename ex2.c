/*
    Objectif : Définir si un chiffre/nombre est magique, selon sa représentation graphique.
    Auteurs  : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 02/11/2021
*/


#include <stdio.h>


int main(int argc, char **arg)
{
    unsigned char running = 1; // 0 : arrêt du programme, 1 : execution du programme.
    int inpt; // Valeur saisie par l'utilisateur (choix du menu, chiffre/nombre pour le programme).
    unsigned char type_check; // 1 : scanf a bien récupéré un nombre, et non un autre type de valeur.
    unsigned char inpt_check; // Doit être égal à 3 pour que la valeur saisie par l'utilisateur soit conforme.
    unsigned char bars; // Barres nécessaires pour un chiffre
    unsigned char is_good; // Egal à 1 si le nombre est magique.
    

    // Boucle permettant de répéter le programme
    do
    {
        printf("\nExercice 2 :\n1. Lancer\n2. Quitter\nEntrez votre choix : ");
        fflush(stdin); // Purge du buffer pour éviter tout conflit avec les futurs scanf. Valable pour tous les fflush.
        type_check = scanf("%d", &inpt);
        
        
        // Vérification de la saisie de "inpt" pour le menu
        while (inpt_check != 3)
        {
            inpt_check = 0; // Rénitialisation de la variable pour répéter le processus de vérification

            // Si l'utilisateur a saisi un caractère
            if (type_check != 1)
            {
                printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez saisir soit '1', soit '2' : ", 138);
                fflush(stdin);
                type_check = scanf("%d", &inpt);
            }
            else
                inpt_check++;

            // Si la valeur est trop petite
            if (inpt < 0)
            {
                printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez saisir soit '1', soit '2' : ");
                fflush(stdin);
                type_check = scanf("%d", &inpt);
            }
            else
                inpt_check++;

            // Si la valeur est trop grande
            if (inpt > 2)
            {
                printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez saisir soit '1', soit '2' : ");
                fflush(stdin);
                type_check = scanf("%d", &inpt);
            }
            else
                inpt_check++;
        }
        inpt_check = 0; // Rénitialisation de la variable pour les futures vérifications


        switch (inpt)
        {
            // 1. Lancer
            case 1:
                printf("\nVeuillez saisir un nombre compris entre 0 et 99 (inclus) : ");
                fflush(stdin);
                type_check = scanf("%d", &inpt);

                // Vérification de la saisie de "inpt" pour le chiffre/nombre magique
                while (inpt_check != 3)
                {
                    inpt_check = 0; // Rénitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 1)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez saisir un nombre compris entre 0 et 99 (inclus) : ", 138);
                        fflush(stdin); // Purge du buffer nécessaire uniquement lorsque de la saisie de caractères
                        type_check = scanf("%d", &inpt);
                    }
                    else
                        inpt_check++;

                    // Si la valeur est trop petite
                    if (inpt < 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur n%cgative.\nVeuillez saisir un nombre compris entre 0 et 99 (inclus) : ", 130);
                fflush(stdin);
                        type_check = scanf("%d", &inpt);
                    }
                    else
                        inpt_check++;

                    // Si la valeur est trop grande
                    if (inpt > 99)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez saisir un nombre compris entre 0 et 99 (inclus) : ");
                fflush(stdin);
                        type_check = scanf("%d", &inpt);
                    }
                    else
                        inpt_check++;
                }
                inpt_check = 0; // Rénitialisation de la variable pour les futures vérifications


                // Si "inpt" est un nombre
                if (inpt > 9)
                {
                    unsigned char digit1 = inpt / 10; // Premier chiffre du nombre
                    unsigned char digit2 = inpt % 10; // Deuxième chiffre du nombre

                    unsigned char test_digit = digit1; // Sélection du chiffre à traiter
                    unsigned char bars_sum = 0; // Somme des barres des deux chiffres

                    // Boucle pour l'addition des barres des chiffres
                    for (int i = 1; i <= 2; ++i)
                    {
                        // Changement du chiffre à traiter
                        if (i == 2)
                            test_digit = digit2;

                        switch (test_digit)
                        {
                            case 0:
                                bars = 6;
                                bars_sum += bars;
                                break;
                            case 1:
                                bars = 2;
                                bars_sum += bars;
                                break;

                            case 2:
                                bars = 5;
                                bars_sum += bars;
                                break;

                            case 3:
                                bars = 5;
                                bars_sum += bars;
                                break;

                            case 4:
                                bars = 4;
                                bars_sum += bars;
                                break;
                            
                            case 5:
                                bars = 5;
                                bars_sum += bars;
                                break;
                            
                            case 6:
                                bars = 6;
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

                            case 9:
                                bars = 6;
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

                    // Si le nombre de barres des 2 chiffres composant le nombre
                    // et la somme des 2 chiffres sont égaux,
                    // on affecte la valeur 1 à "is_good" afin d'indiquer que c'est un nombre magique.
                    if (bars_sum == digit1 + digit2)
                        is_good = 1;
                }

                // Cas le plus simple où l'on nous donne 1 seul chiffre
                switch (inpt)
                {
                    case 4:
                    case 5:
                    case 6:
                        is_good = 1;
                        break;
                }

                // Test final pour voir si c'est un chiffre/nombre magique
                if (is_good && inpt < 10)
                    printf("\nLe chiffre est magique (chiffre = barres n%ccessaires).\n", 130);
                else if (is_good && inpt >= 10)
                    printf("\nLe nombre est magique (somme des chiffres = somme des barres).\n");
                else if (inpt < 10)
                    printf("\nLe chiffre n'est pas magique (chiffre != barres n%ccessaires).\n", 130);
                else
                    printf("\nLe nombre n'est pas magique (somme des chiffres != somme des barres).\n");
                
                break;


            // Quitter
            case 2:
                running = 0; // Arrête le programme
                break;
        }
        
    } while (running);


    return 0;
}
