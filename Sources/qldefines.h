
/* 
Copyright (C) 2000 F.Ametrano, L.Ballabio, A.Benin, M.Marchioro
See the file LICENSE.TXT for information on usage and distribution
Contact ferdinando@ametrano.net if LICENSE.TXT was not distributed with this file
*/

#ifndef quantlib_defines_h
#define quantlib_defines_h

// global trace level (may be superseded locally by a greater value)

#define QL_TRACE_LEVEL 0

// Compiler-dependent switches

#if defined(_MSC_VER)					// Microsoft Visual C++
	// disable useless warnings
	#pragma warning(disable: 4786)  // identifier truncated in debug info
	// set switches
	#define QL_CMATH_IN_STD	0
	#define QL_CCHAR_IN_STD	0
	#define QL_SUPPORTS_NAMESPACES	1
	#define QL_TEMPLATE_SPECIALIZATION_WORKS	0
	#define QL_REQUIRES_DUMMY_RETURN	1
	#define GARBLED_MIN_AND_MAX		1

#elif defined(__BORLANDC__)				// Borland C++
	// set switches
	#define QL_CMATH_IN_STD	1
	#define QL_CCHAR_IN_STD	1
	#define QL_SUPPORTS_NAMESPACES	1
	#define QL_TEMPLATE_SPECIALIZATION_WORKS	1
	#define QL_REQUIRES_DUMMY_RETURN	0
	#define GARBLED_MIN_AND_MAX		0

#elif defined(__MWERKS__)					// Metrowerks CodeWarrior
	// set switches
	#define QL_CMATH_IN_STD	1
	#define QL_CCHAR_IN_STD	1
	#define QL_SUPPORTS_NAMESPACES	1
	#define QL_TEMPLATE_SPECIALIZATION_WORKS	1
	#define QL_REQUIRES_DUMMY_RETURN	0
	#define GARBLED_MIN_AND_MAX		0

#else										// Generic ANSI C++ compliant compiler
	// set switches
	#define QL_CMATH_IN_STD	1
	#define QL_CCHAR_IN_STD	1
	#define QL_SUPPORTS_NAMESPACES	1
	#define QL_TEMPLATE_SPECIALIZATION_WORKS	1
	#define QL_REQUIRES_DUMMY_RETURN	0
	#define GARBLED_MIN_AND_MAX		1

#endif


// Switch-dependent #definitions

// Are math functions defined in the std namespace?
#if QL_CMATH_IN_STD
	#define QL_SQRT	std::sqrt
	#define QL_FABS	std::fabs
	#define QL_EXP	std::exp
	#define QL_LOG	std::log
	#define QL_POW	std::pow
	#define QL_MODF	std::modf
#else
	#define QL_SQRT	sqrt
	#define QL_FABS	fabs
	#define QL_EXP	exp
	#define QL_LOG	log
	#define QL_POW	pow
	#define QL_MODF	modf
#endif

// Are string functions defined in the std namespace?
#if QL_CCHAR_IN_STD
	#define QL_STRLEN	std::strlen
	#define QL_TOLOWER	std::tolower
	#define QL_TOUPPER	std::toupper
#else
	#define QL_STRLEN	strlen
	#define QL_TOLOWER	tolower
	#define QL_TOUPPER	toupper
#endif

// Are namespaces supported?
#if QL_SUPPORTS_NAMESPACES
	#define QL_BEGIN_NAMESPACE(nspace)		namespace nspace {
	#define QL_END_NAMESPACE(nspace)		}
	#define QL_USING_NAMESPACE(nspace)		using namespace nspace;
	#define QL_USING(nspace,type)			using nspace::type;
	#define QL_ADD_NAMESPACE(nspace,type)	nspace::type
#else
	#define QL_BEGIN_NAMESPACE(nspace)
	#define QL_END_NAMESPACE(nspace)
	#define QL_USING_NAMESPACE(nspace)
	#define QL_USING(type,nspace)
	#define QL_ADD_NAMESPACE(nspace,type)
#endif

// Does template specialization work as required?
#if QL_TEMPLATE_SPECIALIZATION_WORKS
	#define QL_DECLARE_TEMPLATE_SPECIALIZATION(declaration) template<> declaration;
	#define QL_DEFINE_TEMPLATE_SPECIALIZATION				template<>
#else
	#define QL_DECLARE_TEMPLATE_SPECIALIZATION(declaration)
	#define QL_DEFINE_TEMPLATE_SPECIALIZATION
#endif

// Is a return statement required at the end of a function even though it can never be reached?
#if QL_REQUIRES_DUMMY_RETURN
	#define QL_DUMMY_RETURN(x)		return x;
#else
	#define QL_DUMMY_RETURN(x) 
#endif

// Do std::min and std::max have the names you would expect? Blame Microsoft for this one
#if GARBLED_MIN_AND_MAX
	#define QL_MIN	std::_cpp_min
	#define QL_MAX	std::_cpp_max
#else
	#define QL_MIN	std::min
	#define QL_MAX	std::max
#endif


#endif
