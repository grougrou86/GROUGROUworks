#pragma once
#include <set>
#include"G_inc.h"
#include<string>
#include "boost/functional/hash.hpp"
#include "boost/lockfree/stack.hpp"
#include "texture.h"
#include "DIFFERED_LOADER.h"
#include <unordered_map>


// clever management of emage
// to do record time of last use to be able to free memory for exemple ....
//think about thred_lacal to ensur thread security while knowing it will be mostly accessed from one thread


namespace ONIGIRIX_GUI {
	
	template< class I>class UsableImage {//use to propagate the image -> takes responsability of conversion sdl gl texture / software
		UsableImage(Image<I>*);
		~UsableImage();
	};

	template <class I> class Image {//image base url should be a unique identifier
	public:
		Image(){}
		virtual ~Image();//FREE IMAGE is lete to texture wraper

		DIFFERED_LOADER::loader<std::pair<I,SDL_H_texture>>* get_SDL_TEXTURE();
		DIFFERED_LOADER::loader<std::pair<I,GL_H_texture>>* get_GL_TEXTURE();
		DIFFERED_LOADER::loader<std::pair<I,SDL_S_texture>>* get_SOFTWARE();

		virtual bool is_rescuable();

	protected:

		DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* _T_H_SDL=nullptr;//The sdl texture (correspond to renderer)
		DIFFERED_LOADER::loader<std::pair<I, GL_H_texture>>* _T_H_GL=nullptr;//The opengl texture
		DIFFERED_LOADER::loader<std::pair<I, SDL_S_texture>>* _T_S_SDL=nullptr;//The software texture

		unsigned int _SDL_TEXTURE_USER;
		unsigned int _GL_TEXTURE_USER;
		unsigned int _SOFTWARE_USER;
		unsigned int _TOTAL_USER;


		virtual void reload_img();//rescue from total disabling


	};

	//specific loader -> can ad a reload image function so memory can be freeed and then reload just on time has to use las time of use also ...  
	//do not forget to set rescuable to true at initialisation
	template<class I> class RescuableImage : public Image<I> {
	public:
		virtual bool is_rescuable();
	protected:
		virtual void reload_img()=0;
		bool _reload_sent = false;//just fore internal use ...
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
		std::wstring url = L"";
	};

	class RealImage :public RescuableImage<InfoRealImage>{ // go to search on disk the file url mean the path here
	public:
		RealImage(std::wstring);
		InfoRealImage* get_info();//usage of a pointer here because nullptr is returned if data is not ready
	protected:
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

	class LetterImage :public RescuableImage<InfoLetterImage>{ // image of a letter 
	public:
		LetterImage(wchar_t letter , std::wstring font , unsigned int size, RGB_c color);
		InfoLetterImage* get_info();//usage of a pointer here because nullptr is returned if data is not ready
	protected:
		virtual void reload_img();
	};


	struct InfoWordImage
	{
		unsigned int width = 0;
		unsigned int height = 0;
	};


	class WordImage :public RescuableImage<InfoWordImage>{ // image of a letter 
	public:
		WordImage(wchar_t letter, std::wstring font, unsigned int size, RGB_c color);
		InfoWordImage* get_info();//usage of a pointer here because nullptr is returned if data is not ready
	protected:
		virtual void reload_img();
	};

	class ImageDealer
	{
	public:
		ImageDealer();
		~ImageDealer();
		RealImage* get_image(std::wstring url);
		LetterImage* get_font_image(std::wstring font, unsigned int size, RGB_c color, wchar_t character);
		WordImage* get_word_image(std::wstring font, unsigned int size, RGB_c color, std::wstring word);

	private:

		std::unordered_map<std::wstring, RealImage> _images;

		std::unordered_map<std::wstring, std::unordered_map<unsigned int, std::unordered_map<RGB_c,std::unordered_map<wchar_t, LetterImage>>>> _font_image;
		std::unordered_map<std::wstring, std::unordered_map<unsigned int, std::unordered_map<RGB_c, std::unordered_map<std::wstring, WordImage>>>> _word_image;
	};

	class ImageConverter {
		// does the job to convert between the three formats !!! : SDL_H_texture / GL_H_texture / SDL_S_texture
		// the return type bool tells if it seems that the loading will work or not it can't promise4 it to work ! 		
		template <class I > bool operator() (DIFFERED_LOADER::loader<std::pair<I, SDL_S_texture>>* target, DIFFERED_LOADER::loader<std::pair<I, GL_H_texture >>* source1, DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* source2);
		template <class I > bool operator() (DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* target, DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* source1, DIFFERED_LOADER::loader<std::pair<I, GL_H_texture >>* source2);
		template <class I > bool operator() (DIFFERED_LOADER::loader<std::pair<I, GL_H_texture >>* target, DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* source1, DIFFERED_LOADER::loader<std::pair<I, SDL_S_texture>>* source2);
	};
	class ImageLoader {

		template<class I> bool operator() (std::wstring url ,DIFFERED_LOADER::loader<std::pair<I, SDL_S_texture>>* target);
		template<> bool operator() (std::wstring url, DIFFERED_LOADER::loader<std::pair<InfoRealImage, SDL_S_texture>>* target);

		void loadBMP(const std::wstring & url, SDL_S_texture& target, unsigned int& width, unsigned int& height);
		void loadPNG(const std::wstring & url, SDL_S_texture& target, unsigned int& width, unsigned int& height);

	};
}