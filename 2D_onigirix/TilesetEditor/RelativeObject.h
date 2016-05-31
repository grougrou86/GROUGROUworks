#pragma once
namespace ONIGIRIX_GUI {
	class RelativeObject {
		virtual int get_x_rel() = 0;
		virtual int get_y_rel() = 0;
		virtual int get_w_rel() = 0;
		virtual int get_h_rel() = 0;
	};
}