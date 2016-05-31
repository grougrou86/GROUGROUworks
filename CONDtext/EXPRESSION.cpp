#include "EXPRESSION.h"
#include<boost\regex.hpp>


namespace Condtext_Compiler {

	Expression_Eval::Expression_Eval(std::string) {//this function makes the compilation

	}

	Expression_Eval::~Expression_Eval() {	}

	any Expression_Eval::eval(Parameter&) {//this function makes the execution
		return any(0);
	}

}