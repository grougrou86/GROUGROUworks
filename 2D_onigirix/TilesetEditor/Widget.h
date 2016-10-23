#pragma once
#include"G_inc.h"
namespace ONIGIRIX_GUI {
	class Widget :public UnderWindow {
	public:
		virtual ~Widget();
		Widget(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, int w1 = 20, int w2 = 20) :UnderWindow(f, x, y, w, h, w1, w2) {
			background->data->pointer_data["WIDGET"] = this; // to access to the wiget in a rectangle and get profit of rectangle functions !!! like hover click etc !!!
		}
		std::vector<Rectangle*>Widget_rectangles;
		std::vector<UnderWindow*>Widget_Underwindows;
		std::vector<Scroll*>Widget_Scrolls;
		std::vector<Widget*>Widget_Widget;

		Fenetre* get_window();

		Rectangle* W_add(Rectangle*);
		UnderWindow* W_add(UnderWindow*);
		Widget* W_add(Widget*);
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
