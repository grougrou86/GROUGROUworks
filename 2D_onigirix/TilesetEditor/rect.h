#ifndef RECT_H
#define RECT_H

#include "G_inc.h" 
#include "Mesure.h"
#include <string>
#include <vector>
#include "DIFFERED_LOADER.h"
#include "ImageIncludes.h"
#include "texture.h"

namespace ONIGIRIX_GUI {
	//ajouter etat / pointersur etat

	struct fct_duree {
		call_funk fct_while;
		call_funk fct_end;
		int left_frames;
	};
	struct for_vieux {
		etat vieux_etat;
		std::vector<style_etat_base*> style_affecte;
	};

	class img_sizing {
	public:
		img_sizing(size_mode mode1 = fit, size_mode mode2 = fit) :x_mode(mode1), y_mode(mode2) {}
		size_mode x_mode;
		size_mode y_mode;
	};
	const bool operator!=(img_sizing, img_sizing);
	/*bool operator==(img_sizing  const&  M1, img_sizing const& M2){
		return M1.x_mode == M2.x_mode&&M1.y_mode == M2.y_mode;
	}*/
	//surface = SDL_CreateRGBSurface(SDL_HWSURFACE,width,height,32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
	typedef void(*Click_fontion)(Rectangle*, Fenetre*, SDL_mainLoop*);
	typedef void(*POS_Click_fontion)(Rectangle*, Fenetre*, SDL_mainLoop*, int x, int y);

	class Rectangle : public Forme, public Relative {

	public:

		virtual int rel_x();
		virtual int rel_y();
		virtual int rel_w();
		virtual int rel_h();

		Relative* RelativeElement;

		Rectangle(Mesure x = Mesure(0, 0), Mesure y = Mesure(0, 0), Mesure w = Mesure(0, 100), Mesure h = Mesure(0, 100));
		Rectangle(Fenetre* f, Mesure x = Mesure(0, 0), Mesure y = Mesure(0, 0), Mesure w = Mesure(0, 100), Mesure h = Mesure(0, 100));

		//clips
		//Rectangle(const Rectangle &);
		void set_x(Mesure);
		bool update_x();

		bool general_update = false;
		void general_updater();

		void set_y(Mesure);
		void set_x2(Mesure);
		void set_y2(Mesure);
		void set_width(Mesure);
		void set_height(Mesure);
		void set_bg_img(std::string);
		void set_bg_img(std::wstring);
		void add_bg(std::wstring,Image*);//if you want the image to be destroyed at same time as the rectangle do the forget to set the rectangle as the proprietar of image !!!
		void add_bg(std::string, Image*);
		void set_bgcolor(int color);
		void set_bgopacity(double opacity);
		void set_bg_img_sizing(img_sizing);
		void set_bordercolor(int);
		void set_borderwidth(int);
		void set_font_size(int);
		void set_text(std::string);
		void set_text(std::wstring);
		void set_font(std::string);
		void set_font_color(int);
		void set_alignement(alignement);
		void set_z_index(int);

		void check_state_upd();

		std::wstring get_bg_img();
		int get_bg_couleur();
		alignement get_alignement();
		Mesure get_x();
		Mesure get_y();
		Mesure get_x2();
		Mesure get_y2();
		Mesure get_width();
		Mesure get_height();
		Image* get_bg_from_name(std::wstring);
		Image* get_bg_from_name(std::string);
		int get_z_index() const;
		int get_bgcolor();
		int get_bordercolor();
		int get_borderwidth();
		double get_bgopacity();
		img_sizing get_bg_img_sizing();
		int get_font_size();
		std::wstring get_text();
		std::string get_font();
		int get_font_color();
		virtual void draw(Fenetre* f);
		virtual Rectangle* copie();
		virtual void TextInputFunction(std::wstring);
		//all about clicking

		virtual ClickSurface* get_click_surface();
		virtual void onclick_fct(int x = 0, int y = 0);
		virtual void set_hover(bool);
		virtual void set_hold(bool);
		void delete_click();
		void set_click_function(Click_fontion fct);
		void set_click_function(POS_Click_fontion fct);

		Click_fontion click_fct = NULL;
		POS_Click_fontion pos_click_fct = NULL;

		~Rectangle();


		Fenetre* ma_fenetre = NULL;
		SDL_mainLoop* ma_loop = NULL;

		//gestion des etat



		//std::vector<etat_imp> etats = std::vector<etat_imp>{ etat_imp{ etat{ "default", true }, 0 } };
		std::vector<etat_point_imp> const_etats;
		std::vector<etat> vieux_etats;
		std::vector<for_vieux> vieux_etats_utiles;

		virtual void KeyFunction(int key);
		virtual void TextinputFct(std::wstring input);
		etat* add_etat(etat, int importance = 0);
		void add_etat(etat*, int importance = 0);
		etat* get_etat(std::string nom);
		void remove_etat(std::string nom);
		void set_etat(std::string);
		void set_etat_activity(bool activ, std::string name);
		struct etat_state etat_state(std::string);

		std::string currentState = "default";

		bool stop_propagation = false;


		void finish_LOOP();
		void add_callback_etat(callback_etat);
		void remove_callback_etat(std::string nom);
		void manage_callback();
		virtual void on_active();
		virtual void on_hover();
		virtual void on_hold();
		virtual void out_active();
		virtual void out_hover();
		virtual void out_hold();



		data_store* data;

		style_etat_data<Mesure>* _x;
		style_etat_data<Mesure>* _y;
		style_etat_data<int>* bg_color;
		style_etat_data<std::wstring>* bg_img;
		style_etat_data<int>* border_color;
		style_etat_data<int>* border_width;
		style_etat_data<double>* bg_opacity = 0;
		style_etat_data<img_sizing>* bg_img_sizing;
		style_etat_data<Mesure>* _w;//width
		style_etat_data<Mesure>* _h;//height

		style_etat_data<std::wstring>* text;
		style_etat_data<std::string>* font;
		style_etat_data<int>* font_size;
		style_etat_data<int>* font_color;
		style_etat_data<alignement>* align;
		int text_height = 0;

		int img_dim_w = -1;
		int img_dim_h = -1;

		void add_move_fnct(fct_duree);
		void updat_move_fnct();

		call_funk everyframe_fct = NULL;
		key_funk keyfunct = NULL;

		std::vector<etat*> clearatclean_etat;
		TextBlock* LeText = NULL;
		//std::map<std::string, SDL_Surface*> oldIMG;
		//std:: vector<int>::iterator index_th ;//pas touch stp
		std::vector<Rectangle_clip>& clips();
		std::vector<Rectangle_clip*> p_clips;
		std::vector<Rectangle_clip*> auto_p_clips;// a ne pas toucher stp juste pour Under_frame ->doit déclencher l'event d'update obligé

		void add_auto_clip(Rectangle_clip*);
		void remove_auto_clip(Rectangle_clip*);

		void ask_clip_updat();

		SDL_Rect destRect;
		SDL_Rect srcRect;

		SDL_Rect stretchRect;// a ne pas modif donne le placement absolut du rectangle !!!
		bool debug = false;

		int get_offset_x();
		int get_offset_y();
		void set_offset_x(int);
		void set_offset_y(int);
		void activate_offset(bool);
		bool is_offset_activated();
		void activate_absolute(bool);
		bool is_absolute_activated();

		bool ever_refresh_text = false;//to try display even empty text(for textinput subclass)...
	private:

		std::map<std::wstring, Image* > oldIMG; // if you one to set or change manualy this do not forget to put the rectangle as owner of the image !
		FastMapSearch<std::wstring> last_search;

		bool active_absolute = false;
		bool active_offset = true;

		int offset_x = 0;
		int offset_y = 0;

		int old_offset_x = 0;
		int old_offset_y = 0;

		bool offset_update = false;

		std::vector<Rectangle_clip> _clips;
		std::vector<Rectangle_clip> _save_p_clips;
		Rectangle_clip final_rec;
		Rectangle_clip last_rec;
		bool clip_updated = false;
		template<typename T>
		T get_what(style_etat_data<T>* & style);
		template<typename T>
		void set_what(style_etat_data<T>* & style, T);
		template<typename T>
		bool update(style_etat_data<T> &);

		void check_stats_change();

		int Zindex = 0;


		SDL_Rect extern_clip;

		double zoom = 1;

		void reload_img(SDL_Texture* &, SDL_Texture* &);

		ClickRect surface_de_clique;//juste pour l'affichage t'occupe pas ou je te .... !!!!!



		//var for functionment don't touch baby

		bool text_ok = false;

		std::vector<fct_duree> move_fnct;

		std::vector<callback_etat*> callbacks_etat;

		std::vector<style_etat_base*> point_styles;

	protected:

		bool copied = false;//pour savoir ce qu'on doit détruire dans le destructeur ! si la variable est une copie 
		int oldRel_w = 0;
		int oldRel_h = 0;
		int oldRel_x = 0;
		int oldRel_y = 0;


	};
}
#endif