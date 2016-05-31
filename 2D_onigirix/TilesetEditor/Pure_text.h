#ifndef PURE_TEXT_H
#define PURE_TEXT_H
#include "G_inc.h"
#include <string>
#include <vector>
namespace ONIGIRIX_GUI {
	class TextBlock {
	public:
		TextBlock() : final_texture(NULL), final_surface(NULL) {}
		TextBlock(Rectangle* re, std::wstring texte, int taill, std::string lapolice, alignement alignm, int largeur, int interlign, int color) : rec(re), interligne(interlign), align(alignm), taille(taill), width(largeur), text(texte), police(lapolice), couleur(color)
		{
			update_texture();
		}
		SDL_Texture* get_texture() const;
		SDL_Surface* get_surface() const;
		~TextBlock() {
			if (final_surface != NULL) { SDL_FreeSurface(final_surface); final_surface = nullptr; }
			if (final_texture != NULL) { SDL_DestroyTexture(final_texture); final_texture = nullptr; }
			clear_SF();
			//		while (!surafeces.empty()) { SDL_FreeSurface(surafeces.back()); surafeces.pop_back(); }
		}
		void totor(int&, int&, int&, bool, std::vector<SDL_Rect*>&);

		void update_texture(bool retext = false);
		int x = 0;
		int y = 0;
		void draw_to_render(SDL_Renderer* screen);

		int width;
		int height;
		int cursor_index_from_mouse(int x_click, int y_click);
		cursor_concreat_info cursor_pos_from_index(int index);
		int max_index;
		int interligne;
		int charaSize;
	private:
		void clear_SF();
		Rectangle* rec;// pour avoir les polices....
		std::vector<std::vector<SDL_Texture*>> les_surface;
		std::vector<std::vector<SDL_Rect>> stretchs;

		alignement align;
		int taille;
		std::wstring text;
		std::string police;
		int couleur;
		std::vector<std::vector<std::wstring>> part_txt;
		int xtil = 0;
		int indextil = 0;

		SDL_Texture* final_texture = NULL;
		SDL_Surface* final_surface = NULL;
	};
}
#endif