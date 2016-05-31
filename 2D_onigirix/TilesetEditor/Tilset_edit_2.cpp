#include "G_inc.h"
#include "all_frame_include.h"
#include "useful-fct.h"

using namespace ONIGIRIX_GUI;


void Tilset_edit_2(ONIGIRIX_GUI::Fenetre* f) {

	f->resize(800, 600);
	f->titre = "Tilset_editor";

	auto M = new MultiMenu(f, Mesure(5, 0), Mesure(30, 0), Mesure(-10, 100), Mesure(32, 0));
	M->add_value(L"OUTPUT");
	M->add_value(L"bonjour");
	M->add_value(L"aurevoir");

		//---------------------//
		//---button from top---//
		//---------------------//
	//open
	Rectangle* opener = new Rectangle(f,Mesure(-325, 100), Mesure(5, 0), Mesure(60, 0), Mesure(30, 0));
	opener->set_bgopacity(1);
	opener->set_bgcolor(0xffffff);
	opener->set_text(L"open");
	opener->set_z_index(10);
	opener->set_font_size(20);
	opener->set_alignement(center);
	opener->set_font("calibri");
	opener->set_bgcolor(0xbbbbbb);
	opener->set_etat("hover");
	opener->set_bgcolor(0xffffff);
	opener->set_etat("default");
	//save
	Rectangle* saver = new Rectangle(f, Mesure(-250, 100), Mesure(5, 0), Mesure(60, 0), Mesure(30, 0));
	saver->set_bgopacity(1);
	saver->set_bgcolor(0xffffff);
	saver->set_text(L"save");
	saver->set_z_index(10);
	saver->set_font_size(20);
	saver->set_alignement(center);
	saver->set_font("calibri");
	saver->set_bgcolor(0xbbbbbb);
	saver->set_etat("hover");
	saver->set_bgcolor(0xffffff);
	saver->set_etat("default");
	//export
	Rectangle* exporter = new Rectangle(f, Mesure(-175, 100), Mesure(5, 0), Mesure(60, 0), Mesure(30, 0));
	exporter->set_bgopacity(1);
	exporter->set_bgcolor(0xffffff);
	exporter->set_text(L"export");
	exporter->set_z_index(10);
	exporter->set_font_size(20);
	exporter->set_alignement(center);
	exporter->set_font("calibri");
	exporter->set_bgcolor(0xbbbbbb);
	exporter->set_etat("hover");
	exporter->set_bgcolor(0xffffff);
	exporter->set_etat("default");
	//goback
	Rectangle* acceuiler = new Rectangle(f, Mesure(-400, 100), Mesure(5, 0), Mesure(60, 0), Mesure(30, 0));
	acceuiler->set_bgopacity(1);
	acceuiler->set_bgcolor(0xffffff);
	acceuiler->set_text(L"acceuil");
	acceuiler->set_z_index(10);
	acceuiler->set_font_size(20);
	acceuiler->set_alignement(center);
	acceuiler->set_font("calibri");
	acceuiler->set_bgcolor(0xbbbbbb);
	acceuiler->set_etat("hover");
	acceuiler->set_bgcolor(0xffffff);
	acceuiler->set_etat("default");
	acceuiler->data->rebuild_funk_data["rebuild"] = Acceuil;
	acceuiler->set_click_function(redirect_data);

	creat_window_decoration(f);

}