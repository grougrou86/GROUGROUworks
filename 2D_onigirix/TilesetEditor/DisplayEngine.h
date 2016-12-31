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
	class DisplayEngine
	{
	public:
		DisplayEngine(ViewPort);
		virtual ~DisplayEngine();
		
		virtual Image* get_output() = 0;// give the output and clear the rendering for next frame 

		virtual void set_ViewPort(ViewPort v);
		virtual ViewPort get_ViewPort();

		//drawing function


		virtual void draw_Image(Image* image, GEOMETRY::Rectangle<int> input, GEOMETRY::Rectangle<int> output )=0;
		virtual void draw_MultImage(Image* image, GEOMETRY::Rectangle<int> input, GEOMETRY::Rectangle<int> output) = 0;//draw multiplication of two images (usefull for mask)
		virtual void draw_Line(GEOMETRY::Line<int> line, int thickness, RGBA_c color )=0;
		virtual void draw_Segment(GEOMETRY::Segment<int> line, int thickness, RGBA_c color)=0;
		virtual void draw_HalfLine(GEOMETRY::HalfLine<int> line, int thickness, RGBA_c color) = 0;
		virtual void draw_Triangle(GEOMETRY::Triangle<int> line,RGBA_c color) = 0; // to draw rectangle draw to triangle
		virtual void draw_BesierCurve(GEOMETRY::BesierCurve<int> line, int thickness, RGBA_c color) = 0;
		virtual void draw_LinearGradient(GEOMETRY::Quadrilater<int> quad, RGBA_c color1, RGBA_c color2) = 0;




		void draw_DisplayPacket(std::vector<DisplayPacket*>& v);// take the vector display the packet and then delete the packet (ATTENTION) it deleats the packet 

	private:

		//Fenetre _fenetres; to set !!!!!
		ViewPort _viewport;

	};

}