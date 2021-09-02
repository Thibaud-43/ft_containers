#ifndef VectorIterators_H
 #define VectorIterators_H

#include <cstddef>
#include "vector.hpp"
#include <iostream>
#include "RandomAccessIterators.hpp"

namespace ft
{
	// NORMAL
	
	template<typename T>
	class VectorIterator: public ft::RandomAccessIterator<T>
	{
		public:
			typedef	T									value_type;
			typedef	RandomAccessIterator<T>				random;
			typedef	T*									pointer_type;
			typedef	ptrdiff_t							difference_type;
			typedef value_type&							reference;
			typedef value_type*							pointer;
			typedef std::random_access_iterator_tag		iterator_category;
	
		//protected:
			VectorIterator(pointer_type x) : random(x) {};
		private:
			VectorIterator(const random & src) : random(src) {};
		public:
			VectorIterator(void) :random(NULL) {};
			VectorIterator(const VectorIterator & src) : random(src) {};
			virtual ~VectorIterator(void) {};

		public:
			// INCREMENT - DECREMENT

			VectorIterator &				operator++(void){random::operator++() ; return *this;};
			VectorIterator &				operator--(void){random::operator--() ; return *this;};
			VectorIterator 					operator++(int){return random::operator++(0);};
			VectorIterator 					operator--(int){return random::operator--(0);};

			// ADDITION / SUBSTRATION 

			difference_type					operator-(const random &rhs) const {return random::operator-(rhs);};
			VectorIterator<T>				operator+(difference_type n) const {return random::operator+(n); };
			VectorIterator<T>				operator-(difference_type n) const {return random::operator-(n); };
			friend VectorIterator<T>		operator+(difference_type n, const VectorIterator &rhs) {return rhs.operator+(n);};
			VectorIterator<T>	&			operator+=(difference_type n) {random::operator+=(n) ; return *this;};
			VectorIterator<T>	&			operator-=(difference_type n) {random::operator-=(n) ; return *this;};

			// ASSIGNATION

			reference						operator*(void) const {return *(this->m_ptr);};
			pointer							operator->(void) const {return this->m_ptr;};
			reference						operator[](difference_type n) const {return (*(this->m_ptr + n));};

		};
	
	// CONST

	template<typename T>
	class ConstVectorIterator: public ft::RandomAccessIterator<T>
	{
		public:
			typedef	T								value_type;
			typedef	RandomAccessIterator<T>			random;
			typedef	T*								pointer_type;
			typedef	ptrdiff_t						difference_type;
			typedef const value_type&				reference;
			typedef const value_type*				pointer;

		public:

			// CANONICAL FORM

			ConstVectorIterator(void) :random(NULL) {};
			ConstVectorIterator(pointer_type x) : random(x) {};
			ConstVectorIterator(const ConstVectorIterator & src) : random(src) {};
			ConstVectorIterator(const random & src) : random(src) {};
			virtual ~ConstVectorIterator(void) {};

			// INCREMENT - DECREMENT

			ConstVectorIterator &				operator++(void){random::operator++() ; return *this;};
			ConstVectorIterator &				operator--(void){random::operator--() ; return *this;};
			ConstVectorIterator 				operator++(int){return random::operator++(0);};
			ConstVectorIterator 				operator--(int){return random::operator--(0);};

			// ADDITION / SUBSTRATION 

			difference_type						operator-(const random &rhs) const {return random::operator-(rhs);};
			ConstVectorIterator<T>				operator+(difference_type n) const {return random::operator+(n); };
			ConstVectorIterator<T>				operator-(difference_type n) const {return random::operator-(n); };
			friend ConstVectorIterator<T>		operator+(difference_type n, const ConstVectorIterator &rhs) {return rhs.operator+(n);};
			ConstVectorIterator<T>	&			operator+=(difference_type n) {random::operator+=(n) ; return *this;};
			ConstVectorIterator<T>	&			operator-=(difference_type n) {random::operator-=(n) ; return *this;};

			// ASSIGNATION

			reference						operator*(void) const {return *(this->m_ptr);};
			pointer							operator->(void) const {return this->m_ptr;};
			reference						operator[](difference_type n) const {return *(this->m_ptr + n);};

		};
}

#endif