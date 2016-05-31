#ifndef PURE_TEXT_H
#define PURE_TEXT_H
#include "G_inc.h"
#include <string>
#include <vector>

class TextBlock{
public:
	TextBlock(): final_texture(NULL), final_surface(NULL) {}
	TextBlock(Fenetre* fenetre, std::string texte, int taill, std::string lapolice, alignement alignm, int largeur, int interlign, int color) : f(fenetre), interligne(interlign), align(alignm), taille(taill), width(largeur), text(texte),police(lapolice),couleur(color) 
	{ update_texture(); }
	SDL_Texture* get_texture() const;
	SDL_Surface* get_surface() const;
	~TextBlock(){ 
		if(final_surface!=NULL)SDL_FreeSurface(final_surface);
		if (final_texture!= NULL)SDL_DestroyTexture(final_texture);
		clear_SF();
//		while (!surafeces.empty()) { SDL_FreeSurface(surafeces.back()); surafeces.pop_back(); }
	}
	void totor(int&, int&,  int&,bool, std::vector<SDL_Rect*>&);

	void update_texture(bool retext=false);
	int x=0;
	int y=0;
	void draw_to_render(SDL_Renderer* screen);

	int width;
	int height;
private:
	void clear_SF();
	Fenetre* f;// pour avoir les polices....
	std::vector<std::vector<SDL_Texture*>> les_surface;
	std::vector<std::vector<SDL_Rect>> stretchs;
	int interligne;
	alignement align;
	int taille;
	std::string text;
	std::string police;
	int couleur;
	std::vector<std::vector<std::string>> part_txt;


	SDL_Texture* final_texture = NULL;
	SDL_Surface* final_surface = NULL;
};
#endif