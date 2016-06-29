#pragma once
#include"G_inc.h"
#include <boost/functional/hash.hpp>
namespace ONIGIRIX_GUI {
	void redirect_data(Rectangle* r, Fenetre* f, SDL_mainLoop* l);
	void relay_click(Rectangle* r, Fenetre* f, SDL_mainLoop* l, int x, int y);
}

template <typename T, int N>
static std::size_t hasharray(const T(&arr)[N])
{
	return boost::hash_range(arr, arr + N);
}

