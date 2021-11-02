#include <stdio.h>


int main(int argc, char **arg){

    unsigned short number = 0;
    printf("ur number pls ? \n");
    scanf("%hu", &number);
    if(number <= 9){
        switch (number)
        {
            case 0:
                printf("non il faut 6 barres pour écrire 0 ! Il n'est pas magique !");
                break;

            case 1:
                printf("non il faut 2 barres pour écrire 1 ! Il n'est pas magique !");
                break;

            case 2:
                printf("non il faut 5 barres pour écrire 2 ! Il n'est pas magique !");
                break;

            case 3:
                printf("non il faut 5 barres pour écrire 3 ! Il n'est pas magique !");
                break;

            case 7:
                printf("non il faut 3 barres pour écrire 7 ! Il n'est pas magique !");
                break;

            case 8:
                printf("non il faut 7 barres pour écrire 8 ! Il n'est pas magique !");
                break;

            case 9:
                printf("non il faut 6 barres pour écrire 9 ! Il n'est pas magique !");
                break;
                
            case 4:
            case 5:
            case 6:
                printf("Il est  magique !");
                break;
            
            default:
                printf("not a number");
                break;
        }
    }else{

        unsigned short first = number /10;
        unsigned short second = number %10;
        printf("First number:%hu\nsecond: %hu\ninital: %hu\n", first, second,number);
        unsigned short getAddNumber = first + second;
        printf("%d + %d = %d\n", first, second, getAddNumber);
        switch (getAddNumber)
        {
            case 1:
                printf("non il faut 2 barres pour écrire 1 ! Il n'est pas magique !");
                break;

            case 2:
                printf("non il faut 5 barres pour écrire 2 ! Il n'est pas magique !");
                break;

            case 3:
                printf("non il faut 5 barres pour écrire 3 ! Il n'est pas magique !");
                break;

            case 7:
                printf("non il faut 3 barres pour écrire 7 ! Il n'est pas magique !");
                break;

            case 8:
                printf("non il faut 7 barres pour écrire 8 ! Il n'est pas magique !");
                break;

            case 9:
                printf("non il faut 6 barres pour écrire 9 ! Il n'est pas magique !");
                break;
                
            case 4:
            case 5:
            case 6:
                printf("Il est  magique !");
                break;
            
            default:
                printf("not a number");
                break;
        }

    }

    return 0;
}
/*
═══╗
   ║
╔══╝
║
╚═══
*/