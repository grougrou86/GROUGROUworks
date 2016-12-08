#include "G_inc.h" 
#include "window-decoration.h"
#include <iostream>
#include <memory>
namespace ONIGIRIX_GUI {
	void set_text_to_fps(Rectangle* r) {
		r->set_text(L"" + std::to_wstring(r->ma_loop->fps));
	}
	void top_fct_1(Rectangle* r) {
		SDL_SetRelativeMouseMode(SDL_TRUE);
		r->data->int_data["x"] = r->ma_fenetre->Mousex;
		r->data->int_data["y"] = r->ma_fenetre->Mousey;
	}
	void top_fct_3(Rectangle* r) {
		SDL_SetRelativeMouseMode(SDL_FALSE);
		SDL_WarpMouseInWindow(r->ma_fenetre->get_DisplayContext().get_SDL_Window(), r->data->int_data["x"], r->data->int_data["y"]);
	}
	void top_fct_2(Rectangle* r) {
		int x(0), y(0);
		x += r->ma_fenetre->DMousex + r->ma_fenetre->get_x();
		y += r->ma_fenetre->DMousey + r->ma_fenetre->get_y();
		if (r->ma_fenetre->DMousex != 0 && r->ma_fenetre->DMousey != 0)r->ma_fenetre->deplace(x, y);
	}
	void rsz_fct_1(Rectangle* r) {
		SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	void rsz_fct_3(Rectangle* r) {
		SDL_SetRelativeMouseMode(SDL_FALSE);
	}
	void rsz_fct_2(Rectangle* r) {
		int x(0), y(0);

		x = r->ma_fenetre->get_width();
		y = r->ma_fenetre->get_height();
		if (x + r->ma_fenetre->DMousex > 300)x += r->ma_fenetre->DMousex;
		if (y + r->ma_fenetre->DMousey > 300)y += r->ma_fenetre->DMousey;
		r->ma_fenetre->resize(x, y);


	}
	void close_on_click(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
		f->close();
	}//fait rien ^.^
	void hide_on_click(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
		f->hide();
	}//fait rien ^.^
	void max_on_click(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
		if (!f->is_max()) f->maximize();
		else  f->unmaximize();
	}//fait rien ^.^
	void full_on_click(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
		if (!f->is_full()) { f->fullScreen(); }
		else { f->unfullScreen(); }
	}//fait rien ^.^

	void creat_window_decoration(Fenetre*& f, bool full, bool big, bool min, bool resizable) {

		etat* pointer_full(new etat);
		etat* pointer_max(new etat);
		f->clearatclean_etat.push_back(pointer_full);
		f->clearatclean_etat.push_back(pointer_max);

		pointer_full->nom = "fullScreen";
		f->add_full_pointer(pointer_full);
		pointer_max->nom = "maximized";
		f->add_max_pointer(pointer_max);

		callback_etat dep_fe;
		dep_fe.nom = "hold";
		dep_fe.on_while = top_fct_2;
		dep_fe.on_start = top_fct_1;
		dep_fe.on_end = top_fct_3;

		callback_etat rsz_fe;
		rsz_fe.nom = "hold";
		rsz_fe.on_while = rsz_fct_2;
		rsz_fe.on_start = rsz_fct_1;
		rsz_fe.on_end = rsz_fct_3;

		Rectangle* r = f->addRectangle(Rectangle(Mesure(-1, 0), Mesure(-1, 0), Mesure(2, 100), Mesure(31, 0)));
		r->set_bgcolor(0x000000);
		r->set_bgopacity(1);
		r->stop_propagation = true;
		r->add_callback_etat(dep_fe);
		r->set_z_index(2);

		Rectangle* fps = f->addRectangle(Rectangle(Mesure(1, 0), Mesure(0,0), Mesure(100, 0), Mesure(20, 0)));
		fps->set_font("calibri");
		fps->set_font_size(9);
		fps->set_text("????");
		fps->set_font_color(0xffffff);
		fps->set_alignement(left);
		fps->everyframe_fct = set_text_to_fps;
		fps->set_z_index(20);

		Rectangle* r10 = f->addRectangle(Rectangle(Mesure(0, 0), Mesure(0, 0), Mesure(0, 100), Mesure(0, 100)));
		r10->set_borderwidth(-1);
		r10->set_bordercolor(0x444444);
		r10->set_z_index(2);

		Rectangle* r6 = f->addRectangle(Rectangle(Mesure(1, 0), Mesure(1, 0), Mesure(-2, 100), Mesure(-2, 100)));
		r6->set_borderwidth(-1);
		r6->set_bordercolor(0x222222);
		r6->set_z_index(2);
		Rectangle* r11 = f->addRectangle(Rectangle(Mesure(2, 0), Mesure(2, 0), Mesure(-4, 100), Mesure(-4, 100)));
		r11->set_borderwidth(-1);
		r11->set_bordercolor(0x111111);
		r11->set_z_index(2);
		Rectangle* r12 = f->addRectangle(Rectangle(Mesure(5, 0), Mesure(5, 0), Mesure(-10, 100), Mesure(-10, 100)));
		r12->set_borderwidth(5);
		r12->set_bordercolor(0x000000);
		r12->set_z_index(2);


		Rectangle* r7 = f->addRectangle(Rectangle(Mesure(20, 0), Mesure(5, 0), Mesure(0, 200), Mesure(30, 0)));
		r7->set_font("calibri");
		r7->set_font_size(19);
		r7->set_text(f->titre);
		r7->set_font_color(0xffffff);
		r7->set_alignement(left);
		r7->set_z_index(2);


		Rectangle* r2 = f->addRectangle(Rectangle(Mesure(-25, 100), Mesure(5, 0), Mesure(20, 0), Mesure(20, 0)));
		r2->set_bg_img("images/top_button/croix.png");
		r2->set_bgopacity(1);
		r2->set_bgcolor(0xdddddd);
		r2->set_etat("hover");
		r2->set_bgcolor(0xffffff);
		r2->set_etat("default");
		r2->set_z_index(2);
		r2->set_click_function(close_on_click);
		r2->stop_propagation = true;

		if (full) {
			Rectangle* r3 = f->addRectangle(Rectangle(Mesure(-50, 100), Mesure(5, 0), Mesure(20, 0), Mesure(20, 0)));
			r3->set_bg_img("images/top_button/full.png");
			r3->set_bgopacity(1);
			r3->set_bgcolor(0xdddddd);
			r3->set_click_function(full_on_click);
			r3->add_etat(pointer_full, 1);
			r3->set_etat("fullScreen");
			r3->set_bg_img("images/top_button/un-full.png");
			r3->set_etat("hover");
			r3->set_bgcolor(0xffffff);
			r3->set_etat("default");
			r3->stop_propagation = true;
			r3->set_z_index(2);
		}
		if (big) {
			Rectangle* r8 = f->addRectangle(Rectangle(Mesure(-75, 100), Mesure(5, 0), Mesure(20, 0), Mesure(20, 0)));
			r8->set_bg_img("images/top_button/grand.png");
			r8->set_bgopacity(1);
			r8->set_bgcolor(0xdddddd);
			r8->set_etat("hover");
			r8->set_bgcolor(0xffffff);
			r8->set_etat("default");
			r8->set_z_index(2);
			r8->set_click_function(max_on_click);
			r8->stop_propagation = true;
		}
		if (min) {
			Rectangle* r5 = f->addRectangle(Rectangle(Mesure(-100, 100), Mesure(5, 0), Mesure(20, 0), Mesure(20, 0)));
			r5->set_bg_img("images/top_button/moin.png");
			r5->set_bgopacity(1);
			r5->set_bgcolor(0xdddddd);
			r5->set_etat("hover");
			r5->set_bgcolor(0xffffff);
			r5->set_etat("default");
			r5->set_click_function(hide_on_click);
			r5->stop_propagation = true;
			r5->set_z_index(2);
		}
		if (resizable) {
			Rectangle* r9 = f->addRectangle(Rectangle(Mesure(-20, 100), Mesure(-20, 100), Mesure(20, 0), Mesure(20, 0)));
			r9->set_bg_img("images/top_button/resize.png");
			r9->set_etat("default");
			r9->add_callback_etat(rsz_fe);
			r9->add_etat(pointer_full, 1);
			r9->add_etat(pointer_max, 1);
			r9->stop_propagation = true;
			r9->set_etat("fullScreen");
			r9->set_x(Mesure(100, 1));
			r9->set_y(Mesure(100, 1));
			r9->set_etat("maximized");
			r9->set_x(Mesure(1, 100));
			r9->set_y(Mesure(1, 100));
			r9->set_z_index(2);
		}
	}
}