#ifndef SDL_FORME_H
#define SDL_FORME_H

#include "G_inc.h" 
#include<vector>

class Forme{
public:

	void dys_updated();//say the display is up to date
	void dys_changed();
	bool dys_is_changed();
	virtual void draw(Fenetre* f) = 0;
	~Forme(){
		while (myTextures.size() != 0){
			SDL_DestroyTexture(myTextures.back());
			myTextures.pop_back();
		}
	}
	virtual ClickSurface* get_click_surface()=0;
	virtual void onclick_fct() = 0;
	std::vector<SDL_Surface*> mySurfaces;
	std::vector<SDL_Texture*> myTextures;

private:

	bool _dys_changed = true;

};
#endif