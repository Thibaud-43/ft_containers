#ifndef MapIterator_HPP
# define MapIterator_HPP

#include <map.hpp>
#include <string>
#include <limits>
#include <pair.hpp>
#include <iostream>
#include <memory>


namespace ft
{
template <class  Key, class T>
struct BNode;

template <class Key, class T>
class MapIterator
{

public:
	typedef pair<Key, T> 									value_type;
	typedef BNode<Key, T> *									pointer;
	typedef	value_type&										reference;
	typedef value_type const * 								const_pointer;
	typedef value_type const & 								const_reference;
	typedef std::ptrdiff_t									difference_type;
	typedef std::forward_iterator_tag						iterator_category;

private:
	void	m_increment(void)
	{
		pointer	tmp;
		if (m_ptr->right)
		{
			tmp = m_ptr->right;
			while (tmp->left)
				tmp = tmp->left;
		}
		else
		{
			tmp = m_ptr;
			while (tmp->parent && !tmp->parent->root && tmp == tmp->parent->right)
				tmp = tmp->parent;
			tmp = tmp->parent;
		}
		m_ptr = tmp;
	}
	void	m_decrement(void)
	{
		pointer	tmp;
		if (m_ptr->left)
		{
			tmp = m_ptr->left;
			while (tmp->right)
				tmp = tmp->right;
		}
		else
		{
			tmp = m_ptr;
			while (tmp->parent && !tmp->parent->root && tmp == tmp->parent->left)
				tmp = tmp->parent;
			tmp = tmp->parent;
		}
		m_ptr = tmp;
	}
public:

	MapIterator(void): m_ptr(NULL)
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
		m_ptr = rhs.m_ptr;
		return (*this);
	}
	MapIterator & operator++ (void) 
	{
		MapIterator	tmp(this);
		operator++();
		return(tmp);
	}
	MapIterator 	operator++ (int) 
	{
		m_increment();
		return(*this);
	}
	MapIterator & operator-- (void) 
	{
		MapIterator	tmp(this);
		operator--();
		return(tmp);
	}
	MapIterator	operator--(int) 
	{
		m_decrement();
		return(*this);
	}
	/*reference	operator[](int index)
	{
	}
	pointer	operator->()
	{

	}
	reference	operator*()
	{

	}*/
	bool			operator== (const MapIterator ptr) const
	{
		return(m_ptr == ptr.m_ptr);
	}
	bool			operator!= (const MapIterator ptr) const
	{
		return (!(*this == ptr));
	}
	/*MapIterator &operator+=(int n)
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

	}*/
	value_type *operator->() const 
    {
		return(&(m_ptr->pair));
	}
	/*bool operator<(MapIterator const &other) const 
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

	}*/
	protected:
		pointer		m_ptr;
};
}

#endif