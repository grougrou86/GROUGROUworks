#include "G_inc.h" 
#include <string>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "encodage.h"
#include <iostream>
#include <fstream>
#include "GENERAL_PARAMETER.h"


namespace ONIGIRIX_GUI {
	Fenetre::Fenetre(int screen_width, int screen_height, bool border) :_width(screen_width), _height(screen_height) {

		

		data = new data_store();

		_DisplayContext.set_SDL_Window(SDL_CreateWindow("Tileset Mover", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN));
		//SDL_SetWindowGrab(gWindow, SDL_TRUE);
		//SDL_WarpMouseInWindow(gWindow, 50, 50);
		//SDL_Cursor* moncu = SDL_GetDefaultCursor();
		//SDL_SetRelativeMouseMode(SDL_TRUE);
		//gScreenSurface = SDL_GetWindowSurface(gWindow);
		SDL_SetWindowIcon(_DisplayContext.get_SDL_Window(), loadImg("images/icon/icon-new.png"));
		if (!SOFTWARE_RENDERING)_DisplayContext.set_SDL_Renderer(SDL_CreateRenderer(_DisplayContext.get_SDL_Window(), -1, SDL_RENDERER_ACCELERATED));// | SDL_RENDERER_PRESENTVSYNC));// | SDL_RENDERER_PRESENTVSYNC);
		//else gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_SOFTWARE);
		else {
			software_rendering = SDL_GetWindowSurface(_DisplayContext.get_SDL_Window());
			_DisplayContext.set_SDL_Renderer(SDL_CreateSoftwareRenderer(software_rendering));
			SDL_SetRenderDrawColor(_DisplayContext.get_SDL_Renderer(), 0xff, 0xff, 0, 0xff);
			SDL_RenderClear(_DisplayContext.get_SDL_Renderer());
		}
		SDL_SetRenderDrawBlendMode(_DisplayContext.get_SDL_Renderer(), SDL_BLENDMODE_BLEND);
		//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");


		SDL_SetRenderDrawColor(_DisplayContext.get_SDL_Renderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		//SDL_Surface* tp_sf=SDL_CreateRGBSurface(SDL_HWSURFACE, width, height, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
		if (!border)SDL_SetWindowBordered(_DisplayContext.get_SDL_Window(), SDL_FALSE);

		SDL_GetWindowPosition(_DisplayContext.get_SDL_Window(), &x_base, &y_base);
		SDL_GetWindowSize(_DisplayContext.get_SDL_Window(), &w_base, &h_base);

		//loading font

		//set the renderer for differents images ^^
		_imageDealer.set_DisplayContext(get_DisplayContext());
		get_videoManager()->set_DisplayContext(get_DisplayContext());


	}
	ImageDealer* Fenetre::get_ImageDealer() {
		return &_imageDealer;
	}
	int Fenetre::rel_x() {
		return 0;
	}
	int Fenetre::rel_y() {
		return 0;
	}
	int Fenetre::rel_w() {
		return _width;
	}
	int Fenetre::rel_h() {
		return _height;
	}
	Fenetre::~Fenetre() {
		
		vider();
		if (data != NULL&&!copied)delete data;
	}

	void Fenetre::vider() {
		videur = true;
	}
	void Fenetre::supp_scroll(Scroll* s) {
		a_supp_scrolls.push_back(s);
	}
	void Fenetre::supp_rect(Rectangle* r) {
		a_supp_rect.push_back(r);
	}
	void Fenetre::supp_Underwindow(UnderWindow* u) {
		a_supp_underwindows.push_back(u);
	}
	void Fenetre::supp_Widget(Widget* u) {
		a_supp_underwindows.push_back(u);
	}
	void Fenetre::removeScroll(Scroll* s) {
		a_supp_scrolls.push_back(s);
	}
	void Fenetre::removeUnderwindow(UnderWindow* u) {
		a_supp_underwindows.push_back(u);
	}
	void Fenetre::removeWidget(Widget* u) {
		a_supp_underwindows.push_back(u);
	}
	void Fenetre::removeRectangle(Rectangle* rec_ref) {
		a_supp_rect.push_back(rec_ref);
	}
	UnderWindow* Fenetre::addUnderwindow(UnderWindow* u) {
		Underwindows.push_back(u);
		return u;
	}
	void Fenetre::clean() {
		while (!a_supp_underwindows.empty()) {
			//zIndexOrder.erase(zIndexOrder.begin() + a_supp_rect.back()->index_th );
			search_and_delete_vect(Underwindows, a_supp_underwindows.back());
			a_supp_underwindows.pop_back();
		}
		while (!a_supp_scrolls.empty()) {
			//zIndexOrder.erase(zIndexOrder.begin() + (*a_supp_scrolls.back())[0]->index_th );
			//zIndexOrder.erase(zIndexOrder.begin() + (*a_supp_scrolls.back())[1]->index_th );
			//delete (*a_supp_scrolls.back())[0];
			//delete (*a_supp_scrolls.back())[1];
			search_and_delete_vect(Rectangles, (*a_supp_scrolls.back())[0]);
			search_and_delete_vect(Rectangles, (*a_supp_scrolls.back())[1]);
			search_and_delete_vect(scrolls, a_supp_scrolls.back());

			a_supp_scrolls.pop_back();
		}
		while (!a_supp_rect.empty()) {
			//zIndexOrder.erase(zIndexOrder.begin() + a_supp_rect.back()->index_th );
			search_and_delete_vect(Rectangles, a_supp_rect.back());
			a_supp_rect.pop_back();
		}

		if (videur) {
			for (auto u : Underwindows)u->deleter();
			while (!Underwindows.empty()) {
				delete Underwindows.back();
				Underwindows.pop_back();
			}
			while (!scrolls.empty()) {
				delete scrolls.back();
				scrolls.pop_back();
			}
			while (!Rectangles.empty()) {
				delete Rectangles.back();
				Rectangles.pop_back();
			}
			while (!clearatclean_etat.empty()) { delete clearatclean_etat.back(); clearatclean_etat.pop_back(); }
			a_supp_rect.clear();
			a_supp_scrolls.clear();
			a_supp_underwindows.clear();
		}
		videur = false;
		update_z_index();
		if (rebulid_funk != NULL)rebulid_funk(this);
		rebulid_funk = NULL;

	}
	// ####### UPDATED AT EACH LOOP ####
	void Fenetre::loopFct() {
		//Apply the image

		

		SDL_SetRenderDrawColor(_DisplayContext.get_SDL_Renderer(), 0XFF, 0XFF, 0XFF, 0XFF);
		SDL_RenderClear(_DisplayContext.get_SDL_Renderer());
		SDL_SetRenderDrawColor(_DisplayContext.get_SDL_Renderer(), 0X0F, 0X00, 0XF0, 0XFF);

		get_videoManager()->Update();//Update the videos on screen 

		for (auto& i : zIndexOrder) {
			//Rectangles[i]->get_x();
			i->updat_move_fnct();
			if (i->everyframe_fct != NULL)i->everyframe_fct(i);
			//Rectangles[i]->index_th = i;
		}
		for (auto u : Underwindows)u->Refresh();

		/*SDL_SetRenderDrawColor(gRenderer, 0X0F, 0X00, 0XF0, 0XFF);
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 5;
		rect.w = 10;
		rect.h = 30;
		SDL_RenderFillRect(gRenderer, &rect);*/

		test = 0;

		for (auto& i : zIndexOrder)i->draw(this);

		//if (something_new)
		 //SDL_RenderPresent(gRenderer);
		
		/*SDL_SetRenderDrawColor(gRenderer, 0X0F, 0X00, 0XF0, 0XFF);
		rect.x = 0;
		rect.y = 5;
		rect.w = 5;
		rect.h = 5;
		SDL_RenderFillRect(gRenderer, &rect);
		std::cout << "true RENDERER " << gRenderer << std::endl;*/

		SDL_RenderPresent(_DisplayContext.get_SDL_Renderer());
		 if (SOFTWARE_RENDERING) SDL_UpdateWindowSurface(_DisplayContext.get_SDL_Window());
		 
		clean();
		for (auto& monRect : Rectangles) {
			monRect->finish_LOOP();
		}
		if (_was_resized) { _was_resized = false; }
		if (send_resize) { _was_resized = true; send_resize = false; }
	}
	// ###### OTHER ######



	void Fenetre::close() {
		SDL_RestoreWindow(_DisplayContext.get_SDL_Window());
		SDL_DestroyWindow(_DisplayContext.get_SDL_Window());
		_DisplayContext.set_SDL_Window( NULL );
		ask_close = true;
	}
	bool Fenetre::TestEnd() {
		return ask_close;
	}
	void Fenetre::hide() {

		SDL_RestoreWindow(_DisplayContext.get_SDL_Window());
		SDL_MinimizeWindow(_DisplayContext.get_SDL_Window());


	}
	void Fenetre::maximize() {
		SDL_RestoreWindow(_DisplayContext.get_SDL_Window());
		if (fullscreen.active) unfullScreen();
		SDL_SetWindowSize(_DisplayContext.get_SDL_Window(), w_max, h_max);
		SDL_SetWindowPosition(_DisplayContext.get_SDL_Window(), x_max, y_max);
		set_full_value(false);
		set_max_value(true);
		update_w_h();
		refresh();

	}
	void Fenetre::unmaximize() {

		SDL_RestoreWindow(_DisplayContext.get_SDL_Window());
		if (fullscreen.active) unfullScreen();
		SDL_SetWindowSize(_DisplayContext.get_SDL_Window(), w_base, h_base);
		SDL_SetWindowPosition(_DisplayContext.get_SDL_Window(), x_base, y_base);
		set_full_value(false);
		set_max_value(false);
		update_w_h();
		refresh();
	}

	void Fenetre::fullScreen() {
		maximize();
		SDL_SetWindowFullscreen(_DisplayContext.get_SDL_Window(), SDL_TRUE);
		set_full_value(true);
		update_w_h();
		refresh();
	}
	void Fenetre::unfullScreen() {
		//std::cout << " dis -- error:" << SDL_GetError() << std::endl;
		SDL_RestoreWindow(_DisplayContext.get_SDL_Window());
		SDL_SetWindowFullscreen(_DisplayContext.get_SDL_Window(), SDL_FALSE);
		set_full_value(false);
		update_w_h();
		refresh();
	}
	bool Fenetre::is_full() {
		return fullscreen.active;
	}
	bool Fenetre::is_max() {
		return maximized.active;
	}

	SDL_Surface* Fenetre::loadBitmap(std::string path) {
		//std::cout << "Loading Bitmap" << std::endl;
		SDL_Surface* glsurf = NULL;
		//Loading success flag
		bool success = true;

		//Load splash image
		glsurf = SDL_LoadBMP(path.c_str());
		if (glsurf == NULL)
		{
			printf("Unable to load image #.# SDL Error: %s\n", SDL_GetError());
			success = false;
		}

		return glsurf;
	}
	SDL_Surface* Fenetre::loadPng(std::string path) {
		//std::cout << "Loading PNG" << std::endl;
		SDL_Surface* glsurf = NULL;
		SDL_Surface* optimizedSurface = NULL;
		//SDL_Surface* surface = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);

		//Loading success flag
		bool success = true;

		//Load splash image
		glsurf = IMG_Load(path.c_str());
		if (glsurf == NULL)
		{
			printf("Unable to load image #.# SDL Error: %s\n", SDL_GetError());
			success = false;
		}

		return glsurf;
	}
	SDL_Surface* Fenetre::loadImg(std::string path) {
		//std::cout << "-- " << path << std::endl;
		std::string extens = path.substr(path.size() - 3);

		if (extens == "png")return loadPng(path);
		else return loadBitmap(path);

	}
	int Fenetre::widthTTF(std::string texte, std::string nom, int taille) {
		return widthTTF(s2ws(texte), nom, taille);
	}
	int Fenetre::widthTTF(std::wstring texte, std::string nom, int taille) {
		try {
			Police mapolice = Polices.at(nom);
			if (mapolice.get_font(taille) != NULL) {
				//TTF_SizeText(TTF_Font *font, const char *text, int *w, int *h)
				std::wstring testo = texte;
				//Uint16 letext[] ;
				Uint16* arr = new Uint16[testo.size() + 1];//dynamique alocation of array huhuhu
				for (int i = 0; i < testo.size() + 1; i++)
					if (i != testo.size())arr[i] = testo[i];
					else arr[i] = '\0';

					int w, h;
					TTF_SizeUNICODE(mapolice.get_font(taille), arr, &w, &h);
					delete[] arr;

					return w;
			}
			//std::cout << TTF_GetError() << std::endl;
		}
		catch (std::out_of_range) {
			std::cout << "error font not preloaded" << std::endl;
		}
		return NULL;
	}
	SDL_Surface* Fenetre::loadTTF(std::string texte, std::string nom, int taille, int couleur) {
		return loadTTF(s2ws(texte), nom, taille, couleur);
	}
	SDL_Surface* Fenetre::loadTTF(std::wstring texte, std::string nom, int taille, int couleur) {
		RGB_c font_RGB = couleurConverter(couleur);
		try {
			Police mapolice = Polices.at(nom);
			if (mapolice.get_font(taille) != NULL) {

				std::wstring testo = texte;
				//Uint16 letext[] ;
				Uint16* arr = new Uint16[testo.size() + 1];//dynamique alocation of array huhuhu
				for (int i = 0; i < testo.size() + 1; i++)
					if (i != testo.size())arr[i] = testo[i];
					else arr[i] = '\0';

				SDL_Surface* textSurface = TTF_RenderUNICODE_Blended(mapolice.get_font(taille), arr, { (Uint8)(font_RGB.get_r()), (Uint8)(font_RGB.get_g()), (Uint8)(font_RGB.get_b()) });
				delete[] arr;

				//SDL_Surface* textSurface = TTF_RenderText_Blended(mapolice.get_font(taille), texte.c_str(), { (Uint8)(font_RGB.r), (Uint8)(font_RGB.g), (Uint8)(font_RGB.b) });
				return textSurface;
			}
			//std::cout << TTF_GetError() << std::endl;
		}
		catch (std::out_of_range) {
			std::cout << "error font not preloaded" << std::endl;
		}
		return NULL;
	}
	void Fenetre::keyFct(int key) {
		for (auto& monRect : Rectangles) {
			monRect->KeyFunction(key);
		}
	}
	void Fenetre::TextinputFct(std::wstring input) {
		/*std::locale::global(std::locale(""));
		std::wstring nihongo = L"且世两上与丑万hsh丣丕且丗丕"; // L"\12362";
		std::wofstream myfile;
		myfile.open("japonais.txt");
		myfile << nihongo;
		myfile.close();
		_setmode(_fileno(stdout), _O_U16TEXT);
		std::wcout << "USER-INPUT " << input << std::endl;
		_setmode(_fileno(stdout), _O_TEXT);
		*/
		//Uint16 nm = input[0];
		for (auto& monRect : Rectangles) {
			monRect->TextinputFct(input);
		}
	}
	bool ZindexTest(Rectangle* const& lhs, Rectangle* const& rhs)
	{
		return lhs->get_z_index() < rhs->get_z_index();
	}
	void Fenetre::update_z_index() {

		zIndexOrder = Rectangles;//clear the vector ^^ by a raw vector ^^

		std::stable_sort(zIndexOrder.begin(), zIndexOrder.end(), ZindexTest);

	}
	bool Fenetre::clickFct(int x, int y) {
		bool stop = false;
		int j(zIndexOrder.size());
		Rectangle* rect;
		for (auto r : Rectangles)r->set_etat_activity(false, "active");
		while (j > 0) {
			j--;
			rect = zIndexOrder[j];
			if (rect->get_click_surface()->IsIn(x, y) && !stop) {
				rect->set_etat_activity(true, "active");
				rect->onclick_fct(x - rect->get_x().totalPX(rect->RelativeElement->rel_w()) - rect->RelativeElement->rel_x() - rect->get_offset_x(), y - rect->get_y().totalPX(rect->RelativeElement->rel_h()) - rect->RelativeElement->rel_y() - rect->get_offset_y());
				if (rect->stop_propagation) { stop = true; }
			}
			rect->set_hold(false);
		}
		return stop;
	}
	bool Fenetre::downFct(int x, int y) {
		int j(zIndexOrder.size());
		Rectangle* rect;
		while (j > 0) {
			j--;
			rect = zIndexOrder[j];
			if (rect->get_click_surface()->IsIn(x, y)) {
				rect->set_hold(true);
				if (rect->stop_propagation) { return true; }
			}
		}
		return false;
	}
	bool Fenetre::moveFct(int x, int y, int dx, int dy) {
		DMousex += dx;
		DMousey += dy;
		Mousex = x;
		Mousey = y;
		bool got = false;
		int j(zIndexOrder.size());
		Rectangle* rect;
		while (j > 0) {
			j--;
			rect = zIndexOrder[j];
			if (rect->get_click_surface()->IsIn(x, y) && !got) { rect->set_hover(true); if (rect->stop_propagation)got = true; }
			else rect->set_hover(false);
		}
		return got;
	}
	
	Fenetre* Fenetre::copie()
	{
		Fenetre* newf = new Fenetre(*this);
		copied = true;
		return newf;
	}
	
	Rectangle* Fenetre::addRectangle(Rectangle& monRectangle) {
		Rectangle* rec_pointer = monRectangle.copie();
		Rectangles.push_back(rec_pointer);
		for (auto& et : rec_pointer->clearatclean_etat)clearatclean_etat.push_back(et);
		rec_pointer->ma_fenetre = this;
		rec_pointer->RelativeElement = this;
		rec_pointer->ma_loop = related_loop;
		update_z_index();
		return rec_pointer;
	}
	Rectangle* Fenetre::addRectangle(Rectangle* monRectangle) {
		Rectangle* rec_pointer = monRectangle;
		Rectangles.push_back(rec_pointer);
		for (auto& et : rec_pointer->clearatclean_etat)clearatclean_etat.push_back(et);
		rec_pointer->ma_fenetre = this;
		rec_pointer->RelativeElement = this;
		rec_pointer->ma_loop = related_loop;
		update_z_index();
		return rec_pointer;
	}
	Text_input* Fenetre::addRectangle(Text_input& monRectangle) {
		Text_input* rec_pointer = monRectangle.copie();
		Rectangles.push_back(rec_pointer);
		for (auto& et : rec_pointer->clearatclean_etat)clearatclean_etat.push_back(et);
		rec_pointer->ma_fenetre = this;
		rec_pointer->RelativeElement = this;
		rec_pointer->ma_loop = related_loop;
		update_z_index();
		return rec_pointer;
	}


	int Fenetre::get_width() {
		return _width;
	}
	int Fenetre::get_height() {
		return _height;
	}
	void Fenetre::add_police(std::string name, std::string path) {
		Polices[name] = Police(path);
	}
	//SDL_GetWindowID(SDL_Window* window)
	int Fenetre::get_id() {
		return SDL_GetWindowID(_DisplayContext.get_SDL_Window());
	}
	void Fenetre::update_w_h() {
		SDL_GetWindowSize(_DisplayContext.get_SDL_Window(), &_width, &_height);
	}
	void Fenetre::refresh() {
		for (auto& monRect : Rectangles) {
			//monRect->dys_changed();
			monRect->draw(this);
		}
		for (auto& scroll : scrolls) { scroll->update(); }
	}
	void Fenetre::set_maximized_dimention(int xm, int ym, int am, int bm) {
		x_max = xm;
		y_max = ym;
		w_max = am;
		h_max = bm;
	}
	void Fenetre::add_full_pointer(etat* pointeur) {
		fullpointer = pointeur;
		fullpointer->user++;
		pointeur->active = fullscreen.active;
	}
	void Fenetre::add_max_pointer(etat* pointeur) {
		maxpointer = pointeur;
		maxpointer->user++;
		pointeur->active = maximized.active;
	}
	void Fenetre::set_full_value(bool stat) {
		fullscreen.active = stat;
		if (fullpointer != NULL)fullpointer->active = stat;

	}
	void Fenetre::set_max_value(bool stat) {
		maximized.active = stat;
		if (maxpointer != NULL)maxpointer->active = stat;

	}
	void Fenetre::LOOPfct() {
		for (auto& monRect : Rectangles) {
			monRect->manage_callback();
		}
	}
	int Fenetre::get_x() {
		int x(0), y(0);
		SDL_GetWindowPosition(_DisplayContext.get_SDL_Window(), &x, &y);
		return x;
	}
	int Fenetre::get_y() {
		int x(0), y(0);
		SDL_GetWindowPosition(_DisplayContext.get_SDL_Window(), &x, &y);
		return y;
	}
	void Fenetre::resize(int w, int h) {
		SDL_SetWindowSize(_DisplayContext.get_SDL_Window(), w, h);
		if (w_base != w || h_base != h)send_resize = true;
		w_base = w;
		h_base = h;



		update_w_h();



		refresh();
	}
	void Fenetre::deplace(int x, int y) {
		x_base = x;
		y_base = y;
		SDL_SetWindowPosition(_DisplayContext.get_SDL_Window(), x, y);
	}
	bool Fenetre::was_resized() {
		return _was_resized;
	}
	DisplayContext Fenetre::get_DisplayContext() {
		return _DisplayContext;
	}
	VideoManager* Fenetre::get_videoManager() {
		return &_videoPlayer;
	}
}