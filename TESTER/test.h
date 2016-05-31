#pragma once
#include <iostream>
#include <array>
#include "boost\utility\enable_if.hpp"
#include "boost\any.hpp"
#include "TYPELIST.h"
#include "Math.h" 

void sin(int);

//MACRO 
class  empty_usable { public: empty_usable(int) {} };
																																								
template<class CNAME_a>																																				
struct is_sin_1																																				
{																																											
template<class CNAME2_a> static auto less_than_test(CNAME2_a a ) -> decltype(::sin(*a ), char(0)) { }														
static std::array<char, 2> less_than_test(...) { }																															
static constexpr bool value = (sizeof(less_than_test((CNAME_a)0)) == 1);																									
};																																											
																																											
template<class CNAME_a> inline typename  boost::enable_if< is_sin_1<CNAME_a*>, typename decltype( ::sin (*(CNAME_a*)0)) >::type	
G_sin(CNAME_a  & a ,typename std::enable_if<!std::is_same<typename decltype( ::sin (*(CNAME_a*)0)), void>::value, empty_usable >::type = 0 ) {																																				
		return ::sin(a );																																	
}				
template<class CNAME_a> inline typename  boost::enable_if< is_sin_1<CNAME_a*>, typename decltype( ::sin (*(CNAME_a*)0)) >::type	
G_sin(CNAME_a  && a ,typename std::enable_if<!std::is_same<typename decltype( ::sin (*(CNAME_a*)0)), void>::value, empty_usable >::type = 0 ) {															
		return ::sin(a );																																	
}				
template<class CNAME_a> inline typename  boost::enable_if< is_sin_1<CNAME_a*>, int >::type	
G_sin(CNAME_a  & a ,typename std::enable_if<std::is_same<typename decltype( ::sin (*(CNAME_a*)0)), void>::value, empty_usable >::type = 0 ) {																																				
				::sin(a );																																 
				return 0;																																				 
}																																											
template<class CNAME_a> inline typename  boost::enable_if< is_sin_1<CNAME_a*>, int >::type	
G_sin(CNAME_a  && a ,typename std::enable_if<std::is_same<typename decltype( ::sin (*(CNAME_a*)0)), void>::value, empty_usable >::type = 0 ) {								
				::sin(a );																																 
				return 0;																																				 
}																																										
																																											
template<class CNAME_a> inline typename boost::disable_if< is_sin_1<CNAME_a*>, int >::type									
G_sin(CNAME_a  a ) {																																				
																																											
			throw("Unknown function for asked type ");																														
			return 0;																																						
	}																																										


