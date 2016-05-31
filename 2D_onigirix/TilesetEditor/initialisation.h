#ifndef SDL_INIT_H
#define SDL_INIT_H

#include <string>
#include <vector>
#include "G_inc.h" 
#include <chrono>
namespace ONIGIRIX_GUI {
	class SDL_mainLoop {
	public:
		SDL_mainLoop();
		Fenetre* addFenetre(Fenetre);
		void Loop();
		void delete_fenetre(Fenetre*);
		int fps = 0;
	private:
		int x_max, y_max;
		int a_max, b_max;
		std::vector < Fenetre* > Fenetres;
		std::vector < Fenetre* > to_Fenetres;
		int frame = 0;
		int old_frame = 0;
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		std::chrono::system_clock::time_point last = start;
		std::chrono::system_clock::time_point now;
		std::chrono::seconds ref{ 1 };
	};
}


#endif