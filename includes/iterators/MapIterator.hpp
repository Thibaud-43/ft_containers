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
	typedef	value_type&										reference;
	typedef	value_type*										pointer;
	typedef value_type const * 								const_pointer;
	typedef value_type const & 								const_reference;
	typedef std::ptrdiff_t									difference_type;
	typedef std::forward_iterator_tag						iterator_category;

private:
	void	m_increment(void)
	{
		BNode<Key, T> *	tmp;
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
		BNode<Key, T> *	tmp;
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
	MapIterator(BNode<Key, T> * ptr): m_ptr(ptr)
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

	bool			operator== (const MapIterator ptr) const
	{
		return(m_ptr == ptr.m_ptr);
	}
	bool			operator!= (const MapIterator ptr) const
	{
		return (!(*this == ptr));
	}

	reference	operator*()
	{
		return (m_ptr->pair);
	}
	pointer	operator->()
	{
		return (&(m_ptr->pair));
	}
	const_reference	operator*() const
	{
		return (m_ptr->pair);
	}
	const_pointer	operator->() const
	{
		return (&(m_ptr->pair));
	}
	MapIterator & operator++ (void) 
	{
		m_increment();
		return(*this);
	}
	MapIterator 	operator++ (int) 
	{
		MapIterator	tmp(*this);
		this->operator++();
		return(tmp);
	}
	MapIterator & operator-- (void) 
	{
		m_decrement();
		return(*this);
	}
	MapIterator	operator--(int) 
	{
		MapIterator	tmp(*this);
		this->operator--();
		return(tmp);

	}


	protected:
		BNode<Key, T> *		m_ptr;
};
}

#endif