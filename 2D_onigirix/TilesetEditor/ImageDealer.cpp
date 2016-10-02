#include"ImageDealer.h"
#include"encodage.h"
#include"Video_Player.h"
#include<mutex>

namespace ONIGIRIX_GUI {


	RealImage::RealImage() {
		throw("error URL needed to build an image");
	}
	RealImage::RealImage(std::wstring url, SDL_Renderer* r) {
		_renderer = r;
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
	template<class I> void InfoImage<I>::reload_img() {
		throw("IMAGE COULD NOT BE RECOVERED ERROR !!!");
	}
	template<class I> bool InfoImage<I>::is_rescuable() {
		return false;
	}
	template<class I> bool RescuableImage<I>::is_rescuable() {
		return true;
	}
	template<class I> InfoImage<I>::~InfoImage() {

		if (_T_H_SDL != nullptr) delete _T_H_SDL;
		if (_T_H_GL != nullptr) delete _T_H_GL;
		if (_T_S_SDL != nullptr) delete _T_S_SDL;

		//need do destroy remaining images !
	}
	template <class I> GL_H_texture* InfoImage<I>::get_GL_TEXTURE() {

		return nullptr;
	}

	

	template <class I> SDL_H_texture* InfoImage<I>::get_SDL_TEXTURE() {
		if (_T_H_SDL == nullptr&&_T_S_SDL == nullptr) {
			reload_img();
		}
		if (_T_H_SDL != nullptr) {
			if (_T_H_SDL->get_data() != nullptr) return &(_T_H_SDL->get_data()->second);
		}
		if (_T_S_SDL != nullptr&&_T_S_SDL->get_data()!=nullptr&&_T_H_SDL==nullptr) {

			if (_renderer != nullptr) {
				SDL_Texture* newtex = SDL_CreateTextureFromSurface(_renderer, _T_S_SDL->get_data()->second.native());
				std::cout << "renderer" << _renderer << std::endl;
				std::function<void(DIFFERED_LOADER::syncro_tools<std::pair<I, SDL_H_texture>>*, std::pair<I, SDL_Texture*>)> soft2hard = [](DIFFERED_LOADER::syncro_tools<std::pair<I, SDL_H_texture>>* flag, std::pair<I, SDL_Texture*> info) {
					SDL_H_texture b;
					std::pair<I, SDL_H_texture>* m =new std::pair<I, SDL_H_texture>();
					m->first = info.first;
					m->second = std::move(b);
					m->second.set(info.second);
					flag->finish_use(m);
				};
				_T_H_SDL = new DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>(soft2hard,std::pair<I, SDL_Texture*>(*get_info(),newtex),false);
				if (_T_H_SDL!=nullptr&&_T_H_SDL->get_data() != nullptr) {
					std::cout << "THE NEW TESXTURES ARE" << _T_H_SDL->get_data() << std::endl;
					return &(_T_H_SDL->get_data()->second);
				}
			}
			return nullptr;
		}
			return nullptr;
	}
	template <class I> SDL_S_texture*  InfoImage<I>::get_SOFTWARE() {
		if (_T_S_SDL == nullptr) {
			reload_img();
		}
		if (_T_S_SDL != nullptr) {
			if (_T_S_SDL->get_data() != nullptr) return &(_T_S_SDL->get_data()->second);
		}
		else {
			return nullptr;
		}
	}
	ImageDealer::ImageDealer(SDL_Renderer* renderer)
	{
		_renderer = renderer;
	}
	void ImageDealer::set_renderer(SDL_Renderer* renderer) {
		_renderer = renderer;
	}
	ImageDealer::~ImageDealer()
	{


	}
	RealImage* ImageDealer::get_image(std::wstring url) {

		if (_images.size() != 0) {

			std::unordered_map<std::wstring, RealImage>::iterator iter = _images.find(url);

			if (iter != _images.end())
			{
				std::cout << ws2s(iter->first) << " is ";
				return &(iter->second);
			}
		}
		
		_images.insert(std::pair<std::wstring, RealImage>(url, RealImage(url,_renderer)));
		_images[url].set_owner(this);
		return &_images[url];
	}

	template<class I> I* InfoImage<I>::get_info() {
		std::pair<I, SDL_S_texture>* data_1 = nullptr;
		std::pair<I, SDL_H_texture>* data_2 = nullptr;
		std::pair<I, GL_H_texture>* data_3 = nullptr;
		get_SOFTWARE();
		data_1 = _T_S_SDL->get_data();
		if (data_1 == nullptr) {
			get_SDL_TEXTURE();
			data_2 = _T_H_SDL->get_data();
			if (data_2 == nullptr) {
				get_GL_TEXTURE();
				data_3 = _T_H_GL->get_data();
				if (data_3 == nullptr) {
					if (! _reload_sent) {
						_reload_sent = true;
						reload_img();
						I* result = get_info();
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
	template<class I> int InfoImage<I>::get_height() {
		if (_height == -1) {
			I* info = get_info();
			if (info != nullptr) {
				_height = get_info()->height;
			}
		}
		return _height;
	}
	template<class I> int InfoImage<I>::get_width() {
		if (_width == -1) {
			I* info = get_info();
			if (info != nullptr) {
				_width = get_info()->width;
			}
		}
		return _width;
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
		_instance_vid->is_play();
	}
}