namespace ONIGIRIX_GUI {
	template<class I> void InfoImage<I>::reload_img() {
		throw("IMAGE COULD NOT BE RECOVERED ERROR !!!");
	}
	template<class I> bool InfoImage<I>::is_rescuable() {
		return false;
	}
	template<class I> bool ONIGIRIX_GUI::RescuableImage<I>::is_rescuable() {
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
		if (_T_S_SDL != nullptr&&_T_S_SDL->get_data() != nullptr&&_T_H_SDL == nullptr) {

			if (_renderer != nullptr) {
				SDL_Texture* newtex = SDL_CreateTextureFromSurface(_renderer, _T_S_SDL->get_data()->second.native());
				std::cout << "renderer" << _renderer << std::endl;
				std::function<void(DIFFERED_LOADER::syncro_tools<std::pair<I, SDL_H_texture>>*, std::pair<I, SDL_Texture*>)> soft2hard = [](DIFFERED_LOADER::syncro_tools<std::pair<I, SDL_H_texture>>* flag, std::pair<I, SDL_Texture*> info) {
					SDL_H_texture b;
					std::pair<I, SDL_H_texture>* m = new std::pair<I, SDL_H_texture>();
					m->first = info.first;
					m->second = std::move(b);
					m->second.set(info.second);
					flag->finish_use(m);
				};
				_T_H_SDL = new DIFFERED_LOADER::loader<std::pair<I, SDL_H_texture>>(soft2hard, std::pair<I, SDL_Texture*>(*get_info(), newtex), false);
				if (_T_H_SDL != nullptr&&_T_H_SDL->get_data() != nullptr) {
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
	template<class I> I* InfoImage<I>::get_info() {
		std::pair<I, SDL_S_texture>* data_1 = nullptr;
		std::pair<I, SDL_H_texture>* data_2 = nullptr;
		std::pair<I, GL_H_texture>* data_3 = nullptr;
		get_SOFTWARE();
		if (_T_S_SDL != nullptr) data_1 = _T_S_SDL->get_data();
		if (data_1 == nullptr) {
			get_SDL_TEXTURE();
			if (_T_H_SDL != nullptr) data_2 = _T_H_SDL->get_data();
			if (data_2 == nullptr) {
				get_GL_TEXTURE();
				if (_T_H_GL != nullptr)data_3 = _T_H_GL->get_data();
				if (data_3 == nullptr) {
					/*if (!_reload_sent) {
						_reload_sent = true;
						reload_img();
						I* result = get_info();
						_reload_sent = false;
						return result;
					}*/
					return nullptr;
				}
				else {
					return &(data_3->first);
				}
			}
			else {
				return &(data_2->first);
			}
		}
		else {
			return &(data_1->first);
		}

		return nullptr;
	}
}