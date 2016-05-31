#ifndef CLICK_RECTANGLE_H
#define CLICK_RECTANGLE_H

#include "G_inc.h"

class ClickRect : public ClickSurface{
public:
	ClickRect(int _x, int _y, int _w, int _h): x(_x),y(_y),w(_w),h(_h) {}
	ClickRect():x(0), y(0), w(0), h(0) {}
	virtual bool IsIn(int x, int y);
	int x;
	int y;
	int w;
	int h;
};
#endif