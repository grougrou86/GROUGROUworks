#pragma once
#pragma once
#include"G_inc.h"
namespace ONIGIRIX_GUI {

	namespace MULTIMENU_CLICK_FCT {
		void playButtonClick(Rectangle* r, Fenetre* f, SDL_mainLoop* l);
		void timeSET(Rectangle* r, Fenetre* f, SDL_mainLoop* l,int x, int y);
		void set_avancement(Rectangle* r);
		void ChangeVolume(Rectangle* r1, int);
	}

	class VideoWidget :public Widget {
	public:

		friend void MULTIMENU_CLICK_FCT::playButtonClick(Rectangle* r, Fenetre* f, SDL_mainLoop* l);
		friend void MULTIMENU_CLICK_FCT::timeSET(Rectangle* r, Fenetre* f, SDL_mainLoop* l,int x,int y);
		friend void MULTIMENU_CLICK_FCT::set_avancement(Rectangle* r);
		friend void MULTIMENU_CLICK_FCT::ChangeVolume(Rectangle* r1, int);
		VideoWidget(Fenetre* f, Mesure x, Mesure y, Mesure w, Mesure h, std::string video);
		

	private:

		Rectangle* _vid;
		ImageVideo* _true_vid;

	};
}