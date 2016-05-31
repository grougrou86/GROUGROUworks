#include "G_inc.h" 
#include <SDL.h>
namespace ONIGIRIX_GUI {
	void Forme::dys_updated() {
		_dys_changed = false;
	}
	void Forme::dys_changed() {
		_dys_changed = true;
	}
	bool Forme::dys_is_changed() {
		return _dys_changed;
	}
}