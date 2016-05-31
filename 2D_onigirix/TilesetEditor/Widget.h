#pragma once
#include"G_inc.h"
namespace ONIGIRIX_GUI {
	class Widget :protected UnderWindow {
	public:
		virtual ~Widget();
		Widget(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, int w1 = 20, int w2 = 20) :UnderWindow(f, x, y, w, h, w1, w2) {}
		std::vector<Rectangle*>Widget_rectangles;
		std::vector<UnderWindow*>Widget_Underwindows;
		std::vector<Scroll*>Widget_Scrolls;

		Fenetre* get_window();

		Rectangle* W_add(Rectangle*);
		UnderWindow* W_add(UnderWindow*);
		Text_input* W_add(Text_input*);
		Scroll* W_add(Scroll*);

		bool W_supp(Rectangle*);
		bool W_supp(UnderWindow*);
		bool W_supp(Scroll*);

		Rectangle* get_background();
		Fenetre* get_fenetre();
		
		data_store data;

		virtual void deleter();
	};
}
