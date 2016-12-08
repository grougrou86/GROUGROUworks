#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <limits>
#include <array>
#include <map>
#include "ImageDealer.h"
#include"QueueExecutor.h"

namespace FontMapper {
	struct GlypsSize {
		int width = 0;
		int height = 0;
		int minx = 0;
		int maxx = 0;
		int miny = 0;
		int maxy = 0;
		int advance = 0;
		//cutting to remove the black space !
		int cutleft = 0;
		int cutright = 0;
		int cuttop = 0;
		int cutbottom = 0;
	};
	//position of the glyps on the surface
	struct GlypsPosition {
		int x = 0;
		int y = 0;
	};
	struct GlypsInfo {
		GlypsPosition Position;
		GlypsSize Size;
	};

	struct FontInfo {
		std::wstring url;
		unsigned int size;
	};
	struct Glyps {

		std::map < wchar_t,GlypsInfo> Characters;
		SDL_Surface* surface=nullptr;
		int width = 0;//surface width
		int height = 0;//surface height

	};
	struct FontInfoLoad {
		FontInfo info;
		DIFFERED_LOADER::syncro_tools<std::pair<Glyps, ONIGIRIX_GUI::SDL_S_texture>>* syncro;
	};
	Glyps GetGlypsSurface(FontInfo font);
	
	DIFFERED_LOADER::loader<std::pair<Glyps, ONIGIRIX_GUI::SDL_S_texture>>* GetGlypsLoader(FontInfo font);
	//cut the surface to save memory
	SDL_Surface* removeBloack(SDL_Surface* surf, int& cutleft, int& cutright, int& cuttop, int& cutbottom);
}
namespace ONIGIRIX_GUI {
	class GlypsImage :public RescuableImage<FontMapper::Glyps> {
	public:
		GlypsImage(FontMapper::FontInfo font, DisplayContext r);
		GlypsImage() { throw("ERROR you must use arrgument to innit a GlypsImage"); }//default constructor to allow usage in map but must not be used !!!
		static QueueExecutor<FontMapper::FontInfoLoad> _imageStack;// the dealer of the queue
	protected:
		virtual void reload_img();
		FontMapper::FontInfo _font;
	};
	void worker_GlypsImage(FontMapper::FontInfoLoad*);
}