#include <SDL_ttf.h>
#include <SDL.h>
#include "FontGlypsSurface.h"
#include <limits>
#include <algorithm>
#include <array>
#include <iostream>
#include <math.h> 
#include <vector>
#include <map>
#include <malloc.h>
#include "ImageDealer.h"
#include "encodage.h"

namespace FontMapper {
	struct UniqueGlyps {
		wchar_t c;
		GlypsSize size;
		SDL_Surface* surface = nullptr;
	};


	bool GlypsSorter1(UniqueGlyps i, UniqueGlyps j) {
		return (i.size.height > j.size.height);
	}
	
	DIFFERED_LOADER::loader<std::pair<Glyps, ONIGIRIX_GUI::SDL_S_texture>>* GetGlypsLoader(FontInfo font) {

		std::function<void(DIFFERED_LOADER::syncro_tools<std::pair<Glyps, ONIGIRIX_GUI::SDL_S_texture>>*, FontInfo)> load = [](DIFFERED_LOADER::syncro_tools<std::pair<Glyps, ONIGIRIX_GUI::SDL_S_texture>>* flag, FontInfo lafont) {
			auto m = new std::pair<Glyps, ONIGIRIX_GUI::SDL_S_texture>();
			int a;
			auto res= GetGlypsSurface(lafont);
			m->first = res;
			ONIGIRIX_GUI::SDL_S_texture b;
			m->second = std::move(b);
			m->second.set(m->first.surface);
			flag->finish_use(m);
		};

		return new DIFFERED_LOADER::loader<std::pair<Glyps, ONIGIRIX_GUI::SDL_S_texture>>(load,  font,false);
		
	}
	Glyps GetGlypsSurface(FontInfo lafont) {
		TTF_Init();
		TTF_Font* font = TTF_OpenFont(ws2s(lafont.url).c_str(), lafont.size);
		Glyps Result;

		std::cout << "Start" << std::endl;
		constexpr int min = std::numeric_limits<wchar_t>::min();
		constexpr int max = std::numeric_limits<wchar_t>::max();
		std::cout << "Start creat the glyps table \n Character to creat :" << (max - min) << std::endl;
		
		std::vector<UniqueGlyps> AllGlyps;
		int IdealArea = 0;

		int L1=0;
		int L2=0;

		//loading all info and individual surface of glyps
		for (wchar_t c = min; c <= max; c++)
		{
			if (TTF_GlyphIsProvided(font, c)) {
				int minx = 0, maxx = 0, miny = 0, maxy = 0, advance = 0;
				TTF_GlyphMetrics(font, c, &minx, &maxx, &miny, &maxy, &advance);
				if (minx != maxx && miny != maxy) {//avoid empty character
					SDL_Surface* surf = TTF_RenderGlyph_Blended(font, c, { 0x0,0x0,0x0 });
					if (surf != nullptr) {
						
						UniqueGlyps G;
						
						SDL_Surface* surf2 = removeBloack(surf, G.size.cutleft, G.size.cutright, G.size.cuttop, G.size.cutbottom);
						SDL_FreeSurface(surf);

						G.c = c;
						G.size.minx = minx;
						G.size.miny = miny;
						G.size.maxx = maxx;
						G.size.maxy = maxy;
						G.surface = surf2;
						if (G.surface != nullptr) {
							G.size.width = G.surface->w;
							G.size.height = G.surface->h;
						}
						G.size.advance = advance;

						//G.surface = surf;
						AllGlyps.push_back(G);
						Result.Characters[G.c].Size = G.size;
						L1++;
					}
				}

			}
			if (c == max)break;
		}
		std::cout << "FINISH GETTING CHARACTERS "  << std::endl;
		//close font 

		TTF_CloseFont(font);

		//Intelligentely creating the final surface !

		//first lets sort the glyps by size

		std::sort(AllGlyps.begin(), AllGlyps.end(), GlypsSorter1);
		int TotWidth = 0;
		int TotHeight = 0;
		int NumRect = 0;
		for (auto& G : AllGlyps) {
			IdealArea += G.size.height *G.size.width;
			TotWidth += G.size.width;
			TotHeight += G.size.height;
			NumRect++;
		}
		int AvreageWidth = (sqrt((double)IdealArea));

		int currx = 0;
		int curry = 0;
		int maxHeight = 0;//the max height of a glipse in the line

		int Height = 0;//the height of the surface
		int Width = 0;//the width of the surface

		for (auto& G : AllGlyps) {
			if (currx + G.size.width> AvreageWidth) {
				if (currx > Width)Width = currx;
				currx = 0;
				curry += maxHeight;
				maxHeight = 0;
			}
			if (G.size.height > maxHeight) {
				maxHeight = G.size.height;
				Height = curry + maxHeight;
			}
			Result.Characters[G.c - min].Position.x = currx;
			Result.Characters[G.c - min].Position.y = curry;
			currx += G.size.width;
		}

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		Result.surface = SDL_CreateRGBSurface(SDL_SWSURFACE, Width, Height, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
#else
		Result.surface = SDL_CreateRGBSurface(SDL_SWSURFACE, Width, Height, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
#endif

		for (auto&G : AllGlyps) {
			SDL_Rect rec;
			rec.h = G.size.height;
			rec.w = G.size.width;
			//std::cout << "w(" << G.surface->w <<"-"<< G.size.width<<")";
			//std::cout << "h(" << G.surface->h << "-" << G.size.height << ")";
			rec.x = Result.Characters[G.c].Position.x;
			rec.y = Result.Characters[G.c].Position.y;
			if(G.surface!=nullptr)SDL_BlitSurface(G.surface, NULL, Result.surface, &rec);
			//delet surfaces
			if (G.surface != nullptr)SDL_FreeSurface(G.surface);
			G.surface = nullptr;
		}

		

		//delete unique surfaces

		AllGlyps.clear();
		AllGlyps.shrink_to_fit();
		//modify letter to why so one only need to multiply by a color to get good color (can not render directly whyte becaus there is a bug in sdlttf)

		unsigned int TotalArea = Result.surface->h*Result.surface->w;

		Uint32 *pixels = (Uint32*)Result.surface->pixels;


		for (unsigned int i =  0; i < TotalArea; i++)
		{
			*(pixels+i) += 0x00FFFFFF;
		}

		//return pixels[(y*surface->w) + x];
		SDL_Surface* NewS = SDL_ConvertSurface(Result.surface, SDL_AllocFormat(SDL_PIXELFORMAT_ARGB4444), 0);//because higer is useless....
		if (NewS == nullptr) 
			printf("Texture conversion failed: %s\n", SDL_GetError());
		
		SDL_FreeSurface(Result.surface);
		Result.surface = NewS;

		IdealArea;
		std::cout << "TEXTURE : " << Result.surface << " " << std::endl;
		std::cout << "AREA1 : " << IdealArea << " " << std::endl;
		std::cout << "AREA2 : " << TotalArea << " " << std::endl;
		std::cout << "AW : " << AvreageWidth << " " << std::endl;
		std::cout << "TW : " << TotWidth << " " << std::endl;
		std::cout << "N : " << NumRect << " "<< std::endl;
		std::cout << "HxW : " << L1 << "/" << L2 << " " << std::endl;
		std::cout << "HxW : " << Result.surface->h<<"/"<< Result.surface->w << " " << std::endl;
		std::cout << "Efficiency : " <<(double)IdealArea/ (double)TotalArea *100.0<<" %"<< std::endl;
		
		Result.height = Result.surface->h;
		Result.width = Result.surface->w;

		TTF_Quit();
		return Result;
	}
	SDL_Surface* removeBloack(SDL_Surface* surf, int& cutleft,int& cutright,int& cuttop,int& cutbottom) {
		Uint32 *pixels = (Uint32*)surf->pixels;
		int x, y;
		int w = surf->w, h = surf->h;
		int area = w*h;

		//init to their max 

		cutleft = w;
		cutright = w;

		cuttop = h;
		cutbottom = h;

		for (unsigned int i = 0; i < area; i++)
		{
			y = i / w;
			x = i - y*w;
			if (pixels[i] != 0) {
				if (y < cuttop)cuttop = y;
				if (h - y - 1 < cutbottom)cutbottom = h - y - 1;
				if (x < cutleft)cutleft = x;
				if (w - x - 1 < cutright)cutright = w - x - 1;
			}
		}

		

		int destw = w - cutleft - cutright;
		int desth = h - cutbottom - cuttop;

		if (destw < 0) {
			cutleft = w;
			cutright = 0;
		}
		if (desth < 0) {
			cuttop = h;
			cutbottom = 0;
		}

		if (destw <= 0 || desth <= 0) {
			std::cout << "nothingy" << std::endl;
			return nullptr;
		}

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		SDL_Surface* result = SDL_CreateRGBSurface(SDL_SWSURFACE, destw, desth, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
#else
		SDL_Surface* result = SDL_CreateRGBSurface(SDL_SWSURFACE, destw, desth, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
#endif

		SDL_Rect rect1,rect2;

		rect2.w = destw;
		rect2.h = desth;
		rect2.x = 0;
		rect2.y = 0;
		rect1.w = destw;
		rect1.h = desth;
		rect1.x = cutleft;
		rect1.y = cuttop;

		SDL_BlitSurface(surf, &rect1, result, &rect2);

		return result;

	}

}
namespace ONIGIRIX_GUI {
	GlypsImage::GlypsImage(FontMapper::FontInfo font, SDL_Renderer* r) {
		_renderer = r;
		_font = font;
		_T_S_SDL = nullptr;
		reload_img();
	}
	void GlypsImage::reload_img() {
		if (_T_S_SDL == nullptr) {
			_T_S_SDL = FontMapper::GetGlypsLoader(_font);
		}
		else {
			
			throw("An image has already been loaded so can not reload !!! because _T_S_SDL is not a nullptr.");
		}
	}
};