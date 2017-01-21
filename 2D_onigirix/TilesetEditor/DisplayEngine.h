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

	typedef double GeometryType;

	class DisplayEngine
	{
	public:
		DisplayEngine(ViewPort);
		virtual ~DisplayEngine();
		
		virtual Image* get_output() = 0;// give the output and clear the rendering for next frame 

		virtual void set_ViewPort(ViewPort v);
		virtual ViewPort get_ViewPort();

		//drawing function


		virtual void draw_Image(Image* image, GEOMETRY2D::Rectangle<GeometryType>* input, GEOMETRY2D::Rectangle<GeometryType>* output )=0;
		virtual void draw_MultImage(Image* image, GEOMETRY2D::Rectangle<GeometryType>* input, GEOMETRY2D::Rectangle<GeometryType>* output) = 0;//draw multiplication of two images (usefull for mask)
		virtual void draw_Line(GEOMETRY2D::Line<GeometryType>* line, GeometryType thickness, RGBA_c color )=0;
		virtual void draw_Segment(GEOMETRY2D::Segment<GeometryType>* line, GeometryType thickness, RGBA_c color)=0;
		virtual void draw_HalfLine(GEOMETRY2D::HalfLine<GeometryType>* line, GeometryType thickness, RGBA_c color) = 0;
		virtual void draw_Polygone(GEOMETRY2D::DynamicPolygone<GeometryType>* line, RGBA_c color) = 0; // to draw rectangle draw to triangle
		virtual void draw_Polyline(GEOMETRY2D::DynamicPolyline<GeometryType>* line, RGBA_c color) = 0; // to draw rectangle draw to triangle
		virtual void draw_BesierCurve(GEOMETRY2D::BesierCurve<GeometryType>* line, GeometryType thickness, RGBA_c color) = 0;
		virtual void draw_LinearGradient(GEOMETRY2D::Quadrilater<GeometryType>* quad, RGBA_c color1, RGBA_c color2) = 0;
		virtual void draw_Shape(GEOMETRY2D::Shape<GeometryType>* quad, RGBA_c color) = 0;
		virtual void draw_Curve(GEOMETRY2D::Curve<GeometryType>* quad, RGBA_c color) = 0;

		void draw_DisplayPacket(std::vector<DisplayPacket*>& v);// take the vector display the packet and then delete the packet (ATTENTION) it deleats the packet 

	private:

		//Fenetre _fenetres; to set !!!!!
		ViewPort _viewport;

	};

}