#include"ALL_WIDGET.h"
#include"G_inc.h"

namespace ONIGIRIX_GUI {

	namespace IMGDISPLAY_CLICK_FCT {//to avoid disrupting overclasses

		void fit_height(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {

		}
		void fit_width(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {

		}
		void set_img_height(Rectangle*r, int value) {

		}
	}

	ImgDisplay::ImgDisplay(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, std::string _img, Design__ImgDisplay design, int w1 , int w2):Widget(f, x, y, w, h, w1, w2),_design(design){
		
		img = W_add(new Rectangle(f));
		img->set_bg_img(_img);
		img->draw(f);
		img->set_width(Mesure(img->img_dim_w, 0));
		img->set_height(Mesure(img->img_dim_h, 0));

		auto btn1 = W_add( new Rectangle(f, Mesure(20, 0), Mesure(-60, 100), Mesure(40, 0), Mesure(40, 0)));
		btn1->activate_offset(false);
		btn1->activate_absolute(true);
		btn1->set_bg_img(_design.btn_full_w);
		btn1->set_click_function(IMGDISPLAY_CLICK_FCT::fit_width);
		btn1->set_bgopacity(_design.btn_bg_opacity);
		btn1->set_borderwidth(_design.btn_border_width);
		btn1->set_bordercolor(_design.btn_border_color);
		btn1->set_bgcolor(_design.btn_bg_color);
		btn1->set_etat("hover");
		btn1->set_bgcolor(_design.btn_hover_bg_color);
		btn1->set_etat("default");

		auto btn2 = W_add( new Rectangle(f, Mesure(80, 0), Mesure(-60, 100), Mesure(40, 0), Mesure(40, 0)));
		btn2->activate_offset(false);
		btn2->activate_absolute(true);
		btn2->set_bg_img(_design.btn_full_h);
		btn2->set_click_function(IMGDISPLAY_CLICK_FCT::fit_height);
		btn2->set_bgopacity(_design.btn_bg_opacity);
		btn2->set_borderwidth(_design.btn_border_width);
		btn2->set_bordercolor(_design.btn_border_color);
		btn2->set_bgcolor(_design.btn_bg_color);
		btn2->set_etat("hover");
		btn2->set_bgcolor(_design.btn_hover_bg_color);
		btn2->set_etat("default");

		auto scroll = W_add(new Scroll(f, Mesure(100, 0), Mesure(10, 0), Mesure(10, 0), Mesure(20, 0), Mesure(-100, 100), false));
		(*scroll)[1]->set_borderwidth(10);
		scroll->set_value(0.3);
	}
	void ImgDisplay::set_img(std::string) {

	}
	int ImgDisplay::get_zoom() {
		return zoom;
	}
	void ImgDisplay::set_zoom(int z) {

	}
	void ImgDisplay::on_zoom_change() {

	}
	int ImgDisplay::get_img_h() {
		return img_base_height;
	}
	int ImgDisplay::get_img_w() {
		return img_base_width;
	}

}