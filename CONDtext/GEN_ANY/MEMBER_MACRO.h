
#pragma once
#include <iostream>
#include <array>
#include "boost\utility\enable_if.hpp"
#include "boost\any.hpp"
#include "TYPELIST.h"
#define PARAM_CALL_1(nom)				\
template<class C_NAME_a> typename decltype( (*(C_NAME_a*)0). nom ()) CALL_MEMBER_ ## nom (C_NAME_a & a){											\
	return a. nom ();		\
	};															\
template<class C_NAME_a> typename decltype( (*(C_NAME_a*)0). nom ()) CALL_MEMBER_ ## nom (C_NAME_a && a){											\
	return a. nom ();		\
	};															\

#define INNER_PARAM_CALL_1_1(nom)				\
 typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0))  nom (){											\
	return  CALL_MEMBER_ ## nom  (*this);		\
	};															\

#define INNER_PARAM_CALL_0_1(nom)				\
 typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0))  nom (){											\
	return  CALL_MEMBER_ ## nom  (*this);		\
	};															\

#define PARAM_CALL_2(nom)				\
template<class C_NAME_a,class C_NAME_b> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b){											\
	return a. nom (b);		\
	};															\
template<class C_NAME_a,class C_NAME_b> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b){											\
	return a. nom (b);		\
	};															\
template<class C_NAME_a,class C_NAME_b> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b){											\
	return a. nom (b);		\
	};															\
template<class C_NAME_a,class C_NAME_b> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b){											\
	return a. nom (b);		\
	};															\

#define INNER_PARAM_CALL_1_2(nom)				\
template<class C_NAME_a> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0))  nom (C_NAME_a & a){											\
	return  CALL_MEMBER_ ## nom  (*this,a);		\
	};															\
template<class C_NAME_a> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0))  nom (C_NAME_a && a){											\
	return  CALL_MEMBER_ ## nom  (*this,a);		\
	};															\

#define INNER_PARAM_CALL_0_2(nom)				\
template<class C_NAME_a> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0))  nom (C_NAME_a & a){											\
	return  CALL_MEMBER_ ## nom  (*this,a);		\
	};															\
template<class C_NAME_a> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0))  nom (C_NAME_a && a){											\
	return  CALL_MEMBER_ ## nom  (*this,a);		\
	};															\

#define PARAM_CALL_3(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c){											\
	return a. nom (b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c){											\
	return a. nom (b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c){											\
	return a. nom (b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c){											\
	return a. nom (b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c){											\
	return a. nom (b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c){											\
	return a. nom (b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c){											\
	return a. nom (b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c){											\
	return a. nom (b,c);		\
	};															\

#define INNER_PARAM_CALL_1_3(nom)				\
template<class C_NAME_a,class C_NAME_b> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0))  nom (C_NAME_a & a,C_NAME_b & b){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b);		\
	};															\
template<class C_NAME_a,class C_NAME_b> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0))  nom (C_NAME_a && a,C_NAME_b & b){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b);		\
	};															\
template<class C_NAME_a,class C_NAME_b> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0))  nom (C_NAME_a & a,C_NAME_b && b){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b);		\
	};															\
template<class C_NAME_a,class C_NAME_b> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0))  nom (C_NAME_a && a,C_NAME_b && b){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b);		\
	};															\

#define INNER_PARAM_CALL_0_3(nom)				\
template<class C_NAME_a,class C_NAME_b> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0))  nom (C_NAME_a & a,C_NAME_b & b){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b);		\
	};															\
template<class C_NAME_a,class C_NAME_b> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0))  nom (C_NAME_a && a,C_NAME_b & b){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b);		\
	};															\
template<class C_NAME_a,class C_NAME_b> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0))  nom (C_NAME_a & a,C_NAME_b && b){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b);		\
	};															\
template<class C_NAME_a,class C_NAME_b> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0))  nom (C_NAME_a && a,C_NAME_b && b){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b);		\
	};															\

#define PARAM_CALL_4(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d){											\
	return a. nom (b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d){											\
	return a. nom (b,c,d);		\
	};															\

#define INNER_PARAM_CALL_1_4(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\

#define INNER_PARAM_CALL_0_4(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c);		\
	};															\

#define PARAM_CALL_5(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return a. nom (b,c,d,e);		\
	};															\

#define INNER_PARAM_CALL_1_5(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\

#define INNER_PARAM_CALL_0_5(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d);		\
	};															\

#define PARAM_CALL_6(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return a. nom (b,c,d,e,f);		\
	};															\

#define INNER_PARAM_CALL_1_6(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\

#define INNER_PARAM_CALL_0_6(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e);		\
	};															\

#define PARAM_CALL_7(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g & g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f,class C_NAME_g> typename decltype( (*(C_NAME_a*)0). nom (*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0,*(C_NAME_g*)0)) CALL_MEMBER_ ## nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f,C_NAME_g && g){											\
	return a. nom (b,c,d,e,f,g);		\
	};															\

#define INNER_PARAM_CALL_1_7(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable< typelist<H, null_typelist>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\

#define INNER_PARAM_CALL_0_7(nom)				\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f & f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e & e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d & d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c & c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b & b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a & a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\
template<class C_NAME_a,class C_NAME_b,class C_NAME_c,class C_NAME_d,class C_NAME_e,class C_NAME_f> typename decltype( CALL_MEMBER_ ## nom (*(any_operable < typelist<H, T>, typelist<A, B>  >*)0,*(C_NAME_a*)0,*(C_NAME_b*)0,*(C_NAME_c*)0,*(C_NAME_d*)0,*(C_NAME_e*)0,*(C_NAME_f*)0))  nom (C_NAME_a && a,C_NAME_b && b,C_NAME_c && c,C_NAME_d && d,C_NAME_e && e,C_NAME_f && f){											\
	return  CALL_MEMBER_ ## nom  (*this,a,b,c,d,e,f);		\
	};															\

