#include"FontDealer.h"
#include"FontGlypsSurface.h"

namespace ONIGIRIX_GUI {
	FontDealer::FontDealer(DisplayContext r) {
		_DisplayContext = r;
	}
	void FontDealer::set_DisplayContext(DisplayContext r) {
		_DisplayContext = r;
	}
	GlypsImage*  FontDealer::get_Font(std::wstring font, unsigned int size) {
		std::unordered_map<unsigned int, GlypsImage>* search1 = &_font_image[font];// get all the already created images for the font 
		std::unordered_map<unsigned int, GlypsImage>::iterator iter = search1->find(size);//search if existing

		if (iter != search1->end())
		{
			return &(iter->second);
		}
		search1->insert(std::pair<unsigned int, GlypsImage>(size,GlypsImage({ font ,size },_DisplayContext)));
		(*search1)[size].set_owner(this);
		return &(*search1)[size];
	}

}
