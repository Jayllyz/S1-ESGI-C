// gcc -Wall ex6.c ez-draw.c -o EXEC -lX11 -lXext -lm (linux)
// gcc -Wall ex6.c ez-draw.c -o EXEC -lgdi32 (windows)
//./EXEC
#include "ez-draw.h"
#include <math.h>
//M_PI
void win1_on_expose (Ez_event *ev, int zoom)
{
    int  w, h,sup;
    double a,b;
    ez_window_get_size (ev->win, &w, &h);
    int middle=h/2;
    ez_set_color (ez_black);
    ez_draw_text (ev->win, EZ_TC, w/2, 1, "q pour quitter");
    ez_draw_text (ev->win, EZ_TC, 100, 1, "a = zoom");
    ez_draw_text (ev->win, EZ_TC, w-100, 1, "b = reset zoom");
    ez_draw_line (ev->win,  middle,  50,h/2,h-50);
    ez_draw_line (ev->win, 50,  middle,w-50,middle);
    ez_draw_text (ev->win, EZ_TC, middle-20, 50, "Y");
    ez_draw_text (ev->win, EZ_TC, w-50, middle + 10, "X");
    sup = middle;
    for(int i=middle; i<=h-50; i+=zoom)
    {
        ez_draw_line (ev->win, middle-5, i, middle+5, i);
        sup-=zoom;
        ez_draw_line (ev->win, middle+5, sup, middle-5, sup);
    }
    for(int j=50; j<=w-50; j+=zoom)
    {
        ez_draw_line (ev->win, j, middle-5, j, middle+5);
    }
    ez_set_color (ez_red);
    ez_set_thick (1);
    for(double i = 0.00; i < 2*M_PI; i+=0.0001) {
        a = (cos(i) - cos(3*i))*zoom;
        b = (sin(i) + sin(3*i))*zoom;
        ez_draw_point (ev->win, a + middle, b + middle);
    }

}


void win1_on_key_press (Ez_event *ev,int zoom)
{
    switch (ev->key_sym) {
        case XK_q : ez_quit (); break;
        case XK_a : 
            zoom+=100;
            ez_window_clear(ev->win);
            win1_on_expose(ev,zoom);
            break;
        case XK_b : 
            zoom=50;
            ez_window_clear(ev->win);
            win1_on_expose(ev,zoom);
            break;
    }
}

void win1_on_event (Ez_event *ev)//main function
{
    int zoom = 50;
    switch (ev->type) {
        case Expose   : win1_on_expose    (ev,zoom); break;
        case KeyPress : win1_on_key_press (ev,zoom); break;
    }
}

int main()
{
    if (ez_init() < 0) exit(1);
    ez_window_create (800, 800, "Exercice 6", win1_on_event);
    ez_main_loop ();
    exit(0);
}
