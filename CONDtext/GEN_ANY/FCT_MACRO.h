
#pragma once
#include <iostream>
#include <array>
#include "boost\utility\enable_if.hpp"
#include "boost\any.hpp"
#include "TYPELIST.h"


#define IS_FCT0(nom,name)																															\
namespace ANY_FCT {																														\
	template<class T>																																\
	struct is_ ## nom ## _0																															\
	{																																				\
		template<class CNAME2_a> static auto less_than_test(CNAME2_a* a) -> decltype( name :: nom (), char(0)) { }							\
		static std::array<char, 2> less_than_test(...) { }																							\
		static constexpr bool value = (sizeof(less_than_test((T*)0)) == 1);																			\
	};																																				\
	template <class T> inline typename boost::enable_if< is_ ## nom ## _0<T>, typename decltype( name :: nom ()) >::type nom ## _o (T const & a) {	\
		return name :: nom ();																														\
	}																																				\
	template <class T> inline typename boost::disable_if< is_ ## nom ## _0<T>, int >::type nom ## _o (T const & a) {								\
		throw("Unknown function for without type  ");																													\
		return 10;																																	\
	}																																				\
		inline auto nom() {																																\
			return nom ## _o((int)0);																												\
		}																																			\
		inline auto G_ ## nom() {																															\
			return nom ## _o((int)0);																												\
		}																																			\
	}

#define IS_FCT1( nom , name )																														\
namespace ANY_FCT {																																				\
template<class CNAME_a>																																				\
struct is_ ## nom ## _1																																				\
{																																											\
template<class CNAME2_a> static auto less_than_test(CNAME2_a a ) -> decltype(name::nom(*a ), char(0)) { }														\
static std::array<char, 2> less_than_test(...) { }																															\
static constexpr bool value = (sizeof(less_than_test((CNAME_a)0)) == 1);																									\
};																																											\
																																											\
template<class CNAME_a> inline typename  boost::enable_if< is_ ## nom ## _1<CNAME_a*>, typename decltype( name::nom (*(CNAME_a*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a );																																	\
}				\
template<class CNAME_a> inline typename  boost::enable_if< is_ ## nom ## _1<CNAME_a*>, typename decltype( name::nom (*(CNAME_a*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a );																																	\
}				\
template<class CNAME_a> inline typename  boost::enable_if< is_ ## nom ## _1<CNAME_a*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a> inline typename  boost::enable_if< is_ ## nom ## _1<CNAME_a*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a );																																 \
				return 0;																																				 \
}																																											\
																																											\
template<class CNAME_a> inline typename boost::disable_if< is_ ## nom ## _1<CNAME_a*>, int >::type									\
G_ ## nom ## (CNAME_a  a ) {																																				\
																																											\
			throw("Unknown function for asked type ");																														\
			return 0;																																						\
	}																																										\
}

#define IS_FCT2( nom , name )																														\
namespace ANY_FCT {																																				\
template<class CNAME_a,class CNAME_b>																																				\
struct is_ ## nom ## _2																																				\
{																																											\
template<class CNAME2_a,class CNAME2_b> static auto less_than_test(CNAME2_a a ,CNAME2_b b ) -> decltype(name::nom(*a ,*b ), char(0)) { }														\
static std::array<char, 2> less_than_test(...) { }																															\
static constexpr bool value = (sizeof(less_than_test((CNAME_a)0,(CNAME_b)0)) == 1);																									\
};																																											\
																																											\
template<class CNAME_a,class CNAME_b> inline typename  boost::enable_if< is_ ## nom ## _2<CNAME_a*,CNAME_b*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b );																																	\
}				\
template<class CNAME_a,class CNAME_b> inline typename  boost::enable_if< is_ ## nom ## _2<CNAME_a*,CNAME_b*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b );																																	\
}				\
template<class CNAME_a,class CNAME_b> inline typename  boost::enable_if< is_ ## nom ## _2<CNAME_a*,CNAME_b*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b );																																	\
}				\
template<class CNAME_a,class CNAME_b> inline typename  boost::enable_if< is_ ## nom ## _2<CNAME_a*,CNAME_b*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b );																																	\
}				\
template<class CNAME_a,class CNAME_b> inline typename  boost::enable_if< is_ ## nom ## _2<CNAME_a*,CNAME_b*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b> inline typename  boost::enable_if< is_ ## nom ## _2<CNAME_a*,CNAME_b*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b> inline typename  boost::enable_if< is_ ## nom ## _2<CNAME_a*,CNAME_b*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b> inline typename  boost::enable_if< is_ ## nom ## _2<CNAME_a*,CNAME_b*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b );																																 \
				return 0;																																				 \
}																																											\
																																											\
template<class CNAME_a,class CNAME_b> inline typename boost::disable_if< is_ ## nom ## _2<CNAME_a*,CNAME_b*>, int >::type									\
G_ ## nom ## (CNAME_a  a ,CNAME_b  b ) {																																				\
																																											\
			throw("Unknown function for asked type ");																														\
			return 0;																																						\
	}																																										\
}

#define IS_FCT3( nom , name )																														\
namespace ANY_FCT {																																				\
template<class CNAME_a,class CNAME_b,class CNAME_c>																																				\
struct is_ ## nom ## _3																																				\
{																																											\
template<class CNAME2_a,class CNAME2_b,class CNAME2_c> static auto less_than_test(CNAME2_a a ,CNAME2_b b ,CNAME2_c c ) -> decltype(name::nom(*a ,*b ,*c ), char(0)) { }														\
static std::array<char, 2> less_than_test(...) { }																															\
static constexpr bool value = (sizeof(less_than_test((CNAME_a)0,(CNAME_b)0,(CNAME_c)0)) == 1);																									\
};																																											\
																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename  boost::enable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c );																																 \
				return 0;																																				 \
}																																											\
																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c> inline typename boost::disable_if< is_ ## nom ## _3<CNAME_a*,CNAME_b*,CNAME_c*>, int >::type									\
G_ ## nom ## (CNAME_a  a ,CNAME_b  b ,CNAME_c  c ) {																																				\
																																											\
			throw("Unknown function for asked type ");																														\
			return 0;																																						\
	}																																										\
}

#define IS_FCT4( nom , name )																														\
namespace ANY_FCT {																																				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d>																																				\
struct is_ ## nom ## _4																																				\
{																																											\
template<class CNAME2_a,class CNAME2_b,class CNAME2_c,class CNAME2_d> static auto less_than_test(CNAME2_a a ,CNAME2_b b ,CNAME2_c c ,CNAME2_d d ) -> decltype(name::nom(*a ,*b ,*c ,*d ), char(0)) { }														\
static std::array<char, 2> less_than_test(...) { }																															\
static constexpr bool value = (sizeof(less_than_test((CNAME_a)0,(CNAME_b)0,(CNAME_c)0,(CNAME_d)0)) == 1);																									\
};																																											\
																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename  boost::enable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d );																																 \
				return 0;																																				 \
}																																											\
																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d> inline typename boost::disable_if< is_ ## nom ## _4<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*>, int >::type									\
G_ ## nom ## (CNAME_a  a ,CNAME_b  b ,CNAME_c  c ,CNAME_d  d ) {																																				\
																																											\
			throw("Unknown function for asked type ");																														\
			return 0;																																						\
	}																																										\
}

#define IS_FCT5( nom , name )																														\
namespace ANY_FCT {																																				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e>																																				\
struct is_ ## nom ## _5																																				\
{																																											\
template<class CNAME2_a,class CNAME2_b,class CNAME2_c,class CNAME2_d,class CNAME2_e> static auto less_than_test(CNAME2_a a ,CNAME2_b b ,CNAME2_c c ,CNAME2_d d ,CNAME2_e e ) -> decltype(name::nom(*a ,*b ,*c ,*d ,*e ), char(0)) { }														\
static std::array<char, 2> less_than_test(...) { }																															\
static constexpr bool value = (sizeof(less_than_test((CNAME_a)0,(CNAME_b)0,(CNAME_c)0,(CNAME_d)0,(CNAME_e)0)) == 1);																									\
};																																											\
																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename  boost::enable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e );																																 \
				return 0;																																				 \
}																																											\
																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e> inline typename boost::disable_if< is_ ## nom ## _5<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*>, int >::type									\
G_ ## nom ## (CNAME_a  a ,CNAME_b  b ,CNAME_c  c ,CNAME_d  d ,CNAME_e  e ) {																																				\
																																											\
			throw("Unknown function for asked type ");																														\
			return 0;																																						\
	}																																										\
}

#define IS_FCT6( nom , name )																														\
namespace ANY_FCT {																																				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f>																																				\
struct is_ ## nom ## _6																																				\
{																																											\
template<class CNAME2_a,class CNAME2_b,class CNAME2_c,class CNAME2_d,class CNAME2_e,class CNAME2_f> static auto less_than_test(CNAME2_a a ,CNAME2_b b ,CNAME2_c c ,CNAME2_d d ,CNAME2_e e ,CNAME2_f f ) -> decltype(name::nom(*a ,*b ,*c ,*d ,*e ,*f ), char(0)) { }														\
static std::array<char, 2> less_than_test(...) { }																															\
static constexpr bool value = (sizeof(less_than_test((CNAME_a)0,(CNAME_b)0,(CNAME_c)0,(CNAME_d)0,(CNAME_e)0,(CNAME_f)0)) == 1);																									\
};																																											\
																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)) >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<!std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
		return name::nom(a ,b ,c ,d ,e ,f );																																	\
}				\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  & f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  & e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  & d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  & c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  & b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  & a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename  boost::enable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type	\
G_ ## nom ## (CNAME_a  && a ,CNAME_b  && b ,CNAME_c  && c ,CNAME_d  && d ,CNAME_e  && e ,CNAME_f  && f ,typename std::enable_if<std::is_same<typename decltype( name::nom (*(CNAME_a*)0,*(CNAME_b*)0,*(CNAME_c*)0,*(CNAME_d*)0,*(CNAME_e*)0,*(CNAME_f*)0)), void>::value, empty_usable >::type = 0 ) {																																				\
				name::nom(a ,b ,c ,d ,e ,f );																																 \
				return 0;																																				 \
}																																											\
																																											\
template<class CNAME_a,class CNAME_b,class CNAME_c,class CNAME_d,class CNAME_e,class CNAME_f> inline typename boost::disable_if< is_ ## nom ## _6<CNAME_a*,CNAME_b*,CNAME_c*,CNAME_d*,CNAME_e*,CNAME_f*>, int >::type									\
G_ ## nom ## (CNAME_a  a ,CNAME_b  b ,CNAME_c  c ,CNAME_d  d ,CNAME_e  e ,CNAME_f  f ) {																																				\
																																											\
			throw("Unknown function for asked type ");																														\
			return 0;																																						\
	}																																										\
}
