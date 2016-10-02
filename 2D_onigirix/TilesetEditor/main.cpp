

#include <stdio.h>
#include <math.h>
#include<iostream>
#include "G_inc.h" 
#include "Mesure.h"
#include "all_frame_include.h"
#include "Video_Player.h"
#include "VLC_test.h"



int main(int argc, char* args[])
{	

	ONIGIRIX_GUI::SDL_mainLoop mainloop;

	ONIGIRIX_GUI::Fenetre* fn2 = mainloop.addFenetre(ONIGIRIX_GUI::Fenetre(1500, 700,false));


	fn2->add_police("calibri", "font/Calibri.ttf");
	fn2->add_police("manuscrit", "font/Regular.ttf");
	fn2->add_police("pixel", "font/Pixel.ttf");
	fn2->add_police("optimus", "font/Optimus.ttf");
	fn2->add_police("MS", "font/Ms Gothic.ttf");
	fn2->add_police("crayon_1", "font/crayon_1.ttf");
	fn2->add_police("keifont", "font/keifont.ttf");
	fn2->add_police("Cyberbit", "font/Cyberbit.ttf");
	fn2->add_police("consola", "font/consola.ttf");
	fn2->add_police("Arial Unicode", "font/Arial Unicode MS.ttf");

	fn2->rebulid_funk = Acceuil;
	mainloop.Loop();
	
	
	ONIGIRIX_GUI::Singleton<ONIGIRIX_GUI::ImageDealer>::Get();

	//pour la forme....
	return 3896;
}