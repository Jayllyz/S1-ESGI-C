// gcc -Wall ex6.c ez-draw.c -o EXEC -lX11 -lXext -lm
//./EXEC
#include "ez-draw.h"


void win1_on_event (Ez_event *ev)                /* Called by ez_main_loop() */
{                                                /* for each event on win1   */
    switch (ev->type) {

        case Expose :                           /* We must redraw everything */
            ez_set_color (ez_red);
            ez_draw_text (ev->win, EZ_MC, 200, 150, 
                "To quit, press the key 'q', or click\n"
                "on the Close button of the window");
            break;

        case KeyPress :                                 /* A key was pressed */
            switch (ev->key_sym) {
                case XK_q : ez_quit (); break;
            }
            break;
    }
}


int main(int argc, char **argv)
{
    if (ez_init() < 0) exit(1);

    ez_window_create (400, 300, "EXO 6", win1_on_event);

    ez_main_loop ();
    exit(0);
}