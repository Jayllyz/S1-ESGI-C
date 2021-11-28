/*
    Objectif : Renvoyer les nombres sympathiques dans un intervalle donné.
    Auteurs  : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 05/11/2021
*/


#include <stdio.h>


int main(int argc, char **argv)
{
    // Variables relatives au bon fonctionnement du programme
    unsigned char running = 1; // 1: le programme est répété, 0: le programme s'arrête
    int usr_inpt; // Saisie de l'utilisateur
    unsigned char type_check; // Nombre de valeurs correctement scannées
    unsigned char check_step; // Nombre d'étapes de vérification validées

    // Variables relatives à l'exercice
    int a_dec, b_dec; // Nombre décimal encadrant l'intervalle
    int bin; // Nombre binaire
    unsigned char is_negative; // Booléen si un nombre est négatif

    do
    {
        printf("\nExercice 4 :\n1. Lancer\n2. Quitter\nEntrez votre choix : ");
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
                printf("\nSaisissez l'intervalle [a, b] : ");
                fflush(stdin);
                type_check = scanf("%d", &usr_inpt);
                
                // Vérification de la saisie
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
                    if (usr_inpt < -32768)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez saisir soit '1', soit '2' : ");
                        fflush(stdin);
                        type_check = scanf("%d", &usr_inpt);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (usr_inpt > 65535)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez saisir soit '1', soit '2' : ");
                        fflush(stdin);
                        type_check = scanf("%d", &usr_inpt);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Rénitialisation de la variable pour les futures vérifications

                break;

            // 2. Quitter
            case 2:
                running = 0;
                break;
        }
    } while (running);
    
    return 0;
}
