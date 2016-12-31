#include "color.h"
namespace ONIGIRIX_GUI {


	bool operator< (RGB_c c1, RGB_c c2) {
		if (c1.get_r() != c2.get_r())return c1.get_r() < c2.get_r();
		if (c1.get_g() != c2.get_g())return c1.get_g() < c2.get_g();
		if (c1.get_b() != c2.get_b())return c1.get_b() < c2.get_b();
		return false;
	}
	bool operator> (RGB_c c1, RGB_c c2) {
		if (c1.get_r() != c2.get_r())return c1.get_r() > c2.get_r();
		if (c1.get_g() != c2.get_g())return c1.get_g() > c2.get_g();
		if (c1.get_b() != c2.get_b())return c1.get_b() > c2.get_b();
		return false;
	}
	bool operator< (RGBA_c c1, RGBA_c c2) {
		if (c1.get_a() != c2.get_a())return c1.get_a() < c2.get_a();
		else return ((RGB_c)c1) < ((RGB_c)c2);
	}
	bool operator> (RGBA_c c1, RGBA_c c2) {
		if (c1.get_a() != c2.get_a())return c1.get_a() > c2.get_a();
		else return ((RGB_c)c1) > ((RGB_c)c2);
	}
	double RGB_c :: get_r() const {
		return _r;
	}
	double RGB_c :: get_g() const {
		return _g;
	}
	double RGB_c :: get_b() const {
		return _b;
	}
	double RGBA_c::get_a() const {
		return _a;
	}
	void RGB_c :: set_r(double r) {
		_r = r;
	}
	void RGB_c :: set_g(double g) {
		_g = g;
	}
	void RGB_c :: set_b(double b) {
		_b = b;
	}
	void RGBA_c::set_a(double a) {
		_a = a;
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