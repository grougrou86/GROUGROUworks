// TO DO : NOT REPEAT MACRO:::

#pragma once 
#include <string>
#include "retab.h"
#include "PARAM.h"
#include "NAMEgenerator.h"
std::string HEADERS =
"															\n\
#pragma once												\n\
#include <iostream>											\n\
#include <array>											\n\
#include \"boost\\utility\\enable_if.hpp\"					\n\
#include \"boost\\any.hpp\"									\n\
#include \"TYPELIST.h\"										\n\
";

std::string OPERATORMACROS =
"																																												\n\
#define ADDOPE1( nom ) any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom ## 2(const any_operable<typelist<A, B>, typelist<A, B>> & q) const { \\							\n\
	any_operable<typelist<A, B>, typelist<A, B>> result = C_ ## nom (q);												\\														\n\
	delete &q;																											\\														\n\
	return result;																										\\														\n\
}																														\\														\n\
template <class X, class Y>																								\\														\n\
any_operable<typelist<A, B>, typelist<A, B>> & C_ ## nom (const any_operable<typelist<X, Y>, typelist<A, B>> & q) const {	\\													\n\
	if (type() == typeid(H))																							\\														\n\
	{																													\\														\n\
		return q.C_ ## nom ## 2(boost::any_cast<H>(*this));																\\														\n\
	}																													\\														\n\
	else																												\\														\n\
	{																													\\														\n\
		throw(\"LEFT TYPE NOT SUPPORTED\");																				\\														\n\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));													\\														\n\
	}																													\\														\n\
}																														\\														\n\
template<class E>																										\\														\n\
any_operable<typelist<A, B>, typelist<A, B>> & C_ ## nom ## 2(const E & val) const {									\\														\n\
	if (type() == typeid(H))																							\\														\n\
	{																													\\														\n\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>( nom (val, boost::any_cast<H>(*this))));				\\														\n\
	}																													\\														\n\
	else																												\\														\n\
	{																													\\														\n\
		throw(\"RIGHT TYPE NOT SUPPORTED\");																			\\														\n\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));													\\														\n\
	}																													\\														\n\
}																																												\n\
																																												\n\
#define ADDOPE2( nom )any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom ## 2(const any_operable<typelist<A, B>, typelist<A, B>> & q) const {			\\					\n\
	any_operable<typelist<A, B>, typelist<A, B>>* result = &C_ ## nom(q);													\\													\n\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\\													\n\
	delete result;																											\\													\n\
	return result2;																											\\													\n\
}																															\\													\n\
template <class X, class Y>																									\\													\n\
any_operable<typelist<A, B>, typelist<A, B>> & C_ ## nom (const any_operable<typelist<X, Y>, typelist<A, B>> & q)  const {	\\													\n\
	if (type() == typeid(H))																								\\													\n\
	{																														\\													\n\
		return q.C_ ## nom ## 2(boost::any_cast<H>(*this));																	\\													\n\
	}																														\\													\n\
	else																													\\													\n\
	{																														\\													\n\
		return any_operable<T, typelist<A, B>>::C_ ## nom(q);																\\													\n\
	}																														\\													\n\
}																															\\													\n\
template<class E>																											\\													\n\
any_operable<typelist<A, B>, typelist<A, B>> & C_ ## nom ## 2 (const E & val) const {										\\													\n\
	if (type() == typeid(H))																								\\													\n\
	{																														\\													\n\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>( nom (val, boost::any_cast<H>(*this))));					\\													\n\
	}																														\\													\n\
	else																													\\													\n\
	{																														\\													\n\
		return any_operable<T, typelist<A, B>>::C_ ##  nom ## 2(val);														\\													\n\
	}																														\\													\n\
}																																												\n\
																																												\n\
#define ADDOPE3( nom ,nom2, signe )																											\\									\n\
template <class T1, class T2>																												\\									\n\
struct nom2																																	\\									\n\
{																																			\\									\n\
	template <class U, class V> static auto less_than_test(const U* u, const V* v) -> decltype(*u signe *v, char(0)) { }					\\									\n\
	static std::array<char, 2> less_than_test(...) { }																						\\									\n\
	static constexpr bool value = (sizeof(less_than_test((T1*)0, (T2*)0)) == 1);															\\									\n\
};																																			\\									\n\
																																			\\									\n\
template<typename T1, typename T2> inline typename  boost::enable_if< nom2<T1, T2>, typename decltype(*(T1*)0 signe *(T2*)0) >::type		\\									\n\
nom (T1 const & a, T2 const & b) {																											\\									\n\
	return a signe b;																														\\									\n\
}																																			\\									\n\
template<typename T1, typename T2> inline typename boost::disable_if< nom2<T1, T2>, int >::type												\\									\n\
nom (T1 const & a, T2 const & b) {																											\\									\n\
	throw(\"ADDITION NOT ALLOWED\");																										\\									\n\
	return 0;																																\\									\n\
}																																												\n\
"; 



//ADDOPE3(OPp, supports_plus, +)
//ADDOPE3(OPm, supports_moin, -)
//ADDOPE3(OPf, supports_foi, *)


std::string ANY_P1 =
"																																												\n\
																																												\n\
template <class tlist, class tlist2> class any_operable;																														\n\
																																												\n\
template <class H, class T, class A, class B>																																	\n\
class any_operable < typelist<H, T>, typelist<A, B>  >																															\n\
	: public any_operable<T, typelist<A, B>>																																	\n\
{																																												\n\
public:																																											\n\
	template<class M> any_operable(M const  & _val) : any_operable<T, typelist<A, B>>(_val) {}																					\n\
	template<> any_operable(any_operable<typelist<A, B>, typelist<A, B>> const & _val) { boost::any.swap(_val::boost::any); }													\n\
	any_operable() : any_operable<T, typelist<A, B>>(0) {}																													\n\
"; 

//ADDOPE2(OPp)
//ADDOPE2(OPf)
//ADDOPE2(OPm)

std::string ANY_P2 =
"																																												\n\
};																																												\n\
template <class H, class A, class B>																																			\n\
class any_operable< typelist<H, null_typelist>, typelist<A, B>  >																												\n\
	: public boost::any																																							\n\
{																																												\n\
public:																																											\n\
	template<class M> any_operable(M const & _val) : boost::any(_val) {}																										\n\
	template<> any_operable(any_operable<typelist<A, B>, typelist<A, B>> const & _val) { boost::any.swap(_val::boost::any); }													\n\
	any_operable() : boost::any(0) {}																															\n\
"; 
//ADDOPE1(OPp)
//ADDOPE1(OPf)
//ADDOPE1(OPm)

std::string ANY_P3 =
"																																												\n\
};																																												\n\
																																												\n\
"; 



std::string inTMP(std::string s,unsigned int n) {
	if (n == 0) return "";
	return "template<"+s+">";
}
std::string inTMP2(std::string s, unsigned int n) {
	if (n == 0) return "template<>";
	return "template<" + s + ">";
}
std::string inCRO(std::string s, unsigned int n) {
	if (n == 0) return "<void>";
	return "<" + s + ">";
}

std::string everyREF(std::string const& before, std::string const& parameter, std::string const& after) {

	size_t pos=0;
	int n = 0;
	while((pos = 1 + parameter.find("#",pos)) - 1 != std::string::npos) { n++; }

	std::cout << n << std::endl;
	std::string result = "";

	if (REFERENCES==3) {
		LOOPER looper(n, 1);
		while (!looper.is_end()) {
			auto repart = looper.new_v();//get ref/rvalue ref repartitions
			int i = 0;
			std::string newparameter = parameter;
			while (newparameter.find("#") != std::string::npos) {
				if (repart[i] == 0)newparameter.replace(newparameter.find("#"), 1, "&");
				else newparameter.replace(newparameter.find("#"), 1, "&&");
				i++;
			}
			result += before + newparameter + after;
		}
	}
	else if (REFERENCES == 2) {
		std::string newparameter = parameter;
		while (newparameter.find("#") != std::string::npos) newparameter.replace(newparameter.find("#"), 1, "&");
		result += before + newparameter + after;
	}
	else {
		std::string newparameter = parameter;
		while (newparameter.find("#") != std::string::npos) newparameter.replace(newparameter.find("#"), 1, " ");
		result += before + newparameter + after;
	}

	return result;

}

std::string MACRO_INNER(unsigned int n,bool second) {

	std::string result = "";
	std::string finale = "";

	if (n - 1 > 0) {

		std::vector<std::string> ARG_b(n , "");//still unknown argument
		std::vector<std::string> ARG_a(n , "");//known argument
		std::vector<std::string> TEMP_ARG(n , "");
		std::vector<std::string> ARG(n , "");
		std::vector<std::string> CALL_ARG(n , "");
		std::vector<std::string> NEW_ARG(n , "");
		std::vector<std::string> CALL_NEW_ARG(n , "");
		std::vector<std::string> CALL_ARG2(n, "");
		std::vector<std::string> CALL_ARG9(n, "");

		for (size_t i = 0; i < n ; i++) // because the nth variable is the variable it selth !!
		{

			NAMEgenerator NGEN;
			std::vector<std::string> vars(n, ""); //even if the n^th one will never be used !!!
			for (auto & n : vars)n = NGEN.new_name();

			if(i>0)NEW_ARG[i] =  vars[i-1];
			else NEW_ARG[i] = "__NO__";
			
			int qr = 0;
			for (auto & v : vars) {
				
				if (qr != n - 1) {//couill mais la dernière variable sert a rien ... blamez moi svp 
					CALL_ARG[i] += v + ",";
					CALL_ARG9[i] += "* "+v + ",";
					if (qr != i-1)CALL_ARG2[i] += v + ",";
					else CALL_ARG2[i] += "boost::any_cast<H>(this) ,";
					CALL_NEW_ARG[i] += v + ",";
					qr++;
				}
			}
			CALL_ARG[i].pop_back();
			CALL_ARG9[i].pop_back();
			CALL_NEW_ARG[i].pop_back();
			CALL_ARG2[i].pop_back();

			for (size_t j = 0; j < i; j++) { 
				ARG_b[i] += "any_operable<typelist<A, B>, typelist<NAME_1_" + vars[j]+", NAME_2_" + vars[j] + ">> & " + vars[j] + ",";
				TEMP_ARG[i] += "class NAME_1_" + vars[j] + ", class NAME_2_" + vars[j] + ",";
			}
			for (size_t j = i; j < n - 1; j++) {
				ARG_a[i] += "NAME_" + vars[j] + " * " + vars[j] + ",";
				TEMP_ARG[i] += "class NAME_" + vars[j]+",";
			}

			TEMP_ARG[i].pop_back();

			TEMP_ARG[i] = "template<" + TEMP_ARG[i] + ">";

			if (ARG_a[i].size()>0) ARG_a[i].pop_back(); 
			else ARG_b[i].pop_back();
			
			ARG[i] = ARG_b[i] + ARG_a[i];

			std::string coeur = "";
			if (i != 0) {
				if (!second) {
					coeur = "if (type() == typeid(H))																			\\	\n\
	{																														\\	\n\
		return " + NEW_ARG[i] + "." + ID_NAME + "_ ## nom (" + CALL_ARG2[i] + ");																	\\	\n\
	}																														\\	\n\
	else																													\\	\n\
	{																														\\	\n\
		return any_operable<T, typelist<A, B>>::" + ID_NAME + "_ ## nom (" + CALL_NEW_ARG[i] + ");											\\	\n\
	}																														\\	\n";
				} else {
					coeur = "if (type() == typeid(H))																			\\	\n\
	{																														\\	\n\
		return " + NEW_ARG[i] + "." + ID_NAME + "_ ## nom (" + CALL_ARG2[i] + ");																	\\	\n\
	}																														\\	\n\
	else																													\\	\n\
	{																														\\	\n\
		throw(\"LEFT TYPE NOT SUPPORTED\");																					\\	\n\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\\	\n\
	}																														\\	\n";
				}
			}
			else {
				if (!second) {
					coeur = "if (type() == typeid(H))																			\\	\n\
	{																														\\	\n\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this)," + CALL_ARG9[i] + ")));																	\\	\n\
	}																														\\	\n\
	else																													\\	\n\
	{																														\\	\n\
		return any_operable<T, typelist<A, B>>::" + ID_NAME + "_ ## nom (" + CALL_NEW_ARG[i] + ");											\\	\n\
	}																														\\	\n";
				}
				else {
					coeur = "if (type() == typeid(H))																			\\	\n\
	{																														\\	\n\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this)," + CALL_ARG9[i] + ")));																	\\	\n\
	}																														\\	\n\
	else																													\\	\n\
	{																														\\	\n\
		throw(\"LEFT TYPE NOT SUPPORTED\");																					\\	\n\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\\	\n\
	}																														\\	\n";
				}
			}

			result += "																													\\					\n\
				" + TEMP_ARG[i] + "																										\\					\n\
				any_operable<typelist<A, B>,typelist<A, B>> & "+ ID_NAME +"_ ## nom("+ARG[i]+"){											\\					\n\
					"+coeur+"																											\\					\n\
				}																														\\					\n\
				";

		}
		
		finale = TEMP_ARG[n-1]+" any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom ("+ ARG[n-1] +") {					\\	\n\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & " + ID_NAME + "_ ## nom("+ CALL_ARG[n-1] +");					\\	\n\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\\	\n\
	delete result;																											\\	\n\
	return result2;																											\\	\n\
}																															\\	\n ";
		result = "#define ADDFCT_"+ std::to_string((int)second) + "_" + std::to_string(n) + "(nom)															\\	\n" + result;


	}
	else {
		//case wher argument taken are at the number of 1 -> the surrent function only !!!

		result += "#define ADDFCT_"+ std::to_string((int)second) + "_" + std::to_string(n) + "(nom)															\\	\n\
any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (){																	\\	\n\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom();											\\	\n\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\\	\n\
	delete result;																											\\	\n\
	return result2;																											\\	\n\
}																															\\	\n\
any_operable<typelist<A, B>,typelist<A, B>> & "+ ID_NAME +"_ ## nom(){															\\	\n\
																															\\	\n";
		if (!second) {
			result += "																										\\	\n\
				if (type() == typeid(H))																					\\	\n\
				{																											\\	\n\
					return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom(*boost::any_cast<H>(this))));		\\	\n\
	}																														\\	\n\
	else																													\\	\n\
	{																														\\	\n\
		return any_operable<T, typelist<A, B>>::" + ID_NAME + "_ ## nom ();													\\	\n\
	}																														\\	\n";
		}
		else {
			result += "																										\\	\n\
				if (type() == typeid(H))																					\\	\n\
				{																											\\	\n\
					return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom(*boost::any_cast<H>(this))));		\\	\n\
	}																														\\	\n\
	else																													\\	\n\
	{																														\\	\n\
		throw(\"LEFT TYPE NOT SUPPORTED\");																					\\	\n\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\\	\n\
	}																														\\	\n";
		}

result += "	}																														\\	\n";


	}
	result = retab( result + finale);
	result += "\n\n\n";
	return result;
}

std::string MACRO_FCT(unsigned int n)
{
	std::string MACRO_FCT_0 = "																																\n\
																																							\n\
#define IS_FCT0(nom,name)																															\\		\n\
namespace " + NAME_SPACE + " {																														\\		\n\
	template<class T>																																\\		\n\
	struct is_ ## nom ## _0																															\\		\n\
	{																																				\\		\n\
		template<class CNAME2_a> static auto less_than_test(CNAME2_a* a) -> decltype( name :: nom (), char(0)) { }							\\		\n\
		static std::array<char, 2> less_than_test(...) { }																							\\		\n\
		static constexpr bool value = (sizeof(less_than_test((T*)0)) == 1);																			\\		\n\
	};																																				\\		\n\
	template <class T> inline typename boost::enable_if< is_ ## nom ## _0<T>, typename decltype( name :: nom ()) >::type nom ## _o (T const & a) {	\\		\n\
		return name :: nom ();																														\\		\n\
	}																																				\\		\n\
	template <class T> inline typename boost::disable_if< is_ ## nom ## _0<T>, int >::type nom ## _o (T const & a) {								\\		\n\
		throw(\"Unknown function for without type  \");																													\\		\n\
		return 10;																																	\\		\n\
	}																																				\\		\n\
		inline auto nom() {																																\\		\n\
			return nom ## _o((int)0);																												\\		\n\
		}																																			\\		\n\
		inline auto G_ ## nom() {																															\\		\n\
			return nom ## _o((int)0);																												\\		\n\
		}																																			\\		\n\
	}																																						\n\
";

	if (n == 0) return retab(MACRO_FCT_0);

	std::string sn = std::to_string(n);
	std::string template_dec;
	std::string template_dec2;
	std::string template_dec_simple;
	std::string template_dec2_simple;
	std::string template_dec3_simple;
	std::string decl2;
	std::string decl3;
	std::string decl4;
	std::string decl5;
	std::string decl6;
	std::string decl7;
	std::string decl8;
	std::string decl16;

	NAMEgenerator NGEN;

	for (size_t i = 0; i < n; i++)
	{
		std::string name = NGEN.new_name();
		template_dec += "class CNAME_"+ name +",";
		template_dec2 += "class CNAME2_" + name + ",";
		template_dec_simple += "CNAME_" + name + ",";
		template_dec2_simple += "CNAME2_" + name + ",";
		template_dec3_simple += "CNAME_" + name + "*,";
		decl2 += "CNAME2_" + name + " "+ name +" ,";
		decl3 += "*" + name + " ,";
		decl4 += "CNAME_" + name + "  # " + name + " ,";
		decl8 += "CNAME_" + name + "  " + name + " ,";
		decl5 += "" + name + " ,";
		decl6 += "*(CNAME_" + name + "*)0,";
		decl16 += "*(CNAME_" + name + "*)0,";
		decl7 += "(CNAME_" + name + ")0,";

	}

		template_dec.pop_back();
		template_dec2.pop_back();
		template_dec_simple.pop_back();
		template_dec2_simple.pop_back();
		template_dec3_simple.pop_back();
		decl2.pop_back();
		decl3.pop_back();
		decl4.pop_back();
		decl5.pop_back();
		decl6.pop_back();
		decl16.pop_back();
		decl7.pop_back();
		decl8.pop_back();
		std::string SPE_PART = "";
		std::string SPE_PART1 = "";
		std::string SPE_PART23 = "";
		SPE_PART1 =
			everyREF(inTMP2(template_dec, n) + " inline typename  boost::enable_if< is_ ## nom ## _" + sn +inCRO(template_dec3_simple, n)+
				", typename decltype( name::nom (" + decl6 + ")) >::type	\\		\n\
G_ ## nom ## (" ,decl4 ,",typename std::enable_if<!std::is_same<typename decltype( name::nom (" + decl16 + ")), void>::value, empty_usable >::type = 0 ) {																																				\\		\n\
		return name::nom(" + decl5 + ");																																	\\		\n\
}				\\		\n");
		std::string SPE_PART2 = "";
		SPE_PART2 =
			everyREF(inTMP2(template_dec, n) + " inline typename  boost::enable_if< is_ ## nom ## _" + sn + inCRO(template_dec3_simple, n) +
				", int >::type	\\		\n\
G_ ## nom ## (", decl4, ",typename std::enable_if<std::is_same<typename decltype( name::nom (" + decl16 + ")), void>::value, empty_usable >::type = 0 ) {																																				\\		\n\
				name::nom(" + decl5 + ");																																 \\		\n\
				return 0;																																				 \\		\n\
}																																											\\		\n");

		SPE_PART += SPE_PART1 + SPE_PART2;

		return retab("																																									\n\
#define IS_FCT" + std::to_string(n) + "( nom , name )																														\\		\n\
namespace " + NAME_SPACE + " {																																				\\		\n\
" + inTMP(template_dec, n) + "																																				\\		\n\
struct is_ ## nom ## _" + sn + "																																				\\		\n\
{																																											\\		\n\
" + inTMP(template_dec2, n) + " static auto less_than_test(" + decl2 + ") -> decltype(name::nom(" + decl3 + "), char(0)) { }														\\		\n\
static std::array<char, 2> less_than_test(...) { }																															\\		\n\
static constexpr bool value = (sizeof(less_than_test(" + decl7 + ")) == 1);																									\\		\n\
};																																											\\		\n\
																																											\\		\n\
" +
SPE_PART
+"																																											\\		\n\
" + inTMP2(template_dec, n) + " inline typename boost::disable_if< is_ ## nom ## _"+sn+"" + inCRO(template_dec3_simple,n) + ", int >::type									\\		\n\
G_ ## nom ## (" + decl8 + ") {																																				\\		\n\
																																											\\		\n\
			throw(\"Unknown function for asked type \");																														\\		\n\
			return 0;																																						\\		\n\
	}																																										\\		\n\
}																																													\n\
");

}

void INIT_STRINGS() {

	HEADERS = retab(HEADERS);
	OPERATORMACROS = retab(OPERATORMACROS);
	ANY_P1 = retab(ANY_P1);
	ANY_P2 = retab(ANY_P2);
	ANY_P3 = retab(ANY_P3);

}