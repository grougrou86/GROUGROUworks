#pragma once
#include"CONDtext.h"
#include"USEDtypelist.h"
#include<boost\regex.hpp>
#include <boost/any.hpp>

//nom avec un backslash -> var locale remplacé au début puis 3 digit pour le niveau de porté comme ca on sait ou effacer !!!

namespace CONDITIONAL_TEXT {

	struct varPOS {
		size_t begin;
		size_t end;
		std::string varname = "";
	};
	struct percise_info {
		int go_to = 0;//0= do nothing else set document line
		std::string operation="";//operation to compute
		std::vector<varPOS> varPosition; // fo position fo rplacement lines

	};
	struct line_info {
		std::string string;
		unsigned int info=0;
		percise_info pres_info;
		int line_number=0;
	};

	enum LINE_INFO { nothing , print , operation , if_statement , while_statement , end_statement , if_print}; // available commands TO_DO  if_print

	class Converter_DATA {

	public:

		Converter_DATA() {

		}
		~Converter_DATA() {

		}
		void set_main(const std::string & s);
		void set_parameter(const Parameter p);
		std::string & run();
		std::string & compile_result();
		std::string & get_error();

	private:

		//variable for display and fun....
		int offset = 150;
		int width = 220; //width of the display

		std::string result;
		std::string comp_result;
		std::string error;
		
		std::vector<line_info> lines;


		Parameter _param;

	};





	/*
	//OTHER TEMPLATE 
	
	template <class T>
	any_operable operator+(T, any_operable) {

	}

	template <class tlist> class anyPLUS;

	template <class H, class T>
	class anyPLUS < typelist<H, T> >
		: public anyPLUS<T>
	{
	public:

		any_operable run(any_operable p, any_operable q)
		{
			if (p.type==typeid(H))
			{
				return operator+(boost::any_cast<H>(p),q);
			}
			else
			{
				return anyPLUS<T>::run(p,q);
			}
		}
	};

	template <class H>
	class anyPLUS< typelist<H, null_typelist> >
	{
	public:
		any_operable run(any_operable p, any_operable q)
		{
			if (p.type == typeid(H))
			{
				return operator+(boost::any_cast<H>(p), q);
			}
			else
			{
				throw("unknown type left");
			}
		}
	};

	//PARTIE 2


	//PARTIE 3

	template<class T,U>

	any_operable TRYoperatorPLUS(T p, U q) {



	}

	//PARTIE 4

	template <class tlist> class anyPLUS2;

	template <class H, class T>
	class anyPLUS2 < typelist<H, T> >
		: public anyPLUS2<T>
	{
	public:
		template<class R>
		any_operable run(R q, any_operable p)
		{
			if (p.type == typeid(H))
			{
				return TRYoperatorPLUS( q, boost::any_cast<H>(p));
			}
			else
			{
				return anyPLUS2<T>::run(p, q);
			}
		}
	};

	template <class H>
	class anyPLUS2< typelist<H, null_typelist> >
	{
	public:
		template<class R>
		any_operable run(R q, any_operable p)
		{
			if (p.type == typeid(H))
			{
				return TRYoperatorPLUS( q, boost::any_cast<H>(p) );
			}
			else
			{
				throw("unknown type right");
			}
		}
	};
	*/
}