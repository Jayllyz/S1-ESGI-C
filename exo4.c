/*
    Objectif : Chercher les nombres sympatiques entre [a,b]
    Autheurs : Anto BENEDETTI, Antony DAVID, Anthony JABRE
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
    int num_of_0 = 0; // Nombre de 0 dans le nombre binaire
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
        printf("\nExercic&e 4 :\n1. Lancer\n2. Quitter\nEntrez votre choix : ");
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
                while (type_check != 2)
                {
                    printf("ERREUR : Vous avez saisi un caract%cre.\nVeuillez r%cessayer : ", 138, 130);
                    fflush(stdin);
                    type_check = scanf("%lld %lld", &a_dec, &b_dec);
                }

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
                    if (i <= 0)
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
                            compteur++;
                        }

                        else // Bit égal à 0
                        {
                            num_of_0++;
                            compteur++;
                        }

                        i /= 2;
                        bin += rem * j;
                        j *= 10;
                    }

                    // Traitement du cas négatif
                    if (negative)
                    {
                        binary_negative = bin;
                        // recherche du premier 0 dans le nombre binaire et sauvegarde de la place du 0 dans find_first_0
                        while (bin % 2 != 0)
                        {
                            find_first_0++;
                            bin /= 10;
                        }
                        j = 1;

                        //boucle permettant de faire +1 a notre nombre binaire et nb sauvegarde dans binary_negative
                        while (find_first_0 > 0)
                        {
                            binary_negative -= j;
                            j *= 10;
                            find_first_0--;
                        }
                        binary_negative += j;

                        // Boucle de transformation de notre nb binaire en transformant les 1 en 0 et vice-versa
                        // Valeur récupérée dans binary_switch
                        num_of_0 = 0;
                        num_of_1 = 0;
                        compteur = 0;
                        while (binary_negative > 0)
                        {
                            if (binary_negative % 2 == 0)
                            {
                                rem = 1;
                                binary_switch += rem * j;
                                j = j * 10;
                            }
                            else
                            {
                                rem = 0;
                                binary_switch += rem * j;
                                j = j * 10;
                            }
                            nb_bit_before++;
                            binary_negative /= 10;
                        }

                        // Check du cas ou l'on fini avec un binary_switch égal a 0
                        if (binary_switch == 0)
                            num_of_1++;


                        // Calcul du nombre de 1 et 0 dans notre bianire final
                        while (binary_switch > 0)
                        {
                            if(binary_switch % 2 == 0) {
                                num_of_0++;
                                compteur++;
                            }

                            else {
                                num_of_1++;
                                compteur++;
                            }

                            binary_switch /= 10;
                        }
                    }

                    //récupération du nombre de 0 transformé en 1 au niveau des bit de poids fort
                    num_of_0 = num_of_0 + (nb_bit_before-compteur);
                    compteur = compteur + (nb_bit_before-compteur);

                    //ajout des nb de 1 et 0 sur 2 octet
                    if(negative == 1)
                    {
                        while(compteur < 16)
                        {
                            compteur++;
                            num_of_1++;
                        }
                    }
                    else
                    {
                        while(compteur < 16)
                        {
                            compteur++;
                            num_of_0++;
                        }
                    }

                    //comparaison du nb de 0 et 1 pour savoir si on print ou non
                    if (num_of_1 == num_of_0 && goodCounter == 0)
                    {
                        goodValue = actual_value; // Le premier bon nombre est dans goodValue
                        goodCounter++;
                    }
                    else if (num_of_1 == num_of_0 && goodCounter == 1)
                    {
                        printf("%d",goodValue); // Le premier bon nombre
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
                        printf(" et %d", goodValue);

                        // Si on trouve qu'un seul bon qui est le dernier
                    else if (num_of_1 == num_of_0  && temp == b_dec && goodCounter == 1)
                        printf("%d", goodValue);

                        // Si on trouve qu'un seul bon qui n'est pas le dernier
                    else if (temp == b_dec && goodCounter == 1 && num_of_1 != num_of_0)
                        printf("%d", goodValue);

                    // Réinitialisation de l'ensemble des variables pour le prochain cas
                    i = temp;
                    bin = 0;
                    negative = 0;
                    binary_switch = 0;
                    find_first_0 = 0;
                    j = 1;
                    num_of_0 = 0;
                    num_of_1 = 0;
                    compteur = 0;
                    nb_bit_before = 0;
                }

                if (goodValue == 0)
                    printf("\nAucun nombre sympatique trouvé dans [%lld, %lld]\n", a_dec, b_dec);

                printf("\n\n");
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
