#pragma once

#include"G_inc.h"
#include<atomic>

namespace ONIGIRIX_GUI {

	struct DisplayEngineWievPort {
		std::atomic<int> x = 0;
		std::atomic<int> y = 0;
		std::atomic<int> width = 0;
		std::atomic<int> height = 0;
	};

	class DisplayEngine
	{
	public:
		DisplayEngine();
		~DisplayEngine();

		virtual void Reset() = 0;//reset to fulltransparent

		//drawing function

		



	private:

		//Fenetre _fenetres; to set !!!!!

		DisplayEngineWievPort _viewport;

	};

}