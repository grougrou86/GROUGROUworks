#include "NAMEgenerator.h"

std::string NAMEgenerator::new_name() {
	bool found = false;
	for (size_t i = 0; i < last_name.size()&&!found ; i++)
	{
		if (last_name[i]!='z') {
			last_name[i] += 1;
			found = true;
		}
		else {
			last_name[i] = 'a';
		}
	}
	if (!found) {
		last_name.push_back('a');
	}
	return std::string(&last_name[0], last_name.size());
}
unsigned int INTgenerator::new_int() {
	return last_int++;
}

std::vector<unsigned int> LOOPER::new_v() {

	std::vector<unsigned int> retour = last_thing;
	int i = 0;
	bool stop=false;
	while (i < last_thing.size()&&!stop) {
		if (last_thing[i] != _max) { last_thing[i]++; stop = true; }
		else last_thing[i] = 0;
		i++;
	}
	if (!stop) {
		_end = true; //si après ca on a atteind le max là...
	}

	return retour;
}
bool LOOPER::is_end() { return _end; }