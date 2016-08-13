#include"ImageDealer.h"
#include"encodage.h"

namespace ONIGIRIX_GUI {

	template<class I> void Image<I>::reload_img() {
		throw("IMAGE COULD NOT BE RECOVERED ERROR !!!");
	}
	template<class I> bool Image<I>::is_rescuable(){
		return false;
	}
	template<class I> bool RescuableImage<I>::is_rescuable() {
		return true;
	}
	template<class I> Image<I>::~Image() {
		//need do destroy remaining images !
	}
	template <class I> DIFFERED_LOADER::loader<std::pair<I, GL_H_texture>>* Image<I>::get_GL_TEXTURE() {
		
		return nullptr;
	}
	template <class I> DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>* Image<I>::get_SDL_TEXTURE() {

		if (_T_H_SDL != nullptr) {
			return _T_H_SDL;
		}
		else if (_T_S_SDL != nullptr) {
			return _T_H_SDL;
		}
		else if (_T_H_GL != nullptr) {

			return _T_H_SDL;
		}
		else {
			return nullptr;
		}
	}
	template <class I> DIFFERED_LOADER::loader<std::pair<I, SDL_S_texture>>*  Image<I>::get_SOFTWARE() {
		return nullptr;
	}
	ImageDealer::ImageDealer()
	{
	}

	ImageDealer::~ImageDealer()
	{
	}
	InfoRealImage* RealImage::get_info() {
		std::pair<InfoRealImage, SDL_S_texture>* data_1 = nullptr;
		std::pair<InfoRealImage, SDL_H_texture>* data_2 = nullptr;
		std::pair<InfoRealImage, GL_H_texture>* data_3 = nullptr;
		data_1 = get_SOFTWARE()->get_data();
		if (data_1 == nullptr) {
			data_2 = get_SDL_TEXTURE()->get_data();
			if (data_2 == nullptr) {
				data_3 = get_GL_TEXTURE()->get_data();
				if (data_3 == nullptr) {
					if (! _reload_sent) {
						_reload_sent = true;
						reload_img();
						InfoRealImage* result = get_info();
						_reload_sent = false;
						return result;
					}
					return nullptr;
				}
				else {
					return &(data_3->first);
				}
			} else {
				return &(data_2->first);
			}
		}
		else {
			return &(data_1->first);
		}

		return nullptr;
	}
	InfoLetterImage* LetterImage::get_info() {
		return nullptr;
	}
	InfoWordImage* WordImage::get_info() {
		return nullptr;
	}
	template<class I> bool ImageLoader::operator() (std::wstring url ,DIFFERED_LOADER::loader<std::pair<I, SDL_S_texture>>* target) {
		throw("The info type for image is not recognised please use info type : 'InfoRealImage' ");
	}
	template<> bool ImageLoader::operator() (std::wstring url ,DIFFERED_LOADER::loader<std::pair<InfoRealImage, SDL_S_texture>>* target) {

	}
	void ImageLoader::loadBMP(const std::wstring & url, SDL_S_texture& target, unsigned int& width, unsigned int& height) {

	}
	void ImageLoader::loadPNG(const std::wstring & url, SDL_S_texture& target, unsigned int& width, unsigned int& height) {
		SDL_Surface* glsurf = nullptr;

		//Loading success flag
		bool success = true;

		//Load splash image
		glsurf = IMG_Load(ws2s(url).c_str());
		if (glsurf == NULL)
		{
			printf("Unable to load image #.# SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		target.set(glsurf);
	}
}