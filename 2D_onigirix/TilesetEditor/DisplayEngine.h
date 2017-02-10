#pragma once

#include"G_inc.h"
#include<atomic>
#include"ImageIncludes.h"
#include"Geometry.h"
#include"color.h"

namespace ONIGIRIX_GUI {

	class DisplayPacket; // forward definition

	struct ViewPort {
		int x = 0;
		int y = 0;
		int width = 0;
		int height = 0;
	};


	/*
	
	Important property of the display engine :

	- the diplay engine assure that th output image is availaible up to the next call of  "get_output()" 

	*/

	

	typedef float DisplayEngine_Unit;
	typedef uint8_t DisplayEngine_ImageType;
	constexpr int DisplayEngine_DataPerPixel=4;
	

	class DisplayEngine
	{
	public:
		DisplayEngine();
		virtual ~DisplayEngine();
		
		virtual Image* get_output() = 0;// give the output and clear the rendering for next frame 

		virtual void set_ViewPort(ViewPort v)=0;
		virtual ViewPort get_ViewPort()=0;

		//drawing function


		virtual void draw_Image(Image* image, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* input, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* output )=0;
		virtual void draw_MultImage(Image* image, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* input, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* output) = 0;//draw multiplication of two images (usefull for mask)
		virtual void draw_Geometry(GEOMETRY2D::Drawable<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* line, DisplayEngine_Unit thickness, RGBA_c color )=0;
		virtual void valid_swap() = 0;// valide the frame that was been drawn and move it to the output

		void draw_DisplayPacket(std::vector<DisplayPacket*>& v);// take the vector display the packet and then delete the packet (ATTENTION) it deleats the packet 


	};

}