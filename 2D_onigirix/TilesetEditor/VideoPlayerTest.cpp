#include"VideoPlayerTest.h"
#include "all_frame_include.h"
#include "G_inc.h"

using namespace ONIGIRIX_GUI;


void Video_Player_Test(ONIGIRIX_GUI::Fenetre* f) {
	f->resize(800, 800);
	f->titre = "TESTE";
	auto W = new UnderWindow(f, Mesure(0, 0), Mesure(30, 0), Mesure(0, 100), Mesure(-30, 100));
	auto I = new VideoWidget(f, Mesure(15, 0), Mesure(10, 0), Mesure(-30, 100), Mesure(-100, 100), "Z:\\cpp\\visual_studio\\GROUGROUengine\\video\\exemple.mkv");
	auto I2 = new VideoWidget(f, Mesure(15, 0), Mesure(0, 100), Mesure(-30, 100), Mesure(-100, 100), "Z:\\cpp\\visual_studio\\GROUGROUengine\\video\\exemple2.mkv");
	W->addUnderWindow(I);
	W->addUnderWindow(I2);

	//auto T = new Textarea(f, Mesure(15, 0), Mesure(100, 0), Mesure(-30, 100), Mesure(-200, 100));
	//T->set_value(L"Type  here \n..爱(愛)...\nLorem é ipsum dolor sit amet, consectetur adipiscing Lorem é ipsum dolor sit amet, consectetur adipiscing Lorem é ipsum dolor sit amet, consectetur adipiscing 敬語は人間のなんらかの意味の上下関係の認識を\n表現する語彙の体系である .");


	Rectangle* r20 = f->addRectangle(Rectangle(Mesure(0, 20), Mesure(-50, 200), Mesure(0, 60), Mesure(5, 0)));
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
	Rectangle* r21 = f->addRectangle(Rectangle(Mesure(0, 20), Mesure(00, 200), Mesure(0, 0), Mesure(0, 0)));

	W->addRectangle(r20);
	W->addRectangle(r21);



	creat_window_decoration(f);
}