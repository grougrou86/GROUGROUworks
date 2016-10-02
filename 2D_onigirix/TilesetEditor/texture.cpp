#include"texture.h"
#include"G_inc.h"

namespace ONIGIRIX_GUI {

	SDL_H_texture::SDL_H_texture(SDL_Texture* s) {
		_texture = s;
	}
	SDL_H_texture::SDL_H_texture() {
		_texture = nullptr;
	}
	SDL_H_texture::~SDL_H_texture() {
		free();
	}
	void SDL_H_texture::set(SDL_Texture* s) {
		free();
		_texture = s;
	}
	void SDL_H_texture::free() {
		if (_texture != nullptr) {
			SDL_DestroyTexture(_texture);
			_texture = nullptr;
		}
	}
	SDL_S_texture::SDL_S_texture(SDL_Surface* s) {
		_texture = s;
	}
	SDL_S_texture::~SDL_S_texture() {
		free();
	}
	SDL_S_texture::SDL_S_texture() {
		_texture = nullptr;
	}
	void SDL_S_texture::set(SDL_Surface* s) {
		free();
		_texture = s;
	}
	SDL_Surface* SDL_S_texture::native() {
		return _texture;
	}
	SDL_Texture* SDL_H_texture::native() {
		return _texture;
	}
	void SDL_S_texture::free() {
		if (_texture != nullptr) {
			SDL_FreeSurface(_texture);
			_texture = nullptr;
		}
	}

}