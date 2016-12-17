#pragma once
#include"Image.h"
#include"InfoImage.h"
#include"RealImage.h"
#include<string>
#include"FastUnorderedMap.h"

namespace ONIGIRIX_GUI {
	class ImageDealer
	{
	public:

		ImageDealer(DisplayContext r = DisplayContext());
		~ImageDealer();

		RealImage* get_image(std::wstring url);
		RealImage* get_image(FastMapSearch<std::wstring>& url);

		void remove_image(std::wstring url);
		void remove_image(FastMapSearch<std::wstring>& url);

		void set_DisplayContext(DisplayContext r);


	private:

		FastMap<std::wstring, RealImage*> _images;

		DisplayContext _DisplayContext;
	};
}