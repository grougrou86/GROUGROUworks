#include"ImageDealer.h"

namespace ONIGIRIX_GUI {

	void Image::reload_img() {
		throw("IMAGE COULD NOT BE RECOVERED ERROR !!!");
	}
	bool Image::is_rescuable(){
		return false;
	}
	bool RescuableImage::is_rescuable() {
		return true;
	}
	Image::~Image() {
		//need do destroy remaining images !
	}
	ImageDealer::ImageDealer()
	{
	}

	ImageDealer::~ImageDealer()
	{
	}
	InfoRealImage RealImage::get_info() {
		return _info;
	}
	InfoLetterImage LetterImage::get_info() {
		return _info;
	}
	InfoWordImage WordImage::get_info() {
		return _info;
	}
}