#pragma once
#include <atomic>
#include <mutex>
#include "G_inc.h"

namespace ONIGIRIX_GUI {

	//we use wraper for different texture because it is easier to debug then ^^

	//!The native handler for opengl textures 
	class GL_H_texture {

	public:
		bool read = false;
	};
	//!the native handler for SDL Surface 
	class SDL_S_texture{
	public:
		virtual ~SDL_S_texture();
	private:
		SDL_Surface* _texture = NULL;
		bool ready = false;
	};
	//!the native handler for SDL texture
	class SDL_H_texture {
	public:
		virtual ~SDL_H_texture();
	private:
		SDL_Texture* _texture= NULL;
		bool ready = false;
	};

	
	/*
	Converter :

	his member are call one different thread at each loop to transfer sdl hardware texture and gl hardware texture to software fo exemple 

	*/

	class Converter {
	public:

	private:
		//to implement .... a stack of paire to convert
	};
}