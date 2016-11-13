#include"GlypsTest.h"
#include "G_inc.h"
#include"FontGlypsSurface.h"
#include"all_frame_include.h"

using namespace ONIGIRIX_GUI;

void GlypsTest(ONIGIRIX_GUI::Fenetre*f) {
	

	std::cout << "Start" << std::endl;
	//std::array < int, std::numeric_limits<wchar_t>::max() - std::numeric_limits<wchar_t>::min() + 1 > Characters;
	//Characters[std::numeric_limits<wchar_t>::max()];
	//Police("font/consola.ttf").get_font(19);
	//FontMapper::Glyps exG = FontMapper::GetGlypsSurface({ L"font/Arial Unicode MS.ttf",30 });
	
	//BasicImage* exI=new BasicImage();
	//SDL_S_texture* Tex1 =new SDL_S_texture(exG.surface);
	//SDL_H_texture* Tex2  = new SDL_H_texture(SDL_CreateTextureFromSurface(f->get_screen_render(),exG.surface));
	//exI->set_SOFTWARE(Tex1);
	//exI->set_SDL_TEXTURE(Tex2);

	// ATTTENTION BIG MEMORY LEAK TO FIND !!!!

	GlypsImage* IMGglyps = new GlypsImage({ L"font/Arial Unicode MS.ttf" ,30 }, f->get_screen_render());
	//IMGglyps->get_SDL_TEXTURE();
	//delete IMGglyps;
	auto W = new Widget(f, Mesure(0, 0), Mesure(30, 0), Mesure(0, 100), Mesure(-30, 100));

	Rectangle* r21 = W->W_add(new Rectangle(f,Mesure(0, 0), Mesure(0, 0), Mesure(IMGglyps->get_width(), 0), Mesure(IMGglyps->get_height(), 0)));
	r21->add_bg("char", IMGglyps);
	r21->set_bg_img("char");
	r21->set_bgcolor(0x000000);
	r21->set_bgopacity(1);

	
	f->titre = "Writing Test";

	Rectangle* r20 = f->addRectangle(Rectangle(Mesure(0, 20), Mesure(-50, 100), Mesure(0, 60), Mesure(5, 0)));
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
	

	creat_window_decoration(f);

}