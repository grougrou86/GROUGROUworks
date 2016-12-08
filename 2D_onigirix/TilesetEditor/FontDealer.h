#pragma once
#include"FontGlypsSurface.h"
namespace ONIGIRIX_GUI {
	class FontDealer {
	public:
		FontDealer(DisplayContext r = DisplayContext());
		void set_DisplayContext(DisplayContext r);
		GlypsImage* get_Font(std::wstring font, unsigned int size);
	private:
		std::unordered_map<std::wstring, std::unordered_map<unsigned int,  GlypsImage>> _font_image;
		DisplayContext _DisplayContext;
	};
}