#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include <string>
#include "vector.hpp"
#include <iostream>
#include <memory>

class vectorIterator;

namespace ft
{
template<typename Iterator>
class ReverseIterator : public Iterator
{

public:
	typedef	typename Iterator::value_type				value_type;
	typedef	typename Iterator::pointer_type				pointer_type;
	typedef	typename Iterator::reference_type			reference_type;
	typedef typename Iterator::const_pointer 			const_pointer;
	typedef typename Iterator::const_reference			const_reference;

	ReverseIterator(void): Iterator()
	{
	}
	ReverseIterator(ReverseIterator const & src):Iterator(src.m_ptr)
	{
	}
    ReverseIterator(Iterator const & iterator):Iterator(iterator)
    {

    }
	~ReverseIterator()
	{
	}
	reference_type	operator*()
	{
        Iterator    tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const 
    {
        Iterator    tmp(*this);
		return (*--tmp);
	}
	pointer_type	operator->()
	{
        Iterator    tmp(*this);
		return (&*--tmp);
	}

	const_pointer operator->() const 
    {
        Iterator    tmp(*this);
		return (&*--tmp);
	}

	Iterator & operator++ (void) 
	{
		return (this->Iterator::operator--());
	}
	ReverseIterator 	operator++ (int) 
	{
        Iterator    tmp(*this);
        operator++();
		return (tmp);
	}

	Iterator & operator-- (void) 
	{
		return (this->Iterator::operator++());
	}
	ReverseIterator	operator--(int) 
	{
        Iterator    tmp(*this);
        operator--();
		return (tmp);
	}
};
};
#endif