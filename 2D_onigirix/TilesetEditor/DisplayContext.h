#pragma once
#include <SDL.h>
namespace ONIGIRIX_GUI {
	class DisplayContext {
	public:
		DisplayContext(SDL_Renderer* r = nullptr, SDL_Surface* s = nullptr) :_SDL_Renderer(r) {};

		SDL_Renderer* get_SDL_Renderer();
		void set_SDL_Renderer(SDL_Renderer* r);
		SDL_Surface* get_SDL_Surface();
		void set_SDL_Surface(SDL_Surface* r);
		SDL_Window* get_SDL_Window();
		void set_SDL_Window(SDL_Window* r);

		bool operator==(const DisplayContext&);

	private:
		SDL_Renderer* _SDL_Renderer = nullptr;
		SDL_Surface*  _SDL_Surface = nullptr;
		SDL_Window*   _SDL_Window = nullptr;

	};
}