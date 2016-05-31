#pragma once
#pragma once
#ifdef GROUGROU_CONSOLDLL_EXPORTS
#define GROUGROU_CONSOLDLL_API __declspec(dllexport) 
#else
#define GROUGROU_CONSOLDLL_API __declspec(dllimport) 
#endif
#include <string>
#include "rlutil.h"

namespace rlutli {
	std::string GROUGROU_CONSOLDLL_API fillString(std::string string, int x);
}
