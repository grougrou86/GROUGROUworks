#include "G_inc.h" 
namespace ONIGIRIX_GUI {
	void Scroll::update() {
		if (value < 0)value = 0;
		else if (value > 1) value = 1;
		Rectangle* lere = boutton;

		Mesure y;
		int min, max, ypx;
		Rectangle* supp = (*(lere->data->scroll_data["scroll"]))[0];
		if ((lere->data->scroll_data["scroll"])->is_vertical) {
			y = (supp)->get_y() + Mesure(value*((supp)->get_height().totalPX(lere->RelativeElement->rel_h()) - (lere)->get_height().totalPX(lere->RelativeElement->rel_h())), 0);
			min = (supp)->get_y().totalPX(lere->RelativeElement->rel_h());
			max = (supp)->get_y().totalPX(lere->RelativeElement->rel_h()) + (supp)->get_height().totalPX(lere->RelativeElement->rel_h()) - (lere)->get_height().totalPX(lere->RelativeElement->rel_h());
			ypx = y.totalPX(lere->RelativeElement->rel_h());

		}
		else {
			y = (supp)->get_x() + Mesure(value*((supp)->get_width().totalPX(lere->RelativeElement->rel_w()) - (lere)->get_width().totalPX(lere->RelativeElement->rel_w())), 0);
			min = (supp)->get_x().totalPX(lere->RelativeElement->rel_w());
			max = (supp)->get_x().totalPX(lere->RelativeElement->rel_w()) + (supp)->get_width().totalPX(lere->RelativeElement->rel_w()) - (lere)->get_width().totalPX(lere->RelativeElement->rel_w());
			ypx = y.totalPX(lere->RelativeElement->rel_w());
		}

		//std::cout << min << "#" << ypx << "#" << max << std::endl;
		Mesure toset;


		if ((lere->data->scroll_data["scroll"])->is_vertical) {
			if (ypx<max&&ypx>min)toset = (y);
			else if (ypx >= max)toset = ((supp)->get_y() + (supp)->get_height() - (lere)->get_height());
			else if (ypx <= min)toset = ((supp)->get_y());
			lere->set_y(toset);
			lere->set_x(supp->get_x());
		}
		else {
			if (ypx<max&&ypx>min)toset = (y);
			else if (ypx >= max)toset = ((supp)->get_x() + (supp)->get_width() - (lere)->get_width());
			else if (ypx <= min)toset = ((supp)->get_x());
			lere->set_x(toset);
			lere->set_y(supp->get_y());
		}
		//std::cout << "Value : " << value << "/1" << std::endl;
	}
	double Scroll::get_value() {
		return value;
	}
	void Scroll::set_value(double valeur) {
		if (valeur > 1)valeur = 1;
		if (valeur < 0)valeur = 0;
		value = valeur;
		update();
		change();
	}
	void scroll_update_old(Rectangle* lere) {
		Rectangle* supp = (*(lere->data->scroll_data["scroll"]))[0];
		Mesure(lere->ma_fenetre->Mousey, 0) - lere->data->mesure_data["y_base"];
		Mesure(lere->ma_fenetre->Mousex, 0) - lere->data->mesure_data["y_base"];
		if ((lere->data->scroll_data["scroll"])->is_vertical) {
			Mesure dif = Mesure(lere->ma_fenetre->Mousey, 0) - lere->data->mesure_data["y_base"];
			Mesure dif2 = supp->get_height() - lere->get_height();
			(lere->data->scroll_data["scroll"])->set_value(lere->data->double_data["val_base"] + (dif).totalPX(lere->RelativeElement->rel_h()) / (dif2).totalPX(lere->RelativeElement->rel_h()));
		}
		else {
			Mesure dif = Mesure(lere->ma_fenetre->Mousex, 0) - lere->data->mesure_data["y_base"];
			Mesure dif2 = supp->get_width() - lere->get_width();
			(lere->data->scroll_data["scroll"])->set_value(lere->data->double_data["val_base"] + (dif).totalPX(lere->RelativeElement->rel_w()) / dif2.totalPX(lere->RelativeElement->rel_w()));

		}

	}
	void Scroll::set_relative(Relative* Rela) {
		RelativeElement = Rela;
		support->RelativeElement = Rela;
		boutton->RelativeElement = Rela;
	}
	void scroll_update_old_s(Rectangle* lere) {
		SDL_SetWindowGrab(lere->ma_fenetre->get_DisplayContext().get_SDL_Window(), SDL_TRUE);
		if ((lere->data->scroll_data["scroll"])->is_vertical) {
			lere->data->mesure_data["y_base"] = Mesure(lere->ma_fenetre->Mousey, 0);

		}
		else {
			lere->data->mesure_data["y_base"] = Mesure(lere->ma_fenetre->Mousex, 0);
		}
		lere->data->double_data["val_base"] = lere->data->scroll_data["scroll"]->value;
	}
	void scroll_update_old_e(Rectangle* lere) {
		SDL_SetWindowGrab(lere->ma_fenetre->get_DisplayContext().get_SDL_Window(), SDL_FALSE);
	}

	Scroll::Scroll(Fenetre* f, Mesure h1, Mesure h2, Mesure w, Mesure x, Mesure y, bool vertical) :fen(f), _h1(h1), _h2(h2), _w(w), _x(x), _y(y) {

		is_vertical = vertical;
		if (is_vertical) {
			support = f->addRectangle(Rectangle(x, y, w, h1));
			boutton = f->addRectangle(Rectangle(x, y, w, h2));
		}
		else {
			support = f->addRectangle(Rectangle(x, y, h1, w));
			boutton = f->addRectangle(Rectangle(x, y, h2, w));
		}
		boutton->stop_propagation = true;
		support->stop_propagation = true;
		boutton->set_bgcolor(0x000000);
		support->set_bgcolor(0x555555);
		boutton->set_bgopacity(1);
		support->set_bgopacity(1);
		boutton->data->scroll_data["scroll"] = this;
		support->data->scroll_data["scroll"] = this;
		f->scrolls.push_back(this);

		callback_etat Moncall;
		Moncall.nom = "hold";
		Moncall.on_while = scroll_update_old;
		Moncall.on_start = scroll_update_old_s;
		Moncall.on_end = scroll_update_old_e;
		boutton->add_callback_etat(Moncall);

	}
	Rectangle* Scroll::operator[](int i) const {
		if (i == 0)return support;
		return boutton;
	}
	void  Scroll::change() { if (onchange != NULL)onchange(support,get_value()); }
	Mesure Scroll::get_x() {
		return _x;
	}
	void Scroll::set_x(Mesure x) {
		//support->set_etat("default");
		support->set_x(x);
		_x = x;
		update();
	}
	Mesure Scroll::get_y() {
		return _y;
	}
	void Scroll::set_y(Mesure y) {
		support->set_y(y);
		_y = y;
		update();
	}
	void Scroll::add_on_change(call_funk_scroll fnct) {
		onchange = fnct;
	}
	void Scroll::remove_on_change() {
		onchange = NULL;
	}
	Mesure Scroll::get_w() {
		return _w;
	}
	void Scroll::set_w(Mesure w) {
		if (is_vertical) { support->set_width(w); boutton->set_width(w); }
		else { support->set_height(w); boutton->set_height(w); }
		_w = w;
		update();
	}
	Mesure Scroll::get_h1() {
		return _h1;
	}
	void Scroll::set_h1(Mesure h1) {
		if (is_vertical)support->set_height(h1);
		else support->set_width(h1);
		_h1 = h1;
		update();
	}
	Mesure Scroll::get_h2() {
		return _h2;
	}
	void Scroll::set_h2(Mesure h2) {
		if (is_vertical)boutton->set_height(h2);
		else boutton->set_width(h2);
		_h2 = h2;
		update();
	}
}