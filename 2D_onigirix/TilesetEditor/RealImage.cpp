#include "Image.h"
#include "InfoImage.h"
#include "RealImage.h"
#include "encodage.h"
#include "QueueExecutor.h"
#include "DisplayContext.h"

namespace ONIGIRIX_GUI {

	RealImage::RealImage() {
		throw("error URL needed to build an image");
	}
	RealImage::RealImage(std::wstring url, DisplayContext r) {
		_DisplayContext = r;
		_url = url;
	}
	void RealImage::reload_img() {
		if (_T_S_SDL == nullptr) {
			_T_S_SDL = get_img_loader(_url);
		}
		else {
			throw("An image has already been loaded so can not reload !!! because _T_S_SDL is not a nullptr.");
		}
	}
	void ConstructRealImage(ImageLoaderWaiter* current_load) {
		std::pair<InfoRealImage, SDL_S_texture>* result = new std::pair<InfoRealImage, SDL_S_texture>();
		RealImage::load(current_load->url, result->second, result->first.width, result->first.height);
		result->first.url = current_load->url;
		current_load->target->finish_use(result);
	}
	QueueExecutor<ImageLoaderWaiter> RealImage::Executor(ConstructRealImage);
	DIFFERED_LOADER::loader<std::pair<InfoRealImage, SDL_S_texture>>* RealImage::get_img_loader(std::wstring url) {
		std::function<void(DIFFERED_LOADER::syncro_tools<std::pair<InfoRealImage, SDL_S_texture>>*, std::pair<std::wstring, QueueExecutor<ImageLoaderWaiter>*>)> toCall = [](DIFFERED_LOADER::syncro_tools<std::pair<InfoRealImage, SDL_S_texture>>* flag, std::pair<std::wstring, QueueExecutor<ImageLoaderWaiter>*> info) {
			ImageLoaderWaiter* data = new ImageLoaderWaiter();
			data->url = info.first;
			data->target = flag;
			info.second->add_task(data);
		};
		DIFFERED_LOADER::loader<std::pair<InfoRealImage, SDL_S_texture>>* retour = new DIFFERED_LOADER::loader<std::pair<InfoRealImage, SDL_S_texture>>(toCall, std::pair<std::wstring, QueueExecutor<ImageLoaderWaiter>*>(url, &RealImage::Executor), false);
		return retour;
	}
	void RealImage::load(const std::wstring & url, SDL_S_texture& target, unsigned int& width, unsigned int& height) {
		SDL_Surface* glsurf = nullptr;
		//Loading success flag
		bool success = true;
		//Load splash image
		glsurf = IMG_Load(ws2s(url).c_str());
		width = glsurf->w;
		height = glsurf->h;
		if (glsurf == NULL)
		{
			printf("Unable to load image #.# SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		target.set(glsurf);
	}
}