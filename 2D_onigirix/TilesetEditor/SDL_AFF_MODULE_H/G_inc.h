#pragma once
#ifndef GENERAL_INC_H
#define GENERAL_INC_H

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

enum alignement{ center, right, left, justify};
enum size_mode{ no, fit, automatic }; //no-> do nothing || fit-> adapte size || adaptr-> make container fit  to image

//specific to display !! ORDRE !!
#include<iostream>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
class Fenetre;
class Rectangle;
typedef void(*call_funk)(Rectangle*);
typedef void(*key_funk)(Rectangle*,int);
typedef void(*rebuild_funk)(Fenetre*);
class SDL_mainLoop;
class Forme;
class Police;
class TextBlock;
class ClickSurface;
class ClickRect;
class Scroll;
struct etat;
struct etat_state;
struct data_store;

#include "data.h"
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



#endif