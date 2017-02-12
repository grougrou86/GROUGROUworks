#pragma once

#include "DisplayEngine.h"
#include <SDL.h>
#include "ImageIncludes.h"
#include<array>
namespace ONIGIRIX_GUI {

	class DisplayEngine_Software;

	class DisplayEngine_Software_Output : public Image {
		friend DisplayEngine_Software;

		virtual  SDL_H_texture* get_SDL_TEXTURE();
		virtual  GL_H_texture* get_GL_TEXTURE();
		virtual  SDL_S_texture* get_SOFTWARE();

		virtual ~DisplayEngine_Software_Output();

		virtual DisplayContext get_DisplayContext();
		virtual void set_DisplayContext(DisplayContext);

	private:

		//set_height / width update the width the sooner as possible 
		// ---> it update the Edit frame if it is bad size and ( if it as not been acced since last swap or at next swap )
		// ---> between each swap the Edit (sdl_surface) and the Displayable sdl_surface are promised to be constant !!!
		void set_height(int);
		void set_width(int);


		SDL_Surface* get_Edit();// only the display engine can set it 
		void swap(); // swap the edited frame so that it can b e render and accessed throw get_SDL_TEXTURE

		SDL_S_texture _s0;
		SDL_S_texture _s1;

		SDL_H_texture _h0;
		SDL_H_texture _h1;


		DisplayContext _DisplayContext;
		//internal usage only

		//about size abdate
		bool size_updated = true;//if the asked size is the current ouput size
		int asked_height = -1;
		int asked_width = -1;

		bool edit_accessed = false; // if get_Edit() has been called since last call of swap()

		bool _s0_updated = true; //if s0 as same size as display (false -> need reset)
		bool _s1_updated = true; //if s1 as same size as display (false -> need reset)
		bool editable_texture = 0;
		void reset_0();//destroy s0, h0 and make it again using the current dimmention
		void reset_1();//destroy s1, h1 and make it again using the current dimmention

		// for the hardware texture

		bool _h_update_0 = false;	// if h0 need update
		bool _h_update_1 = false;	// if h1 need update
		bool _h_reset_0 = false;	// if h0 need reset
		bool _h_reset_1 = false;	// if h1 need reset


	};

}