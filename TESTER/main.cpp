#include <string>
#include <iostream>
#include "test.h"
#include "timer.h"
#include "TYPELIST.h"

void sin(int) {}

class A {
public:
	virtual void print() {
		std::cout << "A"<<_a << std::endl;
	}
	int _a = 1;
};
class B : public A{
public:
	B() {
		A::_a = 3;
	}
	virtual void print() {
		std::cout << "B" <<_a<< std::endl;
	}
	virtual void print3() {
		std::cout << "GFRR" << _c << std::endl;
	}
	int _a = 2;
	int _c = 1000;
};
int main(int argc, char *argv[])
{
	/*double bl = 3.1;
	int bk = 0;
	std::cout << G_sin(bl) << std::endl;;
	std::cout << G_sin(bk) << std::endl;;
	*/
	
	A * first = new A;
	A * second= new B;
	B* moi;
	B tris;
	std::cout << first<<"--"<<second << std::endl;
	first->print();
	second->print();
	std::cout << tris.A::_a << std::endl;
	//(*first) = std::move(*second);
	moi=  static_cast<B*>(second);
	std::cout << first << "--" << second << std::endl;
	moi->print();
	second->print();
	moi->print3();

	system("PAUSE");

}