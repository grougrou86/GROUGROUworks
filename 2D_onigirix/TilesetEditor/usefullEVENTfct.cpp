#include"G_inc.h"
#include"usefullEVENTfct.h"
namespace ONIGIRIX_GUI {
	//as "everyframe_fct" function set rectangle to its background size when the background is loaded !
	void AUTObgSIZE(Rectangle* r) {
		auto bg = (r->get_bg_from_name(r->get_bg_img()));
		if (bg->get_height() > 0 && bg->get_width() > 0) {
			r->set_height(Mesure(bg->get_height(), 0));
			r->set_width(Mesure(bg->get_width(), 0));
			r->everyframe_fct = NULL;
		}
	}
}