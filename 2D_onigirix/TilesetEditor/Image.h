#pragma once

#include "DisplayContext.h"
namespace ONIGIRIX_GUI {
	class RGB_c;
	class RealImage;
}
#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <set>
#include <string>
#include "boost/functional/hash.hpp"
#include "boost/lockfree/queue.hpp"
#include "texture.h"
#include "DIFFERED_LOADER.h"
#include "QueueExecutor.h"
#include "FastUnorderedMap.h"



// clever management of emage
// to do record time of last use to be able to free memory for exemple ....
//think about thred_lacal to ensur thread security while knowing it will be mostly accessed from one thread


namespace ONIGIRIX_GUI {



	class Image {
	public:
		virtual ~Image() {};
		virtual  SDL_H_texture* get_SDL_TEXTURE() = 0;
		virtual  GL_H_texture* get_GL_TEXTURE() = 0;
		virtual  SDL_S_texture* get_SOFTWARE() = 0;
		virtual int get_width();//return -1 if no loaded images
		virtual int get_height();//return -1 if no loaded images
		virtual void set_owner(void*);
		virtual void* get_owner();
		virtual bool is_changing();
	protected:
		int _height = -1;
		int _width = -1;
		void* _owner = nullptr;
	};
	class BasicImage : public Image {
		//totaly unmanaged IMAGE can get and set Texture freely 
		//need to free the textures yourself
	public:
		virtual  SDL_H_texture* get_SDL_TEXTURE();
		virtual  GL_H_texture* get_GL_TEXTURE();
		virtual  SDL_S_texture* get_SOFTWARE();
		virtual  void set_SDL_TEXTURE(SDL_H_texture*);
		virtual  void set_GL_TEXTURE(GL_H_texture*);
		virtual  void set_SOFTWARE(SDL_S_texture*);
		virtual  void set_height(int h);
		virtual  void set_width(int w);
	private:
		SDL_H_texture* _T_H_SDL = nullptr;//The sdl texture (correspond to renderer)
		GL_H_texture* _T_H_GL = nullptr;//The opengl texture
		SDL_S_texture* _T_S_SDL = nullptr;//The software texture
	};

	class ImageStream :public Image {
	public:

		//Beware when using an new image the old image is NOT deleted !!!
		virtual ~ImageStream() {};
		virtual void update(Image*);
		virtual  SDL_H_texture* get_SDL_TEXTURE();
		virtual  GL_H_texture* get_GL_TEXTURE();
		virtual  SDL_S_texture* get_SOFTWARE();
		virtual int get_width();//return -1 if no loaded images
		virtual int get_height();//return -1 if no loaded images
		virtual bool is_changing();
	protected:

		Image* _frame = nullptr;

	};
	class SingleUseImageStream :public ImageStream {

	public:

		//Beware when using an new image the old image is deleted !!!
		virtual ~SingleUseImageStream();
		virtual void update(Image*);

	};
}
//TEMPLATE
#include"ImageTemplate.h"