#include "GROUGROUconsola.h"
#include <string>

namespace rlutli {
	std::string fillString(std::string c, int x) {
		int toadd = x - c.size();

		return c + std::string(toadd, ' ');
	}
}