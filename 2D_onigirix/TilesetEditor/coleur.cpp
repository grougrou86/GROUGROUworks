#include "G_inc.h"
namespace ONIGIRIX_GUI {
	RGB_c couleurConverter(int hexValue)
	{
		RGB_c rgbColor;
		rgbColor.r = ((hexValue >> 16) & 0xFF);  // Extract the RR byte
		rgbColor.g = ((hexValue >> 8) & 0xFF);   // Extract the GG byte
		rgbColor.b = ((hexValue)& 0xFF);        // Extract the BB byte

		return rgbColor;
	};
}