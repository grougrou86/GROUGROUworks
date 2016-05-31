#include "G_inc.h" 
void close_on_click(Rectangle* r, Fenetre* f, SDL_mainLoop* l);
void hide_on_click(Rectangle* r, Fenetre* f, SDL_mainLoop* l);
void max_on_click(Rectangle* r, Fenetre* f, SDL_mainLoop* l);
void full_on_click(Rectangle* r, Fenetre* f, SDL_mainLoop* l);
void creat_window_decoration(Fenetre*& f,bool full=true,bool big=true,bool min=true,bool resizable=true);
