#include <string>
#include <iostream>
#include "test.h"
#include "timer.h"
#include "TYPELIST.h"

void sin(int) {}

int main(int argc, char *argv[])
{
	double bl = 3.1;
	int bk = 0;
	std::cout << G_sin(bl) << std::endl;;
	std::cout << G_sin(bk) << std::endl;;

	

	system("PAUSE");

}