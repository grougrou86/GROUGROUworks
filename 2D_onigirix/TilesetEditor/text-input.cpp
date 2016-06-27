#include "G_inc.h"
#include <string>
#include <stdexcept>  
namespace ONIGIRIX_GUI {
	Text_input::Text_input(std::string font, Mesure x, Mesure y, Mesure w, Mesure h, WritingRestriction wrestriction) :Rectangle(x, y, w, h), restrictions(wrestriction)
	{
		set_bgcolor(0xffffff);
		set_bgopacity(1);
		set_font(font);
		set_font_size(21);
		set_alignement(left);
		ever_refresh_text = true;
	}
	Text_input::Text_input(Fenetre*f, std::string font, Mesure x, Mesure y, Mesure w, Mesure h, WritingRestriction wrestrictions) :Text_input(font, x, y, w, h, wrestrictions) {
		f->addRectangle(this);
	}
	void  Text_input::KeyFunction(int key) {
		if (keyfunct != NULL)keyfunct(this, key);
		etat* moi = get_etat("active");
		if (key == SDLK_LEFT && moi->active&&InfoCU.CursorPosition > 0) { InfoCU.CursorPosition--; clignot = 0; }
		if (key == SDLK_RIGHT&& moi->active&&InfoCU.CursorPosition < LeText->max_index) { InfoCU.CursorPosition++; clignot = 0; }
		if (key == SDLK_UP && moi->active&&InfoCU.CursorPosition > 0) {
			cursor_concreat_info pcur = get_precise_cursor();
			InfoCU.CursorPosition = LeText->cursor_index_from_mouse(pcur.x, pcur.y - LeText->charaSize);
			clignot = 0;
		}
		if (key == SDLK_DOWN && moi->active&&InfoCU.CursorPosition > 0) {
			cursor_concreat_info pcur = get_precise_cursor();
			InfoCU.CursorPosition = LeText->cursor_index_from_mouse(pcur.x, pcur.y + 2 * LeText->charaSize);
			clignot = 0;
		}
		if (key == SDLK_BACKSPACE && moi->active) {
			if (InfoCU.CursorPosition != 0) {
				std::wstring retour = get_value();
				retour.erase(InfoCU.CursorPosition - 1, 1);
				set_value(retour);
				InfoCU.CursorPosition--;
			}
		}
		if ((key == SDLK_KP_ENTER || key == SDLK_RETURN) && moi->active) {
			std::wstring retour = get_value();
			retour.insert(InfoCU.CursorPosition, L"\n");
			set_value(retour);
			InfoCU.CursorPosition++;
		}
	}
	void Text_input::TextInputFunction(std::wstring) {

	}
	void Text_input::TextinputFct(std::wstring input) {
		if (etat_state("active").state == 1) {
			std::wstring retour = get_value();
			retour.insert(InfoCU.CursorPosition, input);
			if (restrictions.test(retour)) {
				set_value(retour);
				InfoCU.CursorPosition++;
			}
		}

	}
	void Text_input::on_active() {
		//std::cout << "textinput-ON" << std::endl;
		InfoCU.CursorVisible = true;
	}
	void Text_input::out_active() { InfoCU.CursorVisible = false; }
	void Text_input::draw(Fenetre* f) {
		Rectangle::draw(f);
		SDL_Rect rect;
		cursor_concreat_info cur = get_precise_cursor();
		clignot++;
		clignot = clignot % max_clignot;
		if (clignot < max_clignot / 2 && InfoCU.CursorVisible)
		{
			rect.w = cur.width;
			rect.h = cur.height;
			rect.x = cur.x + get_x().totalPX(RelativeElement->rel_w()) + RelativeElement->rel_x() + get_offset_x();
			rect.y = cur.y + get_y().totalPX(RelativeElement->rel_h()) + RelativeElement->rel_y() + get_offset_y();
			std::cout << "ofx" << get_offset_x() << "ofy" << get_offset_y() << std::endl;
			rect = intersection(rect, destRect);
			RGB_c bg_C_RGB = couleurConverter(get_font_color());
			SDL_SetRenderDrawBlendMode(f->get_screen_render(), SDL_BLENDMODE_BLEND);
			SDL_SetRenderDrawColor(f->get_screen_render(), bg_C_RGB.get_r(), bg_C_RGB.get_g(), bg_C_RGB.get_b(), 255);
			SDL_RenderFillRect(f->get_screen_render(), &rect);
			SDL_SetRenderDrawColor(f->get_screen_render(), 0xFF, 0xFF, 0xFF, 0xFF);
		}
	}
	Text_input::~Text_input()
	{

	}
	std::wstring Text_input::get_value() {

		return get_text();
	}
	void Text_input::set_value(std::wstring value) {
		set_text(value);
	}
	void Text_input::onclick_fct(int x, int y) {
		InfoCU.CursorPosition = LeText->cursor_index_from_mouse(x, y);
		//usual onclick fct....
		if (click_fct != NULL)click_fct(this, ma_fenetre, ma_loop);
		if (pos_click_fct != NULL)pos_click_fct(this, ma_fenetre, ma_loop, x, y);
	}
	Text_input* Text_input::copie() {
		Text_input* inp = new Text_input(*this);
		copied = true;
		return inp;
	}
	void Text_input::insert_text(std::string, unsigned int pos) {

	}
	void Text_input::erase(unsigned int begin, unsigned int end) {

	}
	unsigned int Text_input::end() {
		return 0;
	}
	cursor_concreat_info Text_input::get_precise_cursor() {
		return LeText->cursor_pos_from_index(InfoCU.CursorPosition);
	}
	bool WritingRestriction::test(std::wstring str)
	{
		if (only_int) {
			if (str.size() == 0)return true;
			try { return std::to_wstring(std::stoi(str)) == str; }//check bay two int/wstring converstion if the result is still the same
			catch (const std::exception &e) { std::cout << "int entered is too big sorry... OU il n'y avais pas de int dans la chaine" << std::endl; return false; }//catch out of range fo too big ints...
		}
		return true;
	}
}