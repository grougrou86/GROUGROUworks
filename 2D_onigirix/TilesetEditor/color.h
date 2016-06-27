#ifndef COULEURS_H
#define COULEURS_H
namespace ONIGIRIX_GUI {

	class RGB_c {
	public:
		double get_r();
		double get_g();
		double get_b();
		void set_r(double);
		void set_g(double);
		void set_b(double);
	private:
		double r;
		double g;
		double b;
	};

	bool operator< (RGB_c c1, RGB_c c2);
	bool operator> (RGB_c c1, RGB_c c2);

	RGB_c couleurConverter(int hexValue);
}

#endif
