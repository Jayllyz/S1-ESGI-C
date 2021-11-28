/*
    Objectif : Chercher les nombres sympatiques entre [a,b]
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
    long long int a_dec; // Premier nombre de l'intervalle
    long long int b_dec; // Dernier nombre de l'intervalle
    long long int bin = 0; // Nombre binaire
    int rem; // Reste des divisions qui correspondent aux bits
    int actual_value; // Nombre de l'intervalle en cours de traitement
    // Variables de comptage
    int num_of_1 = 0; // Nombre de 1 dans le nombre binaire
    int num_of_0 = 16; // Nombre de 0 dans le nombre binaire
    long long int j = 1; // Puissance de 10
    int i; // Variable pour boucles & défini le nombre à traiter
    int temp;
    int goodValue = 0; // Valeurs sympathiques dans l'intervalle
    int goodCounter = 0; // Nombre de valeurs sympathiques dans l'intervalle
    // Variables pour la conversion d'un nb négatif
    unsigned char negative = 0; // 0: nombre négatif, 1: nombre positif
    int find_first_0 = 0;
    long long int binary_negative = 0; // Nombre binaire signé en négatif
    long long int binary_switch = 0;
    int compteur = 0;
    int nb_bit_before = 0;
    int nb_bit_after = 0;


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


        switch (usr_inpt) {
            // 1. Lancer
            case 1:
                printf("\nSaisissez une intervalle [a, b] : ");
                fflush(stdin);
                type_check = scanf("%lld %lld", &a_dec, &b_dec);


                // Vérification de la saisie de "usr_inpt" pour le menu
                while (check_step != 3)
                {
                    check_step = 0; // Rénitialisation de la variable pour répéter le processus de vérification

                    // Si l'utilisateur a saisi un caractère
                    if (type_check != 2)
                    {
                        printf("ERREUR : Vous avez saisi un caract%cre.\nveuillez r%cessayer : ", 138, 130);
                        fflush(stdin);
                        type_check = scanf("%lld %lld", &a_dec, &b_dec);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop petite
                    if (a_dec < -32768 || b_dec < -32768)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop petite.\nveuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%lld %lld", &a_dec, &b_dec);
                    }
                    else
                        check_step++;

                    // Si la valeur est trop grande
                    if (a_dec > 65535 || b_dec > 65535)
                    {
                        printf("ERREUR : Vous avez saisi une valeur trop grande.\nveuillez r%cessayer : ", 130);
                        fflush(stdin);
                        type_check = scanf("%lld %lld", &a_dec, &b_dec);
                    }
                    else
                        check_step++;
                }
                check_step = 0; // Rénitialisation de la variable pour les futures vérifications

                // Si a_dec > b_dec, on permute les deux
                if (a_dec > b_dec)
                {
                    a_dec += b_dec;
                    b_dec = a_dec - b_dec;
                    a_dec -= b_dec;
                }

                // Parcours et traitement des nombres entre a et b
                for (i = a_dec; i <= b_dec; i++)
                {
                    actual_value = i;
                    temp = i;

                    // Cas spécial du nombre négatif --> initialisation du bool negative à 1 et transformation en nb positif
                    if (i < 0)
                    {
                        negative = 1;
                        i *= -1;
                    }

                    // Boucle decimal to binary
                    // et récupération de la valeur dans bin (on calcul en même temps le nb de 0 et 1)
                    while (i != 0)
                    {
                        rem = i % 2;

                        if (rem) // Bit égal à 1
                        {
                            num_of_1++;
                            num_of_0--;
                        }

                        i /= 2;
                        bin += rem * j;
                        j *= 10;
                    }

                    // Traitement du cas négatif
                    if (negative)
                    {
                        binary_negative = 0;
                        j = 1;
                        compteur = 0;

                        // Recherche du premier 1 à partir de la droite
                        while (bin % 2 != 1)
                        {
                            j = j*10;
                            compteur++;
                            bin /= 10;
                        }
                        // Si le premier nombre est directement un 1
                        binary_negative = binary_negative + (bin % 10) * j;
                        bin /= 10;
                        j = j*10;


                        while(bin > 0) // On inverse les autres bits restants dans bin et on les stocke dans binary_negative
                        {
                            if (bin % 2 == 0)
                            {
                                rem = 1;
                                binary_negative += rem * j;
                                j = j * 10;
                                compteur++;
                            }
                            else
                            {
                                rem = 0;
                                binary_negative += rem * j;
                                j = j * 10;
                                compteur++;
                            }
                            bin /= 10;
                        }
                        while(compteur < 15) // On complète ce qui reste pour atteindre 2 octets dans binary_negative
                        {
                            binary_negative = binary_negative + j;
                            j = j *10;
                            compteur++;
                        }

                        // Calcul du nombre de 1 et 0 dans notre binaire final
                        num_of_0 = 16;
                        num_of_1 = 0;

                        while (binary_negative > 0) // On compte le nombre de 1 et 0 dans notre nombre
                        {
                            if(binary_negative % 2 == 0)
                            {
                                num_of_1++;
                                num_of_0--;
                            }
                            binary_negative /= 10;
                        }
                    }

                    // Comparaison du nb de 0 et 1 pour savoir si on print ou non
                    if (num_of_1 == num_of_0 && goodCounter == 0)
                    {
                        goodValue = actual_value; // Le premier bon nombre est dans goodValue
                        goodCounter++;
                    }
                    else if (num_of_1 == num_of_0 && goodCounter == 1)
                    {
                        printf("Les nombres sympathiques entre a et b sont : %d", goodValue); // Le premier bon nombre
                        goodValue = actual_value;
                        goodCounter++;
                    }
                    else if (num_of_1 == num_of_0 && goodCounter > 1)
                    {
                        printf(", %d",goodValue); // On rajoute une virgule pour les prochains
                        goodValue = actual_value;
                    }
                    // Si on est arrivé au dernier nombre et qu'il est bon
                    if (temp == b_dec && goodCounter > 1)
                        printf(" et %d.", goodValue);

                        // Si on trouve qu'un seul bon qui est le dernier
                    else if (num_of_1 == num_of_0  && temp == b_dec && goodCounter == 1)
                        printf("Le seul nombre sympathique trouv%c entre a et b est : %d.\n", 130, goodValue);

                        // Si on trouve qu'un seul bon qui n'est pas le dernier
                    else if (temp == b_dec && goodCounter == 1 && num_of_1 != num_of_0)
                        printf("Le seul nombre sympathique trouv%c entre a et b est : %d.\n", 130, goodValue);

                    // Réinitialisation de l'ensemble des variables pour le prochain cas
                    i = temp;
                    bin = 0;
                    negative = 0;
                    binary_switch = 0;
                    j = 1;
                    num_of_0 = 16;
                    num_of_1 = 0;
                    compteur = 0;
                }

                if (goodValue == 0)
                    printf("\nAucun nombre sympatique trouv%c dans [%lld, %lld].\n", 130, a_dec, b_dec);

                break;

                // 2. Quitter
            case 2:
                running = 0;
                break;
        }
        goodValue=0;
        goodCounter=0;
    } while (running);

    return 0;
}
