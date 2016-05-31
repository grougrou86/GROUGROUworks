#include"fusioneur.h"
#include"G_inc.h"
#include"parameters.h"


void fusion::swapper(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
	case_fusion toto;
	toto=compo[y1][x1];
	compo[y1][x1] = compo[y2][x2];
	compo[y2][x2] = toto;
}
bool fusion::include(std::string s, unsigned int x, unsigned int y) {
	remove(s, x, y);
	for (auto&a : compo)for (auto&b : a)if (!b.full) { b.full = true; b.url = s; b.x = x; b.y = y; return true; }
	return false;
}
bool fusion::exists(std::string s, unsigned int x, unsigned int y) {
	for (auto&a : compo)for (auto&b : a)if (b.full && b.url == s && b.x == x && b.y == y) { return true; }
	return false;
}
void fusion::remove(std::string s, unsigned int x, unsigned int y) {
	for (auto&a : compo)for (auto&b : a)if (b.full && b.url == s && b.x == x && b.y == y) { b.full = false; return; }
}
fusion::fusion(unsigned int x, unsigned int y) {
	int i = 0;
	int j = 0;
	while (i < y) {
		compo.push_back(std::vector<case_fusion>());
		j = 0;
		while (j < x) {
			compo.back().push_back(case_fusion());
			j++;
		}
		i++;
	}
}
SDL_Surface* fusion::return_for_display( ONIGIRIX_GUI::Rectangle* r) {
	
	
	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	sf1 = SDL_CreateRGBSurface(SDL_SWSURFACE, case_size*compo[0].size(), case_size*compo.size(), 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
	#else
	sf1 = SDL_CreateRGBSurface(SDL_SWSURFACE, case_size*compo[0].size(), case_size*compo.size(), 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
	#endif
	size_t i(0), j(0);
	while (i < compo.size()) {
		j = 0;
		while (j < compo[0].size()) {
			case_fusion b = compo[i][j];
			if (b.full) {
				std::cout << b.url << std::endl;
				try {
					r->oldIMG.at(b.url);
				}
				catch (const std::out_of_range& oor) {
					SDL_Surface* sf = r->ma_fenetre->loadImg(b.url);
					r->oldIMG[b.url] = sf;
				}
				SDL_Rect rec1, rec2;
				rec1.w = case_size;
				rec1.h = case_size;
				rec2.w = case_size;
				rec2.h = case_size;
				rec1.x = case_size*b.x;
				rec1.y = case_size*b.y;
				rec2.x = case_size*j;
				rec2.y = case_size*i;

				SDL_BlitSurface(r->oldIMG[b.url], &rec1, sf1, &rec2);

			}
			j++;

		}
		i++;
	}
	return sf1;
}
