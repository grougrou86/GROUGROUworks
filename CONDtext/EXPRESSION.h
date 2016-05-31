#pragma once
#include<string>
#include<map>
#include"ANY_INCLUDES.h"
#include"COMPILER.h"


/*
###############
Expression_Eval
##############
eval an expression given as a sting according to a Parameter (the variable that may be used there ^^)
*/

namespace Condtext_Compiler {
	class Expression_Eval {

	public:

		Expression_Eval(std::string);
		virtual ~Expression_Eval();
		any eval(Parameter&);

	private:

		Parameter _RVAL;//R values of the expression.

	};
}