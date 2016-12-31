#include "G_inc.h" 

#include <chrono>
#include <ctime>

#include <algorithm>
#include<iostream>
#include <Windows.h>
#include <iostream>
#include <deque>
#include "encodage.h"
#include "GENERAL_PARAMETER.h"

namespace ONIGIRIX_GUI {
	SDL_mainLoop::SDL_mainLoop() {
		SDL_Init(SDL_INIT_EVERYTHING);
		int imgFlags = IMG_INIT_PNG;

		//SDL_CaptureMouse(SDL_TRUE);

		SDL_Window* maWindow = SDL_CreateWindow("SCAN", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 10, 10, SDL_WINDOW_RESIZABLE);
		SDL_MaximizeWindow(maWindow);
		SDL_GetWindowPosition(maWindow, &x_max, &y_max);
		SDL_GetWindowSize(maWindow, &a_max, &b_max);
		SDL_DestroyWindow(maWindow);

		IMG_Init(imgFlags);
		TTF_Init();
		SDL_StartTextInput();

	}
	void SDL_mainLoop::Loop() {
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		while (!quit)
		{
			frame++;
			now = std::chrono::system_clock::now();
			double frame_dur = std::chrono::duration_cast<std::chrono::seconds>(now - last).count();

			if (frame_dur >= 1) { last = now; fps = frame; frame = 0; }
			while (!to_Fenetres.empty()) { Fenetres.push_back(to_Fenetres.back()); to_Fenetres.pop_back(); }
			for (auto& maFenetre : Fenetres) {
				maFenetre->DMousex = 0;
				maFenetre->DMousey = 0;

			}

			//étudier la programation parallèle et différée !
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//SDL_GetGlobalMouseState(&x_M, &y_M);
				//User requests quit

				if (e.type == SDL_QUIT)
				{
					//std::cout << e.window.timestamp;
					for (auto& f : Fenetres) {
						if (f->get_id() == e.button.windowID) {
							f->close();
						}
					}
				}
				else if (e.type == SDL_TEXTINPUT) {
					for (auto& maFenetre : Fenetres) {
						//int letext = &e.text.text;
						maFenetre->TextinputFct(std::wstring(s2ws(e.text.text)));
					}
				}
				else if (e.type == SDL_KEYDOWN)
				{
					for (auto& maFenetre : Fenetres) {
						maFenetre->keyFct(e.key.keysym.sym);
					}

				}

				else if (e.type == SDL_MOUSEMOTION) {
					int x, y;
					SDL_GetGlobalMouseState(&x, &y);
					
					//SDL_GetMouseState(&x, &y);
					for (auto& f : Fenetres) {
						if (f->get_id() == e.motion.windowID) {
							f->moveFct(x-f->get_x(), y-f->get_y(), e.motion.xrel, e.motion.yrel);
						}
					}
				}
				else if (e.type == SDL_MOUSEBUTTONUP) {
					int x, y;
					SDL_GetMouseState(&x, &y);
					std::cout << "CLICK : " << x << ":" << y << "|" << e.button.windowID << std::endl;
					for (auto& f : Fenetres) {
						if (f->get_id() == e.button.windowID) {
							f->clickFct(x, y);
						}
					}
				}
				else if (e.type == SDL_MOUSEBUTTONDOWN) {
					int x, y;
					SDL_GetMouseState(&x, &y);
					std::cout << "CLICK : " << x << ":" << y << "|" << e.button.windowID << std::endl;
					for (auto& f : Fenetres) {
						if (f->get_id() == e.button.windowID) {
							f->downFct(x, y);
						}
					}
				}
			}

			for (auto& maFenetre : Fenetres) {
				maFenetre->LOOPfct();// c'est pas les 2 les même.....
				maFenetre->loopFct();

			}
			size_t i = 0;
			while (i < Fenetres.size()) {
				Fenetre* fenetre = Fenetres[i];
				if (fenetre->TestEnd()) {
					fenetre->vider();
					fenetre->clean();
					delete fenetre;
					std::swap(Fenetres[i], Fenetres.back());
					Fenetres.pop_back();
					//return;
				}
				else i++;
			}
			if (Fenetres.size() == 0) { quit = true; }


			if (ACTIVE_DELAY) {
				if (fps > 60)SDL_Delay(4);
				if (fps > 40)SDL_Delay(4);
			}
		}
		for (auto& fe : Fenetres) { delete fe; }
	}
	Fenetre* SDL_mainLoop::addFenetre(Fenetre maFenetre) {
		Fenetre* fn_pointer = maFenetre.copie();
		to_Fenetres.push_back(fn_pointer);
		fn_pointer->set_maximized_dimention(0, 0, a_max + x_max, b_max + y_max);
		fn_pointer->related_loop = this;
		return fn_pointer;
	}
	void SDL_mainLoop::delete_fenetre(Fenetre* ma_f) {
		size_t i = 0;
		while (i < Fenetres.size()) {
			Fenetre* fenetre = Fenetres[i];
			if (ma_f = fenetre) {
				delete fenetre;
				std::swap(fenetre, Fenetres.back());
				return;
			}
			else i++;
		}
	}
}