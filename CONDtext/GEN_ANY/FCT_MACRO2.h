
#pragma once
#include <iostream>
#include <array>
#include "boost\utility\enable_if.hpp"
#include "boost\any.hpp"
#include "TYPELIST.h"
#define ADDFCT_1_1(nom)															\
any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (){																	\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom();											\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(){															\
																															\
																										\
				if (type() == typeid(H))																					\
				{																											\
					return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom(*boost::any_cast<H>(this))));		\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
	}																														\



#define ADDFCT_0_1(nom)															\
any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (){																	\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom();											\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(){															\
																															\
																										\
				if (type() == typeid(H))																					\
				{																											\
					return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom(*boost::any_cast<H>(this))));		\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom ();													\
	}																														\
	}																														\



#define ADDFCT_1_2(nom)															\
																													\
				template<class NAME_a>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(NAME_a * a){											\
					if (type() == typeid(H))																			\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this),* a)));																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a){											\
					if (type() == typeid(H))																			\
	{																														\
		return a.ANY_class__ ## nom (boost::any_cast<H>(this) );																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
				template<class NAME_1_a, class NAME_2_a> any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a) {					\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom(a);					\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
 


#define ADDFCT_0_2(nom)															\
																													\
				template<class NAME_a>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(NAME_a * a){											\
					if (type() == typeid(H))																			\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this),* a)));																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a){											\
					if (type() == typeid(H))																			\
	{																														\
		return a.ANY_class__ ## nom (boost::any_cast<H>(this) );																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a);											\
	}																														\
																											\
				}																														\
				template<class NAME_1_a, class NAME_2_a> any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a) {					\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom(a);					\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
 


#define ADDFCT_1_3(nom)															\
																													\
				template<class NAME_a,class NAME_b>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(NAME_a * a,NAME_b * b){											\
					if (type() == typeid(H))																			\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this),* a,* b)));																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_b>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,NAME_b * b){											\
					if (type() == typeid(H))																			\
	{																														\
		return a.ANY_class__ ## nom (boost::any_cast<H>(this) ,b);																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b){											\
					if (type() == typeid(H))																			\
	{																														\
		return b.ANY_class__ ## nom (a,boost::any_cast<H>(this) );																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b> any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b) {					\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom(a,b);					\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
 


#define ADDFCT_0_3(nom)															\
																													\
				template<class NAME_a,class NAME_b>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(NAME_a * a,NAME_b * b){											\
					if (type() == typeid(H))																			\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this),* a,* b)));																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_b>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,NAME_b * b){											\
					if (type() == typeid(H))																			\
	{																														\
		return a.ANY_class__ ## nom (boost::any_cast<H>(this) ,b);																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b){											\
					if (type() == typeid(H))																			\
	{																														\
		return b.ANY_class__ ## nom (a,boost::any_cast<H>(this) );																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b);											\
	}																														\
																											\
				}																														\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b> any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b) {					\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom(a,b);					\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
 


#define ADDFCT_1_4(nom)															\
																													\
				template<class NAME_a,class NAME_b,class NAME_c>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(NAME_a * a,NAME_b * b,NAME_c * c){											\
					if (type() == typeid(H))																			\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this),* a,* b,* c)));																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_b,class NAME_c>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,NAME_b * b,NAME_c * c){											\
					if (type() == typeid(H))																			\
	{																														\
		return a.ANY_class__ ## nom (boost::any_cast<H>(this) ,b,c);																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_c>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,NAME_c * c){											\
					if (type() == typeid(H))																			\
	{																														\
		return b.ANY_class__ ## nom (a,boost::any_cast<H>(this) ,c);																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c){											\
					if (type() == typeid(H))																			\
	{																														\
		return c.ANY_class__ ## nom (a,b,boost::any_cast<H>(this) );																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c> any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c) {					\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom(a,b,c);					\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
 


#define ADDFCT_0_4(nom)															\
																													\
				template<class NAME_a,class NAME_b,class NAME_c>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(NAME_a * a,NAME_b * b,NAME_c * c){											\
					if (type() == typeid(H))																			\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this),* a,* b,* c)));																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_b,class NAME_c>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,NAME_b * b,NAME_c * c){											\
					if (type() == typeid(H))																			\
	{																														\
		return a.ANY_class__ ## nom (boost::any_cast<H>(this) ,b,c);																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_c>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,NAME_c * c){											\
					if (type() == typeid(H))																			\
	{																														\
		return b.ANY_class__ ## nom (a,boost::any_cast<H>(this) ,c);																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c){											\
					if (type() == typeid(H))																			\
	{																														\
		return c.ANY_class__ ## nom (a,b,boost::any_cast<H>(this) );																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c);											\
	}																														\
																											\
				}																														\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c> any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c) {					\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom(a,b,c);					\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
 


#define ADDFCT_1_5(nom)															\
																													\
				template<class NAME_a,class NAME_b,class NAME_c,class NAME_d>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(NAME_a * a,NAME_b * b,NAME_c * c,NAME_d * d){											\
					if (type() == typeid(H))																			\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this),* a,* b,* c,* d)));																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_b,class NAME_c,class NAME_d>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,NAME_b * b,NAME_c * c,NAME_d * d){											\
					if (type() == typeid(H))																			\
	{																														\
		return a.ANY_class__ ## nom (boost::any_cast<H>(this) ,b,c,d);																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_c,class NAME_d>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,NAME_c * c,NAME_d * d){											\
					if (type() == typeid(H))																			\
	{																														\
		return b.ANY_class__ ## nom (a,boost::any_cast<H>(this) ,c,d);																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_d>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,NAME_d * d){											\
					if (type() == typeid(H))																			\
	{																														\
		return c.ANY_class__ ## nom (a,b,boost::any_cast<H>(this) ,d);																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_1_d, class NAME_2_d>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,any_operable<typelist<A, B>, typelist<NAME_1_d, NAME_2_d>> & d){											\
					if (type() == typeid(H))																			\
	{																														\
		return d.ANY_class__ ## nom (a,b,c,boost::any_cast<H>(this) );																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_1_d, class NAME_2_d> any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,any_operable<typelist<A, B>, typelist<NAME_1_d, NAME_2_d>> & d) {					\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom(a,b,c,d);					\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
 


#define ADDFCT_0_5(nom)															\
																													\
				template<class NAME_a,class NAME_b,class NAME_c,class NAME_d>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(NAME_a * a,NAME_b * b,NAME_c * c,NAME_d * d){											\
					if (type() == typeid(H))																			\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this),* a,* b,* c,* d)));																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_b,class NAME_c,class NAME_d>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,NAME_b * b,NAME_c * c,NAME_d * d){											\
					if (type() == typeid(H))																			\
	{																														\
		return a.ANY_class__ ## nom (boost::any_cast<H>(this) ,b,c,d);																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_c,class NAME_d>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,NAME_c * c,NAME_d * d){											\
					if (type() == typeid(H))																			\
	{																														\
		return b.ANY_class__ ## nom (a,boost::any_cast<H>(this) ,c,d);																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_d>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,NAME_d * d){											\
					if (type() == typeid(H))																			\
	{																														\
		return c.ANY_class__ ## nom (a,b,boost::any_cast<H>(this) ,d);																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_1_d, class NAME_2_d>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,any_operable<typelist<A, B>, typelist<NAME_1_d, NAME_2_d>> & d){											\
					if (type() == typeid(H))																			\
	{																														\
		return d.ANY_class__ ## nom (a,b,c,boost::any_cast<H>(this) );																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d);											\
	}																														\
																											\
				}																														\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_1_d, class NAME_2_d> any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,any_operable<typelist<A, B>, typelist<NAME_1_d, NAME_2_d>> & d) {					\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom(a,b,c,d);					\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
 


#define ADDFCT_1_6(nom)															\
																													\
				template<class NAME_a,class NAME_b,class NAME_c,class NAME_d,class NAME_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(NAME_a * a,NAME_b * b,NAME_c * c,NAME_d * d,NAME_e * e){											\
					if (type() == typeid(H))																			\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this),* a,* b,* c,* d,* e)));																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_b,class NAME_c,class NAME_d,class NAME_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,NAME_b * b,NAME_c * c,NAME_d * d,NAME_e * e){											\
					if (type() == typeid(H))																			\
	{																														\
		return a.ANY_class__ ## nom (boost::any_cast<H>(this) ,b,c,d,e);																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_c,class NAME_d,class NAME_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,NAME_c * c,NAME_d * d,NAME_e * e){											\
					if (type() == typeid(H))																			\
	{																														\
		return b.ANY_class__ ## nom (a,boost::any_cast<H>(this) ,c,d,e);																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_d,class NAME_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,NAME_d * d,NAME_e * e){											\
					if (type() == typeid(H))																			\
	{																														\
		return c.ANY_class__ ## nom (a,b,boost::any_cast<H>(this) ,d,e);																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_1_d, class NAME_2_d,class NAME_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,any_operable<typelist<A, B>, typelist<NAME_1_d, NAME_2_d>> & d,NAME_e * e){											\
					if (type() == typeid(H))																			\
	{																														\
		return d.ANY_class__ ## nom (a,b,c,boost::any_cast<H>(this) ,e);																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_1_d, class NAME_2_d,class NAME_1_e, class NAME_2_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,any_operable<typelist<A, B>, typelist<NAME_1_d, NAME_2_d>> & d,any_operable<typelist<A, B>, typelist<NAME_1_e, NAME_2_e>> & e){											\
					if (type() == typeid(H))																			\
	{																														\
		return e.ANY_class__ ## nom (a,b,c,d,boost::any_cast<H>(this) );																	\
	}																														\
	else																													\
	{																														\
		throw("LEFT TYPE NOT SUPPORTED");																					\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));														\
	}																														\
																											\
				}																														\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_1_d, class NAME_2_d,class NAME_1_e, class NAME_2_e> any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,any_operable<typelist<A, B>, typelist<NAME_1_d, NAME_2_d>> & d,any_operable<typelist<A, B>, typelist<NAME_1_e, NAME_2_e>> & e) {					\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom(a,b,c,d,e);					\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
 


#define ADDFCT_0_6(nom)															\
																													\
				template<class NAME_a,class NAME_b,class NAME_c,class NAME_d,class NAME_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(NAME_a * a,NAME_b * b,NAME_c * c,NAME_d * d,NAME_e * e){											\
					if (type() == typeid(H))																			\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(G_ ## nom (* boost::any_cast<H>(this),* a,* b,* c,* d,* e)));																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d,e);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_b,class NAME_c,class NAME_d,class NAME_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,NAME_b * b,NAME_c * c,NAME_d * d,NAME_e * e){											\
					if (type() == typeid(H))																			\
	{																														\
		return a.ANY_class__ ## nom (boost::any_cast<H>(this) ,b,c,d,e);																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d,e);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_c,class NAME_d,class NAME_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,NAME_c * c,NAME_d * d,NAME_e * e){											\
					if (type() == typeid(H))																			\
	{																														\
		return b.ANY_class__ ## nom (a,boost::any_cast<H>(this) ,c,d,e);																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d,e);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_d,class NAME_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,NAME_d * d,NAME_e * e){											\
					if (type() == typeid(H))																			\
	{																														\
		return c.ANY_class__ ## nom (a,b,boost::any_cast<H>(this) ,d,e);																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d,e);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_1_d, class NAME_2_d,class NAME_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,any_operable<typelist<A, B>, typelist<NAME_1_d, NAME_2_d>> & d,NAME_e * e){											\
					if (type() == typeid(H))																			\
	{																														\
		return d.ANY_class__ ## nom (a,b,c,boost::any_cast<H>(this) ,e);																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d,e);											\
	}																														\
																											\
				}																														\
																																	\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_1_d, class NAME_2_d,class NAME_1_e, class NAME_2_e>																										\
				any_operable<typelist<A, B>,typelist<A, B>> & ANY_class__ ## nom(any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,any_operable<typelist<A, B>, typelist<NAME_1_d, NAME_2_d>> & d,any_operable<typelist<A, B>, typelist<NAME_1_e, NAME_2_e>> & e){											\
					if (type() == typeid(H))																			\
	{																														\
		return e.ANY_class__ ## nom (a,b,c,d,boost::any_cast<H>(this) );																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::ANY_class__ ## nom (a,b,c,d,e);											\
	}																														\
																											\
				}																														\
				template<class NAME_1_a, class NAME_2_a,class NAME_1_b, class NAME_2_b,class NAME_1_c, class NAME_2_c,class NAME_1_d, class NAME_2_d,class NAME_1_e, class NAME_2_e> any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom (any_operable<typelist<A, B>, typelist<NAME_1_a, NAME_2_a>> & a,any_operable<typelist<A, B>, typelist<NAME_1_b, NAME_2_b>> & b,any_operable<typelist<A, B>, typelist<NAME_1_c, NAME_2_c>> & c,any_operable<typelist<A, B>, typelist<NAME_1_d, NAME_2_d>> & d,any_operable<typelist<A, B>, typelist<NAME_1_e, NAME_2_e>> & e) {					\
	any_operable<typelist<A, B>, typelist<A, B>>* result = & ANY_class__ ## nom(a,b,c,d,e);					\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
 


