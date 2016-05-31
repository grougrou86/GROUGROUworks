#pragma once
#include"TYPELIST.h";
#include<string>

namespace CONDITIONAL_TEXT {
	typedef TYPELIST((float, double, int, unsigned int, std::string, size_t)) CONDITIONAL_TEXT_TYPE;
}