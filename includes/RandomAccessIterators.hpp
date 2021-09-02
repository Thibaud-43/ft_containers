#ifndef RandomAccessIterators_H
 #define RandomAccessIterators_H

#include <cstddef>
#include <iostream>

namespace ft
{
	// RANDOM_ACCESS_ITERATORS

	template<typename T>
	class RandomAccessIterator
	{
		public:
			typedef	T*						pointer_type;
			typedef	ptrdiff_t				difference_type;
		protected:
			pointer_type		m_ptr;
		public:

			// CANONICAL FORM

			RandomAccessIterator(void) :m_ptr(NULL) {};
			RandomAccessIterator(pointer_type x) :m_ptr(x) {};
			RandomAccessIterator(const RandomAccessIterator & src) {*this = src;};

			virtual ~RandomAccessIterator(void) {};
			RandomAccessIterator	&	operator=(RandomAccessIterator const & rhs) { m_ptr = rhs.m_ptr; return *this;};

			// COMPARAISON

			bool	operator==(const RandomAccessIterator &rhs) const	{return m_ptr == rhs.m_ptr;};
			bool	operator!=(const RandomAccessIterator &rhs) const	{return m_ptr != rhs.m_ptr;};
			bool	operator<(const RandomAccessIterator &rhs) const	{return m_ptr < rhs.m_ptr;};
			bool	operator<=(const RandomAccessIterator &rhs) const	{return m_ptr <= rhs.m_ptr;};
			bool	operator>(const RandomAccessIterator &rhs) const	{return m_ptr > rhs.m_ptr;};
			bool	operator>=(const RandomAccessIterator &rhs) const	{return m_ptr >= rhs.m_ptr;};

			// INCREMENT - DECREMENT

			RandomAccessIterator<T> &	operator++(void){m_ptr++; return *this;};
			RandomAccessIterator<T> &	operator--(void){m_ptr--; return *this;};
			RandomAccessIterator<T> 	operator++(int){ RandomAccessIterator	tmp(*this); m_ptr++; return tmp;};
			RandomAccessIterator<T> 	operator--(int){RandomAccessIterator	tmp(*this); m_ptr--; return tmp;};


			// ADDITION / SUBSTRATION 

			difference_type						operator-(const RandomAccessIterator &rhs) const {return m_ptr - rhs.m_ptr;};
			RandomAccessIterator<T>				operator+(difference_type n) const {return m_ptr + n;};
			RandomAccessIterator<T>				operator-(difference_type n) const {return m_ptr - n;};
			RandomAccessIterator<T> &			operator+=(difference_type n){m_ptr += n; return *this;};
			RandomAccessIterator<T> &			operator-=(difference_type n){m_ptr -= n; return *this;};
			friend RandomAccessIterator<T>		operator+(difference_type n, const RandomAccessIterator &rhs) { return rhs.m_ptr + n;};

		};
}

#endif