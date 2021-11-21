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


/* <--------------------- F E N Ê T R E   C O U R B E ---------------------> */

void win2_on_expose(Ez_event *ev, int zoom)
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
    ez_draw_text(ev->win, EZ_TC, width-100, 1, "[S] : Zoom arriere");

    // Axe des ordonnées
    ez_draw_text(ev->win, EZ_TC, middleH-20, 50, "Y");
    ez_draw_line(ev->win,  middleH,  50, middleH, height-50);

    // Axe des abscisses
    ez_draw_text(ev->win, EZ_TC, width-50, middleH+10, "X");
    ez_draw_line(ev->win, 50,  middleH, width-50,middleH);

    int secondI= middleH+zoom;
    int secondJ = middleW+zoom;

    // Graduation de l'axe des ordonnées
    for (int i = middleH; i <= height-50; i += zoom)
    {
        ez_draw_line (ev->win, middleH-5, i, middleH+5, i);
        secondI -= zoom;
        ez_draw_line (ev->win, middleH+5, secondI, middleH-5, secondI);
    }

    // Graduation de l'axe des abscisses
    for (int j=middleW; j <= width-50; j += zoom){
        ez_draw_line(ev->win, j, middleH-5, j, middleH+5);
        secondJ -= zoom;
        ez_draw_line(ev->win, secondJ, middleH-5, secondJ, middleH+5);
    }  
    
    ez_set_color(ez_red); // Coloration de la courbe
    ez_set_thick(1); // Épaisseur de la courbe

    // Génération de la courbe
    for (double i = 0.00; i < 2 * M_PI; i += 0.0001) {
        x = (cos(i) - cos(3*i)) * zoom;
        y = (sin(i) + sin(3*i)) * zoom;
        ez_draw_point(ev->win, x+middleH, y+middleH);
    }

}


void win2_on_key_press(Ez_event *ev, int zoom)
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
            zoom += 100;
            ez_window_clear(ev->win);
            win2_on_expose(ev, zoom);
            break;

        // Lorsque l'utilisateur appuie sur 's' --> Zoom arrière
        case XK_s:
        case XK_S:                  
            zoom = 50;
            ez_window_clear(ev->win);
            win2_on_expose(ev, zoom);
            break;
    }
}


void win2_on_event(Ez_event *ev)
{
    int zoom = 50;
    switch (ev->type)
    {
        case Expose:   win2_on_expose   (ev, zoom); break;
        case KeyPress: win2_on_key_press(ev, zoom); break;
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
int main()
{
    if (ez_init() < 0) exit(1);
    
    win1 = ez_window_create(800, 800, "Exercice 6", win1_on_event);
    
    ez_main_loop ();
    exit(0);
}
