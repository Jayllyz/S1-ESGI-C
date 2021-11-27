/*
    Objectif : Réaliser un graphique avec :
                x = cos(t)-cos(3t)
                y = sin(t)-sin(3t)
    Auteurs  : Anto BENEDETTI, Antony DAVID, Anthony JABRE
    Date     : 20/11/2021
*/

/*
    Compilation :
        Linux   : gcc -Wall ex6.c ez-draw.c -o EXEC -lX11 -lXext -lm
        Windows : gcc -Wall ex6.c ez-draw.c -o EXEC -lgdi32
*/


#include "ez-draw.h"
#include <math.h>


Ez_window win1; // Fenêtre menu
Ez_window win2; // Fenêtre courbe
//variables globales
int zoom; 
int bool = 0;

/* <--------------------- F E N Ê T R E   C O U R B E ---------------------> */

void win2_on_expose(Ez_event *ev)
{
    // Dimension de la fenêtre
    int width, height;
    ez_window_get_size(ev->win, &width, &height);
    int middleH = height / 2;
    int middleW = width / 2;

    // Équations
    double x, y;

    // Explications des touches
    ez_draw_text(ev->win, EZ_TC, middleW, 1, "[R] : Retour au menu principal");
    ez_draw_text(ev->win, EZ_TC, 100, 1, "[Z] : Zoom avant");
    ez_draw_text(ev->win, EZ_TC, 100, 30, "Clique gauche/droit -> coordonnees");
    ez_draw_text(ev->win, EZ_TC, width-100, 1, "[S] : Zoom arriere");

    // Détails equations
    ez_draw_text(ev->win, EZ_TC, 100, height-20, "x = cos(t) - cos(3t)");
    ez_draw_text(ev->win, EZ_TC, width-100, height-20, "y = sin(t) - sin(3t)");
    ez_draw_text(ev->win, EZ_TC, middleW, height-20, "t = [0, 2pi]");

    // Axe des ordonnées
    ez_draw_text(ev->win, EZ_TC, middleH-30, 50, "Y");
    ez_draw_line(ev->win,  middleH,  50, middleH, height-50);

    // Axe des abscisses
    ez_draw_text(ev->win, EZ_TC, width-50, middleH+30, "X");
    ez_draw_line(ev->win, 50,  middleH, width-50,middleH);

    int secondI= middleH+zoom;
    int secondJ = middleW+zoom;
    int numberGrad = 0;

    // Graduation de l'axe des ordonnées
    for (int i = middleH; i <= height-50; i += zoom)
    {
        ez_draw_line (ev->win, middleH-5, i, middleH+5, i);
        secondI -= zoom;
        ez_draw_line (ev->win, middleH+5, secondI, middleH-5, secondI);
        ez_draw_text(ev->win, EZ_TC, middleH-10, secondI-15, "%d",numberGrad);
        numberGrad++;
    }
    numberGrad = 0;

    // Graduation de l'axe des abscisses
    for (int j = middleW; j <= width-50; j += zoom){
        ez_draw_line(ev->win, j, middleH-5, j, middleH+5);
       if(numberGrad>0)
            ez_draw_text(ev->win, EZ_TC, j+10, middleH+5, "%d",numberGrad);
        secondJ -= zoom;
        ez_draw_line(ev->win, secondJ, middleH-5, secondJ, middleH+5);
        numberGrad++;
    }  
    
    ez_set_color(ez_red); // Coloration de la courbe
    ez_set_thick(1); // Épaisseur de la courbe

    // Génération de la courbe
    for (double i = 0.00; i < 2 * M_PI; i += 0.0001)
    {
        x = (cos(i) - cos(3*i)) * zoom;
        y = (sin(i) + sin(3*i)) * zoom;
        ez_draw_point(ev->win, x+middleH, y+middleH);
    }
}

void win2_on_button_press(Ez_event *ev){

    int width,height;//taille de la fenêtre
    double x,y;//variable pour les calculs

    ez_window_get_size(ev->win, &width, &height);//on récupére la taille de la fenêtre
    ez_set_color(ez_white);
    ez_fill_rectangle (win2, 30, 50, 150, 80);
    ez_set_color(ez_red);
    height /=2;
    x = ev->mx-height; //on retire la hauteur/2 pour corriger le décalage
    y = ev->my-height;

    if(ev->my !=0) //on transforme en positif ce qui devient négatif avec la soustraction
        y *=-1;  //0 est un cas particulier, pas besoin de convertir

    x/=50;//on divise par 50 car 1 unité = 50 pixels
    y/=50;
    if(bool==1){//si le zoom == 150
        ez_draw_text(ev->win, EZ_TL, 30, 50, "x =%.2lf, y =%.2lf", x/3, y/3);//On divise par 3 car 1 unité est 3 fois plus grande avec le zoom 150
    }
    else{//zoom == 50
        ez_draw_text(ev->win, EZ_TL, 30, 50, "x =%.2lf, y =%.2lf", x, y);
    }
}

void win2_on_key_press(Ez_event *ev)
{
    switch (ev->key_sym)
    {
        // Lorsque l'utilisateur appuie sur 'r' --> Retour menu
        case XK_r:
        case XK_R:
            ez_window_destroy(win2);
            ez_window_show(win1, 1);
            break;

        // Lorsque l'utilisateur appuie sur 'Z' --> Zoom avant
        case XK_z:
        case XK_Z:
            if(bool==1){break;}//pas besoin de refresh la page si on a déjà un zoom de 150
            zoom = 150;
            bool =1;
            ez_window_clear(ev->win);
            win2_on_expose(ev);
            break;

        // Lorsque l'utilisateur appuie sur 's' --> Zoom arrière
        case XK_s:
        case XK_S:
            if(bool==0){break;}//pas besoin de refresh la page si on a déjà un zoom de 50
            zoom = 50;
            bool =0;
            ez_window_clear(ev->win);
            win2_on_expose(ev);
            break;
    }
}


void win2_on_event(Ez_event *ev)
{
    zoom = 50;
    switch (ev->type)
    {
        case Expose  : win2_on_expose   (ev); break;
        case ButtonPress  : win2_on_button_press (ev);  break;
        case KeyPress: win2_on_key_press(ev); break;
    }
}


/* <----------------------- F E N Ê T R E   M E N U -----------------------> */

void win1_on_expose(Ez_event *ev)
{
    // Dimension de la fenêtre
    int width, height;
    ez_window_get_size(ev->win, &width, &height);

    // Menu
    ez_set_nfont(3); // Taille de police
    ez_draw_text(win1, EZ_TC, width/2, height/2 - 30, "Exercice 6");
    ez_set_nfont(2);
    ez_draw_text(win1, EZ_TC, width/2, height/2, "[A] : Lancer");
    ez_draw_text(win1, EZ_TC, width/2, height/2 + 15, "[Q] : Quitter");
}


void win1_on_key_press(Ez_event *ev)
{
    switch (ev->key_sym)
    {
        // Lorsque l'utilisateur appuie sur 'A' --> Génération de la courbe
        case XK_a:
        case XK_A:
            ez_window_show(win1, 0);
            win2 = ez_window_create(800, 800, "Courbe", win2_on_event);
            break;
        
        // Lorsque l'utilisateur appuie sur 'Q' --> Quitter
        case XK_q: 
        case XK_Q:
            ez_quit();
            break;
    }
}


void win1_on_event(Ez_event *ev)
{
    switch (ev->type)
    {
        case Expose:   win1_on_expose   (ev); break;
        case KeyPress: win1_on_key_press(ev); break;
    }
}


// Génération de la fenêtre
int main(int argc,char **argv)
{
    if (ez_init() < 0) exit(1);
    
    win1 = ez_window_create(800, 800, "Exercice 6", win1_on_event);
    ez_main_loop ();
    exit(0);
}
