#include "G_inc.h"
namespace ONIGIRIX_GUI {
	bool ClickRect::IsIn(int x2, int y2) {
		return (x<x2&&y<y2&&y + h>y2&&x + w>x2);
	}
}