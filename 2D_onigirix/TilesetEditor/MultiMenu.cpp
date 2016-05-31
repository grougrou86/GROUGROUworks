#include"ALL_WIDGET.h"
#include"G_inc.h"

namespace ONIGIRIX_GUI {

	namespace MULTIMENU_CLICK_FCT {//to avoid disrupting overclasses

		void close_tab(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
			MultiMenu * m = boost::any_cast<MultiMenu *>(r->data->any_data["relatedWidget"]);
			m->remove_value_from_id(r->data->int_data["id"]);
		}
		void select_tab(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
			MultiMenu * m = boost::any_cast<MultiMenu *>(r->data->any_data["relatedWidget"]);
			m->set_value_from_id(r->data->int_data["id"]);
		}
	}

	void MultiMenu::_on_change() {//TO_DO
		refresh_color_selected();
	}
	int MultiMenu::get_max() {
		return nmb_menu;
	}
	int MultiMenu::get_value() {
		return selected_menu;
	}
	MultiMenu::MultiMenu(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, Design__Multimenu design ):Widget(f,x,y,w,h,0,0),_design(design) {

	}
	int MultiMenu::add_value(std::wstring titre, int pos ) {
		nmb_menu++;
		
		Multimenu_case new_case;
		new_case.nom = titre;
		new_case.id = ids;
		new_case.rect = create_case(titre, new_case.id);

		ids++;

		if (pos < 0)cases.push_back(new_case);
		else {
			auto it = cases.begin();
			size_t place;
			place = pos;
			cases.insert(it + place, new_case);
		}

		refresh_pos_width();

		set_value_from_id(curr_id);
		if (new_case.id == curr_id)refresh_color_selected();

		return new_case.id;
	}
	void MultiMenu::remove_value_from_id(int id) {
		int i = 0;
		for (auto& c : cases) {
			if (c.id == id) {
				remove_value(i);
				return;
			}
			i++;
		}
	}
	void MultiMenu::remove_value(size_t pos) {
		nmb_menu--;
		Rectangle* tosupp = cases[pos].rect;
		auto it = cases.begin();
		cases.erase(it+pos);

		W_supp(tosupp->data->rect_data["closer"]);
		W_supp(tosupp);
		int n_selected = selected_menu;
		if (get_value() == pos) {
			if(pos=cases.size())n_selected--;//because now cases is size minus 1 than what it was before
		}else if (get_value() > pos) {
			n_selected--;
		}
		set_value(n_selected);

		refresh_pos_width();
	}
	void MultiMenu::refresh_pos_width() {
		int i = 0;
		for (auto& a : cases) {
			a.rect->set_x(Mesure(0, 100.0 / (double)get_max()*(double)i));
			a.rect->set_width(Mesure(0, 100.0 / (double)get_max()));
			i++;
		}
	}
	Rectangle* MultiMenu::create_case(std::wstring s, int id) {//TO_DO
		Rectangle* retour = W_add(new Rectangle(get_fenetre()));
		Rectangle* closer = W_add(new Rectangle(get_fenetre()));
		retour->set_text(s);
		retour->set_alignement(center);
		retour->set_bgopacity(1);
		closer->RelativeElement = retour;
		int w_type = retour->rel_h();
		closer->set_width(Mesure(w_type, 0));
		closer->set_x(Mesure(-w_type, 100));
		closer->set_text(L"x");
		closer->set_alignement(center);
		closer->set_bgopacity(1);

		retour->data->int_data["id"] = id;
		closer->data->int_data["id"] = id;

		retour->data->rect_data["closer"] = closer;
		closer->data->rect_data["related"] = retour;

		retour->data->any_data["relatedWidget"] = this;
		closer->data->any_data["relatedWidget"] = this;

		//applying design.

		retour->set_bgopacity(1);
		closer->set_bgopacity(1);

		retour->set_bgcolor(_design.bg_color);
		closer->set_bgcolor(_design.close_color);

		retour->set_font_color(_design.text_color);
		retour->set_font(_design.Police);
		retour->set_font_size(_design.font_size);

		closer->set_font_color(_design.x_close_color);
		closer->set_font(_design.Police);
		closer->set_font_size(_design.font_size);

		retour->set_bordercolor(_design.border_color);
		retour->set_borderwidth(-1);
		closer->set_bordercolor(_design.border_color);
		closer->set_borderwidth(-1);


		retour->set_etat("hover");
		closer->set_etat("hover");


		retour->set_bgcolor(_design.bg_hover_color);
		closer->set_bgcolor(_design.close_color_hover);

		retour->set_font_color(_design.text_hover_color);

		closer->set_font_color(_design.x_close_color_hover);

		retour->set_etat("selected_tab");
		closer->set_etat("selected_tab");

		retour->set_bgcolor(_design.bg_selected_color);

		retour->set_font_color(_design.text_selected_color);

		retour->set_etat("default");
		closer->set_etat("default");

		//click functions and other

		retour->click_fct = MULTIMENU_CLICK_FCT::select_tab;
		closer->click_fct = MULTIMENU_CLICK_FCT::close_tab;

		retour->add_etat({ "selected_tab", false }, 1);
		closer->add_etat({ "selected_tab", false }, 1);
		
		closer->stop_propagation = true;

		return retour;
	}
	int MultiMenu::get_value_id() {
		return cases[get_value()].id;
	}
	void MultiMenu::set_value(size_t pos) {
		selected_menu = pos;
		if (curr_id != cases[pos].id) {
			curr_id = cases[pos].id;
			_on_change();
		}
	}
	void MultiMenu::set_value_from_id(int id) {
		int i = 0;
		for (auto& c : cases) {
			if (c.id == id) {
				set_value(i);
				return;
			}
			i++;
		}
	}
	void MultiMenu::refresh_color_selected() {//TO_DO
		size_t i = 0;
		while (i < cases.size()) {
			auto c = cases[i];
			if (i == selected_menu) {
				c.rect->set_etat_activity(true, "selected_tab");
			} else {
				c.rect->set_etat_activity(false, "selected_tab");
			}
			i++;
		}
	}
}