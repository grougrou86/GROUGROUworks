#pragma once
#include"G_inc.h"
namespace ONIGIRIX_GUI {
	class Textarea :public Widget {
	public:
		Textarea(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, std::string Font = "Arial Unicode", int w1 = 10);
		void set_font(std::string);
		void set_font_size(int);
		std::string get_font();
		int get_font_size();

		std::wstring get_value();
		void set_value(std::wstring);

	private:
		std::string font;
		int font_size = 19;
		Text_input* t;
	};
}