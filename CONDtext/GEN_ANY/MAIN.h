
#pragma once
#include <iostream>
#include <array>
#include "boost\utility\enable_if.hpp"
#include "boost\any.hpp"
#include "TYPELIST.h"
#include "GEN_ANY\OP_MACRO.h"
#include "GEN_ANY\FCT_MACRO.h"
#include "GEN_ANY\FCT_MACRO2.h"
#include "GEN_ANY\MEMBER_MACRO.h"
struct void_return {};																																							
class empty_usable {public:empty_usable(int){}};																																							
namespace ANY_FCT{PARAM_CALL_6(size)
PARAM_CALL_5(size)
PARAM_CALL_4(size)
PARAM_CALL_3(size)
PARAM_CALL_2(size)
PARAM_CALL_1(size)
PARAM_CALL_6(pop_back)
PARAM_CALL_5(pop_back)
PARAM_CALL_4(pop_back)
PARAM_CALL_3(pop_back)
PARAM_CALL_2(pop_back)
PARAM_CALL_1(pop_back)
};IS_FCT6(sin,)
IS_FCT5(sin,)
IS_FCT4(sin,)
IS_FCT3(sin,)
IS_FCT2(sin,)
IS_FCT1(sin,)
IS_FCT0(sin,)
IS_FCT6(cos,)
IS_FCT5(cos,)
IS_FCT4(cos,)
IS_FCT3(cos,)
IS_FCT2(cos,)
IS_FCT1(cos,)
IS_FCT0(cos,)
IS_FCT6(pow,)
IS_FCT5(pow,)
IS_FCT4(pow,)
IS_FCT3(pow,)
IS_FCT2(pow,)
IS_FCT1(pow,)
IS_FCT0(pow,)
IS_FCT6(display,)
IS_FCT5(display,)
IS_FCT4(display,)
IS_FCT3(display,)
IS_FCT2(display,)
IS_FCT1(display,)
IS_FCT0(display,)
IS_FCT6(change,)
IS_FCT5(change,)
IS_FCT4(change,)
IS_FCT3(change,)
IS_FCT2(change,)
IS_FCT1(change,)
IS_FCT0(change,)
IS_FCT6(CALL_MEMBER_size,ANY_FCT)
IS_FCT5(CALL_MEMBER_size,ANY_FCT)
IS_FCT4(CALL_MEMBER_size,ANY_FCT)
IS_FCT3(CALL_MEMBER_size,ANY_FCT)
IS_FCT2(CALL_MEMBER_size,ANY_FCT)
IS_FCT1(CALL_MEMBER_size,ANY_FCT)
IS_FCT0(CALL_MEMBER_size,ANY_FCT)
IS_FCT6(CALL_MEMBER_pop_back,ANY_FCT)
IS_FCT5(CALL_MEMBER_pop_back,ANY_FCT)
IS_FCT4(CALL_MEMBER_pop_back,ANY_FCT)
IS_FCT3(CALL_MEMBER_pop_back,ANY_FCT)
IS_FCT2(CALL_MEMBER_pop_back,ANY_FCT)
IS_FCT1(CALL_MEMBER_pop_back,ANY_FCT)
IS_FCT0(CALL_MEMBER_pop_back,ANY_FCT)
ADDOPE3(ANY_class__a, ANY_class__SUP_a,+)
ADDOPE3(ANY_class__b, ANY_class__SUP_b,-)
ADDOPE3(ANY_class__c, ANY_class__SUP_c,*)
ADDOPE3(ANY_class__d, ANY_class__SUP_d,/)
ADDOPE3(ANY_class__e, ANY_class__SUP_e,^)
ADDOPE3(ANY_class__f, ANY_class__SUP_f,&&)
ADDOPE3(ANY_class__g, ANY_class__SUP_g,||)
ADDOPE3(ANY_class__h, ANY_class__SUP_h,|)
ADDOPE3(ANY_class__i, ANY_class__SUP_i,&)
namespace ANY_FCT {	


template <class tlist, class tlist2> class any_operable;

template <class H, class T, class A, class B>
class any_operable < typelist<H, T>, typelist<A, B>  >
	: public any_operable<T, typelist<A, B>>
{
public:
	template<class M> any_operable(M const  & _val) : any_operable<T, typelist<A, B>>(_val) {}
	template<> any_operable(any_operable<typelist<A, B>, typelist<A, B>> const & _val) { boost::any.swap(_val::boost::any); }
	any_operable() : any_operable<T, typelist<A, B>>(0) {}

ADDOPE2(ANY_class__a)
ADDOPE2(ANY_class__b)
ADDOPE2(ANY_class__c)
ADDOPE2(ANY_class__d)
ADDOPE2(ANY_class__e)
ADDOPE2(ANY_class__f)
ADDOPE2(ANY_class__g)
ADDOPE2(ANY_class__h)
ADDOPE2(ANY_class__i)

ADDFCT_0_1(sin)
ADDFCT_0_2(sin)
ADDFCT_0_3(sin)
ADDFCT_0_4(sin)
ADDFCT_0_5(sin)
ADDFCT_0_6(sin)
ADDFCT_0_1(cos)
ADDFCT_0_2(cos)
ADDFCT_0_3(cos)
ADDFCT_0_4(cos)
ADDFCT_0_5(cos)
ADDFCT_0_6(cos)
ADDFCT_0_1(pow)
ADDFCT_0_2(pow)
ADDFCT_0_3(pow)
ADDFCT_0_4(pow)
ADDFCT_0_5(pow)
ADDFCT_0_6(pow)
ADDFCT_0_1(display)
ADDFCT_0_2(display)
ADDFCT_0_3(display)
ADDFCT_0_4(display)
ADDFCT_0_5(display)
ADDFCT_0_6(display)
ADDFCT_0_1(change)
ADDFCT_0_2(change)
ADDFCT_0_3(change)
ADDFCT_0_4(change)
ADDFCT_0_5(change)
ADDFCT_0_6(change)
ADDFCT_0_1(CALL_MEMBER_size)
ADDFCT_0_2(CALL_MEMBER_size)
ADDFCT_0_3(CALL_MEMBER_size)
ADDFCT_0_4(CALL_MEMBER_size)
ADDFCT_0_5(CALL_MEMBER_size)
ADDFCT_0_6(CALL_MEMBER_size)
ADDFCT_0_1(CALL_MEMBER_pop_back)
ADDFCT_0_2(CALL_MEMBER_pop_back)
ADDFCT_0_3(CALL_MEMBER_pop_back)
ADDFCT_0_4(CALL_MEMBER_pop_back)
ADDFCT_0_5(CALL_MEMBER_pop_back)
ADDFCT_0_6(CALL_MEMBER_pop_back)
INNER_PARAM_CALL_0_6(size)
INNER_PARAM_CALL_0_5(size)
INNER_PARAM_CALL_0_4(size)
INNER_PARAM_CALL_0_3(size)
INNER_PARAM_CALL_0_2(size)
INNER_PARAM_CALL_0_1(size)
INNER_PARAM_CALL_0_6(pop_back)
INNER_PARAM_CALL_0_5(pop_back)
INNER_PARAM_CALL_0_4(pop_back)
INNER_PARAM_CALL_0_3(pop_back)
INNER_PARAM_CALL_0_2(pop_back)
INNER_PARAM_CALL_0_1(pop_back)

};
template <class H, class A, class B>
class any_operable< typelist<H, null_typelist>, typelist<A, B>  >
	: public boost::any
{
public:
	template<class M> any_operable(M const & _val) : boost::any(_val) {}
	template<> any_operable(any_operable<typelist<A, B>, typelist<A, B>> const & _val) { boost::any.swap(_val::boost::any); }
	any_operable() : boost::any(0) {}

ADDOPE1(ANY_class__a)
ADDOPE1(ANY_class__b)
ADDOPE1(ANY_class__c)
ADDOPE1(ANY_class__d)
ADDOPE1(ANY_class__e)
ADDOPE1(ANY_class__f)
ADDOPE1(ANY_class__g)
ADDOPE1(ANY_class__h)
ADDOPE1(ANY_class__i)

ADDFCT_1_1(sin)
ADDFCT_1_2(sin)
ADDFCT_1_3(sin)
ADDFCT_1_4(sin)
ADDFCT_1_5(sin)
ADDFCT_1_6(sin)
ADDFCT_1_1(cos)
ADDFCT_1_2(cos)
ADDFCT_1_3(cos)
ADDFCT_1_4(cos)
ADDFCT_1_5(cos)
ADDFCT_1_6(cos)
ADDFCT_1_1(pow)
ADDFCT_1_2(pow)
ADDFCT_1_3(pow)
ADDFCT_1_4(pow)
ADDFCT_1_5(pow)
ADDFCT_1_6(pow)
ADDFCT_1_1(display)
ADDFCT_1_2(display)
ADDFCT_1_3(display)
ADDFCT_1_4(display)
ADDFCT_1_5(display)
ADDFCT_1_6(display)
ADDFCT_1_1(change)
ADDFCT_1_2(change)
ADDFCT_1_3(change)
ADDFCT_1_4(change)
ADDFCT_1_5(change)
ADDFCT_1_6(change)
ADDFCT_1_1(CALL_MEMBER_size)
ADDFCT_1_2(CALL_MEMBER_size)
ADDFCT_1_3(CALL_MEMBER_size)
ADDFCT_1_4(CALL_MEMBER_size)
ADDFCT_1_5(CALL_MEMBER_size)
ADDFCT_1_6(CALL_MEMBER_size)
ADDFCT_1_1(CALL_MEMBER_pop_back)
ADDFCT_1_2(CALL_MEMBER_pop_back)
ADDFCT_1_3(CALL_MEMBER_pop_back)
ADDFCT_1_4(CALL_MEMBER_pop_back)
ADDFCT_1_5(CALL_MEMBER_pop_back)
ADDFCT_1_6(CALL_MEMBER_pop_back)
INNER_PARAM_CALL_1_6(size)
INNER_PARAM_CALL_1_5(size)
INNER_PARAM_CALL_1_4(size)
INNER_PARAM_CALL_1_3(size)
INNER_PARAM_CALL_1_2(size)
INNER_PARAM_CALL_1_1(size)
INNER_PARAM_CALL_1_6(pop_back)
INNER_PARAM_CALL_1_5(pop_back)
INNER_PARAM_CALL_1_4(pop_back)
INNER_PARAM_CALL_1_3(pop_back)
INNER_PARAM_CALL_1_2(pop_back)
INNER_PARAM_CALL_1_1(pop_back)

};

};
#define ANY(typelist) ANY_FCT::any_operable<typelist,typelist>	
namespace ANY_FCT {	
																																	
template <class H, class T>																														
any_operable <H,T> operator+(any_operable <H,T> a, any_operable <H,T> b)																
{																																				
	return a.F_ANY_class__a2(b);																							
}																																				
																																	
template <class H, class T>																														
any_operable <H,T> operator-(any_operable <H,T> a, any_operable <H,T> b)																
{																																				
	return a.F_ANY_class__b2(b);																							
}																																				
																																	
template <class H, class T>																														
any_operable <H,T> operator*(any_operable <H,T> a, any_operable <H,T> b)																
{																																				
	return a.F_ANY_class__c2(b);																							
}																																				
																																	
template <class H, class T>																														
any_operable <H,T> operator/(any_operable <H,T> a, any_operable <H,T> b)																
{																																				
	return a.F_ANY_class__d2(b);																							
}																																				
																																	
template <class H, class T>																														
any_operable <H,T> operator^(any_operable <H,T> a, any_operable <H,T> b)																
{																																				
	return a.F_ANY_class__e2(b);																							
}																																				
																																	
template <class H, class T>																														
any_operable <H,T> operator&&(any_operable <H,T> a, any_operable <H,T> b)																
{																																				
	return a.F_ANY_class__f2(b);																							
}																																				
																																	
template <class H, class T>																														
any_operable <H,T> operator||(any_operable <H,T> a, any_operable <H,T> b)																
{																																				
	return a.F_ANY_class__g2(b);																							
}																																				
																																	
template <class H, class T>																														
any_operable <H,T> operator|(any_operable <H,T> a, any_operable <H,T> b)																
{																																				
	return a.F_ANY_class__h2(b);																							
}																																				
																																	
template <class H, class T>																														
any_operable <H,T> operator&(any_operable <H,T> a, any_operable <H,T> b)																
{																																				
	return a.F_ANY_class__i2(b);																							
}																																				
template <class H, class T>	 any_operable <H,T>sin(any_operable <H,T> & a){ return a.F_sin();}
template <class H, class T>	 any_operable <H,T>sin(any_operable <H,T> & a,any_operable <H,T> & b){ return b.F_sin(a);}
template <class H, class T>	 any_operable <H,T>sin(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c){ return c.F_sin(a,b);}
template <class H, class T>	 any_operable <H,T>sin(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d){ return d.F_sin(a,b,c);}
template <class H, class T>	 any_operable <H,T>sin(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e){ return e.F_sin(a,b,c,d);}
template <class H, class T>	 any_operable <H,T>sin(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e,any_operable <H,T> & f){ return f.F_sin(a,b,c,d,e);}
template <class H, class T>	 any_operable <H,T>cos(any_operable <H,T> & a){ return a.F_cos();}
template <class H, class T>	 any_operable <H,T>cos(any_operable <H,T> & a,any_operable <H,T> & b){ return b.F_cos(a);}
template <class H, class T>	 any_operable <H,T>cos(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c){ return c.F_cos(a,b);}
template <class H, class T>	 any_operable <H,T>cos(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d){ return d.F_cos(a,b,c);}
template <class H, class T>	 any_operable <H,T>cos(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e){ return e.F_cos(a,b,c,d);}
template <class H, class T>	 any_operable <H,T>cos(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e,any_operable <H,T> & f){ return f.F_cos(a,b,c,d,e);}
template <class H, class T>	 any_operable <H,T>pow(any_operable <H,T> & a){ return a.F_pow();}
template <class H, class T>	 any_operable <H,T>pow(any_operable <H,T> & a,any_operable <H,T> & b){ return b.F_pow(a);}
template <class H, class T>	 any_operable <H,T>pow(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c){ return c.F_pow(a,b);}
template <class H, class T>	 any_operable <H,T>pow(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d){ return d.F_pow(a,b,c);}
template <class H, class T>	 any_operable <H,T>pow(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e){ return e.F_pow(a,b,c,d);}
template <class H, class T>	 any_operable <H,T>pow(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e,any_operable <H,T> & f){ return f.F_pow(a,b,c,d,e);}
template <class H, class T>	 any_operable <H,T>display(any_operable <H,T> & a){ return a.F_display();}
template <class H, class T>	 any_operable <H,T>display(any_operable <H,T> & a,any_operable <H,T> & b){ return b.F_display(a);}
template <class H, class T>	 any_operable <H,T>display(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c){ return c.F_display(a,b);}
template <class H, class T>	 any_operable <H,T>display(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d){ return d.F_display(a,b,c);}
template <class H, class T>	 any_operable <H,T>display(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e){ return e.F_display(a,b,c,d);}
template <class H, class T>	 any_operable <H,T>display(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e,any_operable <H,T> & f){ return f.F_display(a,b,c,d,e);}
template <class H, class T>	 any_operable <H,T>change(any_operable <H,T> & a){ return a.F_change();}
template <class H, class T>	 any_operable <H,T>change(any_operable <H,T> & a,any_operable <H,T> & b){ return b.F_change(a);}
template <class H, class T>	 any_operable <H,T>change(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c){ return c.F_change(a,b);}
template <class H, class T>	 any_operable <H,T>change(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d){ return d.F_change(a,b,c);}
template <class H, class T>	 any_operable <H,T>change(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e){ return e.F_change(a,b,c,d);}
template <class H, class T>	 any_operable <H,T>change(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e,any_operable <H,T> & f){ return f.F_change(a,b,c,d,e);}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_size(any_operable <H,T> & a){ return a.F_CALL_MEMBER_size();}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_size(any_operable <H,T> & a,any_operable <H,T> & b){ return b.F_CALL_MEMBER_size(a);}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_size(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c){ return c.F_CALL_MEMBER_size(a,b);}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_size(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d){ return d.F_CALL_MEMBER_size(a,b,c);}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_size(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e){ return e.F_CALL_MEMBER_size(a,b,c,d);}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_size(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e,any_operable <H,T> & f){ return f.F_CALL_MEMBER_size(a,b,c,d,e);}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_pop_back(any_operable <H,T> & a){ return a.F_CALL_MEMBER_pop_back();}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_pop_back(any_operable <H,T> & a,any_operable <H,T> & b){ return b.F_CALL_MEMBER_pop_back(a);}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_pop_back(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c){ return c.F_CALL_MEMBER_pop_back(a,b);}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_pop_back(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d){ return d.F_CALL_MEMBER_pop_back(a,b,c);}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_pop_back(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e){ return e.F_CALL_MEMBER_pop_back(a,b,c,d);}
template <class H, class T>	 any_operable <H,T>CALL_MEMBER_pop_back(any_operable <H,T> & a,any_operable <H,T> & b,any_operable <H,T> & c,any_operable <H,T> & d,any_operable <H,T> & e,any_operable <H,T> & f){ return f.F_CALL_MEMBER_pop_back(a,b,c,d,e);}
};
