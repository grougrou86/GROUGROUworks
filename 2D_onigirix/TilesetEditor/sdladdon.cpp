#include "G_inc.h" 
namespace ONIGIRIX_GUI {
	void Add_x_y_surface(SDL_Surface*& sdl1, SDL_Surface*& sdl2, int x, int y) {
		SDL_Surface* sdl3 = NULL;
		if (sdl2 != NULL) {
			int width = x + sdl2->w;
			int height = y + sdl2->h;
			if (sdl1 != NULL) {
				if (sdl1->w > width) { width = sdl1->w; }
				if (sdl1->h > height) { height = sdl1->h; }
			}


#if SDL_BYTEORDER == SDL_BIG_ENDIAN
			sdl3 = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
#else
			sdl3 = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
#endif
			if (sdl1 != NULL) {
				SDL_BlitSurface(sdl1, NULL, sdl3, NULL);
			}


			SDL_Rect rect = { x, y, sdl2->w, sdl2->h };
			SDL_BlitSurface(sdl2, NULL, sdl3, &rect);
			SDL_FreeSurface(sdl1);
			sdl1 = sdl3;
		}
	}
	SDL_Surface* empty_surface(int w, int h) {
		SDL_Surface* scaled;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		scaled = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
#else
		scaled = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
#endif
		return scaled;
	}
}