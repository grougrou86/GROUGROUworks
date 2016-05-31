#ifndef CLICK_SURFACE_H
#define CLICK_SURFACE_H
namespace ONIGIRIX_GUI {
	class ClickSurface {
	public:
		virtual bool IsIn(int x, int y) = 0;
	};
}
#endif