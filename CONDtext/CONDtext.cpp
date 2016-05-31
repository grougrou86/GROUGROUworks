//#include "pch.h"
#include "CONDtext.h"
#include "OTHER.h"

#include<map>
#include<string>
#include <iostream>       
#include <stdexcept>

#include "TYPELIST.h"
#include "USEDtypelist.h"
//to parse expression first get content without partensis between parenthesis then replace with a false var and so on
/*IDEA

nom commance par un nombre -> sous tableau --> pas accesible et dans le parse débute par nombre=nombre commen en c++
si ca commence par 0 -> truc spécial genre map de string etc....

*/

namespace CONDITIONAL_TEXT {

	void Converter_DATA::set_main(const std::string & s) {

		std::stringstream test(s);
		std::string segment;
		std::vector<std::string> seglist;

		boost::regex IFexp("^(?: |\t)*#IF.*");
		boost::regex ENDexp("^(?: |\t)*#END.*");
		boost::regex OPexp("^(?: |\t)*#OP.*");
		boost::regex WHILEexp("^(?: |\t)*#WHILE.*");
		boost::regex REPexp("(.*[^(//)]#.*|^#.*)");//check if there might be replacement to do 
		boost::regex VAR_REP("(?:[^(?://)]|^)#([a-zA-Z_\-]+)#");//search variables

		int level = 0;
		int lin_number = 0;
		while (std::getline(test, segment, '\n'))
		{
			lin_number++; //line number start at one line number zero is resorve fo goto that go nowhere !!!


			line_info val;
			val.string = segment;

			boost::cmatch what;


			if (boost::regex_match(val.string.c_str(), what, ENDexp))
			{
				val.info = end_statement;
			}
			else if (boost::regex_match(val.string.c_str(), what, IFexp))
			{
				val.info = if_statement;
			}
			else if (boost::regex_match(val.string.c_str(), what, OPexp))
			{
				val.info = operation;
			}
			else if (boost::regex_match(val.string.c_str(), what, WHILEexp))
			{
				val.info = while_statement;
			}
			else if (boost::regex_match(val.string.c_str(), what, REPexp))
			{
				val.info = print;
				std::string::const_iterator start, end;
				start = val.string.begin();
				end = val.string.end();
				boost::match_results<std::string::const_iterator> result;
				boost::smatch match;
				boost::match_flag_type flags = boost::match_default;
				while (regex_search(start,end, match , VAR_REP,flags))
				{
					std::string var = match[1]; //std::string(what[2].first, what[1].second);
					//std::cout << match. << std::endl;
					start = match[1].first;
					varPOS curr;
					curr.begin = (int)( match[1].first- val.string.begin()); curr.end = (int)(match[1].second- val.string.begin()); curr.varname = var;
					val.pres_info.varPosition.push_back(curr);
					flags |= boost::match_prev_avail;
					flags |= boost::match_not_bob;
				}


			}

			val.line_number = lin_number;

			lines.push_back(val);
		}
	}
	void Converter_DATA::set_parameter(const Parameter p) {
		_param = p;
	}
	std::string&  Converter_DATA::compile_result() {
		comp_result.clear();

		comp_result += "\n";
		for (int i = 0; i < width; ++i)comp_result += "~";
		for (int i = 0; i < width; ++i)comp_result += "#";
		for (int i = 0; i < width; ++i)comp_result += "~";
		comp_result += "\n";

		for (auto& line : lines) {
			comp_result += to_string(line.line_number);
			if (line.line_number < 1000) comp_result += " ";
			if (line.line_number < 100) comp_result += " ";
			if (line.line_number < 10) comp_result += " ";
			comp_result += " : ";

			comp_result += line.string + std::string(" || ") + std::to_string(line.info);
			if (line.info == print) {
				//making allignement of the comments
				int tab_ADD = offset - line.string.size();
				if (tab_ADD < 0)tab_ADD = 0;
				for (int i = 0; i<tab_ADD; ++i)comp_result += " ";

				for (auto& i : line.pres_info.varPosition) {

					comp_result += i.varname + "[" + std::to_string(i.begin) + "-" + std::to_string(i.end) + "]";
				}
			}
			comp_result += '\n';

		}

		comp_result += "\n";
		for (int i = 0; i < width; ++i)comp_result += "~";
		for (int i = 0; i < width; ++i)comp_result += "#";
		for (int i = 0; i < width; ++i)comp_result += "~";
		comp_result += "\n";

		return comp_result;
	}

	std::string &  Converter_DATA::run() {
		error.clear();
		result.clear();

		

		for (auto& line : lines) {//execute line per line
			if (line.info == print) {
				int decalage = 0;
				std::string sub_result = line.string;
				for (auto& i : line.pres_info.varPosition) {
					std::string var_disp;
					try {
						var_disp = any_stringlify(_param.at(i.varname));
					}
					catch (const std::out_of_range& oor) {
						error += " - ERROR LINE [" + std::to_string(line.line_number) + "] : Variable " + i.varname + " not declared use #VAR " + i.varname + " = ... To declare it or add it to parameters\n";
					}
					//result += i.varname + "[" + std::to_string(i.begin) + "-" + std::to_string(i.end) + "]";

					size_t real_begin = i.begin + decalage - 1;
					size_t real_end = i.end + decalage + 1;

					sub_result.erase(real_begin, real_end- real_begin);

					sub_result.insert(real_begin, var_disp);

					decalage += (real_begin - real_end ) + var_disp.size();// -var_disp.size();


				}
				result += sub_result;
			}
			else {
				result += line.string;
			}
			result += '\n';
		}
		return result;
	}
	std::string &  Converter_DATA::get_error() {
		return error;
	}
	Converter::Converter() {
		_data = new Converter_DATA();
	}

	Converter::~Converter() {
		delete _data;
	}

	void Converter::set_main(std::string s) {
		_data->set_main(s);
	}

	void Converter::set_parameter(Parameter p) {
		_data->set_parameter(p);
	}

	std::string Converter::run() {
		return _data->run();
	}
	std::string Converter::compile_result() {
		return _data->compile_result();
	}

	std::string Converter::get_error() {
		return _data->get_error();
	}
	std::string any_stringlify(const boost::any & a) {
		if (a.type() == typeid(std::string))  return boost::any_cast<std::string>(a);
		if (a.type() == typeid(int))  return to_string(boost::any_cast<int>(a));
		if (a.type() == typeid(double))  return to_string(boost::any_cast<double>(a));
		if (a.type() == typeid(float))  return to_string(boost::any_cast<float>(a));
		if (a.type() == typeid(unsigned int))  return to_string(boost::any_cast<unsigned int>(a));
		if (a.type() == typeid(size_t))  return to_string(boost::any_cast<size_t>(a));
		if (a.type() == typeid(short))  return to_string(boost::any_cast<size_t>(a));
		if (a.type() == typeid(bool))  if (boost::any_cast<bool>(a))return std::string("true");else return std::string("false");;

		return std::string("");
	}

	//any_operable any_operable::operator+(any_operable) {

		

	//}


}