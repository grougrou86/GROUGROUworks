
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "PARAM.h"
#include <GROUGROUconsola.h>
#include "NAMEgenerator.h"
#include <map>
#include "retab.h"
#include "STRINGS.h";
#include "STRINGS2.h";

int main(int argc, char *argv[])
{
	finish_param();
	INIT_STRINGS();

	rlutil::setColor(rlutil::WHITE);

	std::cout << "STARTING GENERATION" << std::endl;
	std::cout << "output : " << OUTPUTDIRECTORY << std::endl;

	std::string MACROS;

	NAMEgenerator NGEN;

	std::map<std::string, std::string> OP_code;
	for (auto& op : OPERATORS) OP_code[op] = NGEN.new_name();

	std::string MAIN;
	MAIN += HEADERS;
	MAIN += "#include \"" + ACCESS_F_ACCESS + "OP_MACRO.h\"";
	MAIN += "\n";
	MAIN += "#include \"" + ACCESS_F_ACCESS + "FCT_MACRO.h\"";
	MAIN += "\n";
	MAIN += "#include \"" + ACCESS_F_ACCESS + "FCT_MACRO2.h\"";
	MAIN += "\n";
	MAIN += "#include \"" + ACCESS_F_ACCESS + "MEMBER_MACRO.h\"";
	MAIN += "\n";
	MAIN +="struct void_return {};																																							\n\
class empty_usable {public:empty_usable(int){}};																																							\n";
	MAIN += "namespace ANY_FCT{";
	for (auto& mem : MEMBERS) {
		for (int i = mem.max_num_argument -1; i >0; i--)
		{
			MAIN += "PARAM_CALL_" + std::to_string(i) + "(" + mem.nom +")\n";
		}
	}
	MAIN += "};";
	for (auto& fc : FUNCTIONS) {
		for (int i = fc.max_num_argument-1; i >-1; i--)
		{
			MAIN += "IS_FCT"+std::to_string(i)+"(" + fc.nom + ","+fc.name+")\n";
		}
	}
	for (auto& op : OPERATORS) {
		MAIN += "ADDOPE3(" + ID_NAME + "_" + OP_code[op] + ", " + ID_NAME + "_SUP_" + OP_code[op] + "," + op + ")\n";
	}
	MAIN += "namespace "+ NAME_SPACE +" {	\n";
	MAIN += ANY_P1;
	MAIN += "\n";
	for (auto& op : OPERATORS) {
		MAIN += "ADDOPE2(" + ID_NAME + "_" + OP_code[op] + ")\n";
	}
	MAIN += "\n";
	for (auto& fc : FUNCTIONS) {
		for (size_t k = 1; k < fc.max_num_argument; k++)
		{
			MAIN += "ADDFCT_0_"+std::to_string(k)+"(" + fc.nom + ")\n";
		}
	}
	for (auto& mem : MEMBERS) {
		for (int i = mem.max_num_argument - 1; i >0; i--)
		{
			MAIN += "INNER_PARAM_CALL_0_" + std::to_string(i) + "(" + mem.nom + ")\n";
		}
	}
	MAIN += ANY_P2;
	MAIN += "\n";
	for (auto& op : OPERATORS) {
		MAIN += "ADDOPE1(" + ID_NAME + "_" + OP_code[op] + ")\n";
	}
	MAIN += "\n";
	for (auto& fc : FUNCTIONS) {
		for (size_t k = 1; k < fc.max_num_argument; k++)
		{
			MAIN += "ADDFCT_1_" + std::to_string(k) + "(" + fc.nom + ")\n";
		}
	}
	for (auto& mem : MEMBERS) {
		for (int i = mem.max_num_argument - 1; i >0; i--)
		{
			MAIN += "INNER_PARAM_CALL_1_" + std::to_string(i) + "(" + mem.nom + ")\n";
		}
	}
	MAIN += ANY_P3;
	MAIN += "};\n";//closing the namespace...
	MAIN += "#define ANY(typelist) "+ NAME_SPACE +"::any_operable<typelist,typelist>	\n";
	MAIN += "namespace "+ NAME_SPACE +" {	\n";
	//writing operator functions
	for (auto& op : OPERATORS) {
		MAIN +=
			"																																	\n\
template <class H, class T>																														\n\
any_operable <H,T> operator" + op + "(any_operable <H,T> a, any_operable <H,T> b)																\n\
{																																				\n\
	return a.F_" + ID_NAME + "_" + OP_code[op] + "2(b);																							\n\
}																																				\n\
";
	}
	//writing functions
	for (auto& fc : FUNCTIONS) {
		for (size_t k = 1; k < fc.max_num_argument; k++)
		{
			MAIN += "template <class H, class T>	 any_operable <H,T>" + fc.nom + "(";
			NAMEgenerator NGEN;
			std::vector<std::string> vars;
			for (size_t q = 0; q < k; q++){vars.push_back(NGEN.new_name());}
			for (auto & var : vars) { MAIN += "any_operable <H,T> & " + var + ","; }
			MAIN.pop_back();
			MAIN += "){ return "+vars[k-1]+".F_" + fc.nom + "(";
			for (size_t q = 0; q < k-1; q++) { MAIN += vars[q] + ","; }
			if (k > 1)MAIN.pop_back();
			MAIN += ");}\n";
		}
	}
	MAIN += "};\n";//closing the namespace...

	std::string FCT_MACRO;

	for (size_t i = 0; i < MAX_ARGUMENT; i++)
	{
		FCT_MACRO += MACRO_FCT(i);
	}

	std::string FCT_MACRO2;

	for (size_t i = 1; i < MAX_ARGUMENT; i++)
	{
		FCT_MACRO2 += MACRO_INNER(i, true);
		FCT_MACRO2 += MACRO_INNER(i, false);
	}

	std::string MEMBER_MACRO = "";

	for (size_t i = 1; i < MAX_ARGUMENT + 1; i++)
	{
		MEMBER_MACRO += MEMBER_MACRO_N(i);
		MEMBER_MACRO += INNER_MEMBER_MACRO_N(i,true);
		MEMBER_MACRO += INNER_MEMBER_MACRO_N(i,false);
	}

	std::ofstream out(OUTPUTDIRECTORY + "FCT_MACRO.h");
	out << HEADERS << FCT_MACRO;
	out.close();
	std::ofstream out4(OUTPUTDIRECTORY + "FCT_MACRO2.h");
	out4 << HEADERS << FCT_MACRO2;
	out4.close();
	std::ofstream out3(OUTPUTDIRECTORY + "OP_MACRO.h");
	out3 << HEADERS << OPERATORMACROS ;
	out3.close();
	std::ofstream out2(OUTPUTDIRECTORY + "MAIN.h");
	out2 << MAIN;
	out2.close();
	std::ofstream out5(OUTPUTDIRECTORY + "MEMBER_MACRO.h");
	out5 << HEADERS << MEMBER_MACRO;
	out5.close();

	std::cout << "FINISHED" << std::endl;



	system("Pause");

}