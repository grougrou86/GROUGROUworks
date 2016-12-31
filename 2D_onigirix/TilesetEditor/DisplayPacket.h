#pragma once
#include"DisplayEngine.h"
#include"ZIndex.h"

namespace ONIGIRIX_GUI {
	class DisplayPacket {
	public:
		virtual void draw(DisplayEngine*);
		ZIndex get_ZIndex();//return z index
		void set_ZIndex(ZIndex);//setting the z index

		bool operator< (DisplayPacket paket2);
		bool operator> (DisplayPacket paket2);

	private:
		ZIndex _index;
	};

}