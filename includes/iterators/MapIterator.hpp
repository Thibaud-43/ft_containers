#ifndef MapIterator_HPP
# define MapIterator_HPP

#include <string>
#include <limits>
#include <iostream>
#include <memory>

namespace ft
{
template<typename T>
class MapIterator
{

public:
	typedef	T												value_type;
	typedef	value_type*										pointer;
	typedef	value_type&										reference;
	typedef value_type const * 								const_pointer;
	typedef value_type const & 								const_reference;
	typedef ptrdiff_t										difference_type;
	typedef std::forward_iterator_tag						iterator_category;

	MapIterator(void): m_ptr(nullptr)
	{
	}
	MapIterator(pointer ptr): m_ptr(ptr)
	{
	}
	MapIterator(MapIterator const & src): m_ptr(src.m_ptr)
	{
	}
	virtual ~MapIterator()
	{
	}

	MapIterator & operator= (MapIterator const & rhs) 
	{

	}
	MapIterator & operator++ (void) 
	{

	}
	MapIterator 	operator++ (int) 
	{

	}
	MapIterator & operator-- (void) 
	{

	}
	MapIterator	operator--(int) 
	{

	}
	reference	operator[](int index)
	{
	}
	pointer	operator->()
	{

	}
	reference	operator*()
	{

	}
	bool			operator== (const MapIterator ptr) const
	{

	}
	bool			operator!= (const MapIterator ptr) const
	{

	}
	MapIterator &operator+=(int n)
	{

	};
	MapIterator &operator-=(int n)
	{

	};
	MapIterator operator+(int n) const
	{

	};
	MapIterator operator-(int n) const
	{

	};
	std::ptrdiff_t	operator-(MapIterator & rhs) const
	{

	}
	const_reference operator[](int nb) const 
	{

	}
	const_reference operator*() const 
    {

	}
	const_pointer operator->() const 
    {

	}
	bool operator<(MapIterator const &other) const 
    {

	}
	bool operator<=(MapIterator const &other) const 
    {

	}
	bool operator>(MapIterator const &other) const 
    {

	}
	bool operator>=(MapIterator const &other) const 
    {

	}
	protected:
		pointer		m_ptr;
};
}

#endif