#pragma once
#include "Image.h"
#include "InfoImage.h"
#include "QueueExecutor.h"
#include <string>
#include "DIFFERED_LOADER.h"
#include "texture.h"
#include "DisplayContext.h"

namespace ONIGIRIX_GUI {
	struct InfoRealImage
	{
		unsigned int width = 0;
		unsigned int height = 0;
		std::wstring url = L"";
		void* owner = nullptr;
	};
	struct ImageLoaderWaiter {
		std::wstring url = L"";
		DIFFERED_LOADER::syncro_tools<std::pair<InfoRealImage, SDL_S_texture>>* target = nullptr;
	};
	void ConstructRealImage(ImageLoaderWaiter* current_load);

	class RealImage :public RescuableImage<InfoRealImage> { // go to search on disk the file url mean the path here
		friend void ConstructRealImage(ImageLoaderWaiter*);
	public:
		RealImage(std::wstring, DisplayContext r = DisplayContext());
		RealImage();
	protected:

		//tools to ensure one image is loaded at a time in another thread
		static DIFFERED_LOADER::loader<std::pair<InfoRealImage, SDL_S_texture>>* get_img_loader(std::wstring url);
		static void load(const std::wstring & url, SDL_S_texture& target, unsigned int& width, unsigned int& height);
		static QueueExecutor<ImageLoaderWaiter> Executor;//load all image in another thread all one after the other

		virtual void reload_img();
		std::wstring _url;
	};
}