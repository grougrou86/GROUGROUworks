#ifndef SDL_FENETRE_H
#define SDL_FENETRE_H

#include "G_inc.h" 
#include <string>
#include <vector> 
#include "Mesure.h"



class Fenetre{
public:

	//data_store data;

	void vider();
	void supp_scroll(Scroll*);
	void supp_rect(Rectangle*);

	rebuild_funk rebulid_funk=NULL;

	//getter
	bool ask_close = false;
	bool TestEnd();
	void remove_rec(Rectangle*);

	int get_width();
	int get_height();
	int get_x();
	int get_y();

	bool is_full();
	bool is_max();

	SDL_Surface* get_screen_surface();

	//setter

	//autres

	Fenetre(int screen_width, int screen_height, bool border=true);
	virtual ~Fenetre();
	void close();
	void hide();
	void maximize();
	void unmaximize();
	void fullScreen();
	void unfullScreen();

	void update_w_h();
	void refresh();

	SDL_Surface* loadImg(std::string path);
	SDL_Surface* loadBitmap(std::string path);
	SDL_Surface* loadPng(std::string path);
	SDL_Surface* loadTTF(std::string texte, std::string nom, int taille, int couleur);

	SDL_mainLoop* related_loop;

	void loopFct();//say if need to redisplay screen...
	void keyFct(int key);
	virtual Fenetre* copie() ;
	Rectangle* addRectangle(Rectangle& monRectangle);
	SDL_Window* sdlWindow()const;
	//SDL_GetWindowID(SDL_Window* window)
	int get_id();
	SDL_Renderer* get_screen_render();
	std::string titre;
	void add_police(std::string name, std::string path);
	bool clickFct(int x, int y);
	bool downFct(int x, int y);
	bool moveFct(int x, int y, int dx, int dy);
	std::map<std::string, Police >Polices;//in public to enable fast police exchange
	
	void set_maximized_dimention(int xm,int ym,int am,int bm);

	void add_full_pointer(etat*);
	void add_max_pointer(etat* pointeur);
	void set_full_value(bool);
	void set_max_value(bool);

	void update_z_index();

	void LOOPfct();

	int Mousex = 0, Mousey = 0;
	int DMousex = 0, DMousey = 0;

	data_store* data=NULL;

	void resize(int w, int h);
	void deplace(int x, int y);

	std::vector<Scroll*> scrolls;
	bool copied = false;

	std::vector<etat*> clearatclean_etat;

	void clean();
private:
	

	bool videur = false;
	std::vector<Scroll*> a_supp_scrolls;
	std::vector<Rectangle*> a_supp_rect;

	int x_base, y_base;//pour le maximize
	int w_base, h_base;//pour le maximize

	int _width = 0;
	int _height = 0;

	etat fullscreen = etat{ "fullscreen", false };
	etat* fullpointer = NULL;
	etat maximized = etat{ "maximized", false };
	etat* maxpointer = NULL;

	int x_max, y_max;//pour le maximize
	int w_max, h_max;//pour le maximize


	std::vector<Rectangle*> Rectangles;
	std::vector<int> zIndexOrder;
	std::vector<SDL_Surface*> Surfaces;
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;
	SDL_Renderer* gRenderer = NULL;

	//The image we will load and show on the screen

};

#endif