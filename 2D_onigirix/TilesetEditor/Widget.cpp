#include"G_inc.h"
namespace ONIGIRIX_GUI {
	
	Fenetre* Widget::get_window() {
		return ma_fenetre;
	}
	void Widget::deleter() {
		UnderWindow::deleter();
		for (auto a : Widget_rectangles)ma_fenetre->removeRectangle(a);
		for (auto a : Widget_Scrolls)ma_fenetre->removeScroll(a);
		for (auto a : Widget_Underwindows)ma_fenetre->removeUnderwindow(a);
		for (auto a : Widget_Widget)ma_fenetre->removeWidget(a);
	}
	Rectangle* Widget::W_add(Rectangle* r) {
		Widget_rectangles.push_back(r);
		addRectangle(r);
		return r;
	}
	UnderWindow* Widget::W_add(UnderWindow* u) {
		Widget_Underwindows.push_back(u);
		addUnderWindow(u);
		return u;
	}
	Widget* Widget::W_add(Widget* u) {
		Widget_Widget.push_back(u);
		addUnderWindow(u);
		return u;
	}
	Scroll* Widget::W_add(Scroll* s) {
		Widget_Scrolls.push_back(s);
		s->set_relative(this);
		addRectangle((*s)[0]);
		addRectangle((*s)[1]);
		return s;
	}
	Text_input* Widget::W_add(Text_input* r) {
		Widget_rectangles.push_back(r);
		r->RelativeElement = this;
		addRectangle(r);
		return r;
	}
	Widget::~Widget() {
		if (!deleter_made) { deleter(); deleter_made = true; }
	}
	Rectangle* Widget::get_background() {
		return background;
	}

	Fenetre* Widget::get_fenetre() {
		return ma_fenetre;
	}
	bool Widget::W_supp(Rectangle* r) {
		removeRectangle(r);
		get_fenetre()->removeRectangle(r);
		auto it = find(Widget_rectangles.begin(), Widget_rectangles.end(),r);
		if (it != Widget_rectangles.end()) {
			Widget_rectangles.erase(it);
			return true;
		}
		return false;
	}
	bool Widget::W_supp(UnderWindow* u) {
		removeUnderWindow(u);
		get_fenetre()->removeUnderwindow(u);
		auto it = find(Widget_Underwindows.begin(), Widget_Underwindows.end(), u);
		if (it != Widget_Underwindows.end()) {
			Widget_Underwindows.erase(it);
			return true;
		}
		return false;
	}
	bool Widget::W_supp(Scroll* s) {
		removeRectangle((*s)[0]);
		removeRectangle((*s)[1]);
		get_fenetre()->removeScroll(s);
		auto it = find(Widget_Scrolls.begin(), Widget_Scrolls.end(), s);
		if (it != Widget_Scrolls.end()) {
			Widget_Scrolls.erase(it);
			return true;
		}
		return false;
	}
}