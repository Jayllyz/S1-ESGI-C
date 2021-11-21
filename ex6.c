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


void win1_on_expose (Ez_event *ev, int zoom)
{
    int width, height; // Dimension de la fenêtre
    double a, b;

    ez_window_get_size(ev->win, &width, &height);
    int middleH = height / 2;
    int middleW = width / 2;

    ez_set_color(ez_black); // Coloration du texte et des axes

    // Explications des touches
    ez_draw_text(ev->win, EZ_TC, middleW, 1, "q pour quitter");
    ez_draw_text(ev->win, EZ_TC, 100, 1, "a = zoom");
    ez_draw_text(ev->win, EZ_TC, width-100, 1, "b = reset zoom");

    // Axe des ordonnées
    ez_draw_text(ev->win, EZ_TC, middleH-20, 50, "Y");
    ez_draw_line(ev->win,  middleH,  50, middleH, height-50);

    // Axe des abscisses
    ez_draw_text(ev->win, EZ_TC, width-50, middleH+10, "X");
    ez_draw_line(ev->win, 50,  middleH, width-50,middleH);

     int secondI= middleH+50;
     int secondJ = middleW+50;
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
    for(double i = 0.00; i < 2 * M_PI; i += 0.0001) {
        a = (cos(i) - cos(3*i)) * zoom;
        b = (sin(i) + sin(3*i)) * zoom;
        ez_draw_point(ev->win, a+middleH, b+middleH);
    }

}


void win1_on_key_press (Ez_event *ev, int zoom)
{
    switch (ev->key_sym) {
        // Lorsque l'utilisateur appuie sur 'q' --> Quitter
        case XK_q: ez_quit(); break;

        // Lorsque l'utilisateur appuie sur 'a' --> zoom avant
        case XK_a:
            zoom += 100;
            ez_window_clear(ev->win);
            win1_on_expose(ev, zoom);
            break;

        // Lorsque l'utilisateur appuie sur 'b' --> zoom arrière
        case XK_b:                  
            zoom = 50;
            ez_window_clear(ev->win);
            win1_on_expose(ev, zoom);
            break;
    }
}

void win1_on_event (Ez_event *ev)
{
    int zoom = 50;
    switch (ev->type) {
        case Expose:   win1_on_expose   (ev, zoom); break;
        case KeyPress: win1_on_key_press(ev, zoom); break;
    }
}

// Génération de la fenêtre
int main()
{
    if (ez_init() < 0) exit(1);
    
    ez_window_create (800, 800, "Exercice 6", win1_on_event);
    
    ez_main_loop ();
    exit(0);
}
