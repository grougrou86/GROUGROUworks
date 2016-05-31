#pragma once
#include"G_inc.h"
#include<vector>
namespace ONIGIRIX_GUI {
	class Rectangle_clip {
	public:
		auto_choice<Mesure> x;
		auto_choice<Mesure> y;
		auto_choice<Mesure> w;
		auto_choice<Mesure> h;
		Rectangle_clip() {}
		Rectangle_clip(Mesure _x, Mesure _y, Mesure _w, Mesure _h) :x(_x), y(_y), w(_w), h(_h) {}
		bool isin(Mesure nx, Mesure ny, int rel_W, int rel_H, Rectangle_clip default_clip);
		bool isinx(Mesure nx, int rel_W, Rectangle_clip default_clip);
		bool isiny(Mesure ny, int rel_H, Rectangle_clip default_clip);
		bool vide = false;
	};

	Rectangle_clip remove_default(Rectangle_clip clips, Rectangle_clip default_clip);
	Rectangle_clip intersection(std::vector<Rectangle_clip>const& clips, int rel_W, int rel_H, Rectangle_clip const& default_clip);
	Rectangle_clip intersection(std::vector<Rectangle_clip*>const& clips, int rel_W, int rel_H, Rectangle_clip const& default_clip);
	Rectangle_clip intersection(Rectangle_clip clip1, Rectangle_clip clip2, int rel_W, int rel_H, Rectangle_clip const& default_clip);
	SDL_Rect intersection(SDL_Rect&, SDL_Rect&);
	bool operator==(Rectangle_clip const&, Rectangle_clip const&);
	inline const bool isinx(SDL_Rect&, int);
	inline const bool isiny(SDL_Rect&, int);
	SDL_Rect Clip2Rec(Rectangle_clip clip, int rel_W, int rel_H, Rectangle_clip const& default_clip);
}

//bool operator==(const Rectangle_clip&,const  Rectangle_clip&);