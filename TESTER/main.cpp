#include <string>
#include <iostream>
#include "test.h"
#include "timer.h"
#include "TYPELIST.h"
#include "FastUnorderedMap.h"
#include <unordered_map>
#include <cmath>
#include <fixed_point.h>

void sin(int) {}
/*

u32 x, y;
u64 v = ((u64)x) << 32 | y;
unpack:

x = (u32)((v & 0xFFFFFFFF00000000LL) >> 32);
y = (u32)(v & 0xFFFFFFFFLL);

void com

*/
int main(int argc, char *argv[])
{
	/*double bl = 3.1;
	int bk = 0;
	std::cout << G_sin(bl) << std::endl;;
	std::cout << G_sin(bk) << std::endl;;
	*/

	fpml::fixed_point<unsigned int, 0> a1 = 0.5;
	fpml::fixed_point<unsigned int, 0> b1 = 0.5;
	float a2 = 0.5;
	float b2 = 0.5;

	Timer timer;
	for (size_t i = 0; i < 1000000000; i++)
	{
		b1 = a1 * b1;
		a1 = b1*(a1+b1);
	}
	std::cout << timer.elapsed() << std::endl;
	timer.reset();
	for (size_t i = 0; i < 1000000000; i++)
	{
		b2 = a2 * b2;
		a2 = b2*(a2+b2);
	}
	std::cout << timer.elapsed() << std::endl;
	
	std::cout << b1 <<"--"<< b2 << std::endl;

	system("PAUSE");

	//access / set to raw 

	fpml::fixed_point<unsigned int, 0> a = 0.5;
	fpml::fixed_point<unsigned int, 0> b = 0.5;
	a.set_raw(0xFFFFFFFF);

	b = a*fpml::fixed_point<unsigned int, 0>(0.5);

	double c = a;

	std::cout << timer.elapsed() << a.get_raw() << "/\\" << b.get_raw() << "/\\" << c << std::endl;

}