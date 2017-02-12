#include "DisplayEngine.h"
#include <SDL.h>
#include "ImageIncludes.h"
#include "Geometry.h"
#include "DisplayEngine_SDL_SOFTWARE.h"
#include "DisplayEngine_SDL_SOFTWARE_output.h"
namespace ONIGIRIX_GUI {
	
	DisplayEngine_Software::DisplayEngine_Software(ViewPort v) {
		set_ViewPort(v);
		_output.set_owner(this);

	}
	DisplayEngine_Software::~DisplayEngine_Software() {
		
	}
	void DisplayEngine_Software::set_ViewPort(ViewPort v) {
		_ViewPort = v;
		_output.set_height(v.height);
		_output.set_width(v.width);
	}
	ViewPort DisplayEngine_Software::get_ViewPort() {
		return _ViewPort;
	}
	Image* DisplayEngine_Software::get_output() {
		return &_output;
	}
	DisplayContext DisplayEngine_Software::get_DisplayContext() {
		return _output.get_DisplayContext();
	}
	void DisplayEngine_Software::set_DisplayContext(DisplayContext d) {
		_output.set_DisplayContext(d);
	}
	//DRAWING FUNCTION


	void DisplayEngine_Software::draw_Image(Image* image, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* input, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* output) {
		auto surface = _output.get_Edit();
	}
	void DisplayEngine_Software::draw_MultImage(Image* image, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* input, GEOMETRY2D::Rectangle<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* output) {
		auto surface = _output.get_Edit();
	}
	void DisplayEngine_Software::draw_Geometry(GEOMETRY2D::Drawable<DisplayEngine_Unit, DisplayEngine_ImageType, DisplayEngine_DataPerPixel>* line, DisplayEngine_Unit thickness, RGBA_c color) {
		auto surface = _output.get_Edit();
	}
	void DisplayEngine_Software::test_draw() {
		auto surface = _output.get_Edit();
	}
	void DisplayEngine_Software::valid_swap() {
		_output.swap();
	}

}