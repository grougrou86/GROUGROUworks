#include <string>
#include <iostream>
#include "test.h"
#include "timer.h"
#include "TYPELIST.h"
#include "FastUnorderedMap.h"
#include <unordered_map>

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
	
	/*
	int era = 30000;

	FastMap< std::string, int> FastM;
	std::unordered_map< std::string, int> M;

	std::vector< std::string> noms;
	std::vector<FastMapSearch< std::string>> searches;

	Timer timer;

	for (unsigned int i = 0; i < 100; i++) {
		noms.push_back(std::to_string(i));
		searches.push_back(FastMapSearch< std::string>(std::to_string(i+9999999999)));
	}

	timer.reset();
	for (unsigned int j = 0; j < 10000000; j++) {
		for (unsigned int i = 0; i < 100; i+=4) {
			int* s = FastM[searches[i]];
			if (s == nullptr) {
				FastM.Insert(searches[i], i);
				s = FastM[searches[i]];
			}
			(*s)++;
		}
	}
	std::cout << timer.elapsed() << std::endl;

	timer.reset();
	for (unsigned int j = 0; j < 10000000; j++) {
		for (unsigned int i = 0; i < 100; i+=4) {
			//std::unordered_map< std::string, int>::iterator it = M.find(noms[i]);
			//if (it == M.end()) {
			//	M[noms[i]] =i;
			//}
			M[noms[i]]++;
		}
	}
	std::cout << timer.elapsed() << std::endl;
	*/


	Timer timer;

	timer.reset();
	uint32_t b1 = 2,b2=2;
	uint32_t a1 = 2,a2=2;
	for (uint32_t j = 0; j < 1000000000; j++) {
		b1=b1+b2;
	}
	std::cout << timer.elapsed() <<" "<< b1 << std::endl;

	timer.reset();
	uint64_t c = 2;
	for (uint64_t j = 0; j < 1000000000; j++) {
		c = c*c;
		c = c + c;
	}
	std::cout << timer.elapsed() << " " << c << std::endl;



	system("PAUSE");

}