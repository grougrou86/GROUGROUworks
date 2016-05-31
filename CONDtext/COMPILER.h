#pragma once
#include<string>
#include<map>
#include<vector>
#include"ANY_INCLUDES.h"
#include<iostream>

namespace Condtext_Compiler {

	typedef ANY(EXE_TYPE) any;

	typedef  std::map<std::string, ANY(EXE_TYPE)> Parameter;//the input and output of the compiler 

	class Compiled_File;
	class Code_Line;
	class Expression_Eval;
	void clear_blank(std::vector<std::string>& str);//remove blank string from vector
	void clear_start(std::string& str);//remove space before the string
	void clear_start(std::vector<std::string>& str);
	void clear_all(std::string& str);//remove all space and tab
	void clear_all(std::vector<std::string>& str);
	void clear_end(std::string& str);//remove space after the string
	void clear_end(std::vector<std::string>& str);
	void insert_between(std::vector<std::string>& str,const std::string& to_insert);//insert a string between elements
	std::string fillString(const std::string&, int);
	void reBackHash(std::vector<std::string>&);// function specific to avoid backslashed hashtag to be taken into account afer separation ^^
/*
###############
FILESYSTEM
##############
*/
	template <class T> class FileSystem {
		//the goal is not to reload file and to process to compilation with a compiler T here "COMPILED FILE"
		//mind that one schould only use one way to refer to a file...
	public:
		void add (std::string name ) {
			if (FILES.find(name) == FILES.end()) {
				FILES.insert(std::pair<std::string,T>(name, T(name)));
			}
		}
		T& require(std::string name) {
			if (FILES.find(name)!=FILES.end()) {
				return FILES[name];
			}
			else {
				FILES.insert(std::pair<std::string, T>(name, T(name)));
				return FILES[name];
			}
		}
	private:
		std::map<std::string,T> FILES;
	};
/*
###############
compiled_file
##############
*/
	class Compiled_File {
	public:
		Compiled_File(std::string file);
		Compiled_File();
		virtual ~Compiled_File() {}
		std::pair<Parameter, std::string> run(Parameter);
		std::string get_source();
		static FileSystem<Compiled_File>* FILES();
		std::string to_string()const;
		void nicePrint()const;
	private:
		std::string _source = "";
		void load(std::string);
		static FileSystem<Compiled_File>* _FILES;
		std::vector<Code_Line> _LINES;
		std::vector<int> _LINE_TRANSLATE;
		Parameter _VAR;
	};


	enum LineFunction { code, simple_print, variable_print };

	class Code_Line
	{
	public:
		Code_Line(std::string );
		virtual ~Code_Line(); 
		std::string run(Parameter&);
		std::string to_string() const;
		LineFunction function() const;
		void nicePrint()const;
	private:

		void load_variable_print(std::string);//specialise function for load when there are some variable to print THE MOST COMPLICATE BECAUS PRINTED PART CAN BE CODE...
		void load_code(std::string);//specialised for when there is code

		LineFunction _func;
		std::string _base_print = "";
		std::string _base_code = "";

	};




}
//definition of the expression parser (the real work !!)

std::ostream& operator<<(std::ostream&, const Condtext_Compiler::Code_Line&);
std::ostream& operator<<(std::ostream&, const Condtext_Compiler::Compiled_File&);

#include "EXPRESSION.h"