#pragma once
#include <atomic>
#include <mutex>
#include "G_inc.h"

namespace ONIGIRIX_GUI {

	//IMPORTANT
	//the idea is the textures are used from only one thread but can be loaded from varius threads !
	//need to define convertion and convertion function

	//a texture can juste be ready or not one can asume that if a texture is once said ready it will be forever unless it is deleted.

	
	
	//the countainer make the desalocation and can be passed and subsist even if the texture object is deleted in which case it will outodelete after having recieved the texture 
	
	
	//!  A class to auto delete a no more used texture but enable the texture to be pushed by another thread in it  . 
	/*!
	BE WARE : 
		-class must always be declared 
		-The only function that shall be called from another thread is push_value 
		-all the other function must be called from only one thread 
		-- follow exemple for texture class do no use seperatly from texture class at the exception of a pusher thread that would push the image in it.
	*/
	template<class T> class auto_delete_count {
	public:
		//! is NOT MULTITHREADED return the value
		auto_delete_count():_classCONT(NULL) {
			
		}
		//! is NOT MULTITHREADED return the value
		virtual ~auto_delete_count() {
			//nothing to delete it is to _classCONT  to auto delet it self
		}
		//! is NOT MULTITHREADED return the value
		T value(){
			return _classCONT;
		}
		//! is NOT a multithreaded function must be called from main thread !
		auto_delete_count<T>* request_query() {//WILL SEND 0 if operation is canceled at last minute !!!
			if (!sent_to_fill) {
				sent_to_fill = true;
				return this;
			}
			else {
				throw("texture alwready sent to be filled error");
				return NULL;
			}
		}
		//! shall be used from another thread to push the new value in texture but this other thread must havce aquired the value of this instance pointer by a call to request_query()
		void push_value(T& newval) {
			std::lock_guard<std::mutex> lck(mtx);//auto handel of locking / unlocking -> great ^^
			if (auto_delete) {
				delete this;
			}
			else {
				_classCONT = std::move(newval);
				ready = true;
				sent_to_fill = false;
				//recheck in case auto_delete was change juste in between ....
				if (auto_delete) {
					delete this;
				}
			}
			
		}
		//! is NOT MULTITHREADED return the value
		void detach() {
			_auto_delete = true;
		}
		std::atomic<bool> sent_to_fill = false;
		std::mutex mtx;
		std::atomic<bool> ready = false;
		std::atomic<bool>_auto_delete = false;
	private:
		T _classCONT;
	};

	//!The native handler for opengl textures 
	class GL_H_texture {

	public:
		bool read = false;
	};
	//!the native handler for SDL Surface 
	class SDL_S_texture{
	public:

	private:
		SDL_Surface* _texture = NULL;
		bool ready = false;
	};
	//!the native handler for SDL texture
	class SDL_H_texture {
	public:

	private:
		SDL_Texture* _texture= NULL;
		bool ready = false;
	};

	template<class T>class texture {
	public:
		texture():_texture(new auto_delete_count<T>()) {
			
		}
		virtual ~texture() {
			std::lock_guard<std::mutex> lck(_texture->mtx);
			if (_texture->sent_to_fill) {
				_texture->detach();
			}
			else {
				delete _texture;
			}
		}
		bool state();
		template<class U> void load(U&) {
			
		}
		T get_texture() {
			return _texture;
		}

	protected:
		auto_delete_count<T>* _texture;

		
	};

	class Converter {
	public:
		
	private:
		//to implement .... a stack of paire to convert
		

	};
}