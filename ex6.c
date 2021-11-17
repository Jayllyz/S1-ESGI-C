// gcc -Wall ex6.c ez-draw.c -o EXEC -lX11 -lXext -lm
//./EXEC
#include "ez-draw.h"
#include <math.h>
//M_PI
void win1_on_expose (Ez_event *ev)
{
    int  w, h,sup;
    double a,b;
    ez_window_get_size (ev->win, &w, &h);
    ez_set_color (ez_black);
    ez_draw_text (ev->win, EZ_TC, w/2, 1, "q pour quitter");
    ez_draw_line (ev->win,  50,  50,50,h-50);
    ez_draw_line (ev->win, 50,  h/2,w-50,h/2);
    ez_draw_text (ev->win, EZ_TC, 35, 50, "Y");
    ez_draw_text (ev->win, EZ_TC, w-50, h/2 + 10, "X");
    sup = 50;
    for(int i=50; i<=h-50; i+=50)
    {
        ez_draw_line (ev->win, 45, i, 55, i);
        sup-=50;
        ez_draw_line (ev->win, 45, sup, 55, sup);
    }
    for(int j=50; j<=w-50; j+=50)
    {
        ez_draw_line (ev->win, j, (h/2)-5, j, (h/2)+5);
    }
    ez_set_color (ez_red);
    ez_set_thick (1);
    for(double i = 0.00; i < 2*M_PI; i+=0.001) {
        a = (cos(i) - cos(3*i))*50;
        b = (sin(i) + sin(3*i))*50;
        ez_draw_point (ev->win, a +50, b +(h/2));
    }

}

void win1_on_key_press (Ez_event *ev)
{
    switch (ev->key_sym) {
        //case XK_q : ez_quit (); break;

    }

}

void win1_on_event (Ez_event *ev)//main function
{
    switch (ev->type) {
        case Expose   : win1_on_expose    (ev); break;
        case KeyPress : win1_on_key_press (ev); break;
    }
}

int main()
{
    if (ez_init() < 0) exit(1);
    ez_window_create (800, 800, "Exercice 6", win1_on_event);

    ez_main_loop ();
    exit(0);
}