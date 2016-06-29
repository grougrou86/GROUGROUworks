#include "G_inc.h"
namespace ONIGIRIX_GUI {


	bool operator< (RGB_c c1, RGB_c c2) {
		if (c1.get_r() != c2.get_r())return c1.get_r() < c2.get_r();
		if (c1.get_g() != c2.get_g())return c1.get_g() < c2.get_g();
		if (c1.get_b() != c2.get_b())return c1.get_b() < c2.get_b();
	}
	bool operator> (RGB_c c1, RGB_c c2) {
		if (c1.get_r() != c2.get_r())return c1.get_r() > c2.get_r();
		if (c1.get_g() != c2.get_g())return c1.get_g() > c2.get_g();
		if (c1.get_b() != c2.get_b())return c1.get_b() > c2.get_b();
	}

	double RGB_c :: get_r() const {
		return r;
	}
	double RGB_c :: get_g() const {
		return g;
	}
	double RGB_c :: get_b() const {
		return b;
	}
	void RGB_c :: set_r(double _r) {
		r = _r;
	}
	void RGB_c :: set_g(double _g) {
		g = _g;
	}
	void RGB_c :: set_b(double _b) {
		b = _b;
	}

	RGB_c couleurConverter(int hexValue)
	{
		RGB_c rgbColor;
		rgbColor.set_r((hexValue >> 16) & 0xFF);  // Extract the RR byte
		rgbColor.set_g((hexValue >> 8) & 0xFF);   // Extract the GG byte
		rgbColor.set_b((hexValue)& 0xFF);        // Extract the BB byte

		return rgbColor;
	};
}