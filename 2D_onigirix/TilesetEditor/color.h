#ifndef COULEURS_H
#define COULEURS_H
#include <array>
#include"useful-fct.h"
namespace ONIGIRIX_GUI {

	class RGB_c {
	public:
		double get_r() const ;
		double get_g() const ;
		double get_b() const ;
		void set_r(double);
		void set_g(double);
		void set_b(double);
	private:
		double _r;
		double _g;
		double _b;
	};
	class RGBA_c : public RGB_c {
		
	public:
		double get_a() const ;
		void set_a(double a);
	private:
		double _a;

	};


	bool operator< (RGB_c c1, RGB_c c2);
	bool operator> (RGB_c c1, RGB_c c2);
	bool operator< (RGBA_c c1, RGBA_c c2);
	bool operator> (RGBA_c c1, RGBA_c c2);

	RGB_c couleurConverter(int hexValue);
}


namespace std {
	template <> struct hash<ONIGIRIX_GUI::RGB_c>
	{
		size_t operator()(const ONIGIRIX_GUI::RGB_c & x) const
		{
			double to_hash[3] = { x.get_r(),x.get_g(),x.get_b() };
			return hasharray(to_hash);
		}
		size_t operator()(const ONIGIRIX_GUI::RGBA_c & x) const
		{
			double to_hash[4] = { x.get_r(),x.get_g(),x.get_b(),x.get_a() };
			return hasharray(to_hash);
		}
	};

}
#endif
