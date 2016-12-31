#include"DisplayPacket.h"

namespace ONIGIRIX_GUI {

	ZIndex DisplayPacket::get_ZIndex() {
		return _index;
	}
	void DisplayPacket::set_ZIndex(ZIndex i) {
		_index = i;
	}
	void DisplayPacket::draw(DisplayEngine*) {
		//draw nothing 
	}
	bool DisplayPacket::operator< (DisplayPacket paket2) {
		return get_ZIndex() < paket2.get_ZIndex();
	}
	bool DisplayPacket::operator> (DisplayPacket paket2) {
		return get_ZIndex() > paket2.get_ZIndex();
	}
}