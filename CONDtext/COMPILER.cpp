#include"COMPILER.h"
#include"file2string.h"
#include<boost\regex.hpp>
#include<boost\filesystem.hpp>
#include<boost\algorithm\string.hpp>
#include<map>
#include<string>
#include <iostream>       
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include"rlutil.h"

namespace Condtext_Compiler {
	/*
	***********************************
	HELPER FUNCTIONS
	***********************************
	*/

	void clear_blank(std::vector<std::string>& str) {
		for (size_t i(0) ; i < str.size() ; i++) {
			bool incorrect = true;
			for (auto& l : str[i]) {
				if (l != ' '&& l != '\t') {
					incorrect = false;
					break;
				}
			}
			if (incorrect) {
				str.erase(str.begin()+i);
				i--;
			}
		}
	}
	void clear_start(std::string& str) {
		for (size_t i(0); i < str.size(); i++) {
			char& l = str[i];
			if (l != ' '&& l != '\t') {
				if (i != 0)str.erase(0, i);
				break;
			}
		}
	}
	void clear_start(std::vector<std::string>& str) {
		for (size_t i(0); i < str.size(); i++) {
			clear_start(str[i]);
		}
	}
	void clear_all(std::string& str) {
		for (size_t i(0); i < str.size(); i++) {
			char& l = str[i];
			if (l == ' '&& l == '\t') {
				str.erase(i, i + 1);
			}
		}
	}
	void clear_all(std::vector<std::string>& str) {
		for (size_t i(0); i < str.size(); i++) {
			clear_all(str[i]);
		}
	}
	void clear_end(std::string& str) {
		for (size_t i(str.size()-1); i >=0; i--) {
			char& l = str[i];
			if (l != ' '&& l != '\t') {
				if (i != str.size() - 1)str.erase(i+1, str.size() - 1);
				break;
			}
		}
	}
	void clear_end(std::vector<std::string>& str) {
		for (size_t i(0); i < str.size(); i++) {
			clear_end(str[i]);
		}
	}
	void insert_between(std::vector<std::string>& str,const std::string& to_insert) {
		for (size_t i(1); i < str.size(); i += 2) {
			str.insert(str.begin() + i, to_insert);
		}
	}
	std::string fillString(const std::string& c, int x) {
		int toadd = x - c.size();
		return c + std::string(toadd, ' ');
	}
	void reBackHash(std::vector<std::string>& str) {//refuse backslash hashtag !!
		for (size_t i = 0; i < str.size()-1; i++)
		{
			if (str[i].back() == '\\') {
				//str[i].pop_back();
				str[i] += "#" + str[i + 1];
				str.erase(str.begin() + (i+1));
				i--;
			}
		}
	}
	/*
	***********************************
	CLASS FUNCTIONS
	***********************************
	*/

	FileSystem<Compiled_File>* Compiled_File::_FILES = new FileSystem<Compiled_File>();//setting the file system of the compiler ^^

	Compiled_File::Compiled_File(std::string _file) {
		if(boost::filesystem::exists(boost::filesystem::path(_file.c_str()))) load(file2string(_file));
		else {
			throw("FILE NOT FOUND IN SHADER COMPILER");
		}
	}
	Compiled_File::Compiled_File() {
		throw("MUST SPECIFY A FILE thank you !");
	}
	std::string Compiled_File::to_string() const {
		std::string result;
		for (auto& line : _LINES) {
			result += line.to_string();
		}
		return result;
	}
	void Compiled_File::load(std::string str){

		_source = str;

		boost::regex VarPrint_DETECT("^.*(?:[^\\\\]|)#.*(?:[^\\\\]|)#.*");//search variables first fing because can start with a hastag but be a variable replacement
		boost::regex Code_DETECT("^(?: |\t)*#.*");//search code
		boost::cmatch m;//match for multiplue purpose 

		std::stringstream txt(str);
		std::string txtLine;

		unsigned int falseLine = 0;//the line in the document
		unsigned int trueLine = 0;//the line of code
		_LINE_TRANSLATE.clear();

		while (std::getline(txt, txtLine, '\n'))
		{
			if ((!boost::regex_match(txtLine.c_str(), m, VarPrint_DETECT)) && boost::regex_match(txtLine.c_str(), m, Code_DETECT)) {

				if(txtLine.size()>0)txtLine.erase(0,1);

				//work to decompose the line at { } ; 
				std::vector<std::string> temp1;
				std::vector<std::string> temp2;
				std::vector<std::string> temp3;
				std::vector<std::string> finalVec;

				boost::split(temp1, txtLine, boost::is_any_of(";"));
				clear_blank(temp1);
				for (auto & em : temp1) {
					temp2.clear();
					boost::split(temp2, em, boost::is_any_of("}"));
					insert_between(temp2,"}");
					clear_blank(temp2);
					for (auto & em : temp2) {
						temp3.clear();
						boost::split(temp3, em, boost::is_any_of("{"));
						insert_between(temp3, "{");
						clear_blank(temp3);
						clear_start(temp3);
						clear_end(temp3);
						// creat lines ^^ finaly !!!

						for (auto & em : temp3) {
							_LINES.push_back(Code_Line("#"+em));
							trueLine++;
							_LINE_TRANSLATE.push_back(falseLine);
						}

					}
				}


			}
			else {
				_LINES.push_back(Code_Line(txtLine+"\n"));
				trueLine++;
				_LINE_TRANSLATE.push_back(falseLine);
			}

			falseLine++;

		}
		//stepp split at ";" in two lines and then listing the barceand line and a vector of correspondance of true line to false line for debug 

	}
	std::pair<Parameter, std::string> Compiled_File::run(Parameter PARAM) {
		std::string result = "";

		return std::pair<Parameter, std::string>(PARAM,result);
	}
	FileSystem<Compiled_File>* Compiled_File::FILES() {

		return _FILES;

	}
	std::string Compiled_File::get_source() {

		return _source;

	}
	void Compiled_File::nicePrint()const {
		int last_line = -1;
		unsigned int i = 0;
		for (auto&l : _LINES) {
			if (_LINE_TRANSLATE[i] != last_line) { last_line= _LINE_TRANSLATE[i]; std::cout<<fillString(std::to_string(_LINE_TRANSLATE[i]+1)+":", 5); }
			else std::cout << fillString("", 5);
			l.nicePrint();

			i++;
		}
	}
	Code_Line::Code_Line(std::string s)
	{
		//searching what the line is about !
		_base_code = s;

		boost::regex VarPrint_DETECT("^.*(?:[^\\\\]|)#.*(?:[^\\\\]|)#.*");//search variables first fing because can start with a hastag but be a variable replacement
		boost::regex Code_DETECT("^(?: |\t)*#.*");//search variables

		boost::cmatch m;

		if (boost::regex_match(_base_code.c_str(), m, VarPrint_DETECT)) _func = variable_print;
		else if(boost::regex_match(_base_code.c_str(), m, Code_DETECT)) _func = code;
		else _func = simple_print;

		//redirecting for good annalysiss !
		switch (_func)
		{
		case simple_print: _base_print = _base_code + "\n";
		case code: load_code(_base_code);
		case variable_print: load_variable_print(_base_code);  break;
		}
	}

	Code_Line::~Code_Line()
	{

	}

	void Code_Line::load_variable_print(std::string) {

	}

	void Code_Line::load_code(std::string) {

	}

	std::string Code_Line::run(Parameter&) {

		return "";
	}
	std::string Code_Line::to_string() const{
		return _base_code;
	}
	LineFunction Code_Line::function() const {
		return _func;
	}
	void Code_Line::nicePrint() const{
		Condtext_Compiler::LineFunction func = function();

		rlutil::setColor(rlutil::WHITE);
		if (func == Condtext_Compiler::code) { rlutil::setColor(rlutil::RED); std::cout << to_string() << std::endl;; }
		else if (func == Condtext_Compiler::variable_print) {  
			std::vector<std::string> str;
			boost::split(str, to_string() , boost::is_any_of("#"));
			reBackHash(str);
			insert_between(str, "#");
			int i = 0;
			for (auto & el : str) {
				if(i>0)rlutil::setColor(rlutil::GREEN);
				else rlutil::setColor(rlutil::GREY);
				std::cout << el ;
				i = (i + 1) % 4;
			}

		}
		else { std::cout << to_string(); }
		rlutil::setColor(rlutil::WHITE);
	}
}
std::ostream& operator<<(std::ostream& os, const Condtext_Compiler::Code_Line& line) {
	 return os << line.to_string();
}
std::ostream& operator<<(std::ostream& os, const Condtext_Compiler::Compiled_File& file) {
	return os << file.to_string();
}