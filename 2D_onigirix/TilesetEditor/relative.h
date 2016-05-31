#pragma once
namespace ONIGIRIX_GUI {
	class Relative
	{
	public:
		virtual int rel_x() = 0;
		virtual int rel_y() = 0;
		virtual int rel_w() = 0;
		virtual int rel_h() = 0;
	};
}