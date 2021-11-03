int main(int argc, char **arg){
    int is_good = 0; // variable permettant de savoir si le nombre est magique
    unsigned short number = 0;
    unsigned short getAddNumber;
    printf("ur number pls ? \n");
    scanf("%hu", &number);

    // premier cas le nombre que l'on nous donne comporte 2 chiffres
    if(number > 9) {
        unsigned short first = number / 10;
        unsigned short second = number % 10;
        unsigned short test_number = first;
        unsigned short first_add_number = 0; //addition des barres des chiffre du nombre
        printf("First number:%hu\nsecond: %hu\ninital: %hu\n", first, second, number);
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
    {
        printf("le chiffre est magique");
    }
    else
    {
        printf("le chiffre n'est pas magique");
    }
    return 0;
}
