#include "DisplayEngine.h"
#include <SDL.h>
#include "ImageIncludes.h"
#include "Geometry.h"
#include "DisplayEngine_SDL_SOFTWARE_output.h"
namespace ONIGIRIX_GUI {

	DisplayEngine_Software_Output::~DisplayEngine_Software_Output() {
		_s0.set(nullptr);//to avoid deletion of the texture 
		_s1.set(nullptr);//to avoid deletion of the texture 
		_h0.set(nullptr);//to avoid deletion of the texture 
		_h1.set(nullptr);//to avoid deletion of the texture
	}
	DisplayContext DisplayEngine_Software_Output::get_DisplayContext() {
		return _DisplayContext;
	}
	void DisplayEngine_Software_Output::set_DisplayContext(DisplayContext d) {
		_DisplayContext = d;
		if (!(d == _DisplayContext)) {
			_h_reset_0 = true;
			_h_reset_1 = true;
		}
	}
	SDL_H_texture* DisplayEngine_Software_Output::get_SDL_TEXTURE() {

		//CASE FRAME 1

		if (!editable_texture) {
			//update the texture if needed
			if ((_h_update_1 || _h_reset_1) && _s1.native()!=nullptr) {
				if (_h_reset_1) {
					if (get_DisplayContext().get_SDL_Renderer() == nullptr)throw("Display Context not set or not able to use SDL hardware texture");
					SDL_Texture* newtex = SDL_CreateTexture(get_DisplayContext().get_SDL_Renderer(), SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, _s1.native()->w, _s1.native()->h);
					_h1.set(newtex);
					_h_reset_1 = false;
				}
				SDL_Texture* tex = _h1.native();
				void* mPixels;
				SDL_LockTexture(tex, NULL, &mPixels, &(_s1.native()->pitch));
				memcpy(mPixels, (_s1.native()->pixels), _s1.native()->pitch *  _s1.native()->h);
				SDL_UnlockTexture(tex);
				mPixels = NULL;
				_h_update_1 = false;
			}
			//return the texture
			return &_h1;
		}
		// else 

		//CASE FRAME 2

		//update the texture if needed
		if ((_h_update_0 || _h_reset_0) && _s0.native() != nullptr) {
			if (_h_reset_0) {
				if (get_DisplayContext().get_SDL_Renderer() == nullptr)throw("Display Context not set or not able to use SDL hardware texture");
				SDL_Texture* newtex = SDL_CreateTexture(get_DisplayContext().get_SDL_Renderer(), SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, _s0.native()->w, _s0.native()->h);
				_h0.set(newtex);
				_h_reset_0 = false;
			}
			SDL_Texture* tex = _h0.native();
			void* mPixels;
			SDL_LockTexture(tex, NULL, &mPixels, &(_s0.native()->pitch));
			memcpy(mPixels, (_s0.native()->pixels), _s0.native()->pitch *  _s0.native()->h);
			SDL_UnlockTexture(tex);
			mPixels = NULL;
			_h_update_0 = false;
		}
		//return the texture
		return &_h0;
	};
	GL_H_texture* DisplayEngine_Software_Output::get_GL_TEXTURE() {
		return nullptr;
	}
	SDL_S_texture* DisplayEngine_Software_Output::get_SOFTWARE() {
		if (!editable_texture) return &_s1;
		else return &_s0;
	}
	SDL_Surface*  DisplayEngine_Software_Output::get_Edit() {
		//rest the surface is they have bad size
		if (!edit_accessed) {
			if (editable_texture) {
				if (!_s1_updated)reset_1();
			}
			else {
				if (!_s0_updated)reset_0();
			}
		}
		edit_accessed = true;
		if (editable_texture) return _s1.native();
		else return _s0.native();
	}
	void DisplayEngine_Software_Output::swap() {
		editable_texture = !editable_texture;

		if (!editable_texture) _h_update_1 = true;//the hardware texture 1 has to be updated
		else _h_update_0 = true;

		edit_accessed = false;
		// set the true height of the image
		if (!size_updated) {
			if (editable_texture) {
				//display texture is 0
				if (_s0_updated) {
					_width = asked_width;
					_height = asked_height;
					size_updated = true;
				}
			}
			else {
				//display texture is 1
				if (_s1_updated) {
					_width = asked_width;
					_height = asked_height;
					size_updated = true;
				}
			}
		}
	}
	void DisplayEngine_Software_Output::set_height(int h) {
		if (_height != h) {
			_s0_updated = false;
			_s1_updated = false;
			asked_height = h;
			size_updated = false;
		}
	}
	void DisplayEngine_Software_Output::set_width(int w) {
		if (_width != w) {
			_s0_updated = false;
			_s1_updated = false;
			asked_width = w;
			size_updated = false;
		}
	}
	void DisplayEngine_Software_Output::reset_0() {

		SDL_Surface* surface;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		surface = SDL_CreateRGBSurface(SDL_SWSURFACE, asked_width, asked_height, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
#else
		surface = SDL_CreateRGBSurface(SDL_SWSURFACE, asked_width, asked_height, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
#endif
		_s0.set(surface);
		_s0_updated = true;
		_h_reset_0 = true;

	}
	void DisplayEngine_Software_Output::reset_1() {

		SDL_Surface* surface;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		surface = SDL_CreateRGBSurface(SDL_SWSURFACE, asked_width, asked_height, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
#else
		surface = SDL_CreateRGBSurface(SDL_SWSURFACE, asked_width, asked_height, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
#endif
		_s1.set(surface);
		_s1_updated = true;
		_h_reset_1 = true;
	}

}