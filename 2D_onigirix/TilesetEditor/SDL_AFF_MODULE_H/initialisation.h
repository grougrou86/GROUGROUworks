#ifndef SDL_INIT_H
#define SDL_INIT_H

#include <string>
#include <vector>
#include "G_inc.h" 
class SDL_mainLoop{
public:
	SDL_mainLoop();
	Fenetre* addFenetre(Fenetre);
	void Loop();
	void delete_fenetre(Fenetre*);
private:
	int x_max, y_max;
	int a_max, b_max;
	std::vector < Fenetre* > Fenetres;
	std::vector < Fenetre* > to_Fenetres;

};



#endif