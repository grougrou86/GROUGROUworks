#pragma once
#include <set>
#include"G_inc.h"
#include<string>
#include "boost/functional/hash.hpp"
#include "texture.h"
#include "DIFFERED_LOADER.h"
#include <unordered_map>

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
		Image(){}
		virtual ~Image();//FREE IMAGE is lete to texture wraper

		DIFFERED_LOADER::loader<SDL_H_texture>& get_SDL_TEXTURE();
		DIFFERED_LOADER::loader<GL_H_texture>& get_GL_TEXTURE();
		DIFFERED_LOADER::loader<SDL_S_texture>& get_SOFTWARE();

		virtual bool is_rescuable();

	protected:

		DIFFERED_LOADER::loader<SDL_H_texture>* _T_H_SDL;//The sdl texture (correspond to renderer)
		DIFFERED_LOADER::loader<GL_H_texture>* _T_H_GL;//The opengl texture
		DIFFERED_LOADER::loader<SDL_S_texture>* _T_S_SDL;//The software texture

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

	struct InfoRealImage
	{
		unsigned int width=0;
		unsigned int height=0;
	};

	class RealImage :public RescuableImage{ // go to search on disk the file url mean the path here
	public:
		RealImage(std::wstring);
		InfoRealImage get_info();
	private:
		InfoRealImage _info;
		virtual void reload_img();
	};
	struct InfoLetterImage
	{
		unsigned int width=0;
		unsigned int height=0;
		wchar_t character = L' ';
		int minx = 0;
		int maxx = 0;
		int miny = 0;
		int maxy = 0;
		int advance = 0;
	};

	class LetterImage :public RescuableImage { // image of a letter 
	public:
		LetterImage(wchar_t letter , std::wstring font , unsigned int size, RGB_c color);
		InfoLetterImage get_info();
	private:
		InfoLetterImage _info;
		virtual void reload_img();
	};


	struct InfoWordImage
	{
		unsigned int width = 0;
		unsigned int height = 0;
	};


	class WordImage :public RescuableImage { // image of a letter 
	public:
		WordImage(wchar_t letter, std::wstring font, unsigned int size, RGB_c color);
		InfoWordImage get_info();
	private:
		InfoWordImage _info;
		virtual void reload_img();
	};

	class ImageDealer
	{
	public:
		ImageDealer();
		~ImageDealer();
		Image* get_image(std::wstring url);
		Image* get_font_image(std::wstring font, unsigned int size, RGB_c color, wchar_t character);
		Image* get_word_image(std::wstring font, unsigned int size, RGB_c color, std::wstring word);

	private:

		std::unordered_map<std::wstring, RealImage> _images;

		std::unordered_map<std::wstring, std::unordered_map<unsigned int, std::unordered_map<RGB_c,std::unordered_map<wchar_t, LetterImage>>>> _font_image;
		std::unordered_map<std::wstring, std::unordered_map<unsigned int, std::unordered_map<RGB_c, std::unordered_map<std::wstring, WordImage>>>> _word_image;
	};
}