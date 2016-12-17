#include"Image.h"
#include"InfoImage.h"
#include"RealImage.h"
#include"ImageDealer.h"
#include<string>
#include"FastUnorderedMap.h"

namespace ONIGIRIX_GUI {
	ImageDealer::ImageDealer(DisplayContext renderer)
	{
		_DisplayContext = renderer;
	}
	void ImageDealer::set_DisplayContext(DisplayContext renderer) {
		_DisplayContext = renderer;
	}
	ImageDealer::~ImageDealer()
	{
		while (_images.size()!=0) {
			auto last = _images.last();
			delete (*_images[last]);
			_images.Remove(last);
		}
	}
	RealImage* ImageDealer::get_image(FastMapSearch<std::wstring>& url) {

		RealImage** I = _images[url];
		if (I != nullptr) {
			return *I;
		}

		_images.Insert(url, new RealImage(url.get_key(), _DisplayContext));
		return *_images[url];
	}
	RealImage* ImageDealer::get_image(std::wstring url) {
		return get_image(FastMapSearch<std::wstring>(url));
	}
}