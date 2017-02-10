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
	private :

		//set_hieght / width update the width the sooner as possible 
		// ---> it update the Edit frame if it is bad size and ( if it as not been acced since last swap or at next swap )
		// ---> between each swap the Edit (sdl_surface) and the Displayable sdl_surface are promised to be constant !!!
		void set_height(int);
		void set_width (int);


		SDL_Surface* get_Edit();// only the display engine can set it 
		void swap(); // swap the edited frame so that it can b e render and accessed throw get_SDL_TEXTURE

		SDL_S_texture _s0;
		SDL_S_texture _s1;

		//internal usage only

		//about size abdate
		bool size_updated = true;//if the asked size is the current ouput size
		int asked_height = -1;
		int asked_width = -1;

		bool edit_accessed = false; // if get_Edit() has been called since last call of swap()

		bool _s0_update = true; //if the size of the display frame will be  changable of s0
		bool _s1_update = true; //if the size of the display frame will be  changable of s1
		bool editable_texture=0;
		void reset_s0();//destroy s0 and make it again using the current dimmention
		void reset_s1();//destroy s1 and make it again using the current dimmention

	};

	//the universal display engine 
	// this display engine must work under every c++ compiler non depending frome system 
	// on can have the sdl function related to surface provade apart from library(for ex if system is not compatible to sdl ) TO DO !!



	class DisplayEngine_Software : public DisplayEngine {
	public:
		DisplayEngine_Software(ViewPort);
		virtual ~DisplayEngine_Software();

		virtual ViewPort get_ViewPort();
		virtual void set_ViewPort(ViewPort v);

		virtual Image* get_output();

		virtual void draw_Image(Image* image, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* input, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* output) = 0;
		virtual void draw_MultImage(Image* image, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* input, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* output) = 0;//draw multiplication of two images (usefull for mask)
		virtual void draw_Geometry(GEOMETRY2D::Drawable<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* line, DisplayEngine_Unit thickness, RGBA_c color) = 0;


	private:

		// to stored output so tu ensure that the outputed image is available up to the next call of "get_output()"

		DisplayEngine_Software_Output  _output;

		ViewPort _ViewPort;

	};
}