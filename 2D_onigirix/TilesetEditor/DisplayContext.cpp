
#include"DisplayContext.h"
#include <SDL.h>

SDL_Renderer* DisplayContext::get_SDL_Renderer() {
	return _SDL_Renderer;
}
void DisplayContext::set_SDL_Renderer(SDL_Renderer* r) {
	_SDL_Renderer=r;
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
