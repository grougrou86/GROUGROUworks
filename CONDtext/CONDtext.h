
#pragma once
#ifdef CONDITIONALTEXTDLL_EXPORTS
#define CONDITIONALTEXTDLL_API __declspec(dllexport) 
#else
#define CONDITIONALTEXTDLL_API __declspec(dllimport) 
#endif

#include<map>
#include<string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <boost/any.hpp>


#define HAS_MEM_FUNC(func, name)                                        \
    template<typename T, typename Sign>                                 \
    struct name {                                                       \
        typedef char yes[1];                                            \
        typedef char no [2];                                            \
        template <typename U, U> struct type_check;                     \
        template <typename _1> static yes &chk(type_check<Sign, func > *); \
        template <typename   > static no  &chk(...);                    \
        static bool const value = sizeof(chk<T>(0)) == sizeof(yes);     \
    }


namespace CONDITIONAL_TEXT {

	typedef std::map<std::string, boost::any> Parameter;

	class Converter_DATA ;

	class Converter {

	public:

		CONDITIONALTEXTDLL_API Converter(); // to init ...

		virtual CONDITIONALTEXTDLL_API ~Converter(); // to destroy

		CONDITIONALTEXTDLL_API void set_main(std::string);//set main string

		CONDITIONALTEXTDLL_API void set_parameter(Parameter);//set parameter for use

		CONDITIONALTEXTDLL_API std::string run();//run and get result
		CONDITIONALTEXTDLL_API std::string compile_result();//get compile-details
		CONDITIONALTEXTDLL_API std::string get_error();//get the error if their are

	private:

		Converter_DATA* _data;// every data and other hidden thing is done here for visibility !!!

	};




	template <class T>

	inline std::string to_string(T var) {
		return std::to_string(var);
	}


	template <>

	inline std::string to_string(std::string var) {
		std::ifstream file;
		std::string result;
		file.open(var.c_str());
		if (!file) {
			throw "[ConfigFile] Error in openening file " + var;
		}
		try {
			std::string lineread;

			bool begin = true;

			while (std::getline(file, lineread)) {

				if (begin) {
					begin = false;
					result = result + lineread;
				}
				else result = result + '\n' + lineread;
			}
			file.close();
		}
		catch (std::string e) {
			file.close();
			throw e;
		}

		return result;
	}

	CONDITIONALTEXTDLL_API std::string any_stringlify(const boost::any & a);
	/*
	class any_operable {
	public:
		template<class T>
		any_operable(const T & val) {
			_val(val);
		}
		template<>
		any_operable(const boost::any & val) {
			_val = val;
		}


		any_operable operator+(any_operable);
	private:
		boost::any _val;
	};


	
	*/
	
}