#include"G_inc.h"
#include"useful-fct.h"
namespace ONIGIRIX_GUI {
	void TEXTAREA__fonce_even_over(Rectangle* r, Fenetre* f, SDL_mainLoop* l) { // obligé de foncer le background avec cette fonction car la proèpagation est stopé sur les textinput pour raison de performances
		r->data->rect_data["relRec"]->set_etat_activity(true, "active");
	}
	Textarea::Textarea(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, std::string Font, int w1) :Widget(f, x, y, w, h, w1, 10) {
		font = Font;
		Rectangle* r = W_add(new Rectangle(f));
		r->RelativeElement = get_background();
		r->set_bgcolor(0xeeeeee);
		r->set_bgopacity(1);
		r->set_etat("active");
		r->set_bgcolor(0xcccccc);
		r->set_bgopacity(1);
		r->set_etat("default");
		r->activate_offset(false);
		r->activate_absolute(true);
		t = W_add(new Text_input(f, font, Mesure(2, 0), Mesure(2, 0), Mesure(-4, 100), Mesure(0, 0)));
		t->set_font_size(font_size);
		t->set_font_color(0x222222);
		t->set_alignement(left);
		t->set_bgopacity(0);
		t->stop_propagation = true;
		Rectangle* r2 = W_add(new Rectangle(f));
		r2->set_bordercolor(0);
		r2->set_borderwidth(-1);
		r2->activate_offset(false);
		r->data->int_data["rel-Offset-x"] = -2;
		r->data->int_data["rel-Offset-y"] = 0;
		r->data->rect_data["relRec"] = t;
		t->data->rect_data["relRec"] = r;
		r->pos_click_fct = relay_click;
		t->click_fct = TEXTAREA__fonce_even_over;

	}
	void Textarea::set_font(std::string f) {
		t->set_font(f);
		font = f;
	}
	void Textarea::set_font_size(int s) {
		t->set_font_size(s);
		font_size = s;
	}
	std::string Textarea::get_font() {
		return font;
	}
	int Textarea::get_font_size() {
		return font_size;
	}
	std::wstring Textarea::get_value() {
		return t->get_text();
	}
	void Textarea::set_value(std::wstring s) {
		t->set_text(s);
	}
}