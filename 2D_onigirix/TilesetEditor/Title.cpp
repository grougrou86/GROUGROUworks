
#include "G_inc.h"
#include "tinyfiledialogs.h"

#include "all_frame_include.h"
#define WINDOWS
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#define changedire _chdir
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#define changedire chdir
#endif

void click_load_file(ONIGIRIX_GUI::Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return ;
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	const char* link = tinyfd_openFileDialog(
		"Importez des Scans", // ""
		"", // ""
		0, // 0
		NULL, // NULL or {"*.jpg","*.png"}
		NULL, // NULL or "image files"
		1);
	std::cout << link <<" "<< cCurrentPath << std::endl;
	changedire(cCurrentPath);
}

void click_debut_5(Rectangle* r, Fenetre* f, SDL_mainLoop* l){
	r->ma_fenetre->rebulid_funk = list_serie;
	r->ma_fenetre->vider();
}
void click_para(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
	Fenetre* fn = l->addFenetre(Fenetre(500, 500, false));
	fn->add_police("calibri", "font/Calibri.ttf");
	fn->add_police("pixel", "font/Pixel.ttf");
	fn->add_police("optimus", "font/Optimus.ttf");

	fn->rebulid_funk = Parametres;

}
void Title_maker(Fenetre* fn2){

	fn2->titre = "";

	Rectangle* r1 = fn2->addRectangle(Rectangle(Mesure(0, 0), Mesure(0, 0), Mesure(0, 100), Mesure(0, 100)));
	r1->set_bgopacity(1);
	r1->set_bgcolor(0);

	Rectangle* r2 = fn2->addRectangle(Rectangle(Mesure(-100, 50), Mesure(-25, 50), Mesure(200, 0), Mesure(45, 0)));
	r2->set_bgopacity(1);
	r2->set_bgcolor(0xffffff);
	r2->set_text("SCAN");
	r2->set_font_size(51);
	r2->set_alignement(center);
	r2->set_font("calibri");
	r2->set_etat("hover");
	r2->set_bgcolor(0xbbbbbb);
	r2->set_etat("default");
	r2->set_click_function(click_debut_5);

	Rectangle* r3 = fn2->addRectangle(Rectangle(Mesure(-100, 50), Mesure(+30, 50), Mesure(200, 0), Mesure(45, 0)));
	r3->set_bgopacity(1);
	r3->set_bgcolor(0xffffff);
	r3->set_text("ANIME");
	r3->set_font_size(51);
	r3->set_alignement(center);
	r3->set_font("calibri");
	r3->set_etat("hover");
	r3->set_bgcolor(0xbbbbbb);
	r3->set_etat("default");

	Rectangle* r5 = fn2->addRectangle(Rectangle(Mesure(-100, 50), Mesure(+85, 50), Mesure(200, 0), Mesure(45, 0)));
	r5->set_bgopacity(1);
	r5->set_bgcolor(0xffffff);
	r5->set_text("IMPORT");
	r5->set_font_size(51);
	r5->set_alignement(center);
	r5->set_font("calibri");
	r5->set_etat("hover");
	r5->set_bgcolor(0xbbbbbb);
	r5->set_etat("default");
	r5->set_click_function(click_load_file);

	Rectangle* r4 = fn2->addRectangle(Rectangle(Mesure(-300, 50), Mesure(-100, 50), Mesure(600, 0), Mesure(45, 0)));
	r4->set_text("Manga Bibiliothèque");
	r4->set_font_size(51);
	r4->set_alignement(center);
	r4->set_font("optimus");
	r4->set_font_color(0xff0000);
	r4->set_etat("default");
	//r3->set_click_function(click_debut_5);

	Rectangle* r6 = fn2->addRectangle(Rectangle(Mesure(0, 0), Mesure(-30, 100), Mesure(-5, 100), Mesure(0, 30)));
	r6->set_text("paramètre");
	r6->set_font_size(21);
	r6->set_alignement(right);
	r6->set_font("calibri");
	r6->set_font_color(0xffffff);
	r6->set_etat("hover");
	r6->set_font_color(0xaaaaaa);
	r6->set_etat("default");
	r6->set_click_function(click_para);

	creat_window_decoration(fn2);

}

