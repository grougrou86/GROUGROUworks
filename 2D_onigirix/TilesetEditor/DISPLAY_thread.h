#pragma once

#include "G_inc.h"
#include "DISPLAY_STRUCTURE.h"

namespace ONIGIRIX_GUI {
	template <typename T>
	class DISPLAY_THREAD {

		virtual void EDIT_fenetre(DYSPLAY_ARRAY<T> changes, Fenetre* f) = 0;


	};
}