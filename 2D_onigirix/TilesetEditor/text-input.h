#pragma once
/*
  / \
 / | \  --> améliore l'efficité a lentré des touche attention car la recalcul innutilement tout le text... attention !!!!
/__°__\
*/
#include"G_inc.h"
#include<string>
namespace ONIGIRIX_GUI {
	class WritingRestriction {
	public:
		WritingRestriction() :only_int(false) {}
		WritingRestriction(bool _int) :only_int(_int) {}
		bool only_int;
		bool test(std::wstring);
	};
	struct cursor_info {
		int CursorPosition = 0;
		bool CursorVisible = false;
	};
	struct cursor_concreat_info {
		int x = 0;
		int y = 0;
		int height = 21;
		int width = 1;
	};
	struct selection_info {
		int begin = -1;
		int end = -1;
	};
	class Text_input :public Rectangle
	{
	public:
		Text_input(std::string font, Mesure x = Mesure(0, 0), Mesure y = Mesure(0, 0), Mesure w = Mesure(0, 100), Mesure h = Mesure(0, 100), WritingRestriction wrestrictions = WritingRestriction());
		Text_input(Fenetre*f, std::string font, Mesure x = Mesure(0, 0), Mesure y = Mesure(0, 0), Mesure w = Mesure(0, 100), Mesure h = Mesure(0, 100), WritingRestriction wrestrictions = WritingRestriction());
		~Text_input();
		//redefinition etc...
		virtual void KeyFunction(int key);
		virtual Text_input* copie();
		virtual void onclick_fct(int x, int y);
		virtual void draw(Fenetre* f);
		virtual void TextInputFunction(std::wstring);
		//will not be working like rectangles text who andels state this is going to be only a normal stat editable (maybe for later...)
		std::wstring get_value();
		void set_value(std::wstring);
		void insert_text(std::string, unsigned int pos);//string car pour le copy paste etc...
		void erase(unsigned int begin, unsigned int end);
		unsigned int end();
		cursor_info InfoCU;
		selection_info InfoSE;
		unsigned int max_clignot = 60;
		void TextinputFct(std::wstring input);
		virtual void on_active();
		virtual void out_active();
		WritingRestriction restrictions;//restriction sur l'entrée textuelle

	private:
		cursor_concreat_info get_precise_cursor();
		unsigned int clignot = 0;

	};
}
