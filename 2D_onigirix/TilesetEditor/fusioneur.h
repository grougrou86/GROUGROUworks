#pragma once
#ifndef FUSIONEUR_H
#define FUSIONEUR
#include "G_inc.h"

struct case_fusion {
	bool full = false;
	std::string url = "";
	unsigned int x = 0;
	unsigned int y = 0;
};

class fusion {
public:
	fusion(unsigned int x, unsigned int y);
	std::vector<std::vector<case_fusion>> compo;
	void swapper (unsigned int, unsigned int, unsigned int, unsigned int);
	bool include(std::string , unsigned int x, unsigned int y);
	void remove(std::string, unsigned int x, unsigned int y);
	bool exists(std::string, unsigned int x, unsigned int y);
	SDL_Surface* return_for_display(ONIGIRIX_GUI::Rectangle*);
	SDL_Surface* sf1=nullptr;
	~fusion() {
	}
};

#endif