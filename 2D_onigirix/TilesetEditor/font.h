#include<map>
#include<string>
#include <stdexcept>
#ifndef POLICE_H
#define POLICE_H

#include<iostream>
#include"G_inc.h"

namespace ONIGIRIX_GUI {
	class Police {
	public:

		Police(std::string path) :file(path) {}
		Police() {}
		TTF_Font* get_font(unsigned int taille) {
			try {
				TTF_Font* mapolice = fonts.at(taille);
				return mapolice;
			}
			catch (std::out_of_range) {

				TTF_Font* mapolice = TTF_OpenFont(file.c_str(), taille);
				std::cout << "try to creat from :" << file.c_str() << " T: " << taille << " | " << mapolice << std::endl;
				fonts[taille] = mapolice;
				return mapolice;
			}
		}
		~Police() { for (auto& i : fonts)TTF_CloseFont(i.second); }

	private:

		std::string file;
		std::map<unsigned int, TTF_Font*> fonts;

	};
}
#endif