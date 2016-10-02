#pragma once
namespace ONIGIRIX_GUI {
	class RGB_c;
	class VideoInstance;
	class VideoManager;
}
#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <set>
#include<string>
#include "boost/functional/hash.hpp"
#include "boost/lockfree/queue.hpp"
#include "texture.h"
#include "DIFFERED_LOADER.h"
#include <unordered_map>
#include "DIFFERED_LOADER.h"




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
	public : 
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

	class ImageStream:public Image {
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
	class ImageVideo : public ImageStream {
	public:
		friend VideoManager;
		ImageVideo(); 
		virtual ~ImageVideo();

		void play(bool);
		void pause();
		bool is_play();
		double duration();
		double current_time();
		void set_time(int);

	private :
		VideoInstance* _instance_vid = nullptr;
		VideoManager* _manager_vid = nullptr;
	};
	/*
	Requirement for the class I :


	- have a heigth and width parameter 
	- set those parameter to zero by default (not -1) for better performance !

	*/
	template <class I> class InfoImage :public Image{//image base url should be a unique identifier
	public:
		InfoImage(SDL_Renderer* r = nullptr):_renderer(r){}
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

		SDL_Renderer* _renderer = nullptr;

		DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* _T_H_SDL=nullptr;//The sdl texture (correspond to renderer)
		DIFFERED_LOADER::loader<std::pair<I, GL_H_texture>>* _T_H_GL=nullptr;//The opengl texture
		DIFFERED_LOADER::loader<std::pair<I, SDL_S_texture>>* _T_S_SDL=nullptr;//The software texture

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
		std::wstring url = L"";
		void* owner = nullptr;
	};

	class RealImage :public RescuableImage<InfoRealImage>{ // go to search on disk the file url mean the path here
	public:
		RealImage(std::wstring,SDL_Renderer* r = nullptr);
		RealImage();
	protected:
		virtual void reload_img();
		std::wstring _url;
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

	

	class ImageConverter {
		// does the job to convert between the three formats !!! : SDL_H_texture / GL_H_texture / SDL_S_texture
		// the return type bool tells if it seems that the loading will work or not it can't promise4 it to work ! 		
		template <class I > bool operator() (DIFFERED_LOADER::loader<std::pair<I, SDL_S_texture>>* target, DIFFERED_LOADER::loader<std::pair<I, GL_H_texture >>* source1, DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* source2);
		template <class I > bool operator() (DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* target, DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* source1, DIFFERED_LOADER::loader<std::pair<I, GL_H_texture >>* source2);
		template <class I > bool operator() (DIFFERED_LOADER::loader<std::pair<I, GL_H_texture >>* target, DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* source1, DIFFERED_LOADER::loader<std::pair<I, SDL_S_texture>>* source2);
	};
	struct ImageLoaderWaiter {
		std::wstring url=L"";
		DIFFERED_LOADER::syncro_tools<std::pair<InfoRealImage, SDL_S_texture>>* target = nullptr;
	};
	typedef boost::lockfree::queue<ImageLoaderWaiter*> ImageLoaderQueue;
	class ImageLoader {
		/*
		Must be accessed throw the ONIGIRIX_GUI::Singleton<ImageLoader>
		load image from disk by url 
		use : 

		ImageLoader::GET(URL);

		WHere URL is the string of the image

		*/
	public:
		ImageLoader();
		~ImageLoader();

		static DIFFERED_LOADER::loader<std::pair<InfoRealImage, SDL_S_texture>>* GET(std::wstring url);

		static void load(const std::wstring & url, SDL_S_texture& target, unsigned int& width, unsigned int& height);

	private:

		static void StartLoader();//starts the image loading thread
		static std::atomic<bool> Is_started;
		static ImageLoaderQueue ImageQueue;

	};
	class ImageSwapper {
		//The goal of an image swapper is to swapp the content of two images when the content is not used ! 
		//So you can request a swap to the image and then a function of the image swapper shall be call before the rendering in the MainLoop each time it is used !
		//the swap function can return an atomic bool so that one know when the swap has been performed -> purpose image in wich we draw can be retrieved whil beeing replace by a raw image.
		//another function must delete the swapped image after beeing used . pupose stream an image exemple : for GIF an video they can in fact be IMAGES !!! the Image swapper should apear in the image infos .
		//the image is supposed not to be used before the atomic flag return is to false or not at all for the second member.
		//the image can be sent from other cores 
		template <class I> std::atomic<bool> swap(Image* img1, Image* img2);
		template <class I> void swap_delete(Image* remaining, Image* deleted);

	};

	class ImageDealer
	{
	public:

		ImageDealer(SDL_Renderer* r=nullptr);
		~ImageDealer();

		RealImage* get_image(std::wstring url);
		void set_renderer(SDL_Renderer* r);
		//LetterImage* get_font_image(std::wstring font, unsigned int size, RGB_c color, wchar_t character);
		//WordImage* get_word_image(std::wstring font, unsigned int size, RGB_c color, std::wstring word);

	private:

		std::unordered_map<std::wstring, RealImage> _images;

		SDL_Renderer* _renderer;

		//std::unordered_map<std::wstring, std::unordered_map<unsigned int, std::unordered_map<RGB_c,std::unordered_map<wchar_t, LetterImage>>>> _font_image;
		//std::unordered_map<std::wstring, std::unordered_map<unsigned int, std::unordered_map<RGB_c, std::unordered_map<std::wstring, WordImage>>>> _word_image;
	};

}