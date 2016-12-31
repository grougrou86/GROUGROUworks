#include"DisplayEngine.h"
#include"DisplayPacket.h"
namespace ONIGIRIX_GUI {
	bool DisplayPacketSorter(DisplayPacket* p1, DisplayPacket* p2) {
		return (*p1) < (*p2);
	}
	void DisplayEngine::draw_DisplayPacket(std::vector<DisplayPacket*>& v) {
		std::sort(v.begin(), v.end(), DisplayPacketSorter);
		for (auto& el : v) {
			el->draw(this);
			delete el;
		}
		v.clear();
	}
	void DisplayEngine::set_ViewPort(ViewPort v) {
		_viewport=v;
	}
	ViewPort DisplayEngine::get_ViewPort() {
		return _viewport;
	}
	DisplayEngine::DisplayEngine(ViewPort)
	{

	}

	DisplayEngine::~DisplayEngine()
	{

	}
}