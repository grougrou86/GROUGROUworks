#include"texture.h"
#include"G_inc.h"

namespace ONIGIRIX_GUI {

	SDL_H_texture::~SDL_H_texture() {
		if (_texture != nullptr) {
			SDL_DestroyTexture(_texture);
			_texture = nullptr;
		}
	}
	SDL_S_texture::~SDL_S_texture() {
		if (_texture != nullptr) {
			SDL_FreeSurface(_texture);
			_texture = nullptr;
		}
	}
}