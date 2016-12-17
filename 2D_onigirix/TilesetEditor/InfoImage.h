#pragma once
#include"Image.h"
#include "QueueExecutor.h"
#include <string>
#include "DIFFERED_LOADER.h"
#include "texture.h"
#include "DisplayContext.h"

/*
Requirement for the class I :


- have a heigth and width parameter
- set those parameter to zero by default (not -1) for better performance !

*/
namespace ONIGIRIX_GUI {
	template <class I> class InfoImage :public Image {//image base url should be a unique identifier
	public:
		InfoImage(DisplayContext r = DisplayContext()) :_DisplayContext(r) {}
		virtual ~InfoImage();//FREE IMAGE is lete to texture wraper

		virtual  SDL_H_texture* get_SDL_TEXTURE();
		virtual  GL_H_texture* get_GL_TEXTURE();
		virtual  SDL_S_texture* get_SOFTWARE();

		virtual I* get_info();//usage of a pointer here because nullptr is returned if data is not ready
		virtual bool is_rescuable();

		virtual int get_height();
		virtual int get_width();

		void* owner = nullptr;

	protected:

		DisplayContext _DisplayContext = DisplayContext();

		DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* _T_H_SDL = nullptr;//The sdl texture (correspond to renderer)
		DIFFERED_LOADER::loader<std::pair<I, GL_H_texture>>* _T_H_GL = nullptr;//The opengl texture
		DIFFERED_LOADER::loader<std::pair<I, SDL_S_texture>>* _T_S_SDL = nullptr;//The software texture

		unsigned int _SDL_TEXTURE_USER;
		unsigned int _GL_TEXTURE_USER;
		unsigned int _SOFTWARE_USER;
		unsigned int _TOTAL_USER;


		virtual void reload_img();//rescue from total disabling
		bool _reload_sent = false;//just fore internal use ...

	};

	//specific loader -> can ad a reload image function so memory can be freeed and then reload just on time has to use las time of use also ...  
	//do not forget to set rescuable to true at initialisation

	template<class I> class RescuableImage : public InfoImage<I> {
	public:
		virtual ~RescuableImage() {};
		virtual bool is_rescuable();
	protected:
		virtual void reload_img() = 0;
	};
}
#include"InfoImageTemplate.h"