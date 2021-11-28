/*
    Objectif : Calculer le salaire brut mensuel d'un commercial selon plusieurs facteurs
    Auteurs  : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 05/11/2021
*/


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    // Variables relatives au bon fonctionnement du programme
    unsigned char running = 1; // 1: le programme est répété, 0: le programme s'arrête
    int usr_inpt; // Saisie de l'utilisateur
    unsigned char type_check; // Nombre de valeurs correctement scannées
    unsigned char check_step; // Nombre d'étapes de vérification validées

    // Variables relatives à l'exercice
    unsigned char abroad; // 1: à l'étranger, 0: non
    int work_days = 0; // Jours de travail à l'étranger
    double salary = 0; // Salaire du commercial
    double turnover = 0; // Chiffre d'affaire HT réalisé par le commercial
    double commute = 0; // Distance entre le domicile et le lieu de travail
    double commission = 0; // Commission reçu selon le CA
    double indemnity = 0; // Indemnité reçue pour les trajets domicile/lieu de travail

    do
    {
        printf("\nExercice 5 :\n1. Lancer\n2. Quitter\nEntrez votre choix : ");
        fflush(stdin); // Purge du buffer d'entrées pour éviter tout conflit. Valable pour tous
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
            case 1:
                printf("\nSaisissez le salaire de base du commercial : ");
                fflush(stdin);
                type_check = scanf("%lf", &salary);

                // Vérification de la saisie
                while (check_step != 3)
                {
                    check_step = 0; // Rénitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 1)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%lf", &salary);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (salary < 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%lf", &salary);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (salary > 10000)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%lf", &salary);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Rénitialisation de la variable pour les futures vérifications


                printf("Saisissez le CA mensuel HT du commercial : ");
                fflush(stdin);
                type_check = scanf("%lf", &turnover);

                // Vérification de la saisie
                while (check_step != 3)
                {
                    check_step = 0; // Rénitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 1)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%lf", &turnover);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (turnover < 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%lf", &turnover);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (turnover > 1000000)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%lf", &turnover);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Rénitialisation de la variable pour les futures vérifications


                printf("Saisissez le trajet du commercial (en km) : ");
                fflush(stdin);
                type_check = scanf("%lf", &commute);

                // Vérification de la saisie
                while (check_step != 3)
                {
                    check_step = 0; // Rénitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 1)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%lf", &commute);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (commute < 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%lf", &commute);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (commute > 10000)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%lf", &commute);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Rénitialisation de la variable pour les futures vérifications


                printf("Le commercial se trouve t-il %c l'etranger ? [1] = Oui, [0] = Non : ", 133);
                fflush(stdin);
                type_check = scanf("%d", &abroad);

                // Vérification de la saisie
                while (check_step != 3)
                {
                    check_step = 0; // Rénitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 1)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%d", &abroad);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (abroad < 0)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d", &abroad);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (abroad > 1)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%d", &abroad);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Rénitialisation de la variable pour les futures vérifications


                // Calcul de l'indemnité si le commercial travaille à l'étranger
                if (abroad)
                {
                    printf("Saisissez le nombre de jours travaill%cs %c l'%ctranger : ", 130, 133, 130);
                    fflush(stdin);
                    type_check = scanf("%d", &work_days);

                    // Vérification de la saisie
                    while (check_step != 3)
                    {
                        check_step = 0; // Rénitialisation de la variable pour répéter le processus de vérification

                        // Si l'utilisateur a saisi un caractère
                        if (type_check != 1)
                        {
                            printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                            fflush(stdin);
                            type_check = scanf("%d", &work_days);
                        }
                        else
                            check_step++;

                        // Si la valeur est trop petite
                        if (work_days < 0)
                        {
                            printf("ERREUR : Vous avez saisi une valeur trop petite.\nVeuillez r%cessayer : ", 130);
                            fflush(stdin);
                            type_check = scanf("%d", &work_days);
                        }
                        else
                            check_step++;

                        // Si la valeur est trop grande
                        if (work_days > 100000)
                        {
                            printf("ERREUR : Vous avez saisi une valeur trop grande.\nVeuillez r%cessayer : ", 130);
                            fflush(stdin);
                            type_check = scanf("%d", &work_days);
                        }
                        else
                            check_step++;
                    }
                    check_step = 0; // Rénitialisation de la variable pour les futures vérifications


                }


                // Calcul de la commission
                if (turnover == 0)
                    commission = 100;

                else if (turnover <= 13000)
                    commission = turnover * 0.016;

                else if (turnover <= 22000)
                    commission = ((turnover-13000)*2.2)/100+(13000*0.016);

                else
                    commission = ((turnover-22000)*0.03)+(9000*0.022)+(13000*0.016);


                // Calcul de l'indemnité de déplacement
                indemnity = 0.5 * commute;

                if (indemnity < 50)
                    indemnity = 50;

                else if (indemnity > 250)
                    indemnity = 250;

                // Calcul de l'indemnité reçue par les commerciaux à l'étranger
                if (abroad)
                    indemnity += work_days * 100;


                // Calcul du salaire brut mensuel
                salary = salary + commission + indemnity;
                printf("\nLe salaire brut mensuel du commercial est %.2lf euros.\n", salary, 0x80);

                break;

            case 2:
                running = 0;
                break;
        }
    } while (running);

    return 0;
}
