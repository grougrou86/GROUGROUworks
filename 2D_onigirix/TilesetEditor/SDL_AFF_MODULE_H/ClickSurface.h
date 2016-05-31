#ifndef CLICK_SURFACE_H
#define CLICK_SURFACE_H

class ClickSurface{
public:
	virtual bool IsIn(int x, int y) = 0;
};
#endif