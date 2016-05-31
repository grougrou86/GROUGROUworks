#pragma once
//les instace de rectangle et les sous underwindow aussi doivent être crée avec la fenêtre 
namespace ONIGIRIX_GUI {
	class UnderWindow : public Relative
	{

	public:

		Rectangle* background;

		UnderWindow(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, int w1 = 20, int w2 = 20);

		void Refresh();

		virtual ~UnderWindow();

		Scroll* vertical;
		Scroll* horizontal;

		Fenetre* ma_fenetre;
		bool vertical_on = false, horizontal_on = false;


		int n_offset_x = 0;
		int n_offset_y = 0;

		virtual int rel_x();
		virtual int rel_y();
		virtual int rel_w();
		virtual int rel_h();

		Relative* RelativeElement = NULL;

		Rectangle* addRectangle(Rectangle* monRectangle);
		Rectangle* removeRectangle(Rectangle* monRectangle);
		UnderWindow* addUnderWindow(UnderWindow* UnderWindow);
		UnderWindow* removeUnderWindow(UnderWindow* UnderWindow);

		bool hide_out = true;
		bool x_scroll = true;
		bool y_scroll = true;

		void set_x(Mesure);
		void set_y(Mesure);
		void set_width(Mesure);
		void set_height(Mesure);

		int max_h = 0;
		int max_w = 0;

		Mesure get_x();
		Mesure get_y();
		Mesure get_width();
		Mesure get_height();

		Rectangle_clip* own_clip;
		void add_auto_clip(Rectangle_clip*);
		void remove_auto_clip(Rectangle_clip*);
		std::vector<Rectangle_clip*> auto_p_clips;
		virtual void deleter();//ne pas utiliser pour supp

		int get_offset_x();
		int get_offset_y();
		void set_offset_x(int);
		void set_offset_y(int);
		void activate_offset(bool);
		bool is_offset_activated();
		void activate_absolute(bool);
		bool is_absolute_activated();

	protected:

		bool deleter_made = false;

	private:

		bool active_absolute = false;
		bool active_offset = true;
		int offset_x = 0;
		int offset_y = 0;

		bool debug = false;

		Mesure _x;
		Mesure _y;
		Mesure _w;
		Mesure _h;

		int _w1, _w2;

		std::vector<UnderWindow*> Underwindows;
		std::vector<Rectangle*> Rectangles;

	};

}
template <typename T>
int max_h_function(std::vector<T*> A) {
	int max = 0,sub;
	for (T* a : A) {
		if(!a->is_absolute_activated()) {
			sub = a->get_y().totalPX(a->RelativeElement->rel_h()) + a->get_height().totalPX(a->RelativeElement->rel_h());
			if (sub > max)max = sub;
		}
	}
	return max;
}
template <typename T>
int max_w_function(std::vector<T*> A) {
	int max = 0, sub;
	for (T* a : A) {
		if (!a->is_absolute_activated()) {
			sub = a->get_x().totalPX(a->RelativeElement->rel_w()) + a->get_width().totalPX(a->RelativeElement->rel_w());
			if (sub > max)max = sub;
		}
	}
	return max;
}
