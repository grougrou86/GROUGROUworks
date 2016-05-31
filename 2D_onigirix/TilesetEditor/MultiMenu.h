#pragma once
#include"G_inc.h"

namespace ONIGIRIX_GUI {

	class Design__Multimenu {
	public:
		Design__Multimenu() {}
		int bg_color = 0xeeeeee;
		int bg_selected_color = 0xffbbbb;
		int bg_hover_color = 0xbbbbbb;
		int close_color = 0;
		int close_color_hover = 0xffffff;
		int x_close_color = 0xffffff;
		int x_close_color_hover = 0;
		int text_color = 0;
		int text_hover_color = 0;
		int text_selected_color = 0;
		int border_color = 0;

		std::string Police = "calibri";
		int font_size = 19;
	};

	struct Multimenu_case {
		std::wstring nom;
		Rectangle* rect;
		int id;
	};

	class MultiMenu :public Widget {
	public:
		MultiMenu(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, Design__Multimenu design = Design__Multimenu());
		int get_value();
		int get_value_id();
		int get_max();
		int add_value(std::wstring titre, int pos=-1);//négatif--> add at the end. return the id of the case
		void remove_value(size_t pos);
		void remove_value_from_id(int id);
		void set_value(size_t pos);
		void set_value_from_id(int id);

	private:
		int nmb_menu = 0; //nombre totale de menu
		int selected_menu = 0; // numéro du menu sélectionné
		Rectangle* create_case(std::wstring,int id);//but doesn't order it...
		Design__Multimenu _design;
		std::vector<Multimenu_case> cases;
		void refresh_pos_width();//rafraichire les position.... et largeur après suppression et /ou ajout de case(s)
		void refresh_color_selected();
		void _on_change();
		int ids = 0;
		int curr_id = 0;
	};

	
	
}