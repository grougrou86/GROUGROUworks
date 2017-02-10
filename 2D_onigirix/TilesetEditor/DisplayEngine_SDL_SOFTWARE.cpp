#include "DisplayEngine.h"
#include <SDL.h>
#include "ImageIncludes.h"
#include "Geometry.h"
#include "DisplayEngine_SDL_SOFTWARE.h"
namespace ONIGIRIX_GUI {
	DisplayEngine_Software_Output::~DisplayEngine_Software_Output() {
		_s0.set(nullptr, false);//to avoid deletion of the texture 
		_s1.set(nullptr, false);//to avoid deletion of the texture 
	}
	SDL_H_texture* DisplayEngine_Software_Output::get_SDL_TEXTURE() {
		return nullptr;
	};
	GL_H_texture* DisplayEngine_Software_Output::get_GL_TEXTURE() {
		return nullptr;
	}
	SDL_S_texture* DisplayEngine_Software_Output::get_SOFTWARE() {
		if(!editable_texture) return &_s1;
		else return &_s0;
	}
	SDL_Surface*  DisplayEngine_Software_Output::get_Edit() {
		//rest the surface is they have bad size
		if (edit_accessed=false) {
			if (editable_texture) {
				if (!_s1_update)reset_s1();
			}
			else {
				if (!_s0_update)reset_s0();
			}
		}
		edit_accessed = true;
		if (editable_texture) return _s1.native();
		else return _s0.native();
	}
	void DisplayEngine_Software_Output::swap() {
		editable_texture = !editable_texture;
		edit_accessed = false;
		// set the true height of the image
		if (!size_updated) {
			if (editable_texture) {
				//display texture is 0
				if (_s0_update) {
					_width = asked_width;
					_height = asked_height;
					size_updated = true;
				}
			}
			else {
				//display texture is 1
				if (_s1_update) {
					_width = asked_width;
					_height = asked_height;
					size_updated = true;
				}
			}
		}
	}
	void DisplayEngine_Software_Output::set_height(int h) {
		if (_height != h) {
			_s0_update = false;
			_s1_update = false;
			asked_height = h;
			size_updated = false;
		}
	}
	void DisplayEngine_Software_Output::set_width(int w) {
		if (_width != w) {
			_s0_update = false;
			_s1_update = false;
			asked_width = w;
			size_updated = false;
		}
	}
	void DisplayEngine_Software_Output::reset_s0() {

		SDL_Surface* surface;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		surface = SDL_CreateRGBSurface(SDL_SWSURFACE, asked_width, asked_height, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
#else
		surface = SDL_CreateRGBSurface(SDL_SWSURFACE, asked_width, asked_height, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
#endif
		_s0.set(surface);
		_s0_update = true;

	}
	void DisplayEngine_Software_Output::reset_s1() {

		SDL_Surface* surface;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		surface = SDL_CreateRGBSurface(SDL_SWSURFACE, asked_width, asked_height, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
#else
		surface = SDL_CreateRGBSurface(SDL_SWSURFACE, asked_width, asked_height, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
#endif
		_s1.set(surface);
		_s1_update = true;
	}
	DisplayEngine_Software::DisplayEngine_Software(ViewPort v) {
		set_ViewPort(v);
		get_output();//so that it initialisate the first surface !
	}
	DisplayEngine_Software::~DisplayEngine_Software() {
		
	}
	void DisplayEngine_Software::set_ViewPort(ViewPort v) {
		_ViewPort = v;
		_output.set_height(v.height);
		_output.set_width(v.width);
	}
	ViewPort DisplayEngine_Software::get_ViewPort() {
		return _ViewPort;
	}
	Image* DisplayEngine_Software::get_output() {
		return &_output;
	}

	//DRAWING FUNCTION


	

}