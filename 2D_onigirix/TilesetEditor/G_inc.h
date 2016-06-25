#pragma once
#ifndef GENERAL_INC_H
#define GENERAL_INC_H

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}


#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace ONIGIRIX_GUI {

	enum alignement{ center, right, left, justify};
	enum size_mode{ no, fit, automatic }; //no-> do nothing || fit-> adapte size || adaptr-> make container fit  to image
	//specific to display !! ORDRE !!
	template <typename T>
	class auto_choice;
	class Rectangle_clip;
	class Fenetre;
	class Rectangle;
	struct cursor_concreat_info;
	typedef void(*call_funk)(Rectangle*);
	typedef void(*key_funk)(Rectangle*, int);
	typedef void(*rebuild_funk)(Fenetre*);
	class SDL_mainLoop;
	class Forme;
	class Police;
	class TextBlock;
	class ClickSurface;
	class ClickRect;
	class Scroll;
	class Text_input;
	class etat;
	struct etat_state;
	struct data_store;
	class Relative;
	class UnderWindow;
	class Widget;
	class UsableImage;
	class Image;
	class SDL_H_texture;
	class SDL_S_texture;
	class GL_H_texture;

}
#include "relative.h"
#include "data.h"
#include "Automated_type.h"
#include "cliper.h"
#include "etat.h"
#include "ClickSurface.h"
#include "ClickRect.h"
#include "coleur.h"
#include "font.h"
#include "Pure_text.h"
#include "initialisation.h"
#include "Fenetre.h"
#include "SDL_forme.h"
#include "rect.h"
#include "Scroll.h"
#include "text-input.h"
#include "clip_frame.h"
#include "UnderWindow.h"
#include "Widget.h"
#include "ALL_WIDGET.h"
#include "texture.h"
#include "ImageDealer.h"





#endif