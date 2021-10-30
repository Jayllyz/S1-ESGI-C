/*
    Objectif : Dessiner avec des "*" une forme variable en taille.
    Date : 30/10/2021

*/
#include <stdio.h>
#define n 6

int main(int argc, char **argv){

int i,j,k=0;

for(i=0;i<n+1;i++){
    for(j=0;j<=i;j++){
        printf("*");
    }
    for(j=i;j<=n;j++){
        printf(" ");
    }
    for(k=i;k<n;k++){
        printf(" ");
    }
    for(j=0;j<=i;j++){
        printf("*");
    }
    printf("\n");
}

for(k=0;k<n*2+3;k++)//ligne centrale (maybe autre technique)
    printf("*");

for(i=0;i<n+1;i++){
    printf("\n");
    for(j=i;j<=n;j++){
        printf("*");
    }
    for(j=0;j<=i;j++){
            printf(" ");
    }
    for(j=0;j<i;j++){
            printf(" ");
    }
    for(j=i;j<=n;j++){
        printf("*");
    }
}
printf("\n");

return 0;
}

/*

*             *
**           **
***         ***
****       ****
*****     *****
******   ******
******* *******
***************
******* *******
******   ******
*****     *****
****       ****
***         ***
**           **
*             *

*/