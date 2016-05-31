#pragma once
#include <string>
#include <vector>
class NAMEgenerator {
public:
	std::string new_name();
	std::vector<char> last_name = std::vector<char>({ char('a'-1) });
};
class INTgenerator {
public:
	unsigned int new_int();
	unsigned int last_int = 0 ;
};

class LOOPER {
public:
	LOOPER(unsigned int n,unsigned int maximum) :num(n), _max(maximum), last_thing(std::vector<unsigned int>(n,0)){}
	unsigned int num;
	unsigned int _max;
	std::vector<unsigned int> last_thing;
	std::vector<unsigned int> new_v();//get a new possibility
	bool is_end();//bool if every bosibility have been retrieved
private:
	bool _end = false;
};