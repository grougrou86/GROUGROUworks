#include "G_inc.h" 

#include<iostream>

namespace ONIGIRIX_GUI {
	int etat::total = 0;
	callback_etat* callback_etat::copie() const
	{
		return new callback_etat(*this);
	}
}