#pragma once
#include "DisplayEngine.h"
#include <SDL.h>
#include "ImageIncludes.h"
#include<array>
#include "DisplayEngine_SDL_SOFTWARE_output.h"
namespace ONIGIRIX_GUI {
	
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

		virtual void draw_Image(Image* image, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* input, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* output);
		virtual void draw_MultImage(Image* image, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* input, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* output);//draw multiplication of two images (usefull for mask)
		virtual void draw_Geometry(GEOMETRY2D::Drawable<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* line, DisplayEngine_Unit thickness, RGBA_c color);
		
		// test draw only for debug function to remove in future 
		void test_draw();

		virtual void valid_swap();// valide the frame that was beeing drawn and move it to the output


		//set the Display context (so that it sets it in the output )

		virtual DisplayContext get_DisplayContext();
		virtual void set_DisplayContext(DisplayContext);

	private:

		// to stored output so tu ensure that the outputed image is available up to the next call of "get_output()"

		DisplayEngine_Software_Output  _output;

		ViewPort _ViewPort;

	};
}