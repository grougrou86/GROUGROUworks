
#include <string>
#include <iostream>
#include"ANY_INCLUDES.h"
#include "COMPILER.h"
#include "boost\filesystem.hpp"
#include "rlutil.h"

namespace ANY_FCT {
	int main()
	{
		

		Condtext_Compiler::any qw = (int)3;
		Condtext_Compiler::any rrr = (size_t)3;
		Condtext_Compiler::any m = (double)3.0;
		Condtext_Compiler::any n = (double)4.0;
		Condtext_Compiler::any o = std::string("salut bb");
		Condtext_Compiler::any r = 0;

		int mr = 3;


		try
		{

			std::cout << "SIZE : " << boost::any_cast<size_t>(o.size())<< std::endl;;
			m*n;
			std::cout << G_change(mr) << std::endl; ;
			std::cout << "before" << mr << std::endl;
			//nu(G_change(1.0));
			change(qw);
			std::cout << "SUCCESS" << boost::any_cast<int>(qw)  << std::endl;
			std::cout << "before"  << std::endl;
			display();
			G_display();
			std::cout << "after" << std::endl;

			std::cout <<"TEST fin :"<< boost::any_cast<double>(m.F_pow(n)) << std::endl;
			double ar = 0.5;
			std::cout << G_sin(0.5) << "-" << G_pow(4.0, 3.0) << std::endl;;
			int rho = 1;
			G_display(rho, 2, 3);

			std::cout << "TEST fin :" << boost::any_cast<double>(pow(m,n)) << std::endl;
			std::cout << "TEST fin2 :" << boost::any_cast<double>(sin(m)) << std::endl;

			std::cout <<"operator : "<< boost::any_cast<double>((m + n)*m) << std::endl;

		}
		catch (char const *error)
		{
			std::cerr << "Error: " << error << std::endl;
		}

		boost::filesystem::path fichier("../SHADERS");
		std::cout << boost::filesystem::exists(fichier) << std::endl;

		Condtext_Compiler::Compiled_File* test = &Condtext_Compiler::Compiled_File::FILES()->require("../SHADERS/main.sca");
		Condtext_Compiler::Compiled_File* test2 = &Condtext_Compiler::Compiled_File::FILES()->require("../SHADERS/main.sca");


		std::cout << test << "-" << test2 << std::endl << *test << std::endl << std::endl;
		test->nicePrint();

		system("Pause");
		return 0;
	}
}
int main(int argc, char *argv[])
{
	return ANY_FCT::main();
}