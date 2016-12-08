#include"ImageDealer.h"
#include"encodage.h"
#include"Video_Player.h"
#include<mutex>

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
			_T_S_SDL = ImageLoader::GET(_url);
		}
		else {
			throw("An image has already been loaded so can not reload !!! because _T_S_SDL is not a nullptr.");
		}
	}
	int Image::get_height() {
		return _height;
	}
	int Image::get_width() {
		return _width;
	}
	void Image::set_owner(void* pointer) {
		_owner = pointer;
	}
	void* Image::get_owner() {
		return _owner;
	}
	bool Image::is_changing() {
		return false;
	}
	bool ImageStream::is_changing() {
		return true;
	}

	ImageDealer::ImageDealer(DisplayContext renderer)
	{
		_DisplayContext = renderer;
	}
	void ImageDealer::set_DisplayContext(DisplayContext renderer) {
		_DisplayContext = renderer;
	}
	ImageDealer::~ImageDealer()
	{


	}
	RealImage* ImageDealer::get_image(std::wstring url) {

		if (_images.size() != 0) {

			std::unordered_map<std::wstring, RealImage>::iterator iter = _images.find(url);

			if (iter != _images.end())
			{
				return &(iter->second);
			}
		}
		
		_images.insert(std::pair<std::wstring, RealImage>(url, RealImage(url, _DisplayContext)));
		_images[url].set_owner(this);
		return &_images[url];
	}
	

	
	
	InfoLetterImage* LetterImage::get_info() {
		return nullptr;
	}
	InfoWordImage* WordImage::get_info() {
		return nullptr;
	}

	//initing the static var of the loader 
	ImageLoaderQueue ImageLoader::ImageQueue(0) ;
	std::atomic<bool> ImageLoader::Is_started(false);

	ImageLoader::ImageLoader() {
		throw("'ImageLoader' can not be used like this its purpose is only to be used as a pure static object to make loading of file (aspecialy image here) so dont creat it simply call : 'ImageLoader::GET(std::wstring url)'");
	}
	ImageLoader::~ImageLoader() {
		throw("'ImageLoader' can not be used like this please refer to the constructor thrown message ");
	}
	DIFFERED_LOADER::loader<std::pair<InfoRealImage, SDL_S_texture>>* ImageLoader::GET(std::wstring url) {
		std::function<void(DIFFERED_LOADER::syncro_tools<std::pair<InfoRealImage, SDL_S_texture>>*, std::pair<std::wstring, ImageLoaderQueue*> )> toCall = [](DIFFERED_LOADER::syncro_tools<std::pair<InfoRealImage, SDL_S_texture>>* flag, std::pair<std::wstring, ImageLoaderQueue*> info) {
			ImageLoaderWaiter* data = new ImageLoaderWaiter();
			data->url = info.first;
			data->target = flag;
			info.second->push(data);
		};
		DIFFERED_LOADER::loader<std::pair<InfoRealImage, SDL_S_texture>>* retour = new DIFFERED_LOADER::loader<std::pair<InfoRealImage, SDL_S_texture>>(toCall,std::pair<std::wstring, ImageLoaderQueue*>(url, & ImageLoader::ImageQueue),false);
		
		if (!Is_started.exchange(true)) {
			StartLoader();
		}
		return retour;
	}
	void ImageLoaderLoadingFunction(std::atomic<bool>* flag ,ImageLoaderQueue* to_load) {
		ImageLoaderWaiter* current_load;

		ImageLoaderLoadingFunctionStart:

		while (to_load->pop(current_load))
		{
			 
			//do the loading.......
			std::pair<InfoRealImage, SDL_S_texture>* result = new std::pair<InfoRealImage, SDL_S_texture>();
			ImageLoader::load(current_load->url,result->second,result->first.width,result->first.height);
			result->first.url = current_load->url;
			current_load->target->finish_use(result);
			//finish the loading now we have to delete the element ^^
			delete current_load;
		}
		flag->store(false);
		if (!to_load->empty()) {
			if (!flag->exchange(true)) {
				goto ImageLoaderLoadingFunctionStart;
			}
		}

		return;
	}
	void ImageLoader::StartLoader() {
		std::thread t = std::thread(ImageLoaderLoadingFunction, &Is_started, &ImageQueue);
		t.detach();
	}
	void ImageLoader::load(const std::wstring & url, SDL_S_texture& target, unsigned int& width, unsigned int& height) {
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
	SDL_H_texture* ImageStream::get_SDL_TEXTURE() {
		if (_frame != nullptr) return _frame->get_SDL_TEXTURE();
		else return nullptr;
	}
	GL_H_texture* ImageStream::get_GL_TEXTURE() {
		if (_frame != nullptr) return _frame->get_GL_TEXTURE();
		else return nullptr;
	}
	SDL_S_texture* ImageStream::get_SOFTWARE() {
		if (_frame != nullptr) return _frame->get_SOFTWARE();
		else return nullptr;
	}
	int ImageStream::get_width() {
		if (_frame != nullptr) return _frame->get_width();
		else return -1;
	}
	int ImageStream::get_height() {
		if (_frame != nullptr) return _frame->get_height();
		else return -1;
	}
	void ImageStream::update(Image* img) {
		_frame = img;
	}
	SingleUseImageStream::~SingleUseImageStream() {
		if (_frame != nullptr) {
			delete _frame;
			_frame = nullptr;
		}
	}
	void SingleUseImageStream::update(Image* img) {
		if (_frame != nullptr) {
			delete _frame;
			_frame = nullptr;
		}
		ImageStream::update(img);
	}
	void BasicImage::set_height(int h) {
		_height = h;
	}
	void BasicImage::set_width(int w) {
		_width = w;
	}
	SDL_H_texture* BasicImage::get_SDL_TEXTURE() {
		return _T_H_SDL;
	}
	GL_H_texture* BasicImage::get_GL_TEXTURE() {
		return _T_H_GL;
	}
	SDL_S_texture* BasicImage::get_SOFTWARE() {
		return _T_S_SDL;
	}
	void BasicImage::set_SDL_TEXTURE(SDL_H_texture* t) {
		_T_H_SDL = t;
	}
	void BasicImage::set_GL_TEXTURE(GL_H_texture* t) {
		_T_H_GL = t;
	}
	void BasicImage::set_SOFTWARE(SDL_S_texture* t) {
		_T_S_SDL = t;
	}
	ImageVideo::ImageVideo() {
	}
	ImageVideo::~ImageVideo() {
		if (_instance_vid != nullptr && _manager_vid != nullptr) {
			_manager_vid->RemoveInstance(_instance_vid);
		}
	}
	void ImageVideo::play(bool p) {
		_instance_vid->play(p);
	}
	bool ImageVideo::is_play() {
		return _instance_vid->is_play();
	}
	void ImageVideo::set_time(int t) {
		_instance_vid->set_time(t);
	}
	int ImageVideo::get_time() {
		return _instance_vid->get_time();
	}
	int ImageVideo::get_max_time() {
		return _instance_vid->get_max_time();
	}
	void ImageVideo::set_volume(double v) {
		_instance_vid->set_volume(v);
	}
	double ImageVideo::get_volume() {
		return _instance_vid->get_volume();
	}
}