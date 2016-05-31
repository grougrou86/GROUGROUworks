#include"useful-fct.h"
#include"G_inc.h"
namespace ONIGIRIX_GUI {
	void redirect_data(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
		r->ma_fenetre->rebulid_funk = r->data->rebuild_funk_data["rebuild"];
		r->ma_fenetre->vider();
	}
	void relay_click(Rectangle* r, Fenetre* f, SDL_mainLoop* l, int x, int y) {
		r->data->rect_data["relRec"]->onclick_fct(x - r->data->int_data["rel-Offset-x"], y - r->data->int_data["rel-Offset-y"]);
		r->data->rect_data["relRec"]->set_etat_activity(true, "active");
	}
}