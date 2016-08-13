#pragma once
#include<atomic>
#include<thread>
#include<mutex>


/*
EXEMPLE OF USE :

class BIG_DATA {
public:
	virtual ~BIG_DATA() {
	std::cout << "BIG deleted" << std::endl;
	}
	BIG_DATA() { std::this_thread::sleep_for(std::chrono::seconds(1)); }//some big data to init ......
};
void init_BIG_DATA(DIFFERED_LOADER::syncro_tools<BIG_DATA>* flag) {
	BIG_DATA* result = new BIG_DATA(); //heavy operation
	flag->finish_use(result); //																				<<------- VERY IMPORTANT !!! the function to call when result is ready
}


//now to differ load in main just use as following (here true state for start the function in a new thread ^^)

if (true) {							<<---- useless but to show case where the loader is deleted before the data is but the data will still be deleted without problem ^^ 
DIFFERED_LOADER::loader<BIG_DATA> d1(init_BIG_DATA);
}
DIFFERED_LOADER::loader<BIG_DATA> d(init_BIG_DATA,true);
BIG_DATA* raw;
while (d.get_data() == nullptr);//WAIT for the result to be ready (could do something usefull during that time....)
for (size_t i = 0; i < 1000000000; i++)	raw = d.get_data();

------------------------------------------------------------IMPORTANT CONDITION TO USE IT-----------------------------------------------------------------------

		- THE data are released by the loader you do not need to do any thing.
*/

namespace DIFFERED_LOADER {

	template<class T> class loader;
	template<class T> class syncro_tools {
		friend class loader<T>;
	public:
		~syncro_tools() {
			if (_data != nullptr)delete _data;
		}
		void finish_use(T* d) {
			if (ready) throw("big erro try to finish yuse as it has already been done.... so nasty guy");
			mutex2.lock();
			_data = d;
			ready=true;
			if (auto_delete) {
				delete this;
			}
			mutex2.unlock();
		}
		T* _data = nullptr;
		//! tell you if the value is still needed if not return false then just call from the builder thread flag.finish_use(nullptr) so no pain ^^ tcheck it reglarly if the build is really heavy !
		bool need() {
			return !auto_delete;
		}
	protected:
		std::mutex mutex2; //to ensure the two deletion are not made at same time 
		std::atomic<bool> ready = false;
		std::atomic<bool> auto_delete = false;
	};
	template<class T>class loader {//T is the big data
	public:
		loader(T* readyElement) {//direct load by providing the data
			ready = true;
			_data = readyElement;

		}
		loader(void(*function)(syncro_tools<T>*),bool in_thread=false) {//differed load 

			syncro = new syncro_tools<T>();
			syncro->ready.store(false);

			if (in_thread) {
				std::thread t = std::thread(function, syncro);
				t.detach();
			}
			else function(syncro);
		}
		template<class U> loader(void(*function)(syncro_tools<T>*, U), U info,bool in_thread = false) {

			syncro = new syncro_tools<T>();
			syncro->ready.store(false);

			if (in_thread) {
				std::thread t = std::thread(function, syncro, info);
				t.detach();
			}
			else function(syncro, info);
		}
		~loader() {
			if (syncro != nullptr) {
				if (syncro->ready) {
					delete syncro;
				}
				else {
					bool ask_final_deletion = false;
					syncro->mutex2.lock(); //be ware not to wait on lock 1 to avoid dead lock !!!
					syncro->auto_delete = true;
					if (syncro->ready) {
						ask_final_deletion = true;
					}
					syncro->mutex2.unlock();
					if (ask_final_deletion) {
						delete syncro;
					}
				}
			}
			if (_data != nullptr) {
				delete _data;
			}
		}
		T* get_data() {
			if (ready) { return _data; }
			else {
				if (syncro->ready) {
					ready = true;
					_data = syncro->_data;
					syncro->_data = nullptr;
					delete syncro;
					syncro = nullptr;
					return _data;
				}
				else return nullptr;
			}
		}
	private:
		T* _data = nullptr;
		syncro_tools<T>* syncro;
		bool ready = false;
	};
}