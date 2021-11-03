#include <stdio.h>


int main(int argc, char **argv){

    double aX,aY=0;
    double bX,bY=0;

    printf("coord a(x,y) :\n");
    scanf("%lf %lf",&aX,&aY);
    printf("coord b(x,y) :\n");
    scanf("%lf %lf",&bX,&bY);

    printf("a(%lf,%d) b(%lf,%lf)\n\n",aX,aY,bX,bY);

    printf("(zone1)  (zone2)  (zone3)\n"
           "(zone4)  (zone5)  (zone6)\n"
           "(zone7)  (zone8)  (zone9)\n");

    return 0;
}