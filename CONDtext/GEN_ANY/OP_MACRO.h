
#pragma once
#include <iostream>
#include <array>
#include "boost\utility\enable_if.hpp"
#include "boost\any.hpp"
#include "TYPELIST.h"

#define ADDOPE1( nom ) any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom ## 2(const any_operable<typelist<A, B>, typelist<A, B>> & q) const { \
	any_operable<typelist<A, B>, typelist<A, B>> result = C_ ## nom (q);												\
	delete &q;																											\
	return result;																										\
}																														\
template <class X, class Y>																								\
any_operable<typelist<A, B>, typelist<A, B>> & C_ ## nom (const any_operable<typelist<X, Y>, typelist<A, B>> & q) const {	\
	if (type() == typeid(H))																							\
	{																													\
		return q.C_ ## nom ## 2(boost::any_cast<H>(*this));																\
	}																													\
	else																												\
	{																													\
		throw("LEFT TYPE NOT SUPPORTED");																				\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));													\
	}																													\
}																														\
template<class E>																										\
any_operable<typelist<A, B>, typelist<A, B>> & C_ ## nom ## 2(const E & val) const {									\
	if (type() == typeid(H))																							\
	{																													\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>( nom (val, boost::any_cast<H>(*this))));				\
	}																													\
	else																												\
	{																													\
		throw("RIGHT TYPE NOT SUPPORTED");																			\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>(0));													\
	}																													\
}

#define ADDOPE2( nom )any_operable<typelist<A, B>, typelist<A, B>> F_ ## nom ## 2(const any_operable<typelist<A, B>, typelist<A, B>> & q) const {			\
	any_operable<typelist<A, B>, typelist<A, B>>* result = &C_ ## nom(q);													\
	any_operable<typelist<A, B>, typelist<A, B>> result2 = std::move(*result);												\
	delete result;																											\
	return result2;																											\
}																															\
template <class X, class Y>																									\
any_operable<typelist<A, B>, typelist<A, B>> & C_ ## nom (const any_operable<typelist<X, Y>, typelist<A, B>> & q)  const {	\
	if (type() == typeid(H))																								\
	{																														\
		return q.C_ ## nom ## 2(boost::any_cast<H>(*this));																	\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::C_ ## nom(q);																\
	}																														\
}																															\
template<class E>																											\
any_operable<typelist<A, B>, typelist<A, B>> & C_ ## nom ## 2 (const E & val) const {										\
	if (type() == typeid(H))																								\
	{																														\
		return *(new any_operable<typelist<A, B>, typelist<A, B>>( nom (val, boost::any_cast<H>(*this))));					\
	}																														\
	else																													\
	{																														\
		return any_operable<T, typelist<A, B>>::C_ ##  nom ## 2(val);														\
	}																														\
}

#define ADDOPE3( nom ,nom2, signe )																											\
template <class T1, class T2>																												\
struct nom2																																	\
{																																			\
	template <class U, class V> static auto less_than_test(const U* u, const V* v) -> decltype(*u signe *v, char(0)) { }					\
	static std::array<char, 2> less_than_test(...) { }																						\
	static constexpr bool value = (sizeof(less_than_test((T1*)0, (T2*)0)) == 1);															\
};																																			\
																																			\
template<typename T1, typename T2> inline typename  boost::enable_if< nom2<T1, T2>, typename decltype(*(T1*)0 signe *(T2*)0) >::type		\
nom (T1 const & a, T2 const & b) {																											\
	return a signe b;																														\
}																																			\
template<typename T1, typename T2> inline typename boost::disable_if< nom2<T1, T2>, int >::type												\
nom (T1 const & a, T2 const & b) {																											\
	throw("ADDITION NOT ALLOWED");																										\
	return 0;																																\
}
