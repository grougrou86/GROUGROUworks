#pragma once

//the goal is to minimise the communication to other thred but array must be optimisedthe goal is not to send it each frame and to send only changes ! 
//that's why each DISPLAY_RECT has an ID

namespace ONIGIRIX_GUI {

	template <typename T> //typename for texture adresse

	struct DISPLAY_RECT
	{

		int id;

		int zIndex;

		int w;
		int h;
		int x;
		int y;
		int color;
		T* Texture;
		int Texture_stretch_w;
		int Texture_stretch_h;

	};

	template <typename T> //typename for texture adresse

	struct DYSPLAY_ARRAY
	{
		std::vector<ONIGIRIX_GUI::DISPLAY_RECT<T>> rectangles;
	};
}