#pragma once
#include"G_inc.h"
namespace ONIGIRIX_GUI {
	class Design__ImgDisplay {
	public:
		int btn_bg_color=0xbbbbbb;
		int btn_hover_bg_color = 0xcccccc;
		int btn_border_width = -1;
		int btn_border_color = 0;
		int scroll_color_1 = 0;
		int scroll_color_2 = 0xbbbbbb;


		std::string btn_full_h = "images/option_button/full_height.png";
		std::string btn_full_w = "images/option_button/full_width.png";

		//less important
		int btn_bg_opacity=1;
	};

	class ImgDisplay :public Widget {
	public:

		ImgDisplay(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, std::string img , Design__ImgDisplay design= Design__ImgDisplay() ,int w1=10, int w2 = 10);
		void set_img(std::string);
		int get_zoom();
		void set_zoom(int z);
		int get_img_h();
		int get_img_w();

	private:

		void on_zoom_change();
		std::string image;
		int zoom = 1;
		int img_base_height = 0;
		int img_base_width = 0;
		Rectangle* img;
		Design__ImgDisplay _design;

	};
}