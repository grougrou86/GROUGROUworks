#ifndef COULEURS_H
#define COULEURS_H
namespace ONIGIRIX_GUI {

	class RGB_c {
	public:
		double r;
		double g;
		double b;
	};

	RGB_c couleurConverter(int hexValue);
}

#endif
