#pragma once
#include <vector>

class f_struct {
public:
	f_struct(int num_arg, std::string no) :max_num_argument(num_arg), nom(no) {}
	f_struct( std::string no) : nom(no) {}
	int max_num_argument = 7;
	std::string nom = "";
	std::string name = "";
};

void finish_param();

extern std::vector<f_struct>			FUNCTIONS;
extern std::vector<f_struct>			MEMBERS;
extern std::vector<std::string>			OPERATORS;
extern std::string						OUTPUTDIRECTORY;
extern std::string						ACCESS_F_ACCESS;
extern std::string						ID_NAME;
extern std::string						NAME_SPACE;
extern int								MAX_ARGUMENT;
extern int								REFERENCES;