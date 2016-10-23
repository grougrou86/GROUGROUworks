#include "G_inc.h" 
#include<iostream>
#include <algorithm>
#include"SDL2_gfx-1.0.1\SDL2_rotozoom.h"
#include"sdladdon.h"
#include <stdexcept> 
#include <exception>
#include "encodage.h"
#include "GENERAL_PARAMETER.h"
namespace ONIGIRIX_GUI {
	int Rectangle::rel_x() {
		return get_x().totalPX(RelativeElement->rel_w()) + get_offset_x() + RelativeElement->rel_x();
	}
	int Rectangle::rel_y() {
		return get_y().totalPX(RelativeElement->rel_h()) + get_offset_y() + RelativeElement->rel_y();
	}
	int Rectangle::rel_w() {
		return get_width().totalPX(RelativeElement->rel_w());
	}
	int Rectangle::rel_h() {
		return get_height().totalPX(RelativeElement->rel_h());
	}
	void  Rectangle::TextInputFunction(std::wstring) {

	}
	void  Rectangle::KeyFunction(int key) {
		if (keyfunct != NULL)keyfunct(this, key);
	}
	const bool operator!=(img_sizing sz1, img_sizing sz2) {
		return !(sz1.x_mode == sz2.x_mode && sz1.y_mode == sz2.y_mode);
	}
	//##### methode de dessin #####
	void Rectangle::add_move_fnct(fct_duree fct) {
		move_fnct.push_back(fct);
	}
	void Rectangle::updat_move_fnct() {
		int i = 0;
		while (i < move_fnct.size()) {
			move_fnct[i].left_frames--;
			if (move_fnct[i].fct_while != NULL)move_fnct[i].fct_while(this);
			//std::cout << move_fnct[i].left_frames << "currframe" << std::endl;
			if (move_fnct[i].left_frames <= 0) {
				if (move_fnct[i].fct_end != NULL)move_fnct[i].fct_end(this);
				std::swap(move_fnct[i], move_fnct.back());
				move_fnct.pop_back();
			}
			else i--;
		}
	}
	void Rectangle::reload_img(SDL_Texture* & text_bg, SDL_Texture* & text_txt) {

		bool always_reload = false;

		//std::cout << "display changed" << std::endl;
		text_ok = false;
		int i = 0;
		while (myTextures.size() != 0) {
			if(i=0)SDL_DestroyTexture(myTextures.back());
			myTextures.pop_back();
			i++;
		}
		SDL_Surface* rect_bg = NULL;
		//si qqc a changé dans la largeur ou la longeur

		// on recharge les nouvelles

		stretchRect.w = get_width().totalPX(RelativeElement->rel_w());
		stretchRect.h = get_height().totalPX(RelativeElement->rel_h());

		if ((get_text().size() != 0 || ever_refresh_text) && get_font().size() != 0) {

			if (text->changed || font_color->changed) {

				if (LeText != NULL) {
					delete LeText;
					LeText = nullptr;
				}
				LeText = new TextBlock(this, get_text(), get_font_size(), get_font(), get_alignement(), stretchRect.w, 4, get_font_color());

			}
			else {
				if (LeText != NULL) {
					LeText->width = stretchRect.w;
					LeText->update_texture(true);
				}
			}

			if (LeText != NULL)
			{
				text_height = LeText->height;
				set_etat("default");
				set_height(Mesure(LeText->height, 0));
				stretchRect.h = LeText->height;
			}
		}




		if (get_bg_img() != "" && get_bg_img() != "none") {

			std::cout << "trying reload img : " << oldIMG[get_bg_img()] << "--" << get_bg_img() << std::endl;

			rect_bg = nullptr;
			if (oldIMG[get_bg_img()]->is_changing())always_reload = true;//exemple video
			if (oldIMG[get_bg_img()] != nullptr && oldIMG[get_bg_img()]->get_SOFTWARE() != nullptr) {
				/*
				if (oldIMG[get_bg_img()]->get_SDL_TEXTURE() == nullptr) {
					rect_bg = oldIMG[get_bg_img()]->get_SOFTWARE()->native();
					if (rect_bg != nullptr) {
						text_bg = SDL_CreateTextureFromSurface(this->ma_fenetre->get_screen_render(), rect_bg);
					}
				}*/
				rect_bg = nullptr;
				if (oldIMG[get_bg_img()]->get_SDL_TEXTURE() != nullptr) {
					text_bg = oldIMG[get_bg_img()]->get_SDL_TEXTURE()->native();
					std::cout << "THE NEW TESXTURES ARE" << text_bg << std::endl;
					std::cout << "33renderer" << ma_fenetre->get_screen_render() << std::endl;
				}
			}
			std::cout << "utilisated :  " << text_bg << std::endl;

			img_dim_h = oldIMG[get_bg_img()]->get_height();
			img_dim_w = oldIMG[get_bg_img()]->get_width();

			double ratio = (double)img_dim_w / (double)img_dim_h;
			if (rect_bg != NULL) {
				if (get_bg_img_sizing().x_mode == fit&&get_bg_img_sizing().y_mode == automatic) {
					zoom = (double)stretchRect.w / (double)rect_bg->w;
					stretchRect.h = (double)stretchRect.w / (double)ratio;
				}
				if (get_bg_img_sizing().x_mode == automatic&&get_bg_img_sizing().y_mode == fit) {
					zoom = (double)stretchRect.h / (double)rect_bg->h;
					stretchRect.w = (double)stretchRect.h * (double)ratio;
				}
			}

		}
		//std::cout << std::endl;

		myTextures.push_back(text_bg);
		myTextures.push_back(text_txt);
		//SDL_FreeSurface(rect_bg);
		if (!(get_bg_img() != ""&&get_bg_img() != "none"&&oldIMG[get_bg_img()] != nullptr && oldIMG[get_bg_img()]->get_SOFTWARE()==nullptr ))dys_updated();
		if(always_reload)dys_changed();
	}
	void Rectangle::ask_clip_updat() {
		clip_updated = false;
	}
	void Rectangle::draw(Fenetre* f) {


		if (get_offset_x() != old_offset_x || get_offset_y() != old_offset_y) {
			old_offset_x = get_offset_x(); old_offset_y = get_offset_y();
			clip_updated = false;
		}

		SDL_Texture* text_bg = NULL;
		SDL_Texture* text_txt = NULL;


		stretchRect.x = get_x().totalPX(RelativeElement->rel_w()) + RelativeElement->rel_x() + get_offset_x();
		stretchRect.y = get_y().totalPX(RelativeElement->rel_h()) + RelativeElement->rel_y() + get_offset_y();


		//to ask update !
		get_borderwidth();
		get_bordercolor();
		get_bg_img();
		get_bg_img_sizing();
		get_text();
		get_font_color();
		get_text();
		get_width();
		get_height();
		get_bgopacity();
		get_bgcolor();
		get_width();
		get_height();
		get_x();
		get_y();



		if (dys_is_changed() || text->changed || font_color->changed || bg_img->changed || bg_img_sizing->changed || _w->changed || _h->changed) {
			reload_img(text_bg, text_txt);
		}
		else if (myTextures.size() != 0) {
			text_bg = myTextures[0];
			text_txt = myTextures[1];
		}

		if (oldRel_w != RelativeElement->rel_w() || oldRel_h != RelativeElement->rel_h() || oldRel_x != RelativeElement->rel_x() || oldRel_y != RelativeElement->rel_y()) {//on vérifie si l'élement relatif a "bougé"
			oldRel_w = RelativeElement->rel_w();
			oldRel_h = RelativeElement->rel_h();
			oldRel_x = RelativeElement->rel_x();
			oldRel_y = RelativeElement->rel_y();
			if (get_width().pc != 0 || get_height().pc != 0)
			{
				dys_changed();
			}// si ni la largeur ni la hauteur ne dépend de la relativité à l'élément on ne refresh pas
			clip_updated = false;
		}

		Rectangle_clip default_rect(get_x() + Mesure(RelativeElement->rel_x() + get_offset_x(), 0), get_y() + Mesure(RelativeElement->rel_y() + get_offset_y(), 0), get_width(), get_height());
		Rectangle_clip screen_clip(Mesure(0, 0), Mesure(0, 0), Mesure(ma_fenetre->rel_w(), 0), Mesure(ma_fenetre->rel_h(), 0));
		if (!clip_updated || _w->changed || _h->changed || _y->changed || _x->changed || f->was_resized()) {
			if (_clips.size() != 0) {
				final_rec = intersection(_clips, RelativeElement->rel_w(), RelativeElement->rel_h(), default_rect);
				std::cout << "is a clip " << std::endl;
				final_rec = intersection(final_rec, screen_clip, RelativeElement->rel_w(), RelativeElement->rel_h(), default_rect);
			}
			else {
				final_rec = screen_clip;
			}
			if (auto_p_clips.size() != 0) {
				Rectangle_clip final_rec2;
				final_rec2 = intersection(auto_p_clips, RelativeElement->rel_w(), RelativeElement->rel_h(), default_rect);
				final_rec = intersection(final_rec, final_rec2, RelativeElement->rel_w(), RelativeElement->rel_h(), default_rect);
			}
			extern_clip = Clip2Rec(final_rec, RelativeElement->rel_w(), RelativeElement->rel_h(), default_rect);
			clip_updated = true;
		}
		last_rec = intersection(final_rec, default_rect, RelativeElement->rel_w(), RelativeElement->rel_h(), default_rect);
		destRect = Clip2Rec(last_rec, RelativeElement->rel_w(), RelativeElement->rel_h(), default_rect);
		srcRect = Clip2Rec(last_rec, RelativeElement->rel_w(), RelativeElement->rel_h(), default_rect);
		srcRect.x -= stretchRect.x;
		srcRect.y -= stretchRect.y;


		if (!last_rec.vide) {
			if (debug) std::cout << "debug" << std::endl;
			if (get_bgopacity() != 0) {

				RGB_c bg_C_RGB = couleurConverter(get_bgcolor());
				SDL_SetRenderDrawBlendMode(f->get_screen_render(), SDL_BLENDMODE_BLEND);
				SDL_SetRenderDrawColor(f->get_screen_render(), bg_C_RGB.get_r(), bg_C_RGB.get_g(), bg_C_RGB.get_b(), get_bgopacity() * 255);

				SDL_RenderFillRect(f->get_screen_render(), &destRect);

			}
			if (text_bg != NULL) {
				int w, h;
				SDL_QueryTexture(text_bg, NULL, NULL, &w, &h);
				SDL_Rect srcRect2;
				if (stretchRect.h != 0)srcRect2.y = (double)srcRect.y * (double)h / (double)stretchRect.h;
				if (stretchRect.w != 0)srcRect2.x = (double)srcRect.x * (double)w / (double)stretchRect.w;
				if (stretchRect.h != 0)srcRect2.h = (double)srcRect.h * (double)h / (double)stretchRect.h;
				if (stretchRect.w != 0)srcRect2.w = (double)srcRect.w * (double)w / (double)stretchRect.w;
				if (debug) {
					std::cout << "______________" << std::endl;
					std::cout << "DESTIN:" << destRect.x << ".--." << destRect.y << ".--." << destRect.w << ".--." << destRect.h << std::endl;
					std::cout << "ORIGAL:" << stretchRect.x << ".--." << stretchRect.y << ".--." << stretchRect.w << ".--." << stretchRect.h << std::endl;
					std::cout << "SOURCE:" << srcRect.x << ".--." << srcRect.y << ".--." << srcRect.w << ".--." << srcRect.h << std::endl;
					std::cout << "WINDOW:" << ma_fenetre->get_width() << "--" << ma_fenetre->get_height() << std::endl;
					std::cout << "RATIOS:" << w << "//" << h << " .defo. " << (double)srcRect.w / (double)srcRect.h << "-" << (double)destRect.w / (double)destRect.h << std::endl;
				}
				SDL_RenderCopy(f->get_screen_render(), text_bg, &srcRect2, &destRect);
			}
			if (LeText != NULL) {
				//SDL_Rect monrec = { stretchRect.x, stretchRect.y, stretchRect.w, text_height };
				//SDL_RenderCopy(f->get_screen_render(), text_txt, NULL, &monrec);
				LeText->x = stretchRect.x;
				LeText->y = stretchRect.y;
				LeText->draw_to_render(f->get_screen_render());
			}

			//making border

			RGB_c br_C_RGB = couleurConverter(get_bordercolor());
			SDL_SetRenderDrawColor(f->get_screen_render(), br_C_RGB.get_r(), br_C_RGB.get_g(), br_C_RGB.get_b(), 255);
			if (debug)std::cout << "border_width" << get_borderwidth() << std::endl;
			if (get_borderwidth() != 0) {
				if (debug)std::cout << extern_clip.x << "-" << extern_clip.y << "-" << extern_clip.w << "-" << extern_clip.h << std::endl;
				SDL_Rect destRect_bord = extern_clip;
				if (get_borderwidth() > 0) {

					SDL_Rect r1;

					r1.x = stretchRect.x - get_borderwidth(); r1.y = stretchRect.y - get_borderwidth(); r1.w = stretchRect.w + 2 * get_borderwidth(); r1.h = get_borderwidth();
					r1 = intersection(r1, destRect_bord);
					SDL_RenderFillRect(f->get_screen_render(), &r1);

					r1.x = stretchRect.x - get_borderwidth(); r1.y = stretchRect.y - get_borderwidth(); r1.w = get_borderwidth(); r1.h = stretchRect.h + 2 * get_borderwidth();
					r1 = intersection(r1, destRect_bord);
					SDL_RenderFillRect(f->get_screen_render(), &r1);

					r1.x = stretchRect.x + stretchRect.w; r1.y = stretchRect.y - get_borderwidth(); r1.w = get_borderwidth(); r1.h = stretchRect.h + 2 * get_borderwidth();
					r1 = intersection(r1, destRect_bord);
					SDL_RenderFillRect(f->get_screen_render(), &r1);

					r1; r1.x = stretchRect.x - get_borderwidth(); r1.y = stretchRect.y + stretchRect.h; r1.h = get_borderwidth(); r1.w = stretchRect.w + 2 * get_borderwidth();
					r1 = intersection(r1, destRect_bord);
					SDL_RenderFillRect(f->get_screen_render(), &r1);
				}
				else {
					SDL_Rect r1;

					r1.x = stretchRect.x; r1.y = stretchRect.y; r1.w = stretchRect.w; r1.h = -get_borderwidth();
					r1 = intersection(r1, destRect_bord);
					SDL_RenderFillRect(f->get_screen_render(), &r1);

					r1.x = stretchRect.x; r1.y = stretchRect.y; r1.w = -get_borderwidth(); r1.h = stretchRect.h;
					r1 = intersection(r1, destRect_bord);
					SDL_RenderFillRect(f->get_screen_render(), &r1);

					r1.x = stretchRect.x + stretchRect.w + get_borderwidth(); r1.y = stretchRect.y; r1.w = -get_borderwidth(); r1.h = stretchRect.h;
					r1 = intersection(r1, destRect_bord);
					SDL_RenderFillRect(f->get_screen_render(), &r1);

					r1.x = stretchRect.x; r1.y = stretchRect.y + stretchRect.h + get_borderwidth(); r1.h = -get_borderwidth(); r1.w = stretchRect.w;
					r1 = intersection(r1, destRect_bord);
					SDL_RenderFillRect(f->get_screen_render(), &r1);
				}
				//SDL_RenderDrawRect(f->get_screen_render(), &stretchRect);
			}

			SDL_SetRenderDrawColor(f->get_screen_render(), 0xFF, 0xFF, 0xFF, 0xFF);
		}
		else { if (debug) { std::cout << "vide!" << std::endl; std::cout << "ORIGAL:" << stretchRect.x << ".--." << stretchRect.y << ".--." << stretchRect.w << ".--." << stretchRect.h << std::endl; } }

	}
	void vide(Rectangle*, Fenetre*, SDL_mainLoop*) {}//fait rien ^.^
	Rectangle::Rectangle(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h) :Rectangle(x, y, w, h) {
		f->addRectangle(this);
	}
	Rectangle::Rectangle(Mesure x, Mesure y, Mesure w, Mesure h) {

		data = new data_store();

		_x = new style_etat_data<Mesure>(0);
		_y = new style_etat_data<Mesure>(1);
		bg_color = new style_etat_data<int>(2);
		bg_img = new style_etat_data<std::string>(3, "none");
		border_color = new style_etat_data<int>(4);
		border_width = new style_etat_data<int>(5);
		bg_opacity = new style_etat_data<double>(6);
		bg_img_sizing = new style_etat_data<img_sizing>(7);

		_w = new style_etat_data<Mesure>(8);//width
		_h = new style_etat_data<Mesure>(9);//height
		text = new style_etat_data<std::wstring>(10, L"");
		font = new style_etat_data<std::string>(11, "");
		font_size = new style_etat_data<int>(12, 18);
		font_color = new style_etat_data<int>(13);
		align = new style_etat_data<alignement>(14, center);

		set_x(x);
		set_y(y);
		set_width(w);
		set_height(h);
		point_styles = std::vector < style_etat_base* >{ _x, _y, bg_color, bg_img, border_color, border_width, bg_opacity, bg_img_sizing, _w, _h, text, font, font_size, align, font_color };
		this->add_etat({ "default", true }, 0);
		this->add_etat({ "hover", false }, 2);
		this->add_etat({ "hold", false }, 1);
		this->add_etat({ "active", true }, 2);
		this->set_etat_activity(false, "active");
	}
	void Rectangle::set_x(Mesure maMesure) {
		set_what(_x, maMesure);
	}
	void Rectangle::set_y(Mesure maMesure) {
		set_what(_y, maMesure);
	}
	void Rectangle::set_x2(Mesure maMesure) {
		set_width(maMesure - get_x());
	}
	void Rectangle::set_y2(Mesure maMesure) {
		set_height(maMesure - get_y());
	}
	void Rectangle::set_width(Mesure maMesure) {
		set_what(_w, maMesure);
	}
	void Rectangle::set_height(Mesure maMesure) {
		set_what(_h, maMesure);
	}
	void Rectangle::set_bg_img(std::string path) {
		try {
			oldIMG.at(path);   // vector::at throws an out-of-range if image not already loaded for this rectangle
		}
		catch (const std::out_of_range& oor) {
			if (path.substr(path.length() - 3) == "mkv" || path.substr(path.length() - 3) == "mp4" || path.substr(path.length() - 3) == "avi") {
				oldIMG[path] = ma_fenetre->get_videoManager()->get_Video(s2ws(path));
			}
			else {
				oldIMG[path] = ma_fenetre->get_ImageDealer()->get_image(s2ws(path));  //( this->ma_fenetre->loadImg(path);
			}
			if (oldIMG[path]!= nullptr && oldIMG[path]->get_SOFTWARE() != nullptr) {

				if ((img_dim_h == -1 || img_dim_w == -1) && currentState == "default") {
					img_dim_h = oldIMG[path]->get_height();
					img_dim_w = oldIMG[path]->get_width();
				}
			}
		}
		set_what(bg_img, path);
		dys_changed();
	}

	std::string Rectangle::get_bg_img() {
		return get_what(bg_img);
	}
	int Rectangle::get_bg_couleur() {
		return get_what(bg_color);
	}
	alignement Rectangle::get_alignement() {
		return get_what(align);
	}
	Mesure Rectangle::get_x() {
		return get_what(_x);
	}
	template<typename T>
	T Rectangle::get_what(style_etat_data<T>* & style) {
		update(*style);
		return style->old_value;
	}

	template<typename T>
	void Rectangle::set_what(style_etat_data<T>* & style, T val) {
		set_to_best(val, *style, currentState);
		bool deja = false;
		for (auto& et : vieux_etats_utiles) {
			bool deja2 = false;
			if (et.vieux_etat.nom == currentState) {
				deja = true;
				for (auto & ste : et.style_affecte)if (ste == style)deja2 = true;
				if (!deja2)et.style_affecte.push_back(style);
			}
		}
		if (!deja) { std::vector<style_etat_base*> neuf23; neuf23.push_back(style); vieux_etats_utiles.push_back(for_vieux{ etat{ currentState, false }, neuf23 }); }

		if (currentState == style->old_nom)
		{
			style->check_implicite_change = true;
		}
	}
	template<typename T>
	bool Rectangle::update(style_etat_data<T> & style) {
		if (style.check_implicite_change) {
			//std::cout << "value fully UPDATED" << std::endl;
			T new_val = best_result(const_etats, style);
			if (new_val != style.old_value) {
				style.changed = true;
				style.old_value = new_val;
			}
			style.check_implicite_change = false;
		}
		return style.changed;
	}

	Mesure Rectangle::get_y() {
		return best_result(const_etats, *_y);
	}
	Mesure Rectangle::get_x2() {
		return get_x() + get_width();
	}
	Mesure Rectangle::get_y2() {
		return get_y() + get_height();
	}
	Mesure Rectangle::get_width() {
		return get_what(_w);
	}
	Mesure Rectangle::get_height() {
		return get_what(_h);
	}
	Rectangle* Rectangle::copie()
	{

		Rectangle* rect = new Rectangle(*this);
		copied = true;
		//rect->_x = new style_etat_data<Mesure>();
		//*(rect->_x) = *(_x);
		return rect;
	}
	int Rectangle::get_bgcolor() {
		//std::cout << bg_color[0].data<<std::endl;
		return get_what(bg_color);
	}
	double Rectangle::get_bgopacity() {
		return get_what(bg_opacity);
	}
	void Rectangle::set_bgcolor(int color) {
		set_what(bg_color, color);
	}
	void Rectangle::set_bgopacity(double opacity) {
		set_what(bg_opacity, opacity);
	}
	void Rectangle::set_bg_img_sizing(img_sizing img_s) {
		set_what(bg_img_sizing, img_s);
	}
	img_sizing Rectangle::get_bg_img_sizing() {
		return get_what(bg_img_sizing);
	}
	void Rectangle::set_bordercolor(int color) {
		set_what(border_color, color);
	}
	void Rectangle::set_borderwidth(int width) {
		set_what(border_width, width);
	}
	int Rectangle::get_bordercolor() {
		return get_what(border_color);
	}
	int Rectangle::get_borderwidth() {
		return get_what(border_width);
	}
	void Rectangle::set_font_size(int taille) {
		set_what(font_size, taille);
	}
	void Rectangle::set_text(std::wstring texte) {
		set_what(text, texte);
	}
	void Rectangle::set_text(std::string texte) {
		set_text(s2ws(texte));
	}
	void Rectangle::set_font(std::string nompolice) {
		set_what(font, nompolice);
	}
	int Rectangle::get_font_size() {
		return get_what(font_size);
	}
	std::wstring Rectangle::get_text() {
		return get_what(text);
	}
	std::string Rectangle::get_font() {
		return get_what(font);
	}
	int Rectangle::get_font_color() {
		return get_what(font_color);
	}
	void Rectangle::set_font_color(int macouleur) {
		set_what(font_color, macouleur);
	}
	void Rectangle::set_alignement(alignement alignm) {
		set_what(align, alignm);
	}
	/*Rectangle::Rectangle(const Rectangle & src){
		_x = new style_etat_data<Mesure>();
		_y = new style_etat_data<Mesure>();
		bg_color = new style_etat_data<int>();
		bg_img = new style_etat_data<std::string>("none");
		border_color = new style_etat_data<int>();
		border_width = new style_etat_data<int>();
		bg_opacity = new style_etat_data<double>();
		bg_img_sizing = new style_etat_data<img_sizing>();

		click_fct = src.click_fct;

		 *_x=*(src._x);
		 *_y = *(src._y);
		 *bg_color=*(src.bg_color);
		 *bg_img = *(src.bg_img);
		 *border_color = *(src.border_color);
		 *border_width = *(src.border_width);
		 *bg_opacity = *(src.bg_opacity);
		 *bg_img_sizing = *(src.bg_img_sizing);

		 _w = src._w;//width
		 _h = src._h;//height

		 text = src.text;
		 font = src.font;
		 font_size = src.font_size;
		 font_color = src.font_color;
		 align = src.align;
		 text_height = src.text_height;
		 data=src.data;


	}*/
	Rectangle::~Rectangle() {
		if (LeText != NULL)delete LeText;
		for (auto& call : callbacks_etat)delete call;
		int i = 0;
		for (auto& call : myTextures) {
			if(i!=0)SDL_DestroyTexture(call);
			i++;
		}
		for (auto& sdlimg : oldIMG) { 
			if (sdlimg.second->get_owner() == this|| sdlimg.second->get_owner() == nullptr) { delete sdlimg.second; } 
			sdlimg.second = nullptr; 
		}
		if (!copied)
		{
			delete _x;
			delete _y;
			delete bg_color;
			delete bg_img;
			delete border_color;
			delete border_width;
			delete bg_opacity;
			delete bg_img_sizing;
			delete _w;//width
			delete _h;//height
			delete text;
			delete font;
			delete font_size;
			delete font_color;
			delete align;
			delete data;

			if (!const_etats.empty()) {
				etat_point_imp et = const_etats.back();
				et.etat->user--;
				if (et.etat->user == 0)
				{
					if (ma_fenetre != NULL) for (int ijki = 0; ijki < ma_fenetre->clearatclean_etat.size(); ijki++) {
						etat* ettt = ma_fenetre->clearatclean_etat[ijki];
						if (ettt == et.etat) {
							ma_fenetre->clearatclean_etat.erase(ma_fenetre->clearatclean_etat.begin() + ijki);
							ijki--;
						}
					}


					delete et.etat;
					std::cout << "etat deleted" << std::endl << std::endl;
				}
				const_etats.pop_back();
			}
			if (ma_fenetre == NULL)while (!clearatclean_etat.empty()) { delete clearatclean_etat.back(); clearatclean_etat.pop_back(); }
		}
	}
	ClickSurface* Rectangle::get_click_surface() {
		SDL_Rect stretchRect_real = intersection(stretchRect, destRect);
		surface_de_clique = ClickRect(stretchRect_real.x - get_borderwidth(), stretchRect_real.y - get_borderwidth(), stretchRect_real.w + 2 * get_borderwidth(), stretchRect_real.h + 2 * get_borderwidth());
		return &surface_de_clique;
	}
	void Rectangle::onclick_fct(int x, int y) {
		if (click_fct != NULL)
			click_fct(this, ma_fenetre, ma_loop);
		if (pos_click_fct != NULL)pos_click_fct(this, ma_fenetre, ma_loop, x, y);
	}
	void Rectangle::set_hover(bool activ) {
		set_etat_activity(activ, "hover");
	}
	void Rectangle::set_hold(bool activ) {
		set_etat_activity(activ, "hold");
	}
	void Rectangle::delete_click() {
		click_fct = NULL;
		pos_click_fct = NULL;
	}
	void Rectangle::set_click_function(Click_fontion fct) {
		click_fct = fct;
	}
	void Rectangle::set_click_function(POS_Click_fontion fct) {
		pos_click_fct = fct;
	}
	etat* Rectangle::add_etat(etat et, int importance) {
		et.user++;
		etat* et2(new etat(et));
		const_etats.push_back({ et2, importance });
		if (ma_fenetre == NULL)clearatclean_etat.push_back(et2);
		else { ma_fenetre->clearatclean_etat.push_back(et2); }
		return et2;
	}
	etat* Rectangle::get_etat(std::string nom) {
		for (auto& et : const_etats)if (et.etat->nom == nom)return et.etat;
	}
	void Rectangle::remove_etat(std::string nom) {
		for (auto& et : const_etats)if (et.etat->nom == nom) { et.etat->user--; if (et.etat->user == 0)delete et.etat; std::swap(et, const_etats.back()); const_etats.pop_back(); return; }
	}
	void Rectangle::add_etat(etat* et, int importance) {
		et->user++;
		const_etats.push_back({ et, importance });


	}
	void Rectangle::set_etat(std::string new_state) {
		currentState = new_state;
		bool deja = false;
		//if(!deja)vieux_etats_utiles.push_back(etat{new_state,false});
	}
	void Rectangle::set_etat_activity(bool activ, std::string name) {
		/*for (auto& et : etats){
			if (et.etat.nom == name){
				if (!et.etat.active&&activ)general_update = true;
				et.etat.active = activ;
			}
		}*/
		for (auto& et : const_etats) {
			if (et.etat->nom == name) {
				et.etat->active = activ;
			}
		}
	}
	struct etat_state Rectangle::etat_state(std::string name) {
		struct etat_state etat_s = { 3, 0 };

		/*for (auto& et : etats){
			if (et.etat.nom == name){
				etat_s.importance = et.importance;
				if (et.etat.active)etat_s.state=1;
				else etat_s.state = 0;
				return etat_s;
			}
		}*/
		for (auto& et : const_etats) {
			if (et.etat->nom == name) {
				etat_s.importance = et.importance;
				if (et.etat->active)etat_s.state = 1;
				else etat_s.state = 0;
				return etat_s;
			}
		}
		return etat_s;
	}

	int Rectangle::get_z_index() const {
		return Zindex;
	}
	void Rectangle::set_z_index(int index) {
		Zindex = index;
		this->ma_fenetre->update_z_index();
	}
	void Rectangle::add_callback_etat(callback_etat callback) {
		remove_callback_etat(callback.nom);
		callbacks_etat.push_back(callback.copie());
	}
	void Rectangle::remove_callback_etat(std::string nom) {
		int i = 0;
		for (auto& call : callbacks_etat) {
			if (call->nom == nom) { delete call; std::swap(call, callbacks_etat.back()); callbacks_etat.pop_back(); return; }
			i++;
		}


	}
	bool find_from_nom(std::string str, std::vector<etat> vec) {
		for (auto& ve : vec) {
			if (ve.nom == str)return ve.active;
		}
		return false;
	}
	void Rectangle::manage_callback() {
		std::vector<etat> newStat;
		for (auto& callBack : callbacks_etat) {
			bool act = false;
			if (etat_state(callBack->nom).state == 1)act = true;
			newStat.push_back(etat{ callBack->nom, act });
			bool act2 = find_from_nom(callBack->nom, vieux_etats);
			if (act == act2) {
				if (act) {
					if (callBack->on_while != NULL)callBack->on_while(this);
				}
				else {
					if (callBack->on_false != NULL)callBack->on_false(this);

				}
			}
			else if (act) {
				if (callBack->on_start != NULL)callBack->on_start(this);
			}
			else {
				if (callBack->on_end != NULL)callBack->on_end(this);
			}
		}

		while (!vieux_etats.empty())vieux_etats.pop_back();
		vieux_etats = newStat;
		//general_update = true;//on a un nouvel état on doit checker si un truc est affecté !!
		//std::cout << callBack->nom << std::endl;
		check_state_upd();
		if (general_update)general_updater();// on update...
		if (etat_state("active").state == 1)on_active();
		else out_active();
		if (etat_state("hover").state == 1)on_hover();
		else out_hover();
		if (etat_state("holder").state == 1)on_hold();
		else out_hold();

	}
	void Rectangle::TextinputFct(std::wstring input) {}
	void Rectangle::on_active() {
		//std::cout << "ACTIVITT" << std::endl;
	}
	void Rectangle::on_hover() {}
	void Rectangle::on_hold() {}
	void Rectangle::out_active() {}
	void Rectangle::out_hover() {}
	void Rectangle::out_hold() {}
	void Rectangle::general_updater() {

		for (auto& sty : point_styles) {
			sty->check_implicite_change = true; // ask for a complete review of parameters
		}
	}
	void Rectangle::finish_LOOP() {
		for (auto& sty : point_styles) {
			sty->check_implicite_change = false;
			sty->changed = false;
		}
		general_update = false;
	}

	void Rectangle::check_state_upd() {
		for (auto & et : vieux_etats_utiles) {
			bool needup = false;
			int state = etat_state(et.vieux_etat.nom).state;
			if (!et.vieux_etat.active && 1 == state) { et.vieux_etat.active = true; needup = true; }
			else if (et.vieux_etat.active && 0 == state) { et.vieux_etat.active = false; needup = true; }
			if (needup)for (auto& ref : et.style_affecte)ref->check_implicite_change = true;
		}
	}
	std::vector<Rectangle_clip>&  Rectangle::clips() {
		clip_updated = false;
		return _clips;
	}
	void  Rectangle::add_auto_clip(Rectangle_clip* r) {
		auto_p_clips.push_back(r);
	}
	void  Rectangle::remove_auto_clip(Rectangle_clip* r) {
		auto_p_clips.erase(find(auto_p_clips.begin(), auto_p_clips.end(), r));
	}
	int Rectangle::get_offset_x() {
		if (!is_offset_activated())return 0;
		return offset_x;
	}
	int Rectangle::get_offset_y() {
		if (!is_offset_activated())return 0;
		return offset_y;
	}
	void Rectangle::set_offset_x(int x) {
		offset_x = x;
	}
	void Rectangle::set_offset_y(int y) {
		offset_y = y;
	}
	void Rectangle::activate_offset(bool c) {
		active_offset = c;
	}
	bool  Rectangle::is_offset_activated() {
		return active_offset;
	}
	void Rectangle::activate_absolute(bool c) {
		active_absolute = c;
	}
	bool  Rectangle::is_absolute_activated() {
		return active_absolute;
	}
}