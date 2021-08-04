#ifndef VectorIterator_HPP
# define VectorIterator_HPP

#include <string>
#include <limits>
#include <iostream>
#include <memory>

namespace ft
{
template<typename T>
class VectorIterator
{

public:
	typedef	T												value_type;
	typedef	value_type*										pointer;
	typedef	value_type&										reference;
	typedef value_type const * 								const_pointer;
	typedef value_type const & 								const_reference;
	typedef ptrdiff_t										difference_type;
	typedef std::forward_iterator_tag						iterator_category;

	VectorIterator(void): m_ptr(nullptr)
	{
	}
	VectorIterator(pointer ptr): m_ptr(ptr)
	{
	}
	VectorIterator(VectorIterator const & src): m_ptr(src.m_ptr)
	{
	}
	virtual ~VectorIterator()
	{
	}

	VectorIterator & operator= (VectorIterator const & rhs) 
	{
		m_ptr = rhs.m_ptr;
		return *this;
	}
	VectorIterator & operator++ (void) 
	{
		++this->m_ptr;
		return *this;
	}
	VectorIterator 	operator++ (int) 
	{
		VectorIterator	tmp(*this);
		++this->m_ptr;
		return tmp;
	}
	VectorIterator & operator-- (void) 
	{
		m_ptr--;
		return *this;
	}
	VectorIterator	operator--(int) 
	{

		VectorIterator	tmp(*this);
		m_ptr--;
		return tmp;
	}
	reference	operator[](int index)
	{
		return *(m_ptr + index);
	}
	pointer	operator->()
	{
		return m_ptr;
	}
	reference	operator*()
	{
		return (*this->m_ptr);
	}
	bool			operator== (const VectorIterator ptr) const
	{
		if (m_ptr == ptr.m_ptr)
			return true;
		return false;
	}
	bool			operator!= (const VectorIterator ptr) const
	{
		if (m_ptr == ptr.m_ptr)
			return false;
		return true;
	}
	VectorIterator &operator+=(int n)
	{
		while (n < 0)
		{
			(*this)--;
			n++;
		}
		while (n > 0)
		{
			(*this)++;
			n--;
		}
		return (*this);
	};
	VectorIterator &operator-=(int n)
	{

		while (n > 0)
		{
			operator--();	
			n--;
		}
		while (n < 0)
		{
			operator++();
			n++;
		}
		return (*this);
	};
	VectorIterator operator+(int n) const
	{
		VectorIterator tmp(*this);
		tmp += n;
		return (tmp);
	};
	VectorIterator operator-(int n) const
	{
		VectorIterator tmp(*this);

		tmp -= n;
		return (tmp);
	};
	std::ptrdiff_t	operator-(VectorIterator & rhs) const
	{
		return m_ptr - rhs.m_ptr;
	}
	const_reference operator[](int nb) const 
	{
		return (*(this->m_ptr + nb));
	}
	const_reference operator*() const 
	{
		return (*this->m_ptr);
	}
	const_pointer operator->() const 
	{
		return (this->m_ptr);
	}
	bool operator<(VectorIterator const &other) const 
	{
		return (this->m_ptr < other.m_ptr);
	}
	bool operator<=(VectorIterator const &other) const 
	{
		return (this->m_ptr <= other.m_ptr);
	}
	bool operator>(VectorIterator const &other) const 
	{
		return (this->m_ptr > other.m_ptr);
	}
	bool operator>=(VectorIterator const &other) const 
	{
		return (this->m_ptr >= other.m_ptr);
	}
	protected:
		pointer		m_ptr;
};
}

#endif