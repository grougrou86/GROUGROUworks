#include "G_inc.h"
#include "all_frame_include.h"
#include "useful-fct.h"

using namespace ONIGIRIX_GUI;

struct staff_member {
	std::wstring nom;
	std::wstring description;
	std::string img;
};
void Staff(Fenetre* fn2) {

	fn2->resize(370, 500);
	fn2->titre = "STAFF";

	std::vector<staff_member> membre = std::vector<staff_member>({
		staff_member({ L"???????",L"......................?!?!?!?!?!?","images/me-fin.png" }),
		staff_member({ L"Grougrou",L"Codeur c++, Codeur de la gui, Codeur de l'app. Je code pour mes loisirs. En cas de bug n' hésitez pas à me contacter via le site de onigirix : http://www.onigirix.com","images/me-fin.png" })
	});
	UnderWindow* u1 = new UnderWindow(fn2, Mesure(10, 0), Mesure(30, 0), Mesure(-15, 100), Mesure(-30, 100), 10, 10);

	int h1 = 100, htot = 200;
	int y_0=10;
	for (auto m : membre) {
		UnderWindow* u = new UnderWindow(fn2, Mesure(0, 0), Mesure(y_0+h1, 0), Mesure(0, 100), Mesure(htot-h1, 0), 10, 10);

		Rectangle* r = fn2->addRectangle(Rectangle(Mesure(h1, 0), Mesure(y_0+20 , 0), Mesure(-h1, 100), Mesure(h1, 0)));
		r->set_text(m.nom);
		r->set_font_size(50);
		r->set_alignement(center);
		r->set_font("MS");
		r->debug = true;
		Rectangle* r2 = fn2->addRectangle(Rectangle(Mesure(0, 0), Mesure(y_0 , 0), Mesure(h1,0 ), Mesure(h1, 0)));
		r2->set_bg_img(m.img);
		Rectangle* r3 = fn2->addRectangle(Rectangle(Mesure(0, 0), Mesure(0, 0), Mesure(0, 100), Mesure(5, 0)));
		r3->set_text(m.description);
		r3->set_font_size(22);
		r3->set_alignement(left);
		r3->set_font("keifont");
		r3->debug = true;
		u1->addRectangle(r);
		u1->addRectangle(r2);
		u->addRectangle(r3);
		y_0 += htot;
		u1->addUnderWindow(u);
	}
	Rectangle* r20 = fn2->addRectangle(Rectangle(Mesure(0, 20), Mesure(y_0+10, 0), Mesure(0, 60), Mesure(5, 0)));
	r20->set_text(L"Acceuil");
	r20->set_font("keifont");
	r20->set_font_color(0);
	r20->set_font_size(30);
	r20->set_alignement(center);
	r20->set_bgopacity(1);
	r20->set_bgcolor(0xdddddd);
	r20->set_borderwidth(1);
	r20->set_etat("hover");
	r20->set_bgcolor(0x000000);
	r20->set_font_color(0xffffff);
	r20->set_etat("default");
	r20->data->rebuild_funk_data["rebuild"] = Acceuil;
	r20->set_click_function(redirect_data);
	
	
	Rectangle* r21 = fn2->addRectangle(Rectangle(Mesure(0, 0), Mesure(y_0+60, 0), Mesure(0, 0), Mesure(0, 0)));
	u1->addRectangle(r20);
	u1->addRectangle(r21);

	creat_window_decoration(fn2, false, false, false, false);
}