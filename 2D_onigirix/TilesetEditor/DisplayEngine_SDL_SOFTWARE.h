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
		void set_height(int);
		void set_width (int);

		void set_Software(SDL_Surface*);// only the display engine can set it 
		
		SDL_S_texture _s;
	};

	//the universal display engine 
	// this display engine must work under every c++ compiler non depending frome system 
	// on can have the sdl function related to surface provade apart from library(for ex if system is not compatible to sdl ) TO DO !!

	class DisplayEngine_Software {
	public:

		DisplayEngine_Software(ViewPort);
		~DisplayEngine_Software();
		virtual void set_ViewPort(ViewPort v);

		virtual Image* get_output();


		virtual void draw_Image(Image* image, GEOMETRY2D::Rectangle<GeometryType>* input, GEOMETRY2D::Rectangle<GeometryType>* output);
		virtual void draw_MultImage(Image* image, GEOMETRY2D::Rectangle<GeometryType>* input, GEOMETRY2D::Rectangle<GeometryType>* output);//draw multiplication of two images (usefull for mask)
		virtual void draw_Line(GEOMETRY2D::Line<GeometryType>* line, GeometryType thickness, RGBA_c color);
		virtual void draw_Segment(GEOMETRY2D::Segment<GeometryType>* line, GeometryType thickness, RGBA_c color);
		virtual void draw_HalfLine(GEOMETRY2D::HalfLine<GeometryType>* line, GeometryType thickness, RGBA_c color);
		virtual void draw_Polygone(GEOMETRY2D::DynamicPolygone<GeometryType>* line, RGBA_c color); // to draw rectangle draw to triangle
		virtual void draw_Polyline(GEOMETRY2D::DynamicPolyline<GeometryType>* line, RGBA_c color); // to draw rectangle draw to triangle
		virtual void draw_BesierCurve(GEOMETRY2D::BesierCurve<GeometryType>* line, GeometryType thickness, RGBA_c color);
		virtual void draw_LinearGradient(GEOMETRY2D::Quadrilater<GeometryType>* quad, RGBA_c color1, RGBA_c color2);
		virtual void draw_Shape(GEOMETRY2D::Shape<GeometryType>* quad, RGBA_c color);
		virtual void draw_Curve(GEOMETRY2D::Curve<GeometryType>* quad, RGBA_c color);


	private:

		// to stored output so tu ensure that the outputed image is available up to the next call of "get_output()"
		std::array<SDL_Surface*, 2> surf = {nullptr,nullptr};

		size_t drawSurf = 0;// surface to draw at 

		DisplayEngine_Software_Output  _output;

		ViewPort _ViewPort;

		int ViewportChange = 0; // 0 -> no change ==>change the viewport -> value to 1 / 2 need to change the images size for respectively the first and second one 
	};
}