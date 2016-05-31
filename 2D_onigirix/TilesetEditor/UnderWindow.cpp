#include"G_inc.h"
#include <algorithm>  
/*

	 a faire :

	 -ajouter les clips 
	 -ajouter underwindows un vecter à la fenetre
	 -fonction refresh

*/
namespace ONIGIRIX_GUI {
	UnderWindow::~UnderWindow() {
		if (!deleter_made) { deleter(); deleter_made = true; }
	}
	void UnderWindow::deleter() {
		deleter_made = true;
		ma_fenetre->supp_rect(background);
		ma_fenetre->supp_scroll(vertical);
		ma_fenetre->supp_scroll(horizontal);
		for (auto r : Rectangles) { r->remove_auto_clip(own_clip); }
		for (auto r : Underwindows) { r->remove_auto_clip(own_clip); }
		delete own_clip;
	}
	void UnderWindow::Refresh() {
		Rectangle_clip old_own_clip = *own_clip;
		*own_clip = Rectangle_clip(Mesure(rel_x(), 0), Mesure(rel_y(), 0), Mesure(rel_w(), 0), Mesure(rel_h(), 0));
		if (auto_p_clips.size() != 0) {
			Rectangle_clip test = intersection(auto_p_clips, rel_w(), rel_h(), *own_clip);
			*own_clip = intersection(test, *own_clip, rel_w(), rel_h(), *own_clip);
		}
		max_h = max_h_function(Rectangles);
		int max_h2 = max_h_function(Underwindows);
		if (max_h2 > max_h)max_h = max_h2;
		max_w = max_w_function(Rectangles);
		int max_w2 = max_w_function(Underwindows);
		if (max_w2 > max_w)max_w = max_w2;
		if (old_own_clip == *own_clip) {
			for (auto r : Rectangles) { r->ask_clip_updat(); }
			background->ask_clip_updat();
		}
		if (max_w > rel_w())
		{
			n_offset_x = (max_w - rel_w())* horizontal->get_value();
			horizontal->set_h2(Mesure(0, (double)100 * (double)rel_w() / (double)max_w));
			horizontal->set_y(Mesure(0, 100));
			horizontal_on = true;
			horizontal->set_relative(this);
		}
		else {
			n_offset_x = 0;
			horizontal->set_relative(ma_fenetre);
			horizontal->set_y(Mesure(100, 100));
			horizontal_on = false;

		}
		if (max_h > rel_h()) {
			n_offset_y = (max_h - rel_h())* vertical->get_value();
			vertical->set_h2(Mesure(0, (double)100 * (double)rel_h() / (double)max_h));
			vertical->set_x(Mesure(0, 100));
			vertical_on = true;
			vertical->set_relative(this);
		}
		else {
			n_offset_y = 0;
			vertical->set_relative(ma_fenetre);
			vertical->set_x(Mesure(100, 100));
			vertical_on = false;
		}
		for (auto r : Rectangles) { r->set_offset_x(-n_offset_x); r->set_offset_y(-n_offset_y); }
		background->set_offset_x(-n_offset_x); background->set_offset_y(-n_offset_y);
		for (auto r : Underwindows) { r->offset_x = -n_offset_x; r->offset_y = -n_offset_y; }

		//Mise à jour de la hauteur / largeur du font.
		background->set_height(Mesure(std::max(max_h, rel_h()), 0));
		background->set_width(Mesure(std::max(max_w, rel_w()), 0));
	}
	UnderWindow::UnderWindow(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, int w1, int w2) :ma_fenetre(f), _x(x), _y(y), _w(w), _h(h), _w1(w1), _w2(w2)
	{
		own_clip = new Rectangle_clip();
		RelativeElement = f;
		vertical = new Scroll(f, Mesure(0, 100), Mesure(0, 50), Mesure(w1, 0), Mesure(0, 100), Mesure(0, 0), true);
		horizontal = new Scroll(f, Mesure(0, 100), Mesure(0, 50), Mesure(w2, 0), Mesure(0, 0), Mesure(0, 100), false);
		vertical->set_relative(this);
		horizontal->set_relative(this);
		f->addUnderwindow(this);
		background = new Rectangle(f);
		background->add_auto_clip(own_clip);
		background->RelativeElement = this;

	}
	void UnderWindow::set_x(Mesure x) {
		_x = x;
	}
	void UnderWindow::set_y(Mesure y) {
		_y = y;
	}
	void UnderWindow::set_width(Mesure w) {
		_w = w;
	}
	void UnderWindow::set_height(Mesure h) {
		_h = h;
	}

	Mesure UnderWindow::get_x() {
		return _x;
	}
	Mesure UnderWindow::get_y() {
		return _y;
	}
	Mesure UnderWindow::get_width() {
		return _w;
	}
	Mesure UnderWindow::get_height() {
		return _h;
	}
	int UnderWindow::rel_x() {
		return get_x().totalPX(RelativeElement->rel_w()) + RelativeElement->rel_x() + get_offset_x();
	}
	int UnderWindow::rel_y() {
		return get_y().totalPX(RelativeElement->rel_h()) + RelativeElement->rel_y() + get_offset_y();
	}
	int UnderWindow::rel_w() {
		if (vertical_on)return get_width().totalPX(RelativeElement->rel_w()) - _w1;
		else return get_width().totalPX(RelativeElement->rel_w());
	}
	int UnderWindow::rel_h() {
		if (horizontal_on)return get_height().totalPX(RelativeElement->rel_h()) - _w2;
		else return get_height().totalPX(RelativeElement->rel_h());
	}
	Rectangle* UnderWindow::addRectangle(Rectangle* monRectangle) {
		Rectangles.push_back(monRectangle);
		monRectangle->RelativeElement = this;
		monRectangle->add_auto_clip(own_clip);

		return monRectangle;
	}
	Rectangle* UnderWindow::removeRectangle(Rectangle* monRectangle) {
		auto it = find(Rectangles.begin(), Rectangles.end(), monRectangle);
		if (it != Rectangles.end()) {
			(*it)->RelativeElement = ma_fenetre;
			Rectangles.erase(it);
		}
		monRectangle->remove_auto_clip(own_clip);

		return monRectangle;
	}
	UnderWindow* UnderWindow::addUnderWindow(UnderWindow* UnderWindow) {
		Underwindows.push_back(UnderWindow);
		UnderWindow->RelativeElement = this;
		UnderWindow->add_auto_clip(own_clip);

		return UnderWindow;
	}
	UnderWindow* UnderWindow::removeUnderWindow(UnderWindow* UnderWindow) {
		auto it = find(Underwindows.begin(), Underwindows.end(), UnderWindow);
		if (it != Underwindows.end()) {
			(*it)->RelativeElement = ma_fenetre;
			Underwindows.erase(it);
		}
		UnderWindow->remove_auto_clip(own_clip);
		return UnderWindow;
	}
	void  UnderWindow::add_auto_clip(Rectangle_clip* r) {
		auto_p_clips.push_back(r);
	}
	void  UnderWindow::remove_auto_clip(Rectangle_clip* r) {
		auto_p_clips.erase(find(auto_p_clips.begin(), auto_p_clips.end(), r));
	}
	int UnderWindow::get_offset_x() {
		if (!is_offset_activated())return 0;
		return offset_x;
	}
	int UnderWindow::get_offset_y() {
		if (!is_offset_activated())return 0;
		return offset_y;
	}
	void UnderWindow::set_offset_x(int x) {
		offset_x = x;
	}
	void UnderWindow::set_offset_y(int y) {
		offset_y = y;
	}
	void UnderWindow::activate_offset(bool c) {
		active_offset = c;
	}
	bool UnderWindow::is_offset_activated() {
		return active_offset;
	}
	void UnderWindow::activate_absolute(bool c) {
		active_absolute = c;
	}
	bool UnderWindow::is_absolute_activated() {
		return active_absolute;
	}
}