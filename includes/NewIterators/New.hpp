#ifndef RandomAccessIterator_H
 #define RandomAccessIterator_H

#include <cstddef>
#include <iostream>
namespace ft {





	// VECTOR ITERATORS

	template<typename T>
	class ConstVectorIterator : public RandomAccessIterator<T>
	{
		typedef const value_type&			reference;
		typedef const value_type*			pointer;
		int* p;
	public:
		ConstVectorIterator(int* x) :p(x) {}
		ConstVectorIterator(const ConstVectorIterator& mit) : p(mit.p) {}
	};
	
	template<typename T>
	class VectorIterator : public RandomAccessIterator<T>
	{
		typedef value_type&			reference;
		typedef value_type*			pointer;
		int* p;
	public:
		VectorIterator(int* x) :p(x) {}
		VectorIterator(const VectorIterator& mit) : p(mit.p) {}
	};
	

}
#endif