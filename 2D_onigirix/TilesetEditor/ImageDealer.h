#pragma once
#include <set>
#include"G_inc.h"
#include<string>
#include "texture.h"



// clever management of emage
// to do record time of last use to be able to free memory for exemple ....
//think about thred_lacal to ensur thread security while knowing it will be mostly accessed from one thread


namespace ONIGIRIX_GUI {
	
	class UsableImage {//use to propagate the image -> takes responsability of conversion sdl gl texture / software
		UsableImage(Image*);
		~UsableImage();
	};


	class Image {//image base url should be a unique identifier
	public:
		Image(std::wstring url):_url(url){}
		virtual ~Image();//FREE IMAGE is lete to texture wraper

		texture<SDL_H_texture>& get_SDL_TEXTURE();
		texture<GL_H_texture>& get_GL_TEXTURE();
		texture<SDL_S_texture>& get_SOFTWARE();

		virtual bool is_rescuable();

	protected:
		std::wstring _url;

		texture<SDL_H_texture> _T_H_SDL;//The sdl texture (correspond to renderer)
		texture<GL_H_texture> _T_H_GL;//The opengl texture
		texture<SDL_S_texture> _T_S_SDL;//The software texture

		unsigned int _SDL_TEXTURE_USER;
		unsigned int _GL_TEXTURE_USER;
		unsigned int _SOFTWARE_USER;
		unsigned int _TOTAL_USER;


		virtual void reload_img();//rescue from total disabling


	};
	//specific loader -> can ad a reload image function so memory can be freeed and then reload just on time has to use las time of use also ...  
	//do not forget to set rescuable to true at initialisation
	class RescuableImage : public Image {
	public:
		virtual bool is_rescuable();
	private:
		virtual void reload_img()=0;
	};
	//the identification string for the following Image are :
	//	- loadables image from disk : D[path]
	//	- letter image : L[caracter]

	//need to add duration since not used !

	// must use a unique thread id from which images can be processed one id for each type ??


	class RealImage :public RescuableImage{ // go to search on disk the file url mean the path here
	public:
		RealImage(std::wstring);
	};
	class LetterImage :public RescuableImage { // image of a letter 
	public:
		LetterImage(std::wstring , std::wstring font , unsigned int size);
	private:
		static std::vector<std::wstring> FontLocation;
	};

	class ImageDealer
	{
	public:
		ImageDealer();
		~ImageDealer();
		Image* allocate(std::string url);
		void release(std::string url);//remove from use 

	private:

		std::set<Image> _images;

	};
}