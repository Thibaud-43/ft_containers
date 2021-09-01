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

template <typename T, typename node_type>
class MapIterator
{
protected:
	node_type		m_ptr;
	MapIterator(node_type ptr): m_ptr(ptr) { };
public:
	typedef T												value_type;
	typedef std::ptrdiff_t									difference_type;
	typedef	value_type&										reference;
	typedef	value_type*										pointer;
	typedef std::forward_iterator_tag						iterator_category;



	MapIterator(void): m_ptr(NULL){}
	MapIterator(MapIterator const & src) {*this = src;}
	virtual ~MapIterator(){}
	MapIterator & operator= (MapIterator const & rhs) {m_ptr = rhs.m_ptr;return (*this);}
	
	node_type	node()				{		return m_ptr;				}
	template <class U> 
	bool	operator==(const MapIterator<U, node_type> &rhs)  const {return(m_ptr == rhs.m_ptr);}
	template <class U>
	 bool	operator!=(const MapIterator<U, node_type> &rhs)  const {return(m_ptr != rhs.m_ptr); }

	MapIterator & 	operator++ (void) 	{		m_increment();		return(*this);	}
	MapIterator 	operator++ (int) 	{		MapIterator	tmp(*this);		this->operator++();		return(tmp);	}
	MapIterator & 	operator-- (void) 	{		m_decrement();		return(*this);	}
	MapIterator		operator--(int) 	{		MapIterator	tmp(*this);		this->operator--();		return(tmp);	}


	reference		operator*(void)	const		{		return (this->m_ptr->pair);		}
	pointer			operator->(void) const		{		return (&(this->operator*()));	}

	operator MapIterator<const T, node_type>(void) const {
			return MapIterator<const T, node_type>(this->m_ptr);
		}

	template <class, class, class, class>
	friend class map;
	template <class, class>
		friend class MapIterator;

private:
	void	m_increment(void)
	{
		node_type	tmp;
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
		node_type	tmp;
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
};
}

#endif