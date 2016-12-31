// a faire :
/*
FULL UPDATE BAT SCRIPT
SILENT UPDATE
*/
#include "G_inc.h"
#include "tinyfiledialogs.h"
#include "all_frame_include.h"
//#include "xbrz/xbrz.h"
#define WINDOWS
#ifdef WINDOWS
#include <direct.h>
#include <vector>
#define GetCurrentDir _getcwd
#define changedire _chdir
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#define changedire chdir
#endif
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "fusioneur.h"
#include"parameters.h"
#include"savepng.h"
#include"save-to-file.h"
#include"useful-fct.h"

using namespace ONIGIRIX_GUI;

//int case_size = 48;
int to_copy_x = 0;
int to_copy_y = 0;
int case_size = 48;
std::string base_present_url = "images/intro.png";
fusion data_TOTAL(14, 14);
std::vector<std::vector<Rectangle*>> grille;
std::vector<Rectangle*> forclosing;
void carlet(Rectangle* r);
void full_recharge(Rectangle*r);
void click_on_next(Rectangle* r, int key) {

	if (key == SDLK_PAGEDOWN) {
		r->click_fct(r, r->ma_fenetre, r->ma_loop);
	}

}
void click_on_prev(Rectangle* r, int key) {

	if (key == SDLK_PAGEUP) {
		r->click_fct(r, r->ma_fenetre, r->ma_loop);
	}

}
void scroll_horizon(Rectangle* r, int key) {
	Scroll* s = r->data->scroll_data["scroll"];
	double ad = s->get_h2().totalPX(r->ma_fenetre->get_width()) / (double)s->get_h1().totalPX(r->ma_fenetre->get_width())*0.1;
	if (key == SDLK_RIGHT) { s->set_value(s->get_value() + ad); }
	if (key == SDLK_LEFT) { s->set_value(s->get_value() - ad); }

}
void scroll_horizon_p_m(Rectangle* r, int key) {
	Scroll* s = r->data->scroll_data["scroll"];
	double ad = 0.01002;
	if (key == SDLK_w) { s->set_value(s->get_value() + ad); }
	if (key == SDLK_q) { s->set_value(s->get_value() - ad); }

}
void scroll_vertical(Rectangle* r, int key) {
	Scroll* s = r->data->scroll_data["scroll"];
	double ad = s->get_h2().totalPX(r->ma_fenetre->get_height()) / (double)s->get_h1().totalPX(r->ma_fenetre->get_height())*0.1;
	if (key == SDLK_DOWN) { s->set_value(s->get_value() + ad); }
	if (key == SDLK_UP) { s->set_value(s->get_value() - ad); }

}
void deplacer_hold(Rectangle* lere) {
	lere->set_x(lere->get_x() + Mesure(lere->ma_fenetre->DMousex, 0));
	lere->set_y(lere->get_y() + Mesure(lere->ma_fenetre->DMousey, 0));
}
void scroll1_action(Rectangle* lere,int) {
	Rectangle* r = lere->data->rect_data["to_change"];
	r->set_y(Mesure(62, 0) + (-lere->data->scroll_data["scroll"]->get_value())*(r->get_height() - Mesure(r->ma_fenetre->get_height() - 82, 0)));
}
void scroll2_action(Rectangle* lere,int) {
	Rectangle* r = lere->data->rect_data["to_change"];
	r->set_x(Mesure(0, 0) + (-lere->data->scroll_data["scroll"]->get_value())*(r->get_width() - Mesure(r->ma_fenetre->get_width() - 20, 0)));

}
void scroll3_action(Rectangle* lere,int) {
	double zoom = pow(0.6 + lere->data->scroll_data["scroll"]->get_value(), 3);
	Mesure old_w = lere->data->rect_data["to_change"]->get_width();


	lere->data->rect_data["to_change"]->set_width(Mesure(zoom*lere->data->rect_data["to_change"]->img_dim_w, 0));
	lere->data->rect_data["to_change"]->set_height(Mesure(zoom*lere->data->rect_data["to_change"]->img_dim_h, 0));
	Mesure new_w = lere->data->rect_data["to_change"]->get_width();

	double zoom2 = new_w.totalPX(lere->ma_fenetre->get_width()) / (double)old_w.totalPX(lere->ma_fenetre->get_width());

	//std::cout << "zoom avant" << zoom2 << "--" << lere->data->rect_data["to_change"]->get_x().px << "_" << lere->data->rect_data["to_change"]->get_x().pc << std::endl;

	lere->data->rect_data["to_change"]->set_etat("default");
	Mesure old_x = lere->data->rect_data["to_change"]->get_x();
	Mesure old_y = lere->data->rect_data["to_change"]->get_y();
	Mesure dx = (zoom2)*(old_x - Mesure(0, 50));
	Mesure dy = (zoom2)*(old_y - Mesure(0, 50));

	lere->data->rect_data["to_change"]->set_x(dx + Mesure(0, 50));
	lere->data->rect_data["to_change"]->set_y(dy + Mesure(0, 50));
	//std::cout << "zoom apres" << zoom2 << "--"<<dx.px<<"_"<<dx.pc<<"_-_" << lere->data->rect_data["to_change"]->get_x().px << "_" << lere->data->rect_data["to_change"]->get_x().pc << std::endl;



}
void to_other_size_while(Rectangle* r) {
	r->data->int_data["resize_actual_frame"]--;
	double avancement = 1. - (double)r->data->int_data["resize_actual_frame"] / r->data->int_data["resize_frame"];
	r->set_x(r->data->mesure_data["bx"] - avancement*r->data->mesure_data["dx"]);
	r->set_y(r->data->mesure_data["by"] - avancement*r->data->mesure_data["dy"]);
	r->set_width(r->data->mesure_data["bw"] - avancement*r->data->mesure_data["dw"]);
	r->set_height(r->data->mesure_data["bh"] - avancement*r->data->mesure_data["dh"]);
	r->data->scroll_data["zoom_scroll"]->set_value(pow(r->get_width().px / (double)r->img_dim_w, 1. / 3.) - 0.6);
	//std::cout << avancement << "avancement" << std::endl;
}
void to_other_size_end(Rectangle* r) {

}
void click_to_max(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {

	Rectangle* treat = r->data->rect_data["to_zoom"];
	Mesure dx = treat->get_x() - (Mesure(0, 0));
	Mesure dy = treat->get_y() - (Mesure(30, 0));
	Mesure dw = treat->get_width() - Mesure(treat->ma_fenetre->get_width() - 20, 0);
	Mesure dh;
	//Mesure dh = treat->get_height()-(((double)treat->img_dim_h / (double)treat->img_dim_w)*(treat->get_width()-dw));
	treat->data->mesure_data["dx"] = dx;
	treat->data->mesure_data["dy"] = dy;
	treat->data->mesure_data["dw"] = dw;
	treat->data->mesure_data["dh"] = dh;
	treat->data->mesure_data["bx"] = treat->get_x();
	treat->data->mesure_data["by"] = treat->get_y();
	treat->data->mesure_data["bw"] = treat->get_width();
	treat->data->mesure_data["bh"] = treat->get_height();
	int frame = 15;
	treat->data->int_data["resize_frame"] = frame;
	treat->data->int_data["resize_actual_frame"] = frame;
	treat->data->scroll_data["zoom_scroll"] = r->data->scroll_data["zoom_scroll"];
	fct_duree lafct = { to_other_size_while, to_other_size_end, frame };
	treat->add_move_fnct(lafct);


}
void go_back_key_2(Rectangle* r, int key) {
	if (key == SDLK_BACKSPACE) {
		r->click_fct(r, r->ma_fenetre, r->ma_loop);
	}
}
void pos_controller(Rectangle* r) {
	if (r->get_width().totalPX(r->ma_fenetre->get_width()) > r->ma_fenetre->get_width() - 19) {
		r->data->int_data["x_mot"] = 1;
		Mesure difx = r->get_width() + r->get_x();
		if ((difx).totalPX(r->ma_fenetre->get_width()) < r->ma_fenetre->get_width() - 20) {
			r->set_x(Mesure(-20, 100) - r->get_width());
		}
		if ((r->get_x()).totalPX(r->ma_fenetre->get_width()) >0) {
			r->set_x(Mesure(0, 0));
		}
	}
	else {
		r->set_x(Mesure(0, 50) - 0.5*r->get_width());
		r->data->int_data["x_mot"] = 0;
	}
	if (r->get_height().totalPX(r->ma_fenetre->get_height()) > r->ma_fenetre->get_height() - 49) {
		r->data->int_data["y_mot"] = 1;
		Mesure dify = r->get_height() + r->get_y();
		if ((dify).totalPX(r->ma_fenetre->get_height()) < r->ma_fenetre->get_height() - 20) {
			r->set_y(Mesure(-20, 100) - r->get_height());
		}
		if ((r->get_y()).totalPX(r->ma_fenetre->get_height()) >62) {
			r->set_y(Mesure(62, 0));
		}
	}
	else {
		r->set_y(Mesure(0, 50) - 0.5*r->get_height());
		r->data->int_data["y_mot"] = 0;
	}

	if (r->data->int_data["y_mot"] == 1) {
		r->data->scroll_data["y_scroll"]->set_h2(Mesure(pow(r->ma_fenetre->get_height() - 62, 2) / r->get_height().totalPX(r->ma_fenetre->get_height()), 0));
		r->data->scroll_data["y_scroll"]->set_x(Mesure(-20, 100));
		r->data->scroll_data["y_scroll"]->set_value((Mesure(62, 0) - r->get_y()).totalPX(r->ma_fenetre->get_height()) / (double)(r->get_height() - Mesure(r->ma_fenetre->get_height() - 82, 0)).totalPX(r->ma_fenetre->get_height()));
	}
	else { r->data->scroll_data["y_scroll"]->set_x(Mesure(0, 110)); std::cout << "cache--1" << std::endl;}
	//(*(r->data->scroll_data["x_scroll"]))[0]->set_bgopacity(1);
	//(*(r->data->scroll_data["x_scroll"]))[1]->set_bgopacity(1);
	if (r->data->int_data["x_mot"] == 1) {
		r->data->scroll_data["x_scroll"]->set_h2(Mesure(pow(r->ma_fenetre->get_width() - 20, 2) / r->get_width().totalPX(r->ma_fenetre->get_width()), 0));
		r->data->scroll_data["x_scroll"]->set_y(Mesure(-20, 100));
		r->data->scroll_data["x_scroll"]->set_value((Mesure(0, 0) - r->get_x()).totalPX(r->ma_fenetre->get_width()) / (r->get_width() - Mesure(r->ma_fenetre->get_width() - 20, 0)).totalPX(r->ma_fenetre->get_width()));
		//std::cout << "cache-->"<<val1<<"-"<<val2<<"..."<< (*(r->data->scroll_data["x_scroll"]))[0]->get_y().px<<"/"<< (*(r->data->scroll_data["x_scroll"]))[0]->get_y().pc<<"***" << (*(r->data->scroll_data["x_scroll"]))[0]->get_x().px << "/" << (*(r->data->scroll_data["x_scroll"]))[0]->get_x().pc << std::endl;
	}
	else { r->data->scroll_data["x_scroll"]->set_y(Mesure(0, 110)); std::cout << "cache--2" << std::endl;}
	//if (!done_h)val2 = (*(r->data->scroll_data["x_scroll"]))[0]->get_bgopacity();
	//done_h = true;
	if (r->data->int_data["x_mot"] == 1 || r->data->int_data["y_mot"] == 1)r->data->rect_data["to_supp"]->set_bgopacity(1);
	else r->data->rect_data["to_supp"]->set_bgopacity(0);
}
void click_to_max2(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {

	Rectangle* treat = r->data->rect_data["to_zoom"];

	Mesure dh = treat->get_height() - Mesure(treat->ma_fenetre->get_height() - 50, 0);
	Mesure dw = treat->get_width() - (((double)treat->img_dim_w / (double)treat->img_dim_h)*(treat->get_height() - dh));


	Mesure dx = treat->get_x() + 0.5*(treat->get_width() - dw) - (Mesure(0, 50));
	Mesure dy = treat->get_y() - (Mesure(30, 0));
	treat->data->mesure_data["dx"] = dx;
	treat->data->mesure_data["dy"] = dy;
	treat->data->mesure_data["dw"] = dw;
	treat->data->mesure_data["dh"] = dh;
	treat->data->mesure_data["bx"] = treat->get_x();
	treat->data->mesure_data["by"] = treat->get_y();
	treat->data->mesure_data["bw"] = treat->get_width();
	treat->data->mesure_data["bh"] = treat->get_height();
	int frame = 15;
	treat->data->int_data["resize_frame"] = frame;
	treat->data->int_data["resize_actual_frame"] = frame;
	treat->data->scroll_data["zoom_scroll"] = r->data->scroll_data["zoom_scroll"];
	fct_duree lafct = { to_other_size_while, to_other_size_end, frame };
	treat->add_move_fnct(lafct);


}
int unique_index = 0;//unique index!!! for phot in cas of suppression etc....
std::string get_file_name_from_full_path(const std::string& file_path)
{
	std::string file_name;

	std::string::const_reverse_iterator it = std::find(file_path.rbegin(), file_path.rend(), '\\');
	if (it != file_path.rend())
	{
		file_name.assign(file_path.rbegin(), it);
		std::reverse(file_name.begin(), file_name.end());
		return file_name;
	}
	else
		return file_name;
}
Rectangle* rearrangetopp(Rectangle* r, const char* link = NULL, int parameter = 0);
void change_img_aff(Rectangle* r1, std::string url) {
	r1->set_etat("default");
	r1->set_bg_img(url);
	std::cout << "nouvelle image " << url << std::endl;
	r1->set_bg_img_sizing({ no, no });
	r1->draw(r1->ma_fenetre);
	r1->set_width(Mesure(r1->img_dim_w, 0));
	r1->set_height(Mesure(r1->img_dim_h, 0));
	r1->data->int_data["x_mot"] = 1;
	r1->data->int_data["y_mot"] = 1;
	carlet(r1);
}
void click_onglet(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
	
	Rectangle* lerec = r->data->rect_data["manager"];
	int nm = r->data->int_data["mynm"];
	if (nm == 0) {
		//SDL_FreeSurface(r->data->rect_data["manager"]->data->rect_data["aff"]->oldIMG[base_present_url]->get_data()->second.native());
		//r->data->rect_data["manager"]->data->rect_data["aff"]->oldIMG[base_present_url]->get_data()->second.set(data_TOTAL.return_for_display(r->data->rect_data["manager"]->data->rect_data["aff"]));
	}
	lerec->data->int_data["selected"] = nm;
	r->data->rect_data["manager"]->data->rect_data["aff"]->data->int_data["nmaff"] = nm;
	rearrangetopp(lerec);
	change_img_aff(r->data->rect_data["manager"]->data->rect_data["aff"],r->data->string_data["link"]);
	Scroll* to_updt = r->data->rect_data["manager"]->data->scroll_data["updt"];
	Scroll* to_updt2 = r->data->rect_data["manager"]->data->scroll_data["updt2"];
	Scroll* to_updt3 = r->data->rect_data["manager"]->data->scroll_data["updt3"];
	to_updt->set_value(0.4);
	to_updt2->set_value(0);
	to_updt3->set_value(0);
}
void close_onglet(Rectangle* r2, Fenetre* f, SDL_mainLoop* l) {
	Rectangle* r = r2->data->rect_data["related"];
	Rectangle* lerec = r->data->rect_data["manager"];
	int nm = r->data->int_data["mynm"];
	int nmbOBJ = lerec->data->const_char_data["docs"]->size();
	rearrangetopp(lerec);
	int i = nm;
	while (i < (nmbOBJ-1)) {

		lerec->data->rect_data["toplay" + i] = lerec->data->rect_data["toplay" + (i+1)];
		lerec->data->rect_data["toplay" + i]->data->int_data["mynm"] = i;
		i++;
	}

	lerec->data->rect_data.erase("toplay" + (nmbOBJ - 1));
	lerec->data->const_char_data["docs"]->erase(lerec->data->const_char_data["docs"]->begin() + nm);
	f->supp_rect(r2); 
	f->supp_rect(r2->data->rect_data["related"]);
	if (lerec->data->int_data["selected"] == nm)lerec->data->int_data["selected"]--;
	Rectangle* newsel = lerec->data->rect_data["toplay" + lerec->data->int_data["selected"]];
	click_onglet(newsel, newsel->ma_fenetre, NULL);
	rearrangetopp(lerec);

	for (size_t i = 0; i < forclosing.size(); i++)
	{
		if (forclosing[i] == r2) {
			std::swap(forclosing.begin() + i, forclosing.end()); forclosing.pop_back(); i = forclosing.size() + 1;
		}
	}
}
Rectangle* rearrangetopp(Rectangle* r, const char* link ,int parameter) {
	int nmbOBJ = r->data->const_char_data["docs"]->size();
	Rectangle* newrec = NULL;
	if (link != NULL) {
		r->data->const_char_data["alldocs"]->push_back(link);
		r->data->const_char_data["docs"]->push_back(link);
		newrec = r->ma_fenetre->addRectangle(Rectangle(Mesure(6, 00), Mesure(30, 0), Mesure(-12, 100), Mesure(30, 0)));
		r->data->rect_data["toplay" + nmbOBJ]=newrec;
		newrec->set_borderwidth(1);
		newrec->set_bgopacity(1);
		newrec->set_bgcolor(0xffffff);
		std::string nom = link;
		//nom.substr(nom.find_last_of("\\") + 1);
		if (parameter == 0) newrec->set_text(get_file_name_from_full_path(nom));
		else newrec->set_text(nom);
		newrec->set_font_size(20);
		newrec->set_alignement(center);
		newrec->set_font("calibri");
		newrec->set_borderwidth(1);
		newrec->set_bgcolor(0xbbbbbb);
		newrec->set_etat("hover");
		newrec->set_bgcolor(0x999999);
		newrec->set_etat("default");
		newrec->data->rect_data["manager"] = r;
		newrec->data->int_data["mynm"] = nmbOBJ;
		newrec->set_click_function(click_onglet);
		if (link!=NULL)newrec->data->string_data["link"] = link;
		newrec->add_etat(etat("on",false),5);
		newrec->set_etat("on");
		newrec->set_bgcolor(0x4f7000);
		newrec->set_font_color(0xffffff);
		newrec->set_bordercolor(0x4f7000);
		newrec->set_etat("default");
		newrec->data->int_data["uniqueIndex"] = unique_index;
		newrec->set_z_index(2);
		newrec->data->rect_data["aff"] = r->data->rect_data["aff"];
		newrec->stop_propagation = true;
		Rectangle* closerec = r->ma_fenetre->addRectangle(Rectangle(Mesure(6, 00), Mesure(31, 0), Mesure(30, 0), Mesure(31, 0)));
		if (parameter == 1)closerec->set_y(Mesure(-1000,-10));
		//closerec->set_bgcolor(0xff0000);
		closerec->set_text("x");
		closerec->set_font_size(18);
		closerec->set_alignement(center);
		closerec->set_font("calibri");
		closerec->set_etat("hover");
		closerec->set_bgopacity(1);
		closerec->set_bgcolor(0x000000);
		closerec->set_font_color(0xffffff);
		closerec->set_etat("default");
		closerec->stop_propagation = true;
		closerec->set_click_function(close_onglet);
		closerec->set_z_index(10);
		closerec->data->rect_data["related"] = newrec;
		if (parameter != 1)forclosing.push_back(closerec);
		newrec->data->rect_data["close"] = closerec;
		nmbOBJ++;
	}
	int i = 0;
	while (i < nmbOBJ) {
		Rectangle* etude = r->data->rect_data["toplay" + i] ;
		etude->set_width(Mesure(-12.0/(double)nmbOBJ, 100.0 / (double)nmbOBJ));
		etude->set_x(Mesure(6.0 - 12.0 / (double)nmbOBJ*(double)i, 100 / (double)nmbOBJ*(double)i));

		etude->data->rect_data["close"]->set_x(Mesure(6.0 - 12.0 / (double)nmbOBJ*(double)(i+1)-31 , 100 / (double)nmbOBJ*(double)(i+1)));

		if (i == r->data->int_data["selected"]) { etude->set_etat_activity(true, "on"); }
		else { etude->set_etat_activity(false, "on"); }
		std::cout << "boucle" << std::endl;
		i++;
	}

	return newrec;
}
void click_to_load_file(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {

	
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return;
	}


	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
	try {
		const char* link = tinyfd_openFileDialog(
			"Ouvrez un tileset", // ""
			"", // ""
			0, // 0
			NULL, // NULL or {"*.jpg","*.png"}
			NULL, // NULL or "image files"
			1);
		if (link != NULL) {
			std::string path = link;
			std::string extens = path.substr(path.size() - 3);
			if(extens=="png"|| extens == "PNG")rearrangetopp(r, link);
			if (extens == "oni" || extens == "ONI") {
				r->data->rect_data["mainonglet"]->click_fct(r->data->rect_data["mainonglet"], r->data->rect_data["mainonglet"]->ma_fenetre,NULL);
				full_recharge(r);
				data_TOTAL = get_path_fusion(path);
				std::vector<std::string> opened;
				for (auto&a : data_TOTAL.compo)for (auto&b : a)if (b.full && opened.end() == find(opened.begin(), opened.end(), b.url)) { opened.push_back(b.url); rearrangetopp(r, b.url.c_str());}
				r->data->rect_data["mainonglet"]->click_fct(r->data->rect_data["mainonglet"], r->data->rect_data["mainonglet"]->ma_fenetre, NULL);
			}
		}
	}
	catch (int e) {

	}
	//std::cout << link << " " << cCurrentPath << std::endl;
	changedire(cCurrentPath);

	SDL_Delay(500);
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0);
	return;
}
void click_to_save_file(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return;
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
	
	try {

		const char* link = tinyfd_saveFileDialog(
			"Sauver le project", // ""
			"", // ""
			0, // 0
			NULL, // NULL or {"*.txt"}
			NULL); // NULL or "image files"
														  // returns NULL on cancel
		if (link != NULL) {
			std::string url = link;
			save_to_file(url, data_TOTAL);
		}
	}
	catch (int e) {

	}
	
	
	changedire(cCurrentPath);

	SDL_Delay(500);
	SDL_Event e;
	//std::cout << link << " " << cCurrentPath << std::endl;
	changedire(cCurrentPath);
}
void click_to_export_file(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return;
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	try {

		const char* link = tinyfd_saveFileDialog(
			"Tileset a exporter", // ""
			"", // ""
			0, // 0
			NULL, // NULL or {"*.txt"}
			NULL); // NULL or "image files"
				   // returns NULL on cancel
		if (link != NULL) {
			std::string url = link;
			IMG_SavePNG(r->data->rect_data["aff"]->get_bg_from_name(base_present_url)->get_SOFTWARE()->native(), link);
		}
	}
	catch (int e) {

	}


	changedire(cCurrentPath);

	SDL_Delay(500);
	SDL_Event e;
	//std::cout << link << " " << cCurrentPath << std::endl;
	changedire(cCurrentPath);
}
void replace_el_grid(Rectangle* r) {
	double zoom = (double)r->data->rect_data["img_rel"]->get_width().totalPX(r->ma_fenetre->get_width())/ (double)r->data->rect_data["img_rel"]->img_dim_w ;
	r->set_x(r->data->rect_data["img_rel"]->get_x() + (double)r->data->int_data["index_x"]*Mesure( zoom*case_size,0));// ((double)r->data->int_data["index_x"] / (double)r->data->int_data["max_index_x"])*r->data->rect_data["img_rel"]->get_width());
	r->set_y(r->data->rect_data["img_rel"]->get_y() + (double)r->data->int_data["index_y"]*Mesure( zoom*case_size,0));// ((double)r->data->int_data["index_y"] / (double)r->data->int_data["max_index_y"])*r->data->rect_data["img_rel"]->get_height());
	r->set_width(Mesure(zoom*case_size+1,0));
	r->set_height(Mesure(zoom*case_size+1,0));
	//std::cout << r->data->rect_data["img_rel"]->get_width().pc<<"-"<< r->data->rect_data["img_rel"]->get_width().px << std::endl;
	//std::cout << r->data->rect_data["img_rel"]->get_height().pc << "-" << r->data->rect_data["img_rel"]->get_height().px << std::endl;
	//std::cout << r->img_dim_w << std::endl;
}
void click_change_on(Rectangle*r, Fenetre*, SDL_mainLoop*) {
	bool change = true;
	if (r->data->int_data["equinum"]==0) {
		for (auto&a : grille)for (auto&b : a)if (b->get_etat("on")->active) { b->set_etat_activity(!b->get_etat("on")->active, "on"); change = false; }
		if (change) {
			to_copy_x = r->data->int_data["index_x"];
			to_copy_y = r->data->int_data["index_y"];
		}
		else {
			std::cout << "Moove : " << to_copy_x << "-" << to_copy_y << "--" << r->data->int_data["index_x"] << "-" << r->data->int_data["index_y"] << std::endl;
			data_TOTAL.swapper(to_copy_x, to_copy_y, r->data->int_data["index_x"], r->data->int_data["index_y"]);
			//SDL_FreeSurface(r->data->rect_data["img_rel"]->oldIMG[base_present_url]->get_data()->second.native());
			//r->data->rect_data["img_rel"]->oldIMG[base_present_url]->get_data()->second.set( data_TOTAL.return_for_display(r->data->rect_data["img_rel"]));
			r->data->rect_data["img_rel"]->dys_changed();

		}
	}
	else {
		//if (!r->get_etat("on")->active) { if (!data_TOTAL.include(r->data->rect_data["img_rel"]->get_bg_img(), r->data->int_data["index_x"], r->data->int_data["index_y"]))change = false; }
		//else data_TOTAL.remove(r->data->rect_data["img_rel"]->get_bg_img(), r->data->int_data["index_x"], r->data->int_data["index_y"]);
	}
	if(change)r->set_etat_activity(!r->get_etat("on")->active, "on");
}
void carlet(Rectangle* r) {
	int nm_x = r->img_dim_w / case_size;
	int nm_y = r->img_dim_h / case_size;
	int i = 0;
	int j = 0;
	for (auto& a : grille)for (auto&b : a)r->ma_fenetre->supp_rect(b);
	grille.clear();
	while (i < nm_y) {
		j = 0;
		grille.push_back(std::vector<Rectangle*>());
		while (j < nm_x) {
			grille[i].push_back(r->ma_fenetre->addRectangle(Rectangle(Mesure(100, 0), Mesure(100, 0), Mesure(48, 0), Mesure(48, 0))));
			grille[i][j]->data->rect_data["img_rel"]=r;
			grille[i][j]->data->int_data["index_x"] = j;
			grille[i][j]->data->int_data["max_index_x"] = nm_x;
			grille[i][j]->data->int_data["index_y"] = i;
			grille[i][j]->data->int_data["max_index_y"] = nm_y;
			grille[i][j]->everyframe_fct = replace_el_grid;
			grille[i][j]->set_borderwidth(-1);
			//if (!data_TOTAL.exists(r->get_bg_img(), j, i))
			//	grille[i][j]->add_etat(etat("on", false), 1);
			//else
			//	grille[i][j]->add_etat(etat("on", true), 1);
			grille[i][j]->set_etat("on");
			grille[i][j]->set_bordercolor(0xbb0000);
			grille[i][j]->data->int_data["equinum"] = r->data->int_data["nmaff"];
			if(r->data->int_data["nmaff"]==0)grille[i][j]->set_bordercolor(0x00bb00);
			grille[i][j]->set_borderwidth(-3);
			grille[i][j]->set_etat("default");
			grille[i][j]->set_click_function(click_change_on);
			//grille[i][j]->set_bgcolor(0xff0000);
			//grille[i][j]->set_bgopacity(1);

			j++;
		}
		i++;
	}

}
void full_recharge(Rectangle*r) {
	
	while (!forclosing.empty())
	{
		std::cout << "to close :" << forclosing.size() << std::endl;
		forclosing.back()->click_fct(forclosing.back(), forclosing.back()->ma_fenetre, NULL);
	}

}
void Tilset_edit(Fenetre* fn2) {


	fn2->resize(800, 600);
	fn2->titre = "Editeur";


	std::vector<const char*>* documents=new std::vector<const char*>();
	std::vector<const char*>* alldocuments = new std::vector<const char*>();

	fn2->titre = "Editeur";

	

	Rectangle* zr1 = fn2->addRectangle(Rectangle(Mesure(-400, 100), Mesure(5, 0), Mesure(60, 0), Mesure(30, 0)));
	zr1->set_bgopacity(1);
	zr1->set_bgcolor(0xffffff);
	zr1->set_text("acceuil");
	zr1->set_z_index(2);
	zr1->set_font_size(20);
	zr1->set_alignement(center);
	zr1->set_font("calibri");
	//r1->set_borderwidth(1);
	zr1->set_bgcolor(0xbbbbbb);
	zr1->set_etat("hover");
	zr1->set_bgcolor(0xffffff);
	zr1->set_etat("default");
	zr1->data->rebuild_funk_data["rebuild"] = Acceuil;
	zr1->set_click_function(redirect_data);
	zr1->set_z_index(10);

	Rectangle* ar1 = fn2->addRectangle(Rectangle(Mesure(-325, 100), Mesure(5, 0), Mesure(60, 0), Mesure(30, 0)));
	ar1->set_bgopacity(1);
	ar1->set_bgcolor(0xffffff);
	ar1->set_text("open");
	ar1->set_z_index(2);
	ar1->set_font_size(20);
	ar1->set_alignement(center);
	ar1->set_font("calibri");
	ar1->set_bgcolor(0xbbbbbb);
	ar1->set_etat("hover");
	ar1->set_bgcolor(0xffffff);
	ar1->set_etat("default");
	ar1->set_click_function(click_to_load_file);
	creat_window_decoration(fn2);
	ar1->data->const_char_data["docs"] = documents;
	ar1->data->const_char_data["alldocs"] = alldocuments;
	ar1->data->int_data["selected"] = 0;
	ar1->set_z_index(10);
	
	Rectangle* rout = rearrangetopp(ar1, "Output",1);
	rout->set_bgcolor(0xba9696);
	rout->data->string_data["link"] = "images/intro.png";

	Rectangle* ar2 = fn2->addRectangle(Rectangle(Mesure(-250,100), Mesure(5, 0), Mesure(60, 0), Mesure(30, 0)));
	ar2->set_bgopacity(1);
	ar2->set_bgcolor(0xffffff);
	ar2->set_text("save");
	ar2->set_z_index(2);
	ar2->set_font_size(20);
	ar2->set_alignement(center);
	ar2->set_font("calibri");
	//r2->set_borderwidth(1);
	ar2->set_bgcolor(0xbbbbbb);
	ar2->set_etat("hover");
	ar2->set_bgcolor(0xffffff);
	ar2->set_etat("default");
	ar2->set_click_function(click_to_save_file);
	ar2->set_z_index(10);
	ar1->data->rect_data["mainonglet"]=rout;

	Rectangle* ar19 = fn2->addRectangle(Rectangle(Mesure(-175, 100), Mesure(5, 0), Mesure(60, 0), Mesure(30, 0)));
	ar19->set_bgopacity(1);
	ar19->set_bgcolor(0xffffff);
	ar19->set_text("export");
	ar19->set_z_index(2);
	ar19->set_font_size(20);
	ar19->set_alignement(center);
	ar19->set_font("calibri");
	//r2->set_borderwidth(1);
	ar19->set_bgcolor(0xbbbbbb);
	ar19->set_etat("hover");
	ar19->set_bgcolor(0xffffff);
	ar19->set_etat("default");
	ar19->set_click_function(click_to_export_file);
	ar19->set_z_index(10);
	ar1->stop_propagation = true;
	ar2->stop_propagation = true;
	ar19->stop_propagation = true;
	Rectangle* ar3 = fn2->addRectangle(Rectangle(Mesure(6, 0), Mesure(50, 0), Mesure(-12, 100), Mesure(4, 0)));
	ar3->set_bgopacity(1);
	ar3->set_bgcolor(0x4f7000);
	ar3->set_z_index(10);
	ar3->set_etat("default");
	
		Rectangle* ar7 = fn2->addRectangle(Rectangle(Mesure(6, 0), Mesure(54, 0), Mesure(-12, 100), Mesure(2, 0)));
	ar7->set_bgopacity(0.9);
	ar7->set_bgcolor(0x4f7000);
	ar7->set_z_index(10);
	ar7->set_etat("default");
	Rectangle* ar5 = fn2->addRectangle(Rectangle(Mesure(6, 0), Mesure(56, 0), Mesure(-12, 100), Mesure(2, 0)));
	ar5->set_bgopacity(0.7);
	ar5->set_bgcolor(0x4f7000);
	ar5->set_z_index(10);
	ar5->set_etat("default");
	Rectangle* ar6 = fn2->addRectangle(Rectangle(Mesure(6, 0), Mesure(58, 0), Mesure(-12, 100), Mesure(2, 0)));
	ar6->set_bgopacity(0.5);
	ar6->set_bgcolor(0x4f7000);
	ar6->set_z_index(10);
	ar6->set_etat("default");
	Rectangle* ar10 = fn2->addRectangle(Rectangle(Mesure(6, 0), Mesure(60, 0), Mesure(-12, 100), Mesure(2, 0)));
	ar10->set_bgopacity(0.2);
	ar10->set_bgcolor(0x4f7000);
	ar10->set_z_index(10);
	ar10->set_etat("default");
	Rectangle* ar4 = fn2->addRectangle(Rectangle(Mesure(6, 0), Mesure(62, 0), Mesure(-12, 100), Mesure(-54, 100)));
	ar4->set_bgopacity(1);
	ar4->set_bgcolor(0xdddddd);

	//Rectangle* ar4 = fn2->addRectangle(Rectangle(Mesure(-20, 100), Mesure(0, 0), Mesure(-12, 100), Mesure(-54, 100)));
	//ar4->set_bgopacity(1);
	//ar4->set_bgcolor(0xcccccc);
	//ar4->set_etat("default");


	//###############################################################################################################
	Rectangle* r1 = fn2->addRectangle(Rectangle(Mesure(20, 0), Mesure(62, 0), Mesure(-40, 100), Mesure(-40, 100)));
	Rectangle_clip border_cliper(Mesure(0, 0),Mesure(62, 0), Mesure(0, 100), Mesure(0, 100));
	r1->clips().push_back(border_cliper);
	ar1->data->rect_data["aff"] = r1;
	ar2->data->rect_data["aff"] = r1;
	ar19->data->rect_data["aff"] = r1;
	rout->data->rect_data["aff"] = r1;
	callback_etat Moncall;
	Moncall.nom = "hold";
	Moncall.on_while = deplacer_hold;

	std::string url = base_present_url;
	r1->set_bg_img(url);
	r1->set_bg_img_sizing({ no, no });
	r1->set_width(Mesure(r1->img_dim_w, 0));
	r1->set_height(Mesure(r1->img_dim_h, 0));
	 

	/*SDL_Surface* scaled;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	scaled = SDL_CreateRGBSurface(SDL_SWSURFACE, r1->img_dim_w*5, r1->img_dim_w*5, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
#else
	scaled = SDL_CreateRGBSurface(SDL_SWSURFACE, r1->img_dim_w * 5, r1->img_dim_w * 5, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
#endif
	SDL_FreeSurface(scaled);*/

	r1->add_callback_etat(Moncall);
	r1->data->mesure_data["base_width"] = Mesure(-40, 100);
	r1->data->int_data["x_mot"] = 1;
	r1->data->int_data["y_mot"] = 1;
	r1->data->int_data["to_add"] = 1;
	//r1->set_click_function(change_page_click);
	//r1->set_bgcolor(0x000000);
	//r1->set_bgopacity(1);

	Rectangle* r2 = fn2->addRectangle(Rectangle(Mesure(-20, 100), Mesure(-20, 100), Mesure(20, 0), Mesure(20, 0)));
	r2->set_bgcolor(0x555555);
	r2->set_bgopacity(1);

	Rectangle* r4 = fn2->addRectangle(Rectangle(Mesure(30, 0), Mesure(-70, 100), Mesure(40, 0), Mesure(40, 0)));
	r4->set_bg_img("images/option_button/full_height.png");
	r4->set_bgcolor(0x333333);
	r4->set_bgopacity(1);
	r4->set_borderwidth(2);
	r4->set_bordercolor(0x000000);
	r4->set_etat("hover");
	r4->set_bgcolor(0x555555);
	r4->set_etat("default");
	r4->stop_propagation = true;
	r4->set_z_index(2);

	Rectangle* r5 = fn2->addRectangle(Rectangle(Mesure(90, 0), Mesure(-70, 100), Mesure(40, 0), Mesure(40, 0)));
	r5->set_bg_img("images/option_button/full_width.png");
	r5->set_bgcolor(0x333333);
	r5->set_bgopacity(1);
	r5->set_borderwidth(2);
	r5->set_bordercolor(0x000000);
	r5->set_etat("hover");
	r5->set_bgcolor(0x555555);
	r5->stop_propagation = true;
	r5->set_z_index(2);

	Scroll* scroll1 = new Scroll(fn2, Mesure(-82, 100), Mesure(40, 0), Mesure(20, 0), Mesure(-20, 100), Mesure(62, 0), true);
	Scroll* scroll2 = new Scroll(fn2, Mesure(-20, 100), Mesure(40, 0), Mesure(20, 0), Mesure(0, 0), Mesure(-20, 100), false);
	Scroll* scroll3 = new Scroll(fn2, Mesure(120, 0), Mesure(10, 0), Mesure(10, 0), Mesure(20, 0), Mesure(-100, 100), false);
	
	//(*scroll3)[0]->set_bgopacity(0);
	(*scroll3)[1]->set_borderwidth(10);
	(*scroll3)[1]->set_bordercolor(0);
	(*scroll3)[0]->data->rect_data["to_change"] = r1;
	(*scroll1)[0]->data->rect_data["to_change"] = r1;
	(*scroll2)[0]->data->rect_data["to_change"] = r1;
	(*scroll2)[0]->keyfunct = scroll_horizon;
	(*scroll1)[0]->keyfunct = scroll_vertical;
	(*scroll3)[0]->keyfunct = scroll_horizon_p_m;
	scroll1->add_on_change(scroll1_action);
	scroll2->add_on_change(scroll2_action);
	scroll3->add_on_change(scroll3_action);
	ar1->data->scroll_data["updt"] = scroll3;
	ar1->data->scroll_data["updt2"] = scroll2;
	ar1->data->scroll_data["updt3"] = scroll1;
	scroll3->set_value(0.4);
	(*scroll3)[0]->set_z_index(2);
	(*scroll3)[1]->set_z_index(3);
	(*scroll3)[0]->stop_propagation = true;
	(*scroll3)[1]->stop_propagation = true;
	(*scroll2)[0]->set_z_index(2);
	(*scroll2)[1]->set_z_index(3);
	(*scroll2)[0]->stop_propagation = true;
	(*scroll2)[1]->stop_propagation = true;
	(*scroll1)[0]->set_z_index(2);
	(*scroll1)[1]->set_z_index(3);
	(*scroll1)[0]->stop_propagation = true;
	(*scroll1)[1]->stop_propagation = true;



	r1->data->scroll_data["x_scroll"] = scroll2;
	r1->data->scroll_data["y_scroll"] = scroll1;
	r1->data->rect_data["to_supp"] = r2;
	r1->everyframe_fct = pos_controller;

	r5->data->rect_data["to_zoom"] = r1;
	r5->data->scroll_data["zoom_scroll"] = scroll3;
	r5->set_click_function(click_to_max);
	r4->data->rect_data["to_zoom"] = r1;
	r4->data->scroll_data["zoom_scroll"] = scroll3;
	r4->set_click_function(click_to_max2);
	std::string string;

	UnderWindow* u = new UnderWindow(fn2, Mesure(0, 0), Mesure(62, 0), Mesure(0, 100), Mesure(-62, 100));


	creat_window_decoration(fn2);
}
//yoyo