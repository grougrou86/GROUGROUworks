#ifndef SDL_FENETRE_H
#define SDL_FENETRE_H


#include "G_inc.h" 
#include "Mesure.h"
#include <string>
#include <vector>
#include "texture.h"
#include "Video_Player.h"

namespace ONIGIRIX_GUI {
	class Fenetre : public Relative {
	public:


		virtual int rel_x();
		virtual int rel_y();
		virtual int rel_w();
		virtual int rel_h();
		//data_store data;

		void vider();

		void supp_scroll(Scroll*);
		void supp_rect(Rectangle*);
		void supp_Underwindow(UnderWindow* u);
		void supp_Widget(Widget* u);
		void removeScroll(Scroll* s);//same as supp ....
		void removeRectangle(Rectangle*);//same as supp ....
		void removeUnderwindow(UnderWindow*);//same as supp ....
		void removeWidget(Widget*);//same as supp ....

		rebuild_funk rebulid_funk = NULL;

		//getter
		bool ask_close = false;
		bool TestEnd();

		int get_width();
		int get_height();
		int get_x();
		int get_y();

		bool is_full();
		bool is_max();

		DisplayContext get_DisplayContext();

		//setter

		//autres

		Fenetre(int screen_width, int screen_height, bool border = true);
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
		SDL_Surface* loadTTF(std::wstring texte, std::string nom, int taille, int couleur);
		SDL_Surface* loadTTF(std::string texte, std::string nom, int taille, int couleur);
		int widthTTF(std::string texte, std::string nom, int taille);
		int widthTTF(std::wstring texte, std::string nom, int taille);

		SDL_mainLoop* related_loop;

		void loopFct();//say if need to redisplay screen...
		void keyFct(int key);
		void TextinputFct(std::wstring input);
		virtual Fenetre* copie();
		Rectangle* addRectangle(Rectangle& monRectangle);
		Rectangle* addRectangle(Rectangle* monRectangle);

		UnderWindow* addUnderwindow(UnderWindow*);

		Text_input* addRectangle(Text_input& monRectangle);
		//SDL_GetWindowID(SDL_Window* window)
		int get_id();
		std::string titre;
		void add_police(std::string name, std::string path);
		bool clickFct(int x, int y);
		bool downFct(int x, int y);
		bool moveFct(int x, int y, int dx, int dy);
		std::map<std::string, Police >Polices;//in public to enable fast police exchange

		void set_maximized_dimention(int xm, int ym, int am, int bm);

		void add_full_pointer(etat*);
		void add_max_pointer(etat* pointeur);
		void set_full_value(bool);
		void set_max_value(bool);

		void update_z_index();

		void LOOPfct();

		int Mousex = 0, Mousey = 0;
		int DMousex = 0, DMousey = 0;

		data_store* data = NULL;

		void resize(int w, int h);
		void deplace(int x, int y);

		std::vector<Scroll*> scrolls;
		bool copied = false;

		std::vector<etat*> clearatclean_etat;

		bool was_resized();//si la fenetre a été rsizée...

		ImageDealer* get_ImageDealer();

		void clean();

		VideoManager* get_videoManager();

	private:

		ImageDealer _imageDealer;

		bool _was_resized = false;//si la fenetre a été rsizée...
		bool send_resize = false;
		bool videur = false;
		std::vector<Scroll*> a_supp_scrolls;
		std::vector<Rectangle*> a_supp_rect;
		std::vector<UnderWindow*> a_supp_underwindows;


		
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

		std::vector<UnderWindow*> Underwindows;
		std::vector<Rectangle*> Rectangles;
		std::vector<Rectangle*> zIndexOrder;
		//std::vector<int> zIndexOrder_cleaner;
		std::vector<SDL_Surface*> Surfaces;
		//The window we'll be rendering to
		

		//The surface contained by the window

		DisplayContext _DisplayContext;
		//SDL_Surface* gScreenSurface = NULL;
		//SDL_Renderer* gRenderer = NULL;
		//SDL_Window* gWindow = NULL;


		SDL_Surface *software_rendering=NULL;//only activate if you makes software rendering

		//The image we will load and show on the screen

		//the video player

		VideoManager _videoPlayer;

	};
}
#endif