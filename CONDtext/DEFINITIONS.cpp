#include "DEFINITIONS.h"
#include <iostream>

void display() {
	std::cout << "asked for a display" << std::endl;
}
void display(int a, int b, int c) {
	std::cout << a << "-" << b << "-" << c << std::endl;
}
void change(int & a) {
	a = 0;
}
int change2(int & a) {
	a = 0;
	return a;
}
int nu(int a) {
	return 0;
}
int nu(void) {
	return 0;
}