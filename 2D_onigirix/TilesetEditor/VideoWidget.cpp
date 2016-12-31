#include"ALL_WIDGET.h"
#include"G_inc.h"
#include<chrono>

namespace ONIGIRIX_GUI {

	namespace MULTIMENU_CLICK_FCT {//to avoid disrupting overclasses

		void playButtonClick(Rectangle* r, Fenetre* f, SDL_mainLoop* l) {
			bool play = !r->etat_state("play").state;
			((VideoWidget*)r->data->pointer_data["WIDGET"])->_true_vid->play(play);
			r->set_etat_activity(play, "play");
		}
		void timeSET(Rectangle* r, Fenetre* f, SDL_mainLoop* l,int x , int y) {
			int time = ((VideoWidget*)r->data->pointer_data["WIDGET"])->_true_vid->get_max_time()*((double)x/(double)(r->rel_w()));
			((VideoWidget*)r->data->pointer_data["WIDGET"])->_true_vid->set_time(time);
		}
		void set_avancement(Rectangle* r) {
			double time = (double)((VideoWidget*)r->data->pointer_data["WIDGET"])->_true_vid->get_time()/(double)((VideoWidget*)r->data->pointer_data["WIDGET"])->_true_vid->get_max_time();
			r->set_width(Mesure(0,100.0*time));
			if(time>0.99&&!((VideoWidget*)r->data->pointer_data["WIDGET"])->_true_vid->is_play())((Rectangle*)r->data->pointer_data["PLAYBUTT"])->set_etat_activity(false, "play");
		}
		void ChangeVolume(Rectangle* r1, int) {
			double vol = r1->data->scroll_data["scroll"]->get_value();
			((VideoWidget*)r1->data->pointer_data["WIDGET"])->_true_vid->set_volume(vol*100.0);
		}
		void hide_show_controls(Rectangle* r) {
			int currh = -((Widget*)(r->data->pointer_data["WIDGET"]))->get_y().px;
			bool hover=  ((etat*)(r->data->pointer_data["HOVERING"]))->active;
			if (r->data->int_data["HOVERED"] != hover) {
				r->data->int_data["HOVERED"] = hover;
				r->data->int_data["START"] = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
				if (currh != 0 && currh != r->data->int_data["MAX_HEIGHT"]) {
					if (hover) {
						r->data->int_data["START"] -= (double)currh / (double)r->data->int_data["MAX_HEIGHT"] * (double)r->data->int_data["TIME"];
					}
					else {
						r->data->int_data["START"] -= (1-(double)currh / (double)r->data->int_data["MAX_HEIGHT"]) * (double)r->data->int_data["TIME"];
					}
				}
			}
			if (currh < r->data->int_data["MAX_HEIGHT"] && hover) {
				int time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
				((Widget*)(r->data->pointer_data["WIDGET"]))->set_y(Mesure(-(int)(((double)(time - r->data->int_data["START"]) / (double)r->data->int_data["TIME"])*(double)r->data->int_data["MAX_HEIGHT"]), 100));
			}
			if (0 < currh&&!hover) {
				int time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
				((Widget*)(r->data->pointer_data["WIDGET"]))->set_y(Mesure(-(int)(((double)(-time + r->data->int_data["TIME"]+r->data->int_data["START"])/(double)r->data->int_data["TIME"])*(double)r->data->int_data["MAX_HEIGHT"]), 100));
			}
			
		}
	}
	void resizing_video_good(Rectangle* r) {
		auto VidWidget = static_cast<VideoWidget*>(r->RelativeElement);
		auto Vid = VidWidget->_true_vid;
		if (Vid->get_max_height() != 0) {
			double ratio = (double)(Vid->get_max_height()) / (double)(Vid->get_max_width());
			double ratio2 = (double)(VidWidget->rel_h()) / ((double)VidWidget->rel_w());
			int nextH = 0;
			int nextW = 0;
			if (ratio > ratio2) {
				nextH = VidWidget->rel_h();
				nextW = (double)nextH / (double)ratio;
			}
			else {
				nextW = VidWidget->rel_w();
				nextH = (double)nextW*(double)ratio;
			}
			
			r->set_height(Mesure(nextH, 0));
			r->set_width(Mesure(nextW, 0));
			r->set_y(Mesure(-nextH / 2, 50));
			r->set_x(Mesure(-nextW / 2, 50));
			if (nextH > Vid->get_max_height())nextH = Vid->get_max_height();
			if (nextW > Vid->get_max_width())nextH = Vid->get_max_width();
			Vid->set_width_height(nextW, nextH);
		}
	}

	VideoWidget::VideoWidget(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, std::string _video) : Widget(f, x, y, w, h, 0, 0) {

		//background color

		this->get_background()->set_bgcolor(0x000000);
		this->get_background()->set_bgopacity(1);

		//the video 

		_vid = W_add(new Rectangle(f));
		_vid->set_bg_img(_video);
		_vid->set_width(Mesure(0, 100));
		_vid->set_height(Mesure(0, 100));
		_true_vid = static_cast<ImageVideo*>(_vid->get_bg_from_name(_video));
		_vid->draw(f);
		_true_vid->play(false);
		_vid->everyframe_fct = resizing_video_good;

		//the controls

		auto player_hover = this->get_background()->get_etat("hover");

		auto controls = W_add(new Widget(f, Mesure(0, 0), Mesure(0, 100), Mesure(0, 100), Mesure(40, 0)));
		controls->get_background()->data->int_data["TIME"] = 350;
		controls->get_background()->data->int_data["START"] = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
		controls->get_background()->data->int_data["MAX_HEIGHT"]=40;
		controls->get_background()->data->int_data["HOVERED"] = false;
		controls->get_background()->everyframe_fct = MULTIMENU_CLICK_FCT::hide_show_controls;
		controls->get_background()->data->pointer_data["HOVERING"]=player_hover;



		auto btn1 = controls->W_add(new Rectangle(f, Mesure(0, 0), Mesure(0, 0), Mesure(0, 100), Mesure(40, 0)));
		btn1->set_bgcolor(0x333333);
		btn1->set_bgopacity(0.7);
		
		auto play = controls->W_add(new Rectangle(f, Mesure(9, 0), Mesure(5, 0), Mesure(30, 0), Mesure(30, 0)));
		play->data->pointer_data["WIDGET"] = this;//sewt a reference to the widget hihi
		play->set_bg_img("images/VideoPlayer/play-button.png");


		play->add_etat(etat("play",false),2);
		play->set_etat_activity(false, "play");

		play->set_click_function(MULTIMENU_CLICK_FCT::playButtonClick);

		play->set_etat("play");
		play->set_bg_img("images/VideoPlayer/pause.png");

		play->set_etat("hover");
		
		play->set_width(Mesure(36, 0));
		play->set_height(Mesure(36, 0));
		play->set_x(Mesure(7, 0));
		play->set_y(Mesure(-38, 100));
		
		auto TimeBar = controls->W_add(new Rectangle(f, Mesure(50, 0), Mesure(10, 0), Mesure(-100, 100), Mesure(20, 0)));
		TimeBar->set_bgcolor(0xffffff);
		TimeBar->set_bgopacity(1);
		TimeBar->set_click_function(MULTIMENU_CLICK_FCT::timeSET);
		TimeBar->data->pointer_data["WIDGET"] = this;//sewt a reference to the widget hihi

		auto ProgBar = controls->W_add(new Rectangle(f, Mesure(0, 0), Mesure(0, 0), Mesure(0, 100), Mesure(0, 100)));
		ProgBar->set_bgcolor(0x000000);
		ProgBar->set_bgopacity(1);
		ProgBar->RelativeElement = TimeBar;
		ProgBar->everyframe_fct=MULTIMENU_CLICK_FCT::set_avancement;
		ProgBar->data->pointer_data["WIDGET"] = this;//sewt a reference to the widget hihi
		ProgBar->data->pointer_data["PLAYBUTT"] = play;

		auto Volume = controls->W_add(new Scroll(f,Mesure(40,0),Mesure(10,0),Mesure(10,0),Mesure(-45,100), Mesure(15, 0),false));
		Volume->set_value(1.0);
		Volume->add_on_change(MULTIMENU_CLICK_FCT::ChangeVolume);
		(*Volume)[0]->data->pointer_data["WIDGET"] = this;
	}
	

}