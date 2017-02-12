#include "all_frame_include.h"
#include "G_inc.h"
#include "useful-fct.h"

using namespace ONIGIRIX_GUI;

struct boutton_clickFCT_acc {
	std::wstring nom;
	rebuild_funk fct;
};

void Acceuil(Fenetre* fn2) {
	fn2->resize(250, 188);
	fn2->titre = "Tileset Editor 3.0";
	std::vector<boutton_clickFCT_acc> button= std::vector<boutton_clickFCT_acc>({
		boutton_clickFCT_acc({ L"Ouvrir un project",Video_Player_Test }),
		boutton_clickFCT_acc({ L"Tileset Editor 2",ProjectConfig }),
		boutton_clickFCT_acc({ L"Display Engine Test",DisplayEngineTest }),
		boutton_clickFCT_acc({ L"Credit",Staff }),
		boutton_clickFCT_acc({ L"Test",Test_frame })
	});
	
	Rectangle* old_r=NULL;
	UnderWindow* u = new UnderWindow(fn2, Mesure(5, 0), Mesure(100, 0), Mesure(-10, 100), Mesure(-105, 100),10,10);
	for (auto b : button) {
		Rectangle* r = new Rectangle(fn2,Mesure(0, 0), Mesure(2, 0), Mesure(0, 100), Mesure(0, 0));
		r->set_bgopacity(1);
		r->set_bgcolor(0xffffff);
		r->set_text(b.nom);
		r->set_font_size(25);
		r->set_alignement(center);
		r->set_font("MS");
		r->set_bgcolor(0xbbbbbb);
		r->set_etat("hover");
		r->set_bgcolor(0x222222);
		r->set_font_color(0xffffff);
		r->set_etat("default");
		r->set_borderwidth(2);
		r->set_bordercolor(0);
		r->stop_propagation = true;
		if (b.fct != NULL) {
			r->data->rebuild_funk_data["rebuild"] = b.fct;
			r->set_click_function(redirect_data);
		}
		u->addRectangle(r);
		if (old_r != NULL) { old_r->draw(fn2); r->set_y(old_r->get_height() + old_r->get_y() + Mesure(2,0)); }

		old_r = r;
	}
	Rectangle* r20 = new Rectangle(fn2,Mesure(-30, 0), Mesure(40, 0), Mesure(0, 100), Mesure(5, 0));
	r20->set_text(L"Onigirix");
	r20->set_font("optimus");
	r20->set_font_color(0xff0000);
	r20->set_font_size(44);
	r20->set_alignement(center);

	Rectangle* r21 = new Rectangle(fn2,Mesure(0, 72), Mesure(40, 0), Mesure(62, 0), Mesure(52, 0));
	r21->set_bg_img("images/onigirix.png");


	creat_window_decoration(fn2,false,false,false,false);
}