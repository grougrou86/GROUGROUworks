#include "G_inc.h"
#include <string>
#include <vector>
#include "autre.h"
#include<iostream>
#include "sdladdon.h"
namespace ONIGIRIX_GUI {
	int TextBlock::cursor_index_from_mouse(int x_click, int y_click) {
		int final__index = 0;
		std::vector<SDL_Rect> ligne;
		int j1(0), j2(0);
		int j1min(0), j2min(0), j1max(0), j2max(0);
		int start_index(0), end_index(0), index(0);
		bool found(false);
		while (j1 < stretchs.size() && !found) {
			index += part_txt[j1][j2].size();
			index++;
			if (ligne.size() == 0 || stretchs[j1][j2].y != ligne[0].y) {
				if (ligne.size() == 0) {
					ligne = std::vector<SDL_Rect>({ stretchs[j1][j2] });
					j1min = j1; j2min = j2;
					start_index = index - part_txt[j1][j2].size() - 1;
				}
				else {


					if (y_click < ligne[0].y + ligne[0].h + interligne / 2) {
						found == true;
						j1max = j1; j2max = j2;
						end_index = index - part_txt[j1][j2].size() - 1;
					}
					else {
						ligne = std::vector<SDL_Rect>({ stretchs[j1][j2] });
						j1min = j1; j2min = j2;
						start_index = index - part_txt[j1][j2].size() - 1;
					}
				}
			}
			else {
				ligne.push_back(stretchs[j1][j2]);
			}

			j2++;
			if (j2 >= stretchs[j1].size()) {
				j1++;
				j2 = 0;
			}
		}

		std::cout << "Achieved" << std::endl;
		if (j1 == stretchs.size()) {
			j1max = j1; j2max = j2;
			//end_index = index - part_txt[j1][j2].size();
		}


		int count(0);
		bool finalfound(false);
		bool isbefore = false;
		int currj1(j1min), currj2(j2min);
		int oldcurrj1(j1min), oldcurrj2(j2min);
		int currindex(start_index);
		while (count < ligne.size() && !finalfound) {
			std::cout << currj1 << "--" << currj2 << "--" << x_click << "|" << ligne[count].x << "|" << ligne[count].x + ligne[count].w << std::endl;
			currindex += part_txt[currj1][currj2].size() + 1;
			oldcurrj1 = currj1; oldcurrj2 = currj2;

			if (x_click < ligne[count].x + ligne[count].w&&x_click > ligne[count].x) {
				finalfound = true;
			}
			else if (x_click < ligne[count].x) {
				isbefore = true;
				finalfound = true;
			}
			else { count++; }

			currj2++;
			if (currj2 >= stretchs[currj1].size()) {
				currj1++;
				currj2 = 0;
			}

		}

		if (count == ligne.size()) {
			currindex--;
		}
		else {
			currindex -= part_txt[oldcurrj1][oldcurrj2].size() + 1;
			if (count != 0 && isbefore) {
				if ((ligne[count].x - ligne[count - 1].x - ligne[count - 1].w) / 2 < ligne[count].x - x_click)currindex--;
			}
			else {
				if (part_txt[oldcurrj1][oldcurrj2].size() > 0) {
					int relativClick = x_click - stretchs[oldcurrj1][oldcurrj2].x;
					int indexToAdd(1);
					int old_width(0);
					int new_width(0);
					bool succeed(false);
					if (relativClick < 0)indexToAdd = 0;
					else {
						while (indexToAdd < part_txt[oldcurrj1][oldcurrj2].size() + 1 && !succeed) {
							std::wstring txt = part_txt[oldcurrj1][oldcurrj2];
							new_width = rec->ma_fenetre->widthTTF(txt.substr(0, indexToAdd), police, taille);
							if (relativClick < new_width) {
								succeed = true;
								if (new_width - relativClick>relativClick - old_width)indexToAdd--;
							}
							else {
								indexToAdd++;
							}

							std::cout << indexToAdd << std::endl;
							old_width = new_width;

						}
					}
					currindex += indexToAdd;
				}
			}
		}
		final__index = currindex;
		return final__index;
	}
	cursor_concreat_info TextBlock::cursor_pos_from_index(int index) {
		cursor_concreat_info retour;

		int i = 0;
		int j1 = 0;
		int j2 = 0;
		int strat_pos = 0;
		while (i < index&&i < max_index) {
			strat_pos = i;
			i += part_txt[j1][j2].size();
			if ((i < index&&i < max_index)) {
				j2++;
				if (j2 >= part_txt[j1].size()) {
					j2 = 0;
					j1++;
				}
				i++;
				strat_pos = i;
			}
		}

		int x2 = stretchs[j1][j2].x;
		int y2 = stretchs[j1][j2].y;
		if (index - strat_pos == part_txt[j1][j2].size()) {
			x2 += stretchs[j1][j2].w;
		}
		else if (index - strat_pos != 0) {

			if (indextil != index) {
				std::wstring part = part_txt[j1][j2].substr(0, index - strat_pos);
				xtil = rec->ma_fenetre->widthTTF(part, police, taille);
				indextil = index;
			}
			x2 += xtil;
		}

		//std::cout <<j1<<":"<< j2 <<"|"<< x2 << "--" << y2 <<"--"<< i <<"--"<< index <<"/"<<strat_pos<<"size"<< part_txt[j1][j2].size() << std::endl;
		retour.x = x2;
		retour.y = y2;
		retour.height = taille;
		return retour;
	}

	SDL_Surface* TextBlock::get_surface() const {
		return final_surface;
	}
	SDL_Texture* TextBlock::get_texture() const {
		return final_texture;
	}
	void TextBlock::draw_to_render(SDL_Renderer* screen) {
		int i = 0;
		int j = 0;
		while (i < les_surface.size()) {
			j = 0;
			while (j < les_surface[i].size()) {
				SDL_Rect stretchRect = stretchs[i][j];
				stretchRect.x += x;
				stretchRect.y += y;
				int x2, y2;
				x2 = stretchRect.x;
				y2 = stretchRect.y;
				stretchRect = intersection(stretchRect, rec->destRect);
				SDL_Rect srcRect(stretchRect);
				srcRect.x -= x2;
				srcRect.y -= y2;
				if (les_surface[i][j] != NULL)SDL_RenderCopy(screen, les_surface[i][j], &srcRect, &stretchRect);
				j++;
			}
			i++;
		}
	}
	void TextBlock::update_texture(bool retext) {
		height = 0;
		if (!retext) {
			max_index = 0;
			while (!part_txt.empty())
			{
				while (!part_txt.back().empty()) { part_txt.back().pop_back(); }
				part_txt.pop_back();
			}
			std::vector<std::wstring> sp1;
			text.push_back(L"\n"[0]);
			split(text, sp1, '\n');

			sp1.pop_back();
			for (auto& i : sp1) {
				std::vector<std::wstring> j;
				i = i.substr(0, i.size() - 1);
				max_index += i.size() + 1;
				i.push_back(L" "[0]);
				split(i, j, ' ');
				int pos = 0;
				for (auto& k : j) {
					pos++;
					k = k.substr(0, k.size() - 1);
				}
				j.pop_back();
				part_txt.push_back(j);
			}
			max_index--;
			//std::vector<SDL_Surface*> surfaces;
		}
		int currx = 0;
		int curry = 0;
		//SDL_Surface* sf1 = NULL;
		//SDL_Texture*  sf2 = SDL_CreateTexture(f->get_screen_render();
	//#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		//sf1 = SDL_CreateRGBSurface(SDL_SWSURFACE, width, 1, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
	//#else
		//sf1 = SDL_CreateRGBSurface(SDL_SWSURFACE, width, 1, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
	//#endif
		//while (!surafeces.empty()) { SDL_FreeSurface(surafeces.back()); surafeces.pop_back(); }
		if (!retext)clear_SF();
		bool clearing = false;
		//if (retext)clearing = false;
		SDL_Surface* toto = rec->ma_fenetre->loadTTF(" ", police, taille, couleur);
		int spacing = 0;
		if (toto == NULL) { return; }
		spacing = toto->w;	charaSize = toto->h;
		toto->w = 1;
		//std::vector<SDL_Surface*> surafeces;
		std::vector<SDL_Rect*> strechRCT;
		int iter1 = 0;
		//######
		if (!retext) {
			int i = 0;
			int j = 0;
			stretchs.clear();
			while (!les_surface.empty()) { while (!les_surface.back().empty()) { SDL_DestroyTexture(les_surface.back().back()); les_surface.back().pop_back(); }les_surface.pop_back(); }
			while (i < part_txt.size()) {
				j = 0;
				les_surface.push_back(std::vector<SDL_Texture*>());
				stretchs.push_back(std::vector<SDL_Rect>());
				while (j < part_txt[i].size()) {
					SDL_Surface*  sf2 = NULL;
					SDL_Texture*  TEXT_type = NULL;
					SDL_Rect toto;

					if (part_txt[i][j].size() != 0)sf2 = rec->ma_fenetre->loadTTF(part_txt[i][j], police, taille, couleur);
					toto.x = 0;
					toto.y = 0;
					if (sf2 != NULL) { toto.h = sf2->h; toto.w = sf2->w; }
					else { toto.w = 0; toto.h = 0; }

					stretchs.back().push_back(toto);
					if (sf2 != NULL)TEXT_type = SDL_CreateTextureFromSurface(rec->ma_fenetre->get_DisplayContext().get_SDL_Renderer(), sf2);
					les_surface.back().push_back(TEXT_type);
					SDL_FreeSurface(sf2);
					j++;
				}
				i++;
			}
		}
		//#####
		for (auto paragraphe : part_txt) {

			bool premier = true;
			bool l_prem = true;
			int counter = 0;
			int iter2 = 0;
			while (counter < paragraphe.size()) {
				bool add = true;
				bool affunique = false;
				std::wstring mot = paragraphe[counter];
				std::wstring motaff = mot;
				SDL_Surface*  sf2 = NULL;
				SDL_Texture*  TEXT_type = NULL;
				SDL_Rect* streching;
				/*if (!retext) {
					SDL_Rect toto;
					stretchs.back().push_back(toto);
					streching = &stretchs.back().back();
					sf2 = f->loadTTF(motaff, police, taille, couleur);
					streching->x = 0;
					streching->y = 0;
					streching->h = sf2->h;
					streching->w = sf2->w;
					if (sf2 != NULL)TEXT_type = SDL_CreateTextureFromSurface(f->get_screen_render(), sf2);
					les_surface.back().push_back(TEXT_type);
					SDL_FreeSurface(sf2);

				}*/
				TEXT_type = les_surface[iter1][iter2];
				streching = &stretchs[iter1][iter2];

				if (true) {
					currx += streching->w + spacing;
					if ((currx > width + spacing && strechRCT.size() != 0)) {


						currx -= streching->w + 2 * spacing;
						totor(currx, curry, spacing, true, strechRCT);
						curry += taille + interligne;
						currx = 0;
						currx = streching->w + spacing;
					}
					sf2 == NULL;
					strechRCT.push_back(streching);
				}

				counter++;
				iter2++;
			}
			currx -= spacing;
			totor(currx, curry, spacing, false, strechRCT);
			curry += taille + interligne;
			currx = 0;
			iter1++;
		}
		height = curry - taille - interligne + charaSize;
		//final_texture=SDL_CreateTexture(f->get_screen_render(), 32, 1, width, height);
		SDL_FreeSurface(toto);
		//final_surface = sf1;
		//final_texture = ;

	}
	void TextBlock::clear_SF() {
		while (!les_surface.empty()) {
			while (!les_surface.back().empty())
			{
				SDL_DestroyTexture(les_surface.back().back());
				les_surface.back().pop_back();
			}
			les_surface.pop_back();
		}
	}
	void TextBlock::totor(int& currx, int& curry, int& spacing, bool acc_just, std::vector<SDL_Rect*>& streachRECT) {
		int totspace = width - currx;
		float space = spacing;
		if (align == justify&&streachRECT.size() != 1 && acc_just)space += (float)totspace / ((float)streachRECT.size() - 1.0);
		currx = 0;
		float currx2 = 0;
		if (align == center)currx2 = (double)totspace / 2.0;
		if (align == right)currx2 = totspace;
		for (auto& mot2 : streachRECT) {


			//Add_x_y_surface(sf1, mot2, currx, curry);
			mot2->x = currx2;
			mot2->y = curry;

			std::cout << mot2->x << std::endl;
			currx2 += space + (float)mot2->w;
			//if(release)SDL_FreeSurface(mot2);
		}
		//surafeces.clear();
		streachRECT.clear();
	}
}
