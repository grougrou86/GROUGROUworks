#pragma once
#include<string>
#include"NAMEgenerator.h"

std::string MEMBER_MACRO_N(unsigned int n) {
	std::string result = "";
	if (n > 0) {
		std::string result2 = "";
		std::string param_list = "";
		std::string template_param = "";
		std::string call_list = "";
		std::string call_list2 = "";
		std::string first_param = "";
		NAMEgenerator NGEN;

		for (size_t i = 0; i < n; i++)
		{

			std::string name = NGEN.new_name();
			param_list += "C_NAME_" + name + " # " + name + ",";
			template_param += "class C_NAME_" + name + ",";
			if (i != 0)call_list += name + ",";
			if (i != 0)call_list2 += "*(C_NAME_" + name + "*)0,";
			else first_param = name;

		}

		param_list.pop_back();
		template_param.pop_back();
		if (call_list.size() > 0)call_list.pop_back();
		if (call_list2.size() > 0)call_list2.pop_back();

		result = inTMP(template_param, n) + " typename decltype( (*(C_NAME_"+first_param+"*)0). nom ("+ call_list2 +")) CALL_MEMBER_ ## nom (";

		result2 = "){											\\	\n\
	return " + first_param + ". nom (" + call_list + ");		\\	\n\
	};															\\	\n";
		result=everyREF(result, param_list, result2);
		result = "#define PARAM_CALL_" + std::to_string(n) + "(nom)				\\	\n"+ result;
		result += "\n";
	}
	return retab(result);
}

std::string INNER_MEMBER_MACRO_N(unsigned int n,bool second) {
	std::string result = "";
	if (n > 0) {
		std::string result2 = "";
		std::string param_list = "";
		std::string template_param = "";
		std::string call_list = "*this,";
		std::string call_list2 = "";
		if(second)call_list2 = "*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,";
		else call_list2 = "*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,";
		std::string first_param = "";
		NAMEgenerator NGEN;

		for (size_t i = 0; i < n-1; i++)
		{

			std::string name = NGEN.new_name();
			param_list += "C_NAME_" + name + " # " + name + ",";
			template_param += "class C_NAME_" + name + ",";
			call_list += name + ",";
			call_list2 += "*(C_NAME_" + name + "*)0,";
			

		}

		if (param_list.size() > 0)param_list.pop_back();
		if (template_param.size() > 0)template_param.pop_back();
		if (call_list.size() > 0)call_list.pop_back();
		if (call_list2.size() > 0)call_list2.pop_back();

		result = inTMP(template_param, n-1) + " typename decltype( CALL_MEMBER_ ## nom (" + call_list2 + "))  nom (";

		result2 = "){											\\	\n\
	return  CALL_MEMBER_ ## nom  (" + call_list + ");		\\	\n\
	};															\\	\n";
		result = everyREF(result, param_list, result2);
		result = "#define INNER_PARAM_CALL_"+ std::to_string((int)second) +"_" + std::to_string(n) + "(nom)				\\	\n" + result;
		result += "\n";
	}
	return retab(result);
}