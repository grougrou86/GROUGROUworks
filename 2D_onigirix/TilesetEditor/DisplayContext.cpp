
#include"DisplayContext.h"
#include <SDL.h>
namespace ONIGIRIX_GUI {
	SDL_Renderer* DisplayContext::get_SDL_Renderer() {
		return _SDL_Renderer;
	}
	void DisplayContext::set_SDL_Renderer(SDL_Renderer* r) {
		_SDL_Renderer = r;
	}
	SDL_Surface* DisplayContext::get_SDL_Surface() {
		return _SDL_Surface;
	}
	void DisplayContext::set_SDL_Surface(SDL_Surface* r) {
		_SDL_Surface = r;
	}
	SDL_Window* DisplayContext::get_SDL_Window() {
		return _SDL_Window;
	}
	void DisplayContext::set_SDL_Window(SDL_Window* r) {
		_SDL_Window = r;
	}
	bool DisplayContext::operator==(const DisplayContext& d2) {
		return _SDL_Renderer == d2._SDL_Renderer&&_SDL_Surface == d2._SDL_Surface&&_SDL_Window == d2._SDL_Window;
	}
}
