#include "all_frame_include.h"
#include "G_inc.h"
#include "useful-fct.h"

using namespace ONIGIRIX_GUI;

void ProjectConfig(Fenetre* fn2) {
	fn2->resize(430, 500);
	fn2->titre = "Configuration du project";
	
	Rectangle* r1 = new Rectangle(fn2, Mesure(5, 0), Mesure(40, 0), Mesure(-5, 50), Mesure(5, 0));
	r1->set_text(L"Largeur");
	r1->set_font("keifont");
	r1->set_font_color(0x000000);
	r1->set_font_size(30);
	r1->set_alignement(center);

	Rectangle* r2 = new Text_input(fn2,"keifont", Mesure(5, 50), Mesure(40, 0), Mesure(-15, 50), Mesure(5, 0),WritingRestriction(true));
	r2->set_text(L"16");
	r2->set_font("MS");
	r2->set_font_color(0x222222);
	r2->set_borderwidth(1);
	r2->set_font_size(30);
	r2->set_alignement(center);

	Rectangle* r3 = new Rectangle(fn2,Mesure(5, 0), Mesure(80, 0), Mesure(-5, 50), Mesure(5, 0));
	r3->set_text(L"Hauteur");
	r3->set_font("keifont");
	r3->set_font_color(0x000000);
	r3->set_font_size(30);
	r3->set_alignement(center);

	Rectangle* r4 = new Text_input(fn2,"keifont", Mesure(5, 50), Mesure(80, 0), Mesure(-15, 50), Mesure(5, 0), WritingRestriction(true));
	r4->set_text(L"16");
	r4->set_font("MS");
	r4->set_font_color(0x222222);
	r4->set_borderwidth(1);
	r4->set_font_size(30);
	r4->set_alignement(center);

	Rectangle* r5 = new Rectangle(fn2,Mesure(5, 0), Mesure(120, 0), Mesure(-5, 50), Mesure(5, 0));
	r5->set_text(L"Résolution (px)");
	r5->set_font("keifont");
	r5->set_font_color(0x000000);
	r5->set_font_size(25);
	r5->set_alignement(center);

	Rectangle* r6 = new Text_input(fn2,"keifont", Mesure(5, 50), Mesure(120, 0), Mesure(-15, 50), Mesure(5, 0), WritingRestriction(true));
	r6->set_text(L"32");
	r6->set_font("MS");
	r6->set_font_color(0x222222);
	r6->set_borderwidth(1);
	r6->set_font_size(30);
	r6->set_alignement(center);

	Rectangle* r7 = new Rectangle(fn2,Mesure(5, 0), Mesure(160, 0), Mesure(-10, 100), Mesure(5, 0));
	r7->set_text(L"Titre");
	r7->set_font("keifont");
	r7->set_font_color(0x000000);
	r7->set_font_size(25);
	r7->set_alignement(center);

	
	auto t = new Textarea(fn2, Mesure(10, 0), Mesure(190, 0), Mesure(-20, 100), Mesure(100, 0));

	Rectangle* r8 = new Rectangle(fn2,Mesure(5, 0), Mesure(300, 0), Mesure(-10, 100), Mesure(5, 0));
	r8->set_text(L"Crédits");
	r8->set_font("keifont");
	r8->set_font_color(0x000000);
	r8->set_font_size(25);
	r8->set_alignement(center);


	auto t2 = new Textarea(fn2, Mesure(10, 0), Mesure(340, 0), Mesure(-20, 100), Mesure(100, 0));

	Rectangle* r20 = new Rectangle(fn2,Mesure(0, 33-15), Mesure(450, 0), Mesure(0, 30), Mesure(5, 0));
	r20->set_text(L"Retour");
	r20->set_font("keifont");
	r20->set_font_color(0);
	r20->set_font_size(25);
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

	Rectangle* r21 = new Rectangle(Mesure(0, 66-15), Mesure(450, 0), Mesure(0, 30), Mesure(5, 0));
	r21->set_text(L"Valider");
	r21->set_font("keifont");
	r21->set_font_color(0);
	r21->set_font_size(25);
	r21->set_alignement(center);
	r21->set_bgopacity(1);
	r21->set_bgcolor(0xdddddd);
	r21->set_borderwidth(1);
	r21->set_etat("hover");
	r21->set_bgcolor(0x000000);
	r21->set_font_color(0xffffff);
	r21->set_etat("default");
	r21->data->rebuild_funk_data["rebuild"] = Tilset_edit_2;
	r21->set_click_function(redirect_data);

	creat_window_decoration(fn2, false, false, false, false);
}