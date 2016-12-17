#include"Image.h"
#include"encodage.h"
#include"Video_Player.h"
#include<mutex>
#include"QueueExecutor.h"

namespace ONIGIRIX_GUI {


	
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
	
}