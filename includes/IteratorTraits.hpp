#ifndef ITERATORTRAITS_HPP
# define ITERATORTRAITS_HPP

#include <string>
#include <limits>
#include <iostream>
#include <memory>

namespace ft
{	
	template< bool condition, class T = void>
	struct enable_if
	{

	}; 

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template< typename Iterator >
	class iterator_traits
	{
		public:
		typedef typename Iterator::value_type 			value_type;
		typedef typename Iterator::difference_type 		difference_type;
		typedef typename Iterator::pointer 				pointer;
		typedef typename Iterator::reference 			reference;
		typedef typename Iterator::iterator_category 	iterator_category;
	};

	template<typename T>
	class iterator_traits <T *>
	{
		public:
			typedef	T												value_type;
			typedef	value_type*										pointer;
			typedef	value_type&										reference;
			typedef value_type const * 								const_pointer;
			typedef value_type const & 								const_reference;
			typedef std::ptrdiff_t									difference_type;
			typedef std::forward_iterator_tag						iterator_category;
	};
	template<> class iterator_traits<bool>{};
	template<> class iterator_traits<char>{};
	//template<> class iterator_traits<std::char16_t>{};
	//template<> class iterator_traits<std::char32_t>{};
	template<> class iterator_traits<wchar_t>{};
	template<> class iterator_traits<signed char>{};
	template<> class iterator_traits<short int>{};
	template<> class iterator_traits<int>{};
	template<> class iterator_traits<long>{};
	template<> class iterator_traits<long long>{};
	template<> class iterator_traits<unsigned char>{};
	template<> class iterator_traits<unsigned short int>{};
	template<> class iterator_traits<unsigned int>{};
	template<> class iterator_traits<unsigned long>{};
	template<> class iterator_traits<unsigned long long>{};

	template< typename IsIterator>
	struct is_iterator
	{
		typedef char yes[1];
		typedef char no[2]; 

		template <typename IsIterator_>
		static yes& test(typename iterator_traits<IsIterator_>::iterator_category* = NULL);

		template <typename C>
		static no& test(...);
		static const bool value = sizeof(test<IsIterator>(NULL)) == sizeof(yes);
	};
}
#endif