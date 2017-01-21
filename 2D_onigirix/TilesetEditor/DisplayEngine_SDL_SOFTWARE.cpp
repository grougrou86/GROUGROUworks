#include "DisplayEngine.h"
#include <SDL.h>
#include "ImageIncludes.h"
#include "Geometry.h"
#include "DisplayEngine_SDL_SOFTWARE.h"
namespace ONIGIRIX_GUI {

	void DisplayEngine_Software_Output::set_Software(SDL_Surface* s) {
		_s.set(s, false);
	}
	DisplayEngine_Software_Output::~DisplayEngine_Software_Output() {
		_s.set(nullptr, false);//to avoid deletion of the texture 
	}
	SDL_H_texture* DisplayEngine_Software_Output::get_SDL_TEXTURE() {
		return nullptr;
	};
	GL_H_texture* DisplayEngine_Software_Output::get_GL_TEXTURE() {
		return nullptr;
	}
	SDL_S_texture* DisplayEngine_Software_Output::get_SOFTWARE() {
		return &_s;
	}
	void DisplayEngine_Software_Output::set_height(int h) {
		_height = h;
	}
	void DisplayEngine_Software_Output::set_width(int w) {
		_width = w;
	}
	DisplayEngine_Software::DisplayEngine_Software(ViewPort v) {
		set_ViewPort(v);
		get_output();//so that it initialisate the first surface !
	}
	DisplayEngine_Software::~DisplayEngine_Software() {
		for (auto& s : surf) {
			if (s != nullptr) {
				SDL_FreeSurface(s);
				s = nullptr;
			}
		}
	}
	void DisplayEngine_Software::set_ViewPort(ViewPort v) {
		_ViewPort = v;
		ViewportChange = 1;
	}
	Image* DisplayEngine_Software::get_output() {
		
		_output.set_Software(surf[drawSurf]);

		drawSurf = (drawSurf + 1) % 2;

		if (ViewportChange != 0 || surf[drawSurf] != nullptr) {
			//need to recreat surface because not created already or because changed of dimension
			if (surf[drawSurf] != nullptr) {
				SDL_FreeSurface(surf[drawSurf]);
				surf[drawSurf] = nullptr;
			}
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
			surf[drawSurf] = SDL_CreateRGBSurface(SDL_SWSURFACE, _ViewPort.width, _ViewPort.height, 32, 0x00000000, 0x00000000, 0x00000000, 0x00000000);
#else
			surf[drawSurf] = SDL_CreateRGBSurface(SDL_SWSURFACE, _ViewPort.width, _ViewPort.height, 32, 0x00000000, 0x00000000, 0x00000000, 0x00000000);
#endif
		}
		if (ViewportChange == 1)ViewportChange = 2;
		else if (ViewportChange == 2)ViewportChange = 0;

		return &_output;
	}



	//DRAWING FUNCTION


	void DisplayEngine_Software::draw_Image(Image* image, GEOMETRY2D::Rectangle<GeometryType>* input, GEOMETRY2D::Rectangle<GeometryType>* output) {

	}
	void DisplayEngine_Software::draw_MultImage(Image* image, GEOMETRY2D::Rectangle<GeometryType>* input, GEOMETRY2D::Rectangle<GeometryType>* output) {

	}
	void DisplayEngine_Software::draw_Line(GEOMETRY2D::Line<GeometryType>* line, GeometryType thickness, RGBA_c color) {

	}
	void DisplayEngine_Software::draw_Segment(GEOMETRY2D::Segment<GeometryType>* line, GeometryType thickness, RGBA_c color) {

	}
	void DisplayEngine_Software::draw_HalfLine(GEOMETRY2D::HalfLine<GeometryType>* line, GeometryType thickness, RGBA_c color) {

	}
	void DisplayEngine_Software::draw_Polygone(GEOMETRY2D::DynamicPolygone<GeometryType>* line, RGBA_c color) {

	}
	void DisplayEngine_Software::draw_Polyline(GEOMETRY2D::DynamicPolyline<GeometryType>* line, RGBA_c color) {

	}
	void DisplayEngine_Software::draw_BesierCurve(GEOMETRY2D::BesierCurve<GeometryType>* line, GeometryType thickness, RGBA_c color) {

	}
	void DisplayEngine_Software::draw_LinearGradient(GEOMETRY2D::Quadrilater<GeometryType>* quad, RGBA_c color1, RGBA_c color2) {

	}
	void DisplayEngine_Software::draw_Shape(GEOMETRY2D::Shape<GeometryType>* quad, RGBA_c color) {

	}
	void DisplayEngine_Software::draw_Curve(GEOMETRY2D::Curve<GeometryType>* quad, RGBA_c color) {

	}

}